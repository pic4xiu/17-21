#include "stdafx.h"
#include<stdio.h>
#include<cstdlib>
#define max(a,b)  (((a)>(b))?(a):(b))
int V[200][200];
int KnapSack(int n, int w[], int v[], int x[], int C)
{
    int i, j;
    for (i = 0; i <= n; i++)
        V[i][0] = 0;
    for (j = 0; j <= C; j++)
        V[0][j] = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j < C+1; j++){
            if (j<w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
        }
    }
    j = C;
    for (i = n - 1; i >= 0; i--)
    {
        if (V[i][j]>V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
            x[i] = 0;
    }
    printf("选中的物品是:\n");
    for (i = 0; i<n; i++)
        printf("%d ", x[i]);
    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < C+1; j++){
            printf("%d\t ", V[i][j]);
            if (j == C){
                printf("\n");
            }
        }
    }
    return V[n - 1][C];

}

int main()
{
    int s;//最大价值
    int w[5] = {2,2,6,5,4};//重量
    int v[5] = {6,3,5,4,6};//价值
    int x[5];//选取状态
    int n = 5;
    int C=10;//背包容量
    s = KnapSack(n, w, v, x, C);
    printf("最大物品价值为:\n");
    printf("%d\n", s);
    system("pause");
    return 0;

}
