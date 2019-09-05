#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define M 6   /* 数组行数 */
#define N 4   /* 数组列数 */

void main()
{
  int target=0, i, j, m=0;
/* 1、创建综合数据库{(x, t, b, s}（初始为空） */
  int D[M][N]={0};

/* 2、创建规则库存放规则集, condit存放规则的条件, result存放规则的结论 */
  int condit[M][N]={{1,0,1,0},{2,0,1,0},{3,0,1,0},{1,4,0,0},{2,5,0,0},{3,6,0,0}};
  int result[M][N]={{1,4,0,0},{2,5,0,0},{3,6,0,0},{1,0,0,4},{2,0,0,5},{3,0,0,6}};

  while(1){   /* "1"是真，让以下程序重复运行 */
/* 3、输入事实（例如2人），存入综合数据库（即{2,0,1,0}）*/
  printf("\nInput the number of persons: ");
  scanf("%d", &D[0][0]);
  D[0][2]=1;   /*b＝1表示船在左岸*/

/* 4、(推理机)推理过程，控制规则库与数据库的运行 */
	/* (1) 从规则库中逐一取出规则，用循环做M条规则 */
	for (i=0; i<M; i++)
	{ /* (1) 从综合数据库取出事实D[m]，取出规则的条件condit[i] */
	  /* (2) 检查事实D[m]与规则条件condit[i]是否匹配 */
	  for (j=0; j<N; j++)
	       if (condit[i][j] != D[m][j])
		break;     /* 不匹配，不用继续检查 */
	  if (j==N) j=j-1;   /* 下句用到的数组下标不能超限 */

	  /* (3) 若匹配成功，则推出新事实result[i]（即规则的结论） */
	  if (condit[i][j] == D[m][j])   /* 若不匹配，这个条件也不成立 */
	  { /* (4) 将新事实result[i]加入综合数据库D[m+1] */
	    for (j=0; j<N; j++)
		D[m+1][j]=result[i][j];
	    m=m+1;     /* 用新事实D[m]继续进行规则匹配 */

	    /* 检查综合数据库中新事实D[m]是否是目标，例如{2,0,0,5} */
	    if ( D[m][1]==0 && D[m][2]==0 && D[m][3]>0 )
		{  target=1;  /* 标记达到目标 */
		   break;     /* 成功，不再继续匹配下一条规则 */
		}
	  }
	}/* for(i...) */

/* 5、输出推理结果 */
  if (target)  /* 若target=1，推理成功 */
     printf("The time of cross river is %d\n", D[m][3]);
  else
     printf("\nThe inference fails ! Please check the input !\n");

  /* 清零重复运行 */
  target=0;
  m=0;
  for (i=0; i<M; i++)
	  for (j=0; j<N; j++)
		  D[i][j]=0;
  }/* while(...) */
}
