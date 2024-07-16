


#include<iostream>
#include<vector>

class Foo
{
public:
	Foo(int) {
		std::cout << "有参构造调用" << std::endl;
	}
	~Foo()
	{
		std::cout << "析构函数的调用" << std::endl;
	}
	Foo(const Foo& f)
	{
		// 拷贝f对象的值给当前对象
		this->val = f.val;
		std::cout << "拷贝构造函数的使用" << std::endl;
	}
public:
	int val;
};


int main()
{
	using res = std::vector<int>; // 将vector<int>的别名定义为res
	res res1; // 直接用res来生成一个vector<int>对象
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
	// a1的拷贝构造生成为私有的,所以该行代码出错
	Foo a2 = a1; 
	return 0;

}