#include "stdafx.h"
#include <iostream>
#include<windows.h>
using namespace std;
#define NoEdge -1  
int n=4;  
int cost=0; 
int bestc=NoEdge; 
int bestx[4];     
int x[4];         
int a[4][4]=     
{

    -1,30,6,4,

    30,-1,5,10,

    6,5,-1,20,

    4,10,20,-1

};
bool isHave(int i,int t)

{
    for(int j=0; j<t; j++)

        if(x[j]==i)return true;
    return false;
}

 

void Backtrack(int t)

{
    if(t==n)
    {
        if(a[x[n-1]][0]!=NoEdge
                &&((cost+a[x[n-1]][0])<bestc||bestc==NoEdge))
        {
            for(int i=0; i<n; i++)
            {
                bestx[i]=x[i];
                bestc=cost+a[x[n-1]][0];
            }
        }
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(!isHave(i,t)&&a[x[t-1]][i]!=NoEdge&&((cost+a[x[t-1]][i])<bestc||bestc==NoEdge))
            {
                cost+=a[x[t-1]][i];
                x[t]=i;
                Backtrack(t+1);
                cost-=a[x[t-1]][i];
            }
        }
    }
}

int main()
{
    x[0]=0; 
    Backtrack(1);
    for(int i=0; i<n; i++)
        cout<<bestx[i]+1<<" ";
    cout<<endl;
    cout<<bestc<<endl;
	  system("pause");
}
