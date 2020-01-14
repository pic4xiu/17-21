#include <stdio.h> 
#include <stdlib.h> 
#include <Windows.h> 
 
// 动态调⽤DLL库 
void DynamicUse() {  
HMODULE module = LoadLibrary("a.dll");  
if (module == NULL)  {   return;  }  
typedef int(*Func)(); // 定义函数指针类型  
Func test;  test = (Func)GetProcAddress(module, "test"); 
 
 test(); } 
 
int main(char argc, char* argv[]) {  DynamicUse();  system("pause");  return 0; }
