#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
char* big_mul(char* a, char* b) {
    int len_a = strlen(a); 
    int len_b = strlen(b);
    int* num_arr = new int[len_a+len_b];
    memset(num_arr, 0, sizeof(int)*(len_a+len_b)); //置0
    for (int i=len_a-1; i>=0; --i) {//分别算出各个位数 
        for (int j=len_b-1; j>=0; --j) {
        num_arr[i+j+1] += (b[j]-'0')*(a[i]-'0');
        }
    }
    for (int i=len_a+len_b-1; i>=0; --i) {//进位
        if (num_arr[i] >= 10) {
        	num_arr[i-1] += num_arr[i]/10;
        	num_arr[i] %= 10;
        }
    }
    char* result = new char[len_a+len_b+1];
    for( int i=0; i<(len_a+len_b); ++i){
    	result[i] = (char)(((int)'0')+num_arr[i]);
    }
    result[len_a+len_b] = '\0'; 
    delete[] num_arr;
    return result;
}
int main(void){
    char* a = "123456789";
    char* b = "987654321";
    cout << a << " * " << b << " = " << endl;
    char* result = big_mul(a, b);
    cout << result << endl;
	system("pause");
    delete[] result;
    return 0;
}
