
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
    bool visible;
    int vx;
    int vy;
    void draw()
    {
        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle(x,y,5);
    }
};

void draw_picture (Picture picture)
{
    txTransparentBlt (txDC(), picture.x,  picture.y,  95, 213, picture.image, 0, 0, TX_WHITE);
}

int main()
{
txCreateWindow(800,600);
txDisableAutoPause();

    HDC background;
    HDC background1 = txLoadImage ("fon1.bmp");
    HDC background2 = txLoadImage ("fon2.bmp");
    HDC background0 = txLoadImage ("fon0.bmp");
    int x_background = 0;
    int y_background = 0;
    background = background1;

    int r = 95;

    // 1 ���
    Picture picture1 = {100, 300, txLoadImage ("man.bmp"), 15, 15};
    int picture1_old_x = 0;
    int picture1_old_y = 0;
    bool turnback;

    // 2 ����� ����
    Picture picture2 = {100, 300, picture1.image, 2, 2};

    //������
    Barriar bar1 = {111, 30, 100, 100};
    Barriar bar2 = {280, 25, 150, 150};
    Bullet bul = {150, 150, false, 0, 10};

    char str [100];
    bool stop = true;
    int level = 1;
    string PAGE = "Menu";
       //����
       while(true)
       //����
    {
        txClear();
        txSetColor(TX_WHITE,5);
        txSetFillColor(TX_BLACK);
        txBegin();
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            PAGE = "Menu";
        }
        if(PAGE == "Menu")
        //�����
        {
            txBitBlt (txDC(), 0, 0,  800, 600, background0);
            txRectangle(300, 200, 500, 250);
            txDrawText(300, 200, 500, 250, "�����");

            txRectangle(300, 300, 500, 350);
            txDrawText(300, 300, 500, 350, "�����");

            txRectangle(300, 400, 500, 450);
            txDrawText(300, 400, 500, 450, "�������");

            if(txMouseButtons() == 1 && txMouseX() > 300 && txMouseX() < 500 && txMouseY() > 200 && txMouseY() < 250)
            {
                PAGE = "Game";
            }

        //�����
            if(txMouseButtons() == 1 && txMouseX() > 300 && txMouseX() < 500 && txMouseY() > 300 && txMouseY() < 350)
            {
                break;
            }

        //�������
            if(txMouseButtons() == 1 && txMouseX() > 300 && txMouseX() < 500 && txMouseY() > 400 && txMouseY() < 450)
            {
                PAGE = "Rules";
            }



        }

        if(PAGE == "Rules")
        {
             txDrawText(0, 100, 800, 600, "���� \n ����������� ���. \n \n "
                                            "������� ����. \n \n"
                                            "������� �� ���, ��� ��������. \n \n"
                                            "����������. \n \n"
                                            "������������� �� �������� w,d,s,a. \n \n"
                                            "C������� �� �����.\n");

        }
        if(PAGE == "Game")
        {
            txBitBlt (txDC(), x_background,   y_background,  800, 600, background);
            draw_picture(picture1);
            picture1_old_x = picture1.x;
            picture1_old_y = picture1.y;
            //��
            draw_picture(picture2);
            txSetColor(TX_ORANGE);
            txSetFillColor(TX_ORANGE);
            txRectangle (picture2.x,  picture2.y+15, picture2.x+r , picture2.y);

            //����������
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

            if(bul.visible)
            {

                bul.draw();
                bul.y -= bul.vy;
            }

            txSetColor(TX_WHITE);
            txRectangle(bar1.x, bar1.y, bar1.x+bar1.w, bar1.y+bar1.h);

            if(stop)
            {
                picture2.y = picture2.y + picture2.vy;
                picture2.x = picture2.x + picture2.vx;
            }

            if (picture1.x+95 > bar1.x && picture1.x < bar1.x+bar1.w &&
                picture1.y+213 > bar1.y && picture1.y < bar1.y+bar1.h)
            {
                picture1.x = picture1_old_x;
                picture1.y = picture1_old_y;
            }

            if(picture2.y<0 || picture2.y>400)
            {
                picture2.vy=-picture2.vy;
            }

            if(picture2.x<0 || picture2.x>700)
            {
                picture2.vx=-picture2.vx;
            }

            if(GetAsyncKeyState (VK_SPACE))
            {
                bul.visible = true;
                bul.x = picture1.x+47;
                bul.y = picture1.y+50;
            }

            if(bul.y < -10)
            {
                bul.visible = false;
            }
            //����� ������
            txSetColor(TX_WHITE);
            sprintf(str,"����e��: %d", level);
            txTextOut(10, 10, str);
            if( bul.visible &&
                bul.x > picture2.x && bul.x < picture2.x+101 &&
                bul.y > picture2.y && bul.y < picture2.y+10)
            {
                r -= 10;
                if(r<0)
                {
                    r=0;
                    stop = false;
                }
            }

            if(r==0 && level==1)
            {
                background = background2;
                level = 2;
                stop = true;
                r = 100;
                picture2.vy = 10;
                picture2.vx = 10;
            }

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

        }

        txEnd();
        txSleep(10);
    }

    txDeleteDC (background1);
    txDeleteDC (background2);
    txDeleteDC (picture1.image);
    txDeleteDC (picture2.image);

txTextCursor (false);
return 0;
}


