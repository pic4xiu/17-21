#include"stdafx.h"
#include <iostream>
using namespace std;
void Merge(int *array, int low, int middle, int high)
{
    int *A = new int[high - low + 1];  //��ʱ���飬�洢����Ϊhigh - low + 1������
    int i = low;
    int j = middle + 1;
    int k = 0;
    while(i <= middle && j <= high)  //ֱ��ǰ�벿���벿������ȫ¼���ݴ�
    {
        if(array[i] < array[j])  //���ǰ�벿������С�ں�벿�ģ�ǰ�벿�����ݴ�
            A[k++] = array[i++];
        else                     //�����벿�����ݴ棬���±��Լ�
            A[k++] = array[j++];
    }

    while(i <= middle) //��֤ǰ�벿����¼���ݴ�
        A[k++] = array[i++];
    while(j <= high)   //��֤��벿����¼���ݴ�
        A[k++] = array[j++];
    for(i = low; i <= high; i++)  //���ݴ���������������array[low]--array[high]��
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