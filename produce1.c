#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define M 6   /* �������� */
#define N 4   /* �������� */

void main()
{
  int target=0, i, j, m=0;
/* 1�������ۺ����ݿ�{(x, t, b, s}����ʼΪ�գ� */
  int D[M][N]={0};

/* 2������������Ź���, condit��Ź��������, result��Ź���Ľ��� */
  int condit[M][N]={{1,0,1,0},{2,0,1,0},{3,0,1,0},{1,4,0,0},{2,5,0,0},{3,6,0,0}};
  int result[M][N]={{1,4,0,0},{2,5,0,0},{3,6,0,0},{1,0,0,4},{2,0,0,5},{3,0,0,6}};

  while(1){   /* "1"���棬�����³����ظ����� */
/* 3��������ʵ������2�ˣ��������ۺ����ݿ⣨��{2,0,1,0}��*/
  printf("\nInput the number of persons: ");
  scanf("%d", &D[0][0]);
  D[0][2]=1;   /*b��1��ʾ������*/

/* 4��(������)�������̣����ƹ���������ݿ������ */
	/* (1) �ӹ��������һȡ��������ѭ����M������ */
	for (i=0; i<M; i++)
	{ /* (1) ���ۺ����ݿ�ȡ����ʵD[m]��ȡ�����������condit[i] */
	  /* (2) �����ʵD[m]���������condit[i]�Ƿ�ƥ�� */
	  for (j=0; j<N; j++)
	       if (condit[i][j] != D[m][j])
		break;     /* ��ƥ�䣬���ü������ */
	  if (j==N) j=j-1;   /* �¾��õ��������±겻�ܳ��� */

	  /* (3) ��ƥ��ɹ������Ƴ�����ʵresult[i]��������Ľ��ۣ� */
	  if (condit[i][j] == D[m][j])   /* ����ƥ�䣬�������Ҳ������ */
	  { /* (4) ������ʵresult[i]�����ۺ����ݿ�D[m+1] */
	    for (j=0; j<N; j++)
		D[m+1][j]=result[i][j];
	    m=m+1;     /* ������ʵD[m]�������й���ƥ�� */

	    /* ����ۺ����ݿ�������ʵD[m]�Ƿ���Ŀ�꣬����{2,0,0,5} */
	    if ( D[m][1]==0 && D[m][2]==0 && D[m][3]>0 )
		{  target=1;  /* ��ǴﵽĿ�� */
		   break;     /* �ɹ������ټ���ƥ����һ������ */
		}
	  }
	}/* for(i...) */

/* 5������������ */
  if (target)  /* ��target=1�������ɹ� */
     printf("The time of cross river is %d\n", D[m][3]);
  else
     printf("\nThe inference fails ! Please check the input !\n");

  /* �����ظ����� */
  target=0;
  m=0;
  for (i=0; i<M; i++)
	  for (j=0; j<N; j++)
		  D[i][j]=0;
  }/* while(...) */
}