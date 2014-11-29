#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <bios.h>
#define n 7 /*размерность матрицы*/
#define por 0.5/*порядок*/
/*#define A[n][n] {{1.0,0.1,0.6,0.3,2.0},{0.1,1.0,1.8,23.0,0.1},{0.6,1.8,1.0,0.3,50.0},{0.3,23.0,0.3,1.0,0.7},{2.0,0.1,50.0,0.7,1.0}}*/
float A[n][n]={{1.0,0.1,0.6,0.3,2.0,90,5},{0.1,1.0,1.8,23.0,0.1,0.4,6},{0.6,1.8,1.0,0.3,0.1,0.1,1},{0.3,23.0,0.3,1.0,0.7,15,0.1},{2.0,0.1,0.1,0.7,1.0,10,2},{90,0.4,0.1,15,10,1,3},{5,0.1,1,0.1,2,3,1}};
int RES[n][n],RES1[n*n];
void vyvod(void);

/*вывод исходной матрицы*/
void vyvod(void)
{int i,j;
 clrscr();
 cprintf("\n\r Матрица имеет вид:\n\n\r");
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++) cprintf("  %5.2f  ",A[i][j]);
   cprintf("\n\r");
 }
  return;
}


void main(void)
{int i,j,k,l,max;
 vyvod();

 /*создание матрицы коррелирующих элементов*/
 for(i=0;i<n;i++)
 {RES[i][0]=i;k=1;
  for (j=i+1;j<n;j++)
  if (A[i][j]>por)
    {for(l=0;l<=k;l++) if (A[j][RES[i][l]]<=por) l=k+2;
     if (l==k+1) RES[i][k++]=j;
    }
 }

 /*вывод матрицы*/
  cprintf("\n\rКоррелирующие элементы:\n\r");
  for (i=0;i<n;i++)
  {for(j=0;j<n;j++) cprintf("  %5d  ",RES[i][j]);cprintf("\n\r");}

 /*создание вектора элементов*/
  RES1[0]=0;l=1;j=1;
  for (i=0;i<n;i++)
  {while((RES[i][j]!=0)&(j<n)) RES1[l++]=RES[i][j++];
   j=0;
   RES1[l++]=0;/*0--разделитель элементов из различных строк*/
  }

  /*вывод вектора*/
  cprintf("\n\rВектор коррелирующих элементов:\n\r");
  for (i=0;i<l;i++)
  cprintf("  %5d  ",RES1[i]);
  bioskey(0);
}








