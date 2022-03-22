#include <iostream>

using namespace std;

//初始化列表


/*
	当类中成员是其他类对象时，称该成员为对象成员
	构造的顺序是：先调用对象成员的构造，再调用本类构造
	析构顺序与构造相反


	静态成员函数：
	1、所有对象共享同一个函数
	2、静态成员函数只能访问静态成员变量
	可以通过类名调用方法,或者	对象.方法调用
	如:	Person::func()



	空对象占用的内存空间为：1
	C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	每个对象也要有独一无二的内存地址


	成员变量和成员函数分开存储，其中非静态成员变量属于类的对象上，
	其他包含静态成员变量，非静态成员函数，静态成员函数都不属于类的对象上
*/
class Person {
public:
	Person():ma(10),mb(20),mc(30) {
			
	}
	int ma;
	int mb;
	int mc;
};

void test1() {
	Person p;
	cout << p.ma << endl;
	cout << p.mb << endl;
	cout << p.mc << endl;

}
int main6() {
	test1();
	system("pause");
	return 0;
}