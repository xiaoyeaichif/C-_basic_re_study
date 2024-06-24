

#include<iostream>

using namespace std;

/*
	1: const ,一级指针，以及引用的结合
*/


int main_2_8()
{
	// 写一句代码，在内存0x0018ff44处写一个4字节的10
	int* p = (int*)0x0018ff44;
	//*p = 10;
	cout << p << endl;
	return 0;
}