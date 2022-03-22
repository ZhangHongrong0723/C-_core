#include <iostream>

using namespace std;
/*
	如果添加const时候，编译器将代码修改，int temp=10；const int &ref=temp;
	const int &ref=10;   其中地址不可改，数值也不可改
	int &ref 相当于 int * const ref;

	引用就是指针常量
	

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