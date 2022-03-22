#include <iostream>

using namespace std;

/*
	引用的基本使用：
	作用：给变量起别名
	语法：数据类型 &别名=原名

	注意事项：
		引用必须初始化
		引用在初始化后，不可以再改变
	

	交换函数：
		1、值传递
		2、地址传递
		3、引用传递
	
	引用做函数的返回值：
	1、不要返回局部变量的引用
	2、函数的调用可以作为左值


	引用的本质：
	引用的本质
	是在C++内部实现为一个指针常量（指针的指向不能修改，指针的数值可以修改）
	
	引用必须引用合法空间 比如内存空间，不能引用一个数字如：int &f=10;错误

	
*/

//值传递：
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

//1、不要返回局部变量的引用

int & test01() {
	int a = 10;//局部变量存放在四区的栈区
	return a;
}

//2、函数的调用可以作为左值

int& test02() {

	static int a = 10;//全局区上的数据在程序结束后释放
	return a;

}
int main2() {
	int a = 10;
	int& b = a;
	cout << b << endl;


	int x = 10;
	int y = 20;
	mySwap1(x, y);//值传递，形参不会修饰实参

	cout << "1   *************" << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;


	mySwap2(&x,&y);//地址传递，形参会修饰实参
	cout << "2   *************" << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;


	mySwap3(x, y);//引用传递，形参会修饰实参

	cout << "3   *************" << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;





	cout << endl; cout << endl; cout << endl;
	int& ref = test01();
	cout << ref << endl;//第一次结果正确，是因为编译器做了保留
	cout << ref << endl;//第二次结果错误，因为a的内存已经释放

	int& ref2 = test02();
	test02() = 1000;//当返回a的引用时候，把数值赋给他，所以把地址中的数值改为1000
	cout << ref2<<endl;

	system("pause");
	return 0;
}