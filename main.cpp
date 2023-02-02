
    #include "TXLib.h"

struct Picture

 {
    int x;
    int y;
    HDC image;
    int vx;
    int vy;

 };

struct Barriar
 {
     int x;
     int y;
     int w;
     int h;

 };

struct Bullet
{
    int x;
    int y;
    int vx;
    int vy;

    void draw()
    {
    TXSetColor (TX_BLACK);
    TXSetFillColor (TX_BLACK;
    txCircle(x,y,5);
    }


    }



 void draw_picture (Picture picture)
 {
    txTransparentBlt (txDC(), picture.x,  picture.y,  95,213, picture.image, 0, 0, TX_WHITE);
 }



int main()
{
txCreateWindow(800,600);
txDisableAutoPause();

    HDC background = txLoadImage ("fon.bmp");
    int x_background = 0;
    int y_background = 0;

    // 1 упр
    Picture picture1 = {300, 300, txLoadImage ("man.bmp"), 5, 5};

    // 2 вверх вниз
    Picture picture2 = {400, 300, picture1.image, 15, 5};

    //Barriar
    Barriar bar1 = {600, 100, 100, 400};

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();
        txSetColor(TX_WHITE,5);
        txSetFillColor(TX_BLACK);

        txBitBlt (txDC(), x_background,   y_background,  800, 600, background);

        draw_picture(picture1);
        draw_picture(picture2);


        txRectangle(bar1.x, bar1.y, bar1.x+bar1.w, bar1.y+bar1.h);

        picture2.y = picture2.y + picture2.vy;
        picture2.x = picture2.x + picture2.vx;

        if (picture1.x < bar1.x+bar1.w && picture1.x+213 > bar1.x)

        {
            picture1.x = bar1.x;
        }


        if(picture2.y<0 || picture2.y>600)

        {
            picture2.vy=-picture2.vy;
        }

        if(picture2.x<0 || picture2.x>800)

        {
            picture2.vx=-picture2.vx;
        }

        if(GetAsyncKeyState ('SPACE'))
        {
            picture1.y = picture1.y - picture1.vy;
        }

        if(GetAsyncKeyState ('W'))
        {
            picture1.y = picture1.y - picture1.vy;
        }
        if(GetAsyncKeyState ('S'))
        {
            picture1.y = picture1.y + picture1.vy;
        }
        if(GetAsyncKeyState ('A'))
        {
            picture1.x = picture1.x - picture1.vx;
        }
        if(GetAsyncKeyState ('D'))
        {
            picture1.x = picture1.x + picture1.vx;
        }

        bul.vitable = true;
        bul.x = picture.x
        bul.y = picture.y



        if(picture1.x < 0)
        {
            picture1.x = 0;
            x_background += 5;
        }

        if(picture1.x > 800-95)
        {
            picture1.x = 800-95;
            x_background -= 5;
        }

        if(picture1.y < 0)
        {
            picture1.y = 0;
            y_background +=5;
        }

        if(picture1.y > 600-213)
        {
            picture1.y = 600-213;
            y_background -= 5;
        }



        txSleep(10);
    }

    txDeleteDC (background);
    txDeleteDC (picture1.image);
    txDeleteDC (picture2.image);

txTextCursor (false);
return 0;
}


