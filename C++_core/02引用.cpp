#include <iostream>

using namespace std;

/*
	���õĻ���ʹ�ã�
	���ã������������
	�﷨���������� &����=ԭ��

	ע�����
		���ñ����ʼ��
		�����ڳ�ʼ���󣬲������ٸı�
	

	����������
		1��ֵ����
		2����ַ����
		3�����ô���
	
	�����������ķ���ֵ��
	1����Ҫ���ؾֲ�����������
	2�������ĵ��ÿ�����Ϊ��ֵ


	���õı��ʣ�
	���õı���
	����C++�ڲ�ʵ��Ϊһ��ָ�볣����ָ���ָ�����޸ģ�ָ�����ֵ�����޸ģ�
	
	���ñ������úϷ��ռ� �����ڴ�ռ䣬��������һ�������磺int &f=10;����

	
*/

//ֵ���ݣ�
void mySwap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

}
void mySwap2(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}
void mySwap3(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//1����Ҫ���ؾֲ�����������

int & test01() {
	int a = 10;//�ֲ����������������ջ��
	return a;
}

//2�������ĵ��ÿ�����Ϊ��ֵ

int& test02() {

	static int a = 10;//ȫ�����ϵ������ڳ���������ͷ�
	return a;

}
int main2() {
	int a = 10;
	int& b = a;
	cout << b << endl;


	int x = 10;
	int y = 20;
	mySwap1(x, y);//ֵ���ݣ��ββ�������ʵ��

	cout << "1   *************" << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;


	mySwap2(&x,&y);//��ַ���ݣ��βλ�����ʵ��
	cout << "2   *************" << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;


	mySwap3(x, y);//���ô��ݣ��βλ�����ʵ��

	cout << "3   *************" << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;





	cout << endl; cout << endl; cout << endl;
	int& ref = test01();
	cout << ref << endl;//��һ�ν����ȷ������Ϊ���������˱���
	cout << ref << endl;//�ڶ��ν��������Ϊa���ڴ��Ѿ��ͷ�

	int& ref2 = test02();
	test02() = 1000;//������a������ʱ�򣬰���ֵ�����������԰ѵ�ַ�е���ֵ��Ϊ1000
	cout << ref2<<endl;

	system("pause");
	return 0;
}