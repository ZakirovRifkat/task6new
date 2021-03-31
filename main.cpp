#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <locale.h>
void treug(int kol,float x1,float y1,float x2,float y2,float x3,float y3, int rec)
{

    line(x2,y2,x3,y3);
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);


    if (kol<rec)
        {
            treug(kol+1,
            (x1 + x2) / 2 + (x2 - x3) / 2,
            (y1 + y2) / 2 + (y2 - y3) / 2,
            (x1 + x2) / 2 + (x1 - x3) / 2,
            (y1 + y2) / 2 + (y1 - y3) / 2,
            (x1 + x2) / 2,
            (y1 + y2) / 2, rec);
            treug(
            kol+1,
            (x3 + x2) / 2 + (x2 - x1) / 2,
            (y3 + y2) / 2 + (y2 - y1) / 2,
            (x3 + x2) / 2 + (x3 - x1) / 2,
            (y3 + y2) / 2 + (y3 - y1) / 2,
            (x3 + x2) / 2,
            (y3 + y2) / 2, rec);
            treug(kol+1,
            (x1 + x3) / 2 + (x3 - x2) / 2,
            (y1 + y3) / 2 + (y3 - y2) / 2,
            (x1 + x3) / 2 + (x1 - x2) / 2,
            (y1 + y3) / 2 + (y1 - y2) / 2,
            (x1 + x3) / 2,
            (y1 + y3) / 2, rec);

    }
}
 void osnova(float x1,float y1,float x2,float y2,float x3,float y3, int rec)
{
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x2,y2,x3,y3);


    float ax,ay,bx,by,cx,cy;
    ax=(x1+x2)/2;
    ay=(y1+y2)/2;
    bx=(x1+x3)/2;
    by=(y1+y3)/2;
    cx=(x2+x3)/2;
    cy=(y2+y3)/2;


    return treug(1,ax,ay,bx,by,cx,cy, rec);

}
int main()
{   setlocale(LC_ALL,"Rus");

    int rec;

    printf("Введите количество иттераций:\n");
    scanf("%d", &rec);


    int gd =DETECT, gm;
    initgraph(&gd, &gm,"");


    setbkcolor(WHITE);
    cleardevice();

    setlinestyle(0,0,2);
    setcolor(RED);
    osnova(50,280,500,280,280,50, rec);

    getch();
    closegraph();

    return 0;
}
