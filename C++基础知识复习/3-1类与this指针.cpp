


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
	//构造函数初始化
	SeqStack(int size)
	{
		cout << this << " 构造函数初始化" << endl;
		_size = size;
		_pstack = new int[_size];
		_top = -1;
	}
	//析构函数初始化
	~SeqStack()
	{
		cout << this << " 析构函数的调用" << endl;
		delete[]_pstack;
		_pstack = nullptr;
	}
	//自己写的初始化
	void init(int size = 10)
	{
		_size = size;
		_pstack = new int[_size];	
		_top = -1;
	}
	//自己写的析构
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
/*
	1：全局区
	2：堆区
	3：栈区
*/


//全局区的内存释放
SeqStack d(10); //先调用构造函数，程序结束调用析构函数

int main_0301()
{
	SeqStack s(10);//栈区开辟内存
	//堆区开辟内存
	//new先分配内存，然后调用对象的构造函数初始化
	//所以相对于malloc，new比他多一次构造函数的调用
	SeqStack* p1 = new SeqStack(10);
	p1->push(10);
	p1->push(10);
	p1->pop();
	cout <<"堆区：" << p1->top() << endl;
	//堆区内存需要自己释放
	//使用delete释放堆区内存,首先会调用对象的析构函数
	//然后释放该内存
	delete p1;

	for (int i = 0; i < 15; i++)
	{
		s.push(rand() % 100);
	}
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	//s.release();
	return 0;
}