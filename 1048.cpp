//1048. ���ּ���(20)
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

//����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ��������������A��
//����һ������B������ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺������λ����Ӧλ��������Ӻ��13ȡ��
//����������J����10��Q����11��K����12����ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10��
//�������λΪ��1λ��
//
//�����ʽ��
//
//������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���
//
//�����ʽ��
//
//��һ����������ܺ�Ľ����
//
//����������
//1234567 368782971
//���������
//3695Q8118

//idea:
//��Ϊ����������п��ܳ��Ȳ�ͬ
//��Ҫ�ڶ̵�ǰ������ַ�
//���õ����������������ַ�
//֮��������������ܽ��
//Ҳ���Բ���ֱ��string(del,'0')+short�İ취�ı���ַ���

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	string a1, b1;
	if (a.size() >= b.size())
	{
		for (auto ita = a.rbegin(); ita != a.rend(); ++ita)
		{
			a1.push_back(*ita);
		}
		for (auto itb = b.rbegin(); itb != b.rend(); ++itb)
		{
			b1.push_back(*itb);
		}
		for (int i = 0; i != a.size() - b.size(); ++i)
			b1.push_back('0');
	}
	else
	{
		for (auto itb = b.rbegin(); itb != b.rend(); ++itb)
		{
			b1.push_back(*itb);
		}
		for (auto ita = a.rbegin(); ita != a.rend(); ++ita)
		{
			a1.push_back(*ita);
		}
		for (int i = 0; i != b.size() - a.size(); ++i)
			a1.push_back('0');
	}

	string sout;
	char arr[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };
	char c;
	for (int i = 0; i != b1.size(); ++i)
	{
		//ż��λ
		if (i & 1)
		{
			//����Ҫд(b1[i] - a1[i]) >= 0,д>0��Ӧ�����0�ı��J��
			c = (b1[i] - a1[i]) >= 0 ? arr[(b1[i] - a1[i])] : arr[(b1[i] - a1[i])+10];
		}
		else
		{
			c = arr[(a1[i] - '0' + b1[i] - '0') % 13];
		}
		sout.push_back(c);
	}

	for (auto it = sout.rbegin(); it != sout.rend(); ++it)
		cout << *it;


}