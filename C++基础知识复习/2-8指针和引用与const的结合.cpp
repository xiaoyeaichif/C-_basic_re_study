

#include<iostream>

using namespace std;

/*
	1: const ,һ��ָ�룬�Լ����õĽ��
*/


int main_2_8()
{
	// дһ����룬���ڴ�0x0018ff44��дһ��4�ֽڵ�10
	int* p = (int*)0x0018ff44;
	//*p = 10;
	cout << p << endl;
	return 0;
}