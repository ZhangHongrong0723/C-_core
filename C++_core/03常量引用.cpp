#include <iostream>

using namespace std;
/*
	������constʱ�򣬱������������޸ģ�int temp=10��const int &ref=temp;
	const int &ref=10;   ���е�ַ���ɸģ���ֵҲ���ɸ�
	int &ref �൱�� int * const ref;

	���þ���ָ�볣��
	

*/

void showValue(int &val) {

	val = 1000;
	cout << "val=" << val << endl;
}
int main3() {

	int a = 100;
	showValue(a);

	system("pause");
	return 0;

}