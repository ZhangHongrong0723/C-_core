#include<iostream>
using namespace std;
#include <fstream>
class Person {
public:
	char m_name[20];
	int m_age;

	

};
int main13() {
	ofstream ofst;
	ofst.open("C:/test/abc.txt",ios::binary|ios::out);
	Person p = {"����",18};
	ofst.write((const  char*)&p,sizeof(p));
	ofst.close();

	ifstream ifst;
	ifst.open("C:/test/abc.txt",ios::binary|ios::in);
	if (!ifst.is_open()) {
		cout << "�ļ�δ��" << endl;
	}
	else {
		Person p;
		ifst.read(( char *)&p,sizeof(p));
		cout << "������" << p.m_name << endl;
		cout << "������" << p.m_age << endl;
	}
	ifst.close();
	system("pause");
	return 0;
}