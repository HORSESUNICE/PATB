//1040. �м���PAT��25��
//
//ʱ������
//120 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CAO, Peng

//�ַ���APPAPT�а������������ʡ�PAT�������е�һ��PAT�ǵ�2λ(P), ��4λ(A), ��6λ(T)���ڶ���PAT�ǵ�3λ(P), ��4λ(A), ��6λ(T)��
//
//�ָ����ַ�������һ�������γɶ��ٸ�PAT��
//
//�����ʽ��
//
//����ֻ��һ�У�����һ���ַ��������Ȳ�����105��ֻ����P��A��T������ĸ��
//
//�����ʽ��
//
//��һ������������ַ����а������ٸ�PAT�����ڽ�����ܱȽϴ�ֻ�����1000000007ȡ�����Ľ����
//
//����������
//APPAPT
//���������
//2

//idea:
//��ʼ�ҵ������Ǳ��������е�P
//Ȼ���������A��T���������������
//��Ȼ�ǳ�ʱ��
//�������˱��˵ķ���
//����ͳ��T�ĸ���
//����A�ĳ��������㣬����A��ɵ�PAT����ΪAǰP����*A��T����
//һ�α����Ϳ�����

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	long long sum = 0;
	string pat;
	cin >> pat;

	long long p = 0;
	long long t = count(pat.begin(), pat.end(), 'T');
	for (auto it = pat.begin(); it != pat.end(); ++it)
	{
		if (*it == 'P')
			++p;
		else if (*it == 'A')
			sum += p*t;
		else
			--t;
	}

	cout << sum % 1000000007;
}