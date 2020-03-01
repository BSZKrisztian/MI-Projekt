#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 Az indulas  xStart,yStart: (1,1)
 A cel xCel,yCel;
*/
struct elem
{
  int x,y,irany;
};

int a[50][50],jo,n,xUj,yUj,xCel,yCel,xStart,yStart;
struct elem st[250];
void back(int);
void kiir(int);
int megfelel(int);
int tele(int);
void adat_be();
int main()
{

   adat_be();
   xStart=1,yStart=1;
   xUj=xStart;
   yUj=yStart;
   xCel=n,yCel=n;
   st[1].x=xStart;
   st[1].y=yStart;
   back(1);
   return 0;
}
void adat_be()
{
   FILE *fin=fopen("adat.be","r");
   int i,j;
   fscanf(fin,"%i",&n);
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++) fscanf(fin,"%i",&a[i][j]);

   for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) printf("%i  ",a[i][j]);
        printf("\n");
    }
}
void back(int k)
{
    int i;
    st[k].x=xUj;
    st[k].y=yUj;
    for(i=1;i<=4;i++)
    {
        st[k].irany=i;
        if (megfelel(k))
            {
                //kiir(k);
                //char c = getch();
                if(tele(k))  kiir(k);
                else
                {
                    back(k+1);
                }
            }
    }
}
int megfelel(int k)
{
   int i;
   jo=1;
   //for(i=1;i<k&&jo;i++) jo=jo&&st[i]!=st[k];
   if(st[k].irany==1)
    {
       xUj=st[k].x-1;
       yUj=st[k].y;
    }

   if(st[k].irany==2)
    {
      xUj=st[k].x;
      yUj=st[k].y+1;
    }

    if(st[k].irany==3)
    {
      xUj=st[k].x+1;
      yUj=st[k].y;
    }
    if(st[k].irany==4)
    {
      xUj=st[k].x;
      yUj=st[k].y-1;
    }
   jo=a[xUj][yUj]==1;
   for(i=1;i<=k&&jo;i++) jo=st[i].x!=xUj||st[i].y!=yUj;
   if(jo) jo=xUj>=1&&yUj>=1&&xUj<=n&&yUj<=n;
   return jo;
}
void kiir(int k)
{
   int i;
   for(i=1;i<=k;i++) printf("(%i,%i)",st[i].x, st[i].y);
   printf("\n");
}
int tele(int k)
{
    //printf("%i (%i,%i)\n",jo,xUj,yUj);

    return st[k].x==xCel&&st[k].y==yCel;
}
