


#include<iostream>

using namespace std;

/*
	1�����ǳ���  ----> ������ʵ����
		Ҳ����˵���Ƕ���ĳ���

	2��OOP���Ե��Ĵ�������ʲô��
	����  ��װ/����  �̳�  ��̬
*/

#if 0
const int NAME_LEN = 20;
class CGoods {
public:   //���ⲿ�ṩ���еķ�����������˽�е�����
	//��Ʒ��ʼ��
	void init(const char *name,double price,int amount);

	//��ӡ��Ʒ��Ϣ
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


private: //��Ա����һ������Ϊ˽��(����)
	char _name[NAME_LEN];
	double _price;
	int _amount;

};
//�����ʼ��
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
	//��Ĵ�Сֻ�ͳ�Ա�����Ĵ�С�й�
	CGoods good1;
	good1.init("���", 10.5, 200);
	good1.show();
	return 0;
}
#endif

class SeqStack {
public:
	//���캯����ʼ��
	SeqStack(int size)
	{
		cout << this << " ���캯����ʼ��" << endl;
		_size = size;
		_pstack = new int[_size];
		_top = -1;
	}
	//����������ʼ��
	~SeqStack()
	{
		cout << this << " ���������ĵ���" << endl;
		delete[]_pstack;
		_pstack = nullptr;
	}
	//�Լ�д�ĳ�ʼ��
	void init(int size = 10)
	{
		_size = size;
		_pstack = new int[_size];	
		_top = -1;
	}
	//�Լ�д������
	void release()
	{
		delete[]_pstack;
		_pstack = nullptr;
	}
	//���Ԫ��
	void push(int val)
	{
		if (full())
		{
			resize();
		}
		_pstack[++_top] = val;
	}
	//��ȡջ��Ԫ��
	int top()
	{
		return _pstack[_top];
	}
	//����ջ��Ԫ��
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
	1��ȫ����
	2������
	3��ջ��
*/


//ȫ�������ڴ��ͷ�
SeqStack d(10); //�ȵ��ù��캯�����������������������

int main_0301()
{
	SeqStack s(10);//ջ�������ڴ�
	//���������ڴ�
	//new�ȷ����ڴ棬Ȼ����ö���Ĺ��캯����ʼ��
	//���������malloc��new������һ�ι��캯���ĵ���
	SeqStack* p1 = new SeqStack(10);
	p1->push(10);
	p1->push(10);
	p1->pop();
	cout <<"������" << p1->top() << endl;
	//�����ڴ���Ҫ�Լ��ͷ�
	//ʹ��delete�ͷŶ����ڴ�,���Ȼ���ö������������
	//Ȼ���ͷŸ��ڴ�
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