

#include<iostream>

using namespace std;

/*
	1:new��delete
	2��malloc��free
	3������������
*/

/*
	1:mallocֻ�����ڴ�, �������ʼ��������malloc���ٵ��ڴ�ָ����Ҫ����ǿ��ת����
	malloc�ǰ��ֽڿ����ڴ�,����void*, new�����ڴ�ֱ�ӷ���ָ�����ͣ�Ҳ���Խ��г�ʼ��
*/


int main_2_9()
{
	//malloc �� free
	int* p = (int*)malloc(sizeof(int)); //ֻ�����ڴ�,�����г�ʼ��
	if (p == nullptr)
	{
		return -1;
	}
	*p = 20;
	free(p);

	//C++  delete

	int* p1 = new int(20); //ֱ�ӷ���ָ����ָ�룬���ҳ�ʼ��
	delete p1;


	return 0;
}