
    #include "TXLib.h"

    int main()
    {
    txCreateWindow(800,600);

    //txDiable

    int x = 300;
    int vx = 15;
    int y = 300;
    int vy = 5;



    HDC background = txLoadImage ("fon.bmp");
    int x_background = 0;
    int y_background = 0;


    HDC picture1 =   txLoadImage ("man.bmp");
    HDC picture2 =   txLoadImage ("man.bmp");
    HDC picturex4 =   txLoadImage ("man.bmp");
    int x_picturex4 = 300;
    int y_picturex4 = 300;

    int x3 = 600;
    int y3 = 100;
    int x4 = 500;
    int y4 = 500;

    while(true)
    {
    txClear();
    txSetColor(TX_WHITE,5);
    txSetFillColor(TX_BLACK);

    txBitBlt (txDC(), x_background,   y_background,  800, 600, background);

    txTransparentBlt (txDC(), 400, y,   95,213, picture1, 0, 0, TX_WHITE);
    txTransparentBlt (txDC(), x,   300, 95,213, picture2, 0, 0, TX_WHITE);
    //txTransparentBlt (txDC(), x1,  y1,  95,213, picture1, 0, 0, TX_WHITE);
    txTransparentBlt (txDC(), x_picturex4,  y_picturex4,  95,213, picturex4, 0, 0, TX_WHITE);

    txRectangle(x3,y3,x4,y4);

    y=y+vy;
    x=x+vx;

    if (x_picturex4 < x4 && x_picturex4+213 > x3)

    {
        x_picturex4 = x3;
    }


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
            y_picturex4=y_picturex4-5;
        }
        if(GetAsyncKeyState ('S'))
        {
            y_picturex4=y_picturex4+5;
        }
        if(GetAsyncKeyState ('A'))
        {
            x_picturex4=x_picturex4-5;
        }
        if(GetAsyncKeyState ('D'))
        {
            x_picturex4=x_picturex4+5;
        }

        if(x_picturex4<0)
        {
            x_picturex4=0;
            x_background +=5;
        }

        if(x_picturex4>800-95)
        {
            x_picturex4=800-95;
            x_background -=5;
        }

        if(y_picturex4<0)
        {
            y_picturex4=0;
            y_background +=5;
        }

        if(y_picturex4>600-213)
        {
            y_picturex4=600-213;
            y_background -=5;
        }



        txSleep(10);
    }

    txDeleteDC (background);
    txDeleteDC (picture1);
    txDeleteDC (picture2);
    txDeleteDC (picturex4);
txTextCursor (false);
return 0;
}


