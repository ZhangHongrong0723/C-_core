#include <iostream>
#include <string>
using namespace std;

class Person{
public:
	int m_a;

public:
	Person() {
	
	}
	Person(int a) {
		m_a = a;
	}
	//操作符+的运算符重载
	//成员函数本质的重载是 Person p3=p1.operator(p2);
	//全局函数重载的本质是 Person p3= operator(p1+p2);
	//运算符重载也可以进行函数重载
	

	//Person operator+(Person &p){
	//	return this->m_a + p.m_a;
	//
	//}
	// 

	//自增自减运算符
	//编译器自身本身提供的就是浅拷贝
	Person& operator++() {

		m_a++;
		return *this;

	}


	//函数调用运算符重载
	//仿函数
	void operator()(string test) {
		cout << test << endl;
	}

};

Person operator+(Person& p1, Person& p2) {
	return p1.m_a + p2.m_a;

}
//左移运算符重载必须放在全局函数中
ostream& operator<<(ostream &out,Person &p) {//本质上是out<<p
	out << "a的数值为" << p.m_a;
	return out;

}


int main9() {
	Person p1(10);
	Person p2(20);
	Person p3 =  p1+p2;
	//cout << (p3.m_a) << endl;
	cout << p1;
	cout << ++p2 << endl;


	Person p5;
	p5("hello");
	//匿名函数对象
	Person()("jjj");
	system("pause");
	return 0;
}