//1016. ����A+B (15)
//
//ʱ������
//100 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CHEN, Yue

//������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA��
//���磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��
//
//�ָ���A��DA��B��DB�����д�������PA + PB��
//
//�����ʽ��
//
//������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��
//
//�����ʽ��
//
//��һ�������PA + PB��ֵ��
//
//��������1��
//3862767 6 13530293 3
//�������1��
//399
//��������2��
//3862767 1 13530293 8
//�������2��
//0

//idea:
//ֻҪ�����������ת��Ϊ��Ҫ������־Ϳ���
//��Ҫ���Ŀ���û�з���Ҫ��������Ǿ�Ϊ0

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string a, b, da, db;
	cin >> a >> da >> b >> db;
	string s1, s2;
	for (string::size_type i = 0; i != a.size(); ++i)
	{
		if (a[i] == da[0])
			s1.push_back(da[0]);
	}

	for (string::size_type i = 0; i != b.size(); ++i)
	{
		if (b[i] == db[0])
			s2.push_back(db[0]);
	}

	long long pa = 0, pb = 0;

	//�Լ�д�Ĵ���������ֱ����stoi����
	//for (string::size_type i = 0; i != s1.size(); ++i)
	//{
	//	pa += (da[0] - '0')*static_cast<int>(pow(10, i));
	//}
	//
	//for (string::size_type i = 0; i != s2.size(); ++i)
	//{
	//	pb += (db[0] - '0')*static_cast<int>(pow(10, i));
	//}

	//�ַ������Ϊ�ջ����쳣��Ҫע��
	if (s1.empty())
		pa = 0;
	else
		pa = stoll(s1);

	if (s2.empty())
		pb = 0;
	else
		pb = stoll(s2);

	cout << pa + pb;
}