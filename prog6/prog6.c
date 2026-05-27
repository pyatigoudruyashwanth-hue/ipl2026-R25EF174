#include<stdio.h>
#include<math.h>
#define hight  100
#define width  100
typedef struct
{
    int radius;
    int x;
    int y;
}a;
void intbuffer(char buffer[100][100])
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            buffer[i][j]=' ';
        }
    }
}
void plotpoint(char buffer[100][100], int x, int y)
{
    if(x>0&&x<100&&y>0&&y<100)
    {
        buffer[x][y]='*';
    }           
}
void drawcircle(a c,char buffer[100][100])
{
    int r = c.radius;
    int cx = c.x;
    int cy = c.y;
    for(int x = -r; x <= r; x++){
        int tmp = r*r -x*x;
        if(tmp < 0) continue;
        int y = (int)round(sqrt(tmp));
        plotpoint(buffer, cx + x, cy + y);
        plotpoint(buffer, cx + x, cy - y);
    }
}
void printbuffer(char buffer[100][100])
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            printf("%c",buffer[i][j]);
        }
        printf("\n");
    }
}
int main()
{

    char buffer[hight][width];
    intbuffer(buffer);
    a c;
    c.radius=10;
    c.x=20;
    c.y=20;
    drawcircle(c,buffer);
    printbuffer(buffer);
    return 0;
}



