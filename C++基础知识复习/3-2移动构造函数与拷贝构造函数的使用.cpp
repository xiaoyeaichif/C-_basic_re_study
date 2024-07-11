


#include<iostream>
#include<vector>


class Myclass {
public:
	Myclass(int size):data(size)
	{
		std::cout << this << " Constructed\n"; // 输出当前的地址
	}
	//拷贝构造函数
	Myclass(const  Myclass & other): data(other.data)
	{
		std::cout <<this <<" Copied\n";
	}
	// 移动构造函数的定义
	Myclass(const  Myclass&& other) noexcept : data(std::move(other.data))
	{
		std::cout <<this <<" Moved\n";
	}
	// 析构函数
	~Myclass() {
		std::cout << this << " Destructed\n";
	}
private:
	std::vector<int> data;
};

int main()
{
	Myclass temp(1000); // 有参构造函数
	Myclass b = temp; // 拷贝构造函数的调用,拷贝完成还需要调用拷贝构造函数的析构函数
	Myclass c = std::move(temp); // 把temp的资源转移给b 
	return 0;
}

/*
	001F2468 构造函数初始化

	00EFFD94 Constructed
	
	00EFFD7C Moved
	00EFFD7C Destructed

	00EFFD94 Destructed

	001F2468 析构函数的调用

	1：也就是先构造的函数，后析构
	2：区分赋值和构造最简单的方法就是，左右两端是否在赋值前就已经初始化了，
		如果右端初始化了，左边没有初始化就是拷贝构造函数的调用，
		如果都初始化就是赋值的调用
*/