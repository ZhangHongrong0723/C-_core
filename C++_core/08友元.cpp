#include <iostream>
#include <string>
using namespace std;

/*
	��Ԫ��ʵ�֣�
	1��ȫ�ֺ�������Ԫ
	2��������Ԫ
	3����Ա��������Ԫ


	����д��Ա����������Ļ�����Ҫ���������� �� void Person����show(){}
*/
//1��ȫ�ֺ�������Ԫ

class Build {
	friend void show();
	//2��������Ԫ���������ټ�
	//�磺friend clas boy;
	//3����Ա��������Ԫ�������
	//�����������еķ�������ʱ�����˽�е����ԣ����� friend girl::visited();
public:
	Build() {
		livroom = "hello";
		bedroom = "HI";
	}
public:
	string livroom;

private: 
	string bedroom;
};
void show() {
	Build p;
	cout << p.livroom << endl;
	cout << p.bedroom << endl;
	
}
int main8() {
	show();
	system("pause");
	return 0;
}