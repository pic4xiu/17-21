#include"stdafx.h"
#include <iostream>
using namespace std;
void Merge(int *array, int low, int middle, int high)
{
    int *A = new int[high - low + 1];  //临时数组，存储个数为high - low + 1个数据
    int i = low;
    int j = middle + 1;
    int k = 0;
    while(i <= middle && j <= high)  //直至前半部或后半部数据完全录入暂存
    {
        if(array[i] < array[j])  //如果前半部的数据小于后半部的，前半部数据暂存
            A[k++] = array[i++];
        else                     //否则后半部数据暂存，并下标自加
            A[k++] = array[j++];
    }

    while(i <= middle) //保证前半部数据录入暂存
        A[k++] = array[i++];
    while(j <= high)   //保证后半部数据录入暂存
        A[k++] = array[j++];
    for(i = low; i <= high; i++)  //将暂存的数据重新填充至array[low]--array[high]中
        array[i] = A[i - low];
}
void MergeSort(int *array, int low, int high)
{
    int middle;
    if(low < high)
    {
        middle = (low + high) / 2; 
        MergeSort(array, low, middle); 
        MergeSort(array, middle + 1, high); 
        Merge(array, low, middle, high);
    }
}

int main()
{
    cout<<"input the length of this arr:\n";
    int n;
    cin>>n; 
    int *array = new int[n];
    cout<<endl<<"input the arr:\n"<<endl;
    for(int i = 0; i < n;cin>>array[i++]);
    MergeSort(array, 0, n - 1);
    cout<<"it is:\n"<<endl;
	for (int j=0; j<n; cout<<array[j++]<<'\t'); 
	system("pause");
    return 0;
}