//1009. ˵����(20)
//
//ʱ������
//400 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CHEN, Yue

//����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������
//
//�����ʽ�������������һ��������������һ���ڸ����ܳ��Ȳ�����80���ַ�����
//�ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ�����
//����֮����1���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�
//
//�����ʽ��ÿ���������������ռһ�У���������ľ��ӡ�
//
//����������
//Hello World Here I Come
//���������
//Come I Here World Hello

//idea:
//������C++����ͷǳ�����
//ֱ�ӽ��������vector����������Ϳ���

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	istringstream is(s);
	vector<string> word;
	string w;

	while (is >> w)
		word.push_back(w);

	auto it = word.end() - 1;
	while (it != word.begin())
	{
		cout << *it << " ";
		--it;
	}
	cout << *(word.begin());
}