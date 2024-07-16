


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

int main_3_2()
{
	Myclass temp(1000); // �вι��캯��
	Myclass b = temp; // �������캯���ĵ���,������ɻ���Ҫ���ÿ������캯������������
	Myclass c = std::move(temp); // ��temp����Դת�Ƹ�b 
	return 0;
}

/*
	00222468 ���캯����ʼ��
	0036FAEC Constructed

	0036FAD4 Copied

	0036FABC Moved
	0036FABC Destructed

	0036FAD4 Destructed

	0036FAEC Destructed
	00222468 ���������ĵ���


	1��Ҳ�����ȹ���ĺ�����������
	2�����ָ�ֵ�͹�����򵥵ķ������ǣ����������Ƿ��ڸ�ֵǰ���Ѿ���ʼ���ˣ�
		����Ҷ˳�ʼ���ˣ����û�г�ʼ�����ǿ������캯���ĵ��ã�
		�������ʼ�����Ǹ�ֵ�ĵ���
*/