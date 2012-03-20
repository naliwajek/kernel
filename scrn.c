#include <system.h>

/* This values are set for 80x25 QEMU mode */
#define WIDTH 80
#define ROWS 25

/* These define textpointer, background, foreground
   colors (attributes) and cursor coordinates (x,y) */

unsigned short *textmemptr = (unsigned short *)0xB8000;
int attrib = 0x0F;
int csr_x = 0;
int csr_y = 0;

void scroll(void)
{
    unsigned blank, temp;

    /* Background color for blank */
    blank = 0x20 | (attrib << 8);

    if(csr_y >= ROWS)
    {
        /* Move the current text chunk that makes up the screen
        *  back in the buffer by a line */
        temp = csr_y - ROWS + 1;
        memcpy (textmemptr, textmemptr + temp * WIDTH, (ROWS - temp) * WIDTH * 2);

        /* Finally, we set the chunk of memory that occupies
        *  the last line of text to our 'blank' character */
        memsetw (textmemptr + (ROWS - temp) * WIDTH, blank, WIDTH);
        csr_y = ROWS - 1;
    }
}

void move_csr(void)
{
    /* Updates the hardware cursor */
    unsigned temp;

    /* The equation for finding the index in a linear
       chunk of memory can be represented by:
       Index = [(y * width) + x] */
    temp = csr_y * WIDTH + csr_x;

    /* This sends a command to indicies 14 and 15 in the
    *  CRT Control Register of the VGA controller. These
    *  are the high and low bytes of the index that show
    *  where the hardware cursor is to be 'blinking' */
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void cls(void)
{
	int i = 0;
	for (i = 0; i < WIDTH * ROWS; i++)
		textmemptr[i] = (attrib << 8) | 0x20;
}

void putch(char c)
{
    unsigned short *where;
    unsigned att = attrib << 8;

    /* Handle a backspace, by moving the cursor back one space */
    if(c == 0x08)
    {
        if(csr_x != 0) csr_x--;
    }
    /* Handles a tab by incrementing the cursor's x, but only
    *  to a point that will make it divisible by 8 */
    else if(c == 0x09)
    {
        csr_x = (csr_x + 8) & ~(8 - 1);
    }
    /* Handles a 'Carriage Return', which simply brings the
    *  cursor back to the margin */
    else if(c == '\r')
    {
        csr_x = 0;
    }
    /* We handle our newlines the way DOS and the BIOS do: we
    *  treat it as if a 'CR' was also there, so we bring the
    *  cursor to the margin and we increment the 'y' value */
    else if(c == '\n')
    {
        csr_x = 0;
        csr_y++;
    }
    /* Any character greater than and including a space, is a
    *  printable character. The equation for finding the index
    *  in a linear chunk of memory can be represented by:
    *  Index = [(y * width) + x] */
    else if(c >= ' ')
    {
        where = textmemptr + (csr_y * WIDTH + csr_x);
        *where = c | att;	/* Character AND attributes: color */
        csr_x++;
    }

    /* If the cursor has reached the edge of the screen's width, we
    *  insert a new line in there */
    if(csr_x >= WIDTH)
    {
        csr_x = 0;
        csr_y++;
    }

    /* Scroll the screen if needed, and finally move the cursor */
    scroll();
    move_csr();
}

void kprint(char *text)
{
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        putch(text[i]);
    }
}

void settextcolor(unsigned char forecolor, unsigned char backcolor)
{
    /* Top 4 bytes are the background, bottom 4 bytes
    *  are the foreground color */
    attrib = (backcolor << 4) | (forecolor & 0x0F);
}

void init_video(void)
{
    /* May seem stupid to keep here only one func but it'll be better with GUI */
    cls();
}

