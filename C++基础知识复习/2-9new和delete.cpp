

#include<iostream>

using namespace std;

/*
	1:new和delete
	2：malloc和free
	3：两个的区别
*/

/*
	1:malloc只开辟内存, 不负责初始化，另外malloc开辟的内存指针需要进行强制转化，
	malloc是按字节开辟内存,返回void*, new开辟内存直接返回指针类型，也可以进行初始化
*/


int main_2_9()
{
	//malloc 和 free
	int* p = (int*)malloc(sizeof(int)); //只开辟内存,不进行初始化
	if (p == nullptr)
	{
		return -1;
	}
	*p = 20;
	free(p);

	//C++  delete

	int* p1 = new int(20); //直接返回指定的指针，并且初始化
	delete p1;


	return 0;
}