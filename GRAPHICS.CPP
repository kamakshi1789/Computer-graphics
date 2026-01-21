#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* -------- DDA LINE -------- */
void ddaLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, i;
    float xinc, yinc, x, y;

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    x = x1;
    y = y1;

    for(i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
        x += xinc;
        y += yinc;
    }
}

/* -------- BRESENHAM LINE -------- */
void bresLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int x = x1;
    int y = y1;
    int i;

    putpixel(x, y, WHITE);

    for(i = 0; i < dx; i++)
    {
        x++;
        if(p < 0)
            p = p + 2 * dy;
        else
        {
            y++;
            p = p + 2 * (dy - dx);
        }
        putpixel(x, y, WHITE);
    }
}

/* -------- MIDPOINT CIRCLE -------- */
void midpointCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    while(x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;

        if(p < 0)
            p = p + 2 * x + 1;
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }
}

/* -------- MAIN PROGRAM -------- */
void main()
{
    int gd = DETECT, gm;
    int choice;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    do
    {
        cleardevice();
        printf("\n===== GRAPHICS MENU =====");
        printf("\n1. Line using DDA");
        printf("\n2. Line using Bresenham");
        printf("\n3. Circle (Built-in)");
        printf("\n4. Circle (Midpoint Algorithm)");
        printf("\n5. Rectangle");
        printf("\n6. Triangle");
        printf("\n7. Ellipse");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        cleardevice();

        switch(choice)
        {
            case 1:
                ddaLine(100, 100, 300, 200);
                break;

            case 2:
                bresLine(100, 100, 300, 200);
                break;

            case 3:
                circle(250, 200, 100);
                break;

            case 4:
                midpointCircle(250, 200, 100);
                break;

            case 5:
                rectangle(150, 100, 350, 300);
                break;

            case 6:
                line(200, 100, 100, 300);
                line(200, 100, 300, 300);
                line(100, 300, 300, 300);
                break;

            case 7:
                ellipse(250, 200, 0, 360, 150, 80);
                break;

            case 8:
                closegraph();
                exit(0);

            default:
                printf("Invalid Choice");
        }

        getch();

    } while(choice != 8);
}
