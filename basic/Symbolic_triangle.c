#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <math.h>

int n,count=0,half,sum=0;
int **a;

void backtrack(int t)

{

	if(count>half || (t*(t+1)/2-count>half)) return;
	int i,j,k;
	if(t==n){	
		sum++;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			{
				if(a[i][j])
					printf("-");
				else
					printf("+");
				printf(" ");
			}
			printf("\n");
			for(k=0;k<=i;k++)
				printf(" ");
		}
		printf("\n");
	}
	else{
		for(i=0;i<2;i++){
			a[0][t]=i;
			count=count+i;
			for(j=1;j<=t;j++){
				a[j][t-j]=a[j-1][t-j]^a[j-1][t-j+1];
				count+=a[j][t-j];
			}
			backtrack(t+1);
			for(j=1;j<=t;j++){				
				count-=a[j][t-j];
			}
			count=count-i;
		}
	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	if((n*(n+1)/2)%2==1)
	{
		printf("result is 0.\n");
		return 0;
	}
	half=n*(n+1)/4;
	a=new int*[n];
	for(i=0;i<n;i++)
		a[i]=new int [n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			a[i][j]=0;
	}
	backtrack(0);
	printf("the result is %d.\n",sum);
	system("pause");
	return 0;
}
