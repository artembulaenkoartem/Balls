
#include "TXLib.h"

int main()
{
txCreateWindow(800,600);

    int x = 300;
    int vx = 15;
    int y = 300;
    int vy = 5;

    int x1 = 300;
    int y1 = 300;

    while(true)
    {
        txClear();
        txSetColor(TX_WHITE,5);
        txSetFillColor(TX_BLACK);


        txCircle(400,y,15);
        y=y+vy;

        txCircle(x,300,15);
        x=x+vx;

        txCircle(x1,y1,15);


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

txTextCursor (false);
return 0;
}

