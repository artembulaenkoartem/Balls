
#include "TXLib.h"

int main()
{
txCreateWindow(800,600);

//txDiable

    int x = 300;
    int vx = 15;
    int y = 300;
    int vy = 5;

    int x1 = 300;
    int y1 = 300;

    HDC background = txLoadImage ("fon.bmp");
    HDC picture1 =   txLoadImage ("man.bmp");
    HDC picture2 =   txLoadImage ("man.bmp");

    while(true)
    {
    txClear();
    txSetColor(TX_WHITE,5);
    txSetFillColor(TX_BLACK);

    txBitBlt (txDC(), 0,   0,  800, 600, background);

    txTransparentBlt (txDC(), 400, y,   95,213, picture1, 0, 0, TX_WHITE);
    txTransparentBlt (txDC(), x,   300, 95,213, picture2, 0, 0, TX_WHITE);
    txTransparentBlt (txDC(), x1,  y1,  95,213, picture1, 0, 0, TX_WHITE);

    y=y+vy;
    x=x+vx;



        if(y<0 || y>600)

        {
            vy=-vy;
        }

        if(x<0 || x>800)

        {
            vx=-vx;
        }

        if(GetAsyncKeyState ('W'))
        {
            y1=y1-5;
        }
        if(GetAsyncKeyState ('S'))
        {
            y1=y1+5;
        }
        if(GetAsyncKeyState ('A'))
        {
            x1=x1-5;
        }
        if(GetAsyncKeyState ('D'))
        {
            x1=x1+5;
        }

        txSleep(10);
    }

    txDeleteDC (background);
    txDeleteDC (picture1);
    txDeleteDC (picture2);

txTextCursor (false);
return 0;
}


