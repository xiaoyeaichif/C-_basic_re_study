


#include<iostream>

using namespace std;

/*
	1：类是抽象  ----> 对象是实例化
		也就是说类是对象的抽象化

	2：OOP语言的四大特征是什么？
	抽象  封装/隐藏  继承  多态
*/

#if 0
const int NAME_LEN = 20;
class CGoods {
public:   //给外部提供公有的方法，来访问私有的属性
	//商品初始化
	void init(const char *name,double price,int amount);

	//打印商品信息
	void show();

	//
	void setName(char * name) {
		strcpy(_name, name);
	}
	//
	void setPrice(double price) {
		_price = price;
	}
	//
	void setAmount(int amount) {
		_amount = amount;
	}
	//
	const char * getName();
	//
	int getPrice();
	//
	int getAmount();


private: //成员变量一般设置为私有(属性)
	char _name[NAME_LEN];
	double _price;
	int _amount;

};
//类外初始化
void CGoods::init(const char* name, double price, int amount)
{
	strcpy(_name, name);
	_price = price;
	_amount = amount;
}
void CGoods::show()
{
	cout << "name:" << _name << endl;
	cout << "price:" << _price << endl;
	cout << "amount:" << _amount << endl;
}


int main()
{
	//类的大小只和成员变量的大小有关
	CGoods good1;
	good1.init("面包", 10.5, 200);
	good1.show();
	return 0;
}
#endif

class SeqStack {
public:
	void init(int size = 10)
	{
		_size = size;
		_pstack = new int[_size];	
		_top = -1;
	}
	void release()
	{
		delete[]_pstack;
		_pstack = nullptr;
	}
	//添加元素
	void push(int val)
	{
		if (full())
		{
			resize();
		}
		_pstack[++_top] = val;
	}
	//获取栈顶元素
	int top()
	{
		return _pstack[_top];
	}
	//弹出栈顶元素
	void pop()
	{
		if (empty())
		{
			return;
		}
		--_top;
	}
	bool empty()
	{
		return _top == -1;
	}
	bool full()
	{
		return _top == _size-1;
	}
private:
	int* _pstack;
	int _top;
	int _size;
	void resize()
	{
		int *ptmp = new int[2 * _size];
		for (int i = 0; i < _size; i++)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};

int main()
{
	SeqStack stack;
	stack.init(5);
	for (int i = 0; i < 15; i++)
	{
		stack.push(rand() % 100);
	}
	while (!stack.empty())
	{
		cout << stack.top() << ' ';
		stack.pop();
	}
	stack.release();
	return 0;
}