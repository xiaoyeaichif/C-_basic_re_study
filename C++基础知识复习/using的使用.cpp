


#include<iostream>
#include<vector>

class Foo
{
public:
	Foo(int) {
		std::cout << "�вι������" << std::endl;
	}
	~Foo()
	{
		std::cout << "���������ĵ���" << std::endl;
	}
	Foo(const Foo& f)
	{
		// ����f�����ֵ����ǰ����
		this->val = f.val;
		std::cout << "�������캯����ʹ��" << std::endl;
	}
public:
	int val;
};


int main()
{
	using res = std::vector<int>; // ��vector<int>�ı�������Ϊres
	res res1; // ֱ����res������һ��vector<int>����
	for (int i = 0; i < 5; i++)
	{
		res1.push_back(i);
	}
	for (auto a : res1)
	{
		std::cout << a << ' ';
	}
	std:: cout << std::endl;
	//
	Foo a1 = 123;
	// a1�Ŀ�����������Ϊ˽�е�,���Ը��д������
	Foo a2 = a1; 
	return 0;

}