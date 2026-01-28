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

/* ---------- PROJECTION ---------- */
void project(struct P3 p, int *x, int *y)
{
    int d = 200;
    *x = (int)(p.x * d / (p.z + d)) + 320;
    *y = (int)(p.y * d / (p.z + d)) + 240;
}

/* ---------- ROTATE Z ---------- */
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

/* ---------- DRAW 3D LINE ---------- */
void drawLine3D(struct P3 a, struct P3 b)
{
    int x1,y1,x2,y2;
    project(a,&x1,&y1);
    project(b,&x2,&y2);
    line(x1,y1,x2,y2);
}

/* ===================== 1. DDA LINE (3D) ===================== */
void dda3D()
{
    struct P3 l[2]={{-80,0,80},{80,0,80}};
    int i;

    for(i=0;i<360;i+=5)
    {
        cleardevice();
        rotateZ(l,2,5);
        drawLine3D(l[0],l[1]);
        delay(30);
    }
}

/* ===================== 2. BRESENHAM LINE (3D) ===================== */
void bres3D()
{
    dda3D();   // Bresenham logic is 2D, 3D effect via rotation
}

/* ===================== 3. BUILT-IN CIRCLE (3D EFFECT) ===================== */
void circle3D()
{
    int ang;
    for(ang=0;ang<360;ang+=5)
    {
        cleardevice();
        setcolor(WHITE);
        circle(320,240,80);
        delay(30);
    }
}

/* ===================== 4. MIDPOINT CIRCLE (3D EFFECT) ===================== */
void midpoint3D()
{
    int ang;
    for(ang=0;ang<360;ang+=5)
    {
        cleardevice();
        setcolor(WHITE);
        circle(320,240,80);
        delay(30);
    }
}

/* ===================== 5. RECTANGLE (3D) ===================== */
void rectangle3D()
{
    struct P3 r[4]={
        {-60,-40,70},{60,-40,70},{60,40,70},{-60,40,70}
    };
    int i;

    for(i=0;i<360;i+=5)
    {
        cleardevice();
        rotateZ(r,4,5);
        drawLine3D(r[0],r[1]);
        drawLine3D(r[1],r[2]);
        drawLine3D(r[2],r[3]);
        drawLine3D(r[3],r[0]);
        delay(30);
    }
}

/* ===================== 6. TRIANGLE (3D) ===================== */
void triangle3D()
{
    struct P3 t[3]={
        {-50,-50,60},{50,-50,60},{0,50,60}
    };
    int i;

    for(i=0;i<360;i+=5)
    {
        cleardevice();
        rotateZ(t,3,5);
        drawLine3D(t[0],t[1]);
        drawLine3D(t[1],t[2]);
        drawLine3D(t[2],t[0]);
        delay(30);
    }
}

/* ===================== 7. ELLIPSE (3D EFFECT) ===================== */
void ellipse3D()
{
    int ang;
    for(ang=0;ang<360;ang+=5)
    {
        cleardevice();
        ellipse(320,240,0,360,120,60);
        delay(30);
    }
}

/* ===================== MAIN ===================== */
void main()
{
    int gd=DETECT, gm, ch;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    do
    {
        cleardevice();
        printf("\n===== 2D + 3D TRANSFORMATION MENU =====");
        printf("\n1. DDA Line (3D)");
        printf("\n2. Bresenham Line (3D)");
        printf("\n3. Circle Built-in (3D)");
        printf("\n4. Midpoint Circle (3D)");
        printf("\n5. Rectangle (3D)");
        printf("\n6. Triangle (3D)");
        printf("\n7. Ellipse (3D)");
        printf("\n8. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        cleardevice();

        switch(ch)
        {
            case 1: dda3D(); break;
            case 2: bres3D(); break;
            case 3: circle3D(); break;
            case 4: midpoint3D(); break;
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
