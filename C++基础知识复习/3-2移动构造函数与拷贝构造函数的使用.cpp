


#include<iostream>
#include<vector>


class Myclass {
public:
	Myclass(int size):data(size)
	{
		std::cout << this << " Constructed\n"; // �����ǰ�ĵ�ַ
	}
	//�������캯��
	Myclass(const  Myclass & other): data(other.data)
	{
		std::cout <<this <<" Copied\n";
	}
	// �ƶ����캯���Ķ���
	Myclass(const  Myclass&& other) noexcept : data(std::move(other.data))
	{
		std::cout <<this <<" Moved\n";
	}
	// ��������
	~Myclass() {
		std::cout << this << " Destructed\n";
	}
private:
	std::vector<int> data;
};

int main()
{
	Myclass temp(1000); // �вι��캯��
	Myclass b = temp; // �������캯���ĵ���,������ɻ���Ҫ���ÿ������캯������������
	Myclass c = std::move(temp); // ��temp����Դת�Ƹ�b 
	return 0;
}

/*
	001F2468 ���캯����ʼ��

	00EFFD94 Constructed
	
	00EFFD7C Moved
	00EFFD7C Destructed

	00EFFD94 Destructed

	001F2468 ���������ĵ���

	1��Ҳ�����ȹ���ĺ�����������
	2�����ָ�ֵ�͹�����򵥵ķ������ǣ����������Ƿ��ڸ�ֵǰ���Ѿ���ʼ���ˣ�
		����Ҷ˳�ʼ���ˣ����û�г�ʼ�����ǿ������캯���ĵ��ã�
		�������ʼ�����Ǹ�ֵ�ĵ���
*/