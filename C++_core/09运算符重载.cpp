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
	//������+�����������
	//��Ա�������ʵ������� Person p3=p1.operator(p2);
	//ȫ�ֺ������صı����� Person p3= operator(p1+p2);
	//���������Ҳ���Խ��к�������
	

	//Person operator+(Person &p){
	//	return this->m_a + p.m_a;
	//
	//}
	// 

	//�����Լ������
	//�������������ṩ�ľ���ǳ����
	Person& operator++() {

		m_a++;
		return *this;

	}


	//�����������������
	//�º���
	void operator()(string test) {
		cout << test << endl;
	}

};

Person operator+(Person& p1, Person& p2) {
	return p1.m_a + p2.m_a;

}
//������������ر������ȫ�ֺ�����
ostream& operator<<(ostream &out,Person &p) {//��������out<<p
	out << "a����ֵΪ" << p.m_a;
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
	//������������
	Person()("jjj");
	system("pause");
	return 0;
}