#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <bios.h>
#define n 7 /*размерность матрицы*/
#define por 0.5/*порядок*/
/*#define A[n][n] {{1.0,0.1,0.6,0.3,2.0},{0.1,1.0,1.8,23.0,0.1},{0.6,1.8,1.0,0.3,50.0},{0.3,23.0,0.3,1.0,0.7},{2.0,0.1,50.0,0.7,1.0}}*/
float A[n][n]={{1.0,0.1,0.6,0.3,2.0,90,5},{0.1,1.0,1.8,23.0,0.1,0.4,6},{0.6,1.8,1.0,0.3,0.1,0.1,1},{0.3,23.0,0.3,1.0,0.7,15,0.1},{2.0,0.1,0.1,0.7,1.0,10,2},{90,0.4,0.1,15,10,1,3},{5,6,1,0.1,2,3,1}};
static int a[n],RES[n][n],BIG[n],sizeB,sizeR,str;
void vyvod(void);
int cikl(int index, int index_1);
void change(void);
int korrel(void);
int myreturn = 0;

//вывод коррелирующей матрицы
void vyvod(void)
{int i,j;
 cprintf("\n\r Матрица имеет вид:\n\n\r");
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++) cprintf("  %3.1f  ",A[i][j]);cprintf("\n\r");
   cprintf("\n\r");
 }
 cprintf("\n\r Матрица имеет вид:\n\n\r");
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++) cprintf("  %3d  ",RES[i][j]);cprintf("\n\r");
   cprintf("\n\r");
 }
  return;
}


//выборка из index_1 по (index+1)
int usl(int i,int index_1)//вспомогательная функция
{if(i<index_1)return 1;
 else a[index_1-1]=0;return 0;
}

int cikl(int index, int index_1)
{int i;
 if(myreturn)return(1);
 if(index>=0)
	for(i=index;usl(i,index_1);i++)
	if(!myreturn)
	{a[i]=1;if(i!=0) a[i-1]=0; cikl(index-1,i);}
	else return(1);
 else {myreturn=korrel();return(myreturn);}
 return(0);
}


//проверка на корреляцию в соответствии с выборкой
void change(void)//вспомогательная функция
{int i;
 for (i=1;i<n;i++)
 RES[str][i]=0;
 sizeR=1;
}

int korrel(void)
{int i,l;
 for (i=0;i<sizeB;i++)
  if (a[i]==0)
  {for(l=0;l<sizeR;l++)
    if (A[BIG[i]][RES[str][l]]<=por)
     {change();return(0);}
   if (l==sizeR) RES[str][sizeR++]=BIG[i];
  }
  return(1);
}



void main(void)
{int j,z;
 clrscr();
 //создание матрицы коррелирующих элементов RES
 for(str=0;str<n;str++)
 {sizeB=0;
  for(j=0;j<n;j++) a[j]=0;
//BIG- выборка из строки элементов над главной диагональю >por
  for(j=str+1;j<n;j++) if (A[str][j]>por) BIG[sizeB++]=j;

 RES[str][0]=str;sizeR=1;
  for(z=0,myreturn=0;z<sizeB&&(!cikl(z-1,sizeB));z++,myreturn=0);
 }
  vyvod();
}


