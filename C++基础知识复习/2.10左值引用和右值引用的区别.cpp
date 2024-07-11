
#include<iostream>
#include<string.h>
using namespace std;

class Stack
{
public:
	// size表示栈初始的内存大小
	Stack(int size = 1000)
		:msize(size), mtop(0)
	{
		cout << "Stack(int)" << endl;
		mpstack = new int[size];
	}
	// 栈的析构函数
	~Stack()
	{
		cout << "~Stack()" << endl;
		delete[]mpstack;
		mpstack = nullptr;
	}
	// 栈的拷贝构造函数
	Stack(const Stack& src)
		:msize(src.msize), mtop(src.mtop)
	{
		cout << "Stack(const Stack&)" << endl;
		mpstack = new int[src.msize];
		memcpy(mpstack, src.mpstack, sizeof(int) * mtop);
	}
	// 栈的赋值重载函数
	Stack& operator=(const Stack& src)
	{
		cout << "operator=" << endl;
		if (this == &src)
			return *this;

		delete[]mpstack;

		msize = src.msize;
		mtop = src.mtop;
		mpstack = new int[src.msize];
		memcpy(mpstack, src.mpstack, sizeof(int) * mtop);
		return *this;
	}
	// 返回栈的长度
	int getSize()const { return msize; }
private:
	int* mpstack;
	int mtop;
	int msize;
};
Stack GetStack(Stack& stack)
{
	// 这里构造新的局部对象tmp
	Stack tmp(stack.getSize());
	/*
	因为tmp是函数的局部对象，不能出函数作用域，
	所以这里tmp需要拷贝构造生成在main函数栈帧上
	的临时对象，因此这里会调用拷贝构造函数，完成
	后进行tmp局部对象的析构操作
	*/
	return tmp;
}
int main_02_10()
{
	Stack s;
	/*
	GetStack返回的临时对象给s赋值，该语句结束，临时对象
	析构，所以此处调用operator=赋值重载函数，然后调用
	析构函数
	*/
	s = GetStack(s); //
	return 0;
}
