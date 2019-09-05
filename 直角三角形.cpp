/*打印一个直角三角形*/
#include <stdio.h>

int main()
{
	int i,j;
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		for (i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}