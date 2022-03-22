#include <iostream>
#include <string>
using namespace std;

/*
	友元的实现：
	1、全局函数做友元
	2、类做友元
	3、成员函数做友元


	类外写成员函数，定义的话，需要加上作用域 如 void Person：：show(){}
*/
//1、全局函数做友元

class Build {
	friend void show();
	//2、类做友元就在这里再加
	//如：friend clas boy;
	//3、成员函数做友元就在这加
	//就是其他类中的方法想访问本类中私有的属性，加上 friend girl::visited();
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