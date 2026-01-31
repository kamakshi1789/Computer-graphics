#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

/* ---------- 3D POINT ---------- */
struct P3 {
    float x, y, z;
};

/* ---------- 3D → 2D PROJECTION ---------- */
void project(struct P3 p, int *x, int *y)
{
    int d = 200;
    *x = (int)(p.x * d / (p.z + d)) + 320;
    *y = (int)(p.y * d / (p.z + d)) + 240;
}

/* ---------- ROTATION ABOUT Z AXIS ---------- */
void rotateZ(struct P3 p[], int n, float ang)
{
    int i;
    float r = ang * 3.14 / 180.0;

    for(i=0;i<n;i++)
    {
        float x = p[i].x*cos(r) - p[i].y*sin(r);
        float y = p[i].x*sin(r) + p[i].y*cos(r);
        p[i].x = x;
        p[i].y = y;
    }
}

/* ========================================================= */
/* 1(a). DDA LINE ALGORITHM (3D) */
/* ========================================================= */
void dda3D(struct P3 a, struct P3 b)
{
    int x1,y1,x2,y2;
    project(a,&x1,&y1);
    project(b,&x2,&y2);

    int dx = x2-x1;
    int dy = y2-y1;
    int steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

    float xinc = dx/(float)steps;
    float yinc = dy/(float)steps;

    float x=x1, y=y1;
    int i;

    for(i=0;i<=steps;i++)
    {
        putpixel((int)(x+0.5),(int)(y+0.5),WHITE);
        x+=xinc;
        y+=yinc;
    }
}

/* ========================================================= */
/* 1(b). BRESENHAM LINE ALGORITHM (3D) */
/* ========================================================= */
void bresenham3D(struct P3 a, struct P3 b)
{
    int x1,y1,x2,y2;
    project(a,&x1,&y1);
    project(b,&x2,&y2);

    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int p = 2*dy - dx;
    int x=x1, y=y1, i;

    putpixel(x,y,WHITE);

    for(i=0;i<dx;i++)
    {
        x++;
        if(p<0) p+=2*dy;
        else { y++; p+=2*(dy-dx); }
        putpixel(x,y,WHITE);
    }
}

/* ========================================================= */
/* 2(d). MIDPOINT CIRCLE ALGORITHM (3D) */
/* ========================================================= */
void midpointCircle3D(struct P3 c, int r)
{
    int xc,yc;
    project(c,&xc,&yc);

    int x=0, y=r;
    int p=1-r;

    while(x<=y)
    {
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+y,yc+x,WHITE);
        putpixel(xc-y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE);
        putpixel(xc-y,yc-x,WHITE);

        x++;
        if(p<0) p+=2*x+1;
        else { y--; p+=2*(x-y)+1; }
    }
}

/* ========================================================= */
/* 3(e). RECTANGLE (3D) */
/* ========================================================= */
void rectangle3D()
{
    struct P3 r[4]={{-60,-40,80},{60,-40,80},{60,40,80},{-60,40,80}};
    int i;

    for(i=0;i<360;i+=5)
    {
        cleardevice();
        rotateZ(r,4,5);
        dda3D(r[0],r[1]);
        dda3D(r[1],r[2]);
        dda3D(r[2],r[3]);
        dda3D(r[3],r[0]);
        delay(30);
    }
}

/* ========================================================= */
/* 4(f). TRIANGLE (3D) */
/* ========================================================= */
void triangle3D()
{
    struct P3 t[3]={{-50,-50,80},{50,-50,80},{0,50,80}};
    int i;

    for(i=0;i<360;i+=5)
    {
        cleardevice();
        rotateZ(t,3,5);
        dda3D(t[0],t[1]);
        dda3D(t[1],t[2]);
        dda3D(t[2],t[0]);
        delay(30);
    }
}

/* ========================================================= */
/* 5(g). ELLIPSE (3D EFFECT) */
/* ========================================================= */
void ellipse3D()
{
    int i;
    for(i=0;i<360;i+=5)
    {
        cleardevice();
        ellipse(320,240,0,360,120,60);
        delay(30);
    }
}

/* ========================================================= */
/* MAIN MENU */
/* ========================================================= */
void main()
{
    int gd=DETECT, gm, ch;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    do
    {
        cleardevice();
        printf("\n===== ALL 7 GRAPHICS ALGORITHMS WITH 3D =====");
        printf("\n1. DDA Line ");
        printf("\n2. Bresenham Line ");
        printf("\n3. Built-in Circle ");
        printf("\n4. Midpoint Circle ");
        printf("\n5. Rectangle ");
        printf("\n6. Triangle ");
        printf("\n7. Ellipse ");
        printf("\n8. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        cleardevice();

        switch(ch)
        {
            case 1:{struct P3 a={-80,0,80},b={80,0,80}; dda3D(a,b);} break;
            case 2:{struct P3 a={-80,0,80},b={80,0,80}; bresenham3D(a,b);} break;
            case 3: circle(320,240,80); break;
            case 4:{struct P3 c={0,0,80}; midpointCircle3D(c,60);} break;
            case 5: rectangle3D(); break;
            case 6: triangle3D(); break;
            case 7: ellipse3D(); break;
            case 8: closegraph(); exit(0);
            default: printf("Invalid Choice");
        }
        getch();
    }
    while(ch!=8);
}
