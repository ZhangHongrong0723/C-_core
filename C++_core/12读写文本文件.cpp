#include<iostream>
using namespace std;
#include <fstream>
#include <string>
/*
	����ͷ�ļ�<fstream>
	�ļ�����һ��������ı��ļ��Ķ�д�Ͷ������ļ��Ķ�д
	�ı��ļ������ı���ASCII��ķ�ʽ���ڼ������
	�������ļ����ļ��Զ����Ƶ���ʽ�����ڼ�����У��û�һ�㲻��ֱ�Ӷ���

	�ļ����������ࣺ
	ofstream:д�ļ�
	ifstream�����ļ�
	fstream����д�ļ�

	�򿪷�ʽ    ����
	ios::in	    Ϊ���ļ�����
	ios::out    Ϊд�ļ�����
	ios::ate    ��ʼλ�ã��ļ�β
	ios::app    ׷�ӷ�ʽд�ļ�
	ios::trunc  ����ļ����ڣ���ɾ���ڴ���
	ios::binary �����Ʒ�ʽ
	

	������ö����Ʒ�ʽдһ���ļ�����Ҫʹ��|
	ios::binary|ios::in
*/
int main12() {
	ofstream ofst;
	ofst.open("C:/test/as.txt", ios::out);
	string word;
	cin >> word;
	ofst << word;
	ofst.close();
	cout << "д��ɹ�" << endl;

	ifstream ifst;
	ifst.open("C:/test/ss.txt", ios::in);
	if (!ifst.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	//���ļ������ַ�ʽ
	/* 1��
	char buf[1024]={0};
	while (ifst>>buf) {
		cout << buf << endl;
	}*/

	/*2��
	char buf[1024] = { 0 };
	while (ifst.getline(buf,sizeof(buf))) {
		cout << buf << endl;
	}*/


	string buf;
	while (getline(ifst, buf)) {
		cout << buf<<endl;
	}

	/*
		4��������
	char c;
	while (c=ifst.get()!=EOF) {
		cout << c;
	}*/
	ifst.close();

	system("pause");
	return 0;
}