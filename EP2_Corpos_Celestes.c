/***************************************************************/
/**                                                           **/
/**   VICTOR PEPE          Número USP - 13679565              **/
/**   Exercício-Programa 02                                   **/
/**   Professor: GUILHERME MOTA                               **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#include <math.h>

double dist(double p1x, double p1y, double p2x, double p2y);

double forca(char c, int i,
             double x0, double y0, double m0,
             double x1, double y1, double m1,
             double x2, double y2, double m2);

void atualize(double *x, double *y, double *vx, double *vy, double ax, double ay, double dt);

int main()
{
    double x0, y0, vx0, vy0, m0, x1, y1, vx1, vy1, m1, x2, y2, vx2, vy2, m2, T, dt;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
          &x0, &y0, &vx0, &vy0, &m0, &x1, &y1, &vx1, &vy1, &m1, &x2, &y2, &vx2, &vy2, &m2, &T, &dt);
    int n;
    double ax0, ay0, ax1, ay1, ax2, ay2;
    double fx0, fy0, fx1, fy1, fx2, fy2;
    printf("%g %g %g %g %g %g\n", x0, y0, x1, y1, x2, y2);

    for (n = 0; n <= T; n = n + dt)
    {
        fx0 = forca('x', 0, x0, y0, m0, x1, y1, m1, x2, y2, m2);
        ax0 = fx0 / m0;
        fx1 = forca('x', 1, x0, y0, m0, x1, y1, m1, x2, y2, m2);
        ax1 = fx1 / m1;
        fx2 = forca('x', 2, x0, y0, m0, x1, y1, m1, x2, y2, m2);
        ax2 = fx2 / m2;
        fy0 = forca('y', 0, x0, y0, m0, x1, y1, m1, x2, y2, m2);
        ay0 = fy0 / m0;
        fy1 = forca('y', 1, x0, y0, m0, x1, y1, m1, x2, y2, m2);
        ay1 = fy1 / m1;
        fy2 = forca('y', 2, x0, y0, m0, x1, y1, m1, x2, y2, m2);
        ay2 = fy2 / m2;
        atualize(&x0, &y0, &vx0, &vy0, ax0, ay0, dt);
        atualize(&x1, &y1, &vx1, &vy1, ax1, ay1, dt);
        atualize(&x2, &y2, &vx2, &vy2, ax2, ay2, dt);
        printf("%g %g %g %g %g %g\n", x0, y0, x1, y1, x2, y2);
    }
    return 0;
}

double dist(double p1x, double p1y, double p2x, double p2y)
{
    double dx, dy, d;
    dx = p1x - p2x;
    dy = p1y - p2y;
    d = sqrt((dy * dy) + (dx * dx));
    return d;
}

double forca(char c, int i,
             double x0, double y0, double m0,
             double x1, double y1, double m1,
             double x2, double y2, double m2)
{

    double f01, f02, f12, fx01, fx10, fx02, fx20, fx12, fx21, fy01, fy10, fy02, fy20, fy12, fy21, fx1, fx2, fx0, fy1, fy2, fy0;
    double sen01, sen02, sen12, cos01, cos02, cos12;
    double d01, d02, d12;
    double G;
    G = 6.67 / 100000000000;
    cos01 = (x1 - x0) / dist(x0, y0, x1, y1);
    cos02 = (x2 - x0) / dist(x0, y0, x2, y2);
    cos12 = (x2 - x1) / dist(x1, y1, x2, y2);
    sen01 = (y1 - y0) / dist(x0, y0, x1, y1);
    sen02 = (y2 - y0) / dist(x0, y0, x2, y2);
    sen12 = (y2 - y1) / dist(x1, y1, x2, y2);
    d01 = dist(x0, y0, x1, y1);
    d02 = dist(x0, y0, x2, y2);
    d12 = dist(x1, y1, x2, y2);
    f01 = m0 * m1 * G / (d01 * d01);
    fx01 = cos01 * f01;
    fx10 = -fx01;
    fy01 = sen01 * f01;
    fy10 = -fy01;
    f02 = m0 * m2 * G / (d02 * d02);
    fx02 = cos02 * f02;
    fx20 = -fx02;
    fy02 = sen02 * f02;
    fy20 = -fy02;
    f12 = m2 * m1 * G / (d12 * d12);
    fx12 = cos12 * f12;
    fx21 = -f12;
    fy12 = sen12 * f12;
    fy21 = -f12;
    if (i == 0)
    {
        fy0 = fy01 + fy02;
        fx0 = fx01 + fx02;
        if (c == 'x')
        {
            return fx0;
        }
        else
        {
            return fy0;
        }
    }

    if (i == 1)
    {
        fy1 = fy10 + fy12;
        fx1 = fx10 + fx12;
        if (c == 'x')
        {
            return fx1;
        }
        else
        {
            return fy1;
        }
    }
    if (i == 2)
    {
        fy2 = fy20 + fy21;
        fx2 = fx20 + fx21;
        if (c == 'x')
        {
            return fx2;
        }
        else
        {
            return fy2;
        }
    }
}

void atualize(double *x, double *y, double *vx, double *vy, double ax, double ay, double dt)
{
    *vx = *vx + (ax * dt);
    *vy = *vy + (ay * dt);
    *x = *x + ((*vx) * dt);
    *y = *y + ((*vy) * dt);
}
