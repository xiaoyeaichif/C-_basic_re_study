
#include<iostream>
#include<string.h>
using namespace std;

class Stack
{
public:
	// size��ʾջ��ʼ���ڴ��С
	Stack(int size = 1000)
		:msize(size), mtop(0)
	{
		cout << "Stack(int)" << endl;
		mpstack = new int[size];
	}
	// ջ����������
	~Stack()
	{
		cout << "~Stack()" << endl;
		delete[]mpstack;
		mpstack = nullptr;
	}
	// ջ�Ŀ������캯��
	Stack(const Stack& src)
		:msize(src.msize), mtop(src.mtop)
	{
		cout << "Stack(const Stack&)" << endl;
		mpstack = new int[src.msize];
		memcpy(mpstack, src.mpstack, sizeof(int) * mtop);
	}
	// ջ�ĸ�ֵ���غ���
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
	// ����ջ�ĳ���
	int getSize()const { return msize; }
private:
	int* mpstack;
	int mtop;
	int msize;
};
Stack GetStack(Stack& stack)
{
	// ���ﹹ���µľֲ�����tmp
	Stack tmp(stack.getSize());
	/*
	��Ϊtmp�Ǻ����ľֲ����󣬲��ܳ�����������
	��������tmp��Ҫ��������������main����ջ֡��
	����ʱ��������������ÿ������캯�������
	�����tmp�ֲ��������������
	*/
	return tmp;
}
int main_02_10()
{
	Stack s;
	/*
	GetStack���ص���ʱ�����s��ֵ��������������ʱ����
	���������Դ˴�����operator=��ֵ���غ�����Ȼ�����
	��������
	*/
	s = GetStack(s); //
	return 0;
}
