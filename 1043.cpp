//1043. ���PATest(20)
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

//����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ�����
//�뽫�ַ����µ���˳�򣬰���PATestPATest....��������˳������������������ַ���
//��Ȼ�������ַ��ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�PATest��˳���ӡ��
//ֱ�������ַ����������
//
//�����ʽ��
//
//������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����
//
//�����ʽ��
//
//��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�
//
//����������
//redlesPayBestPATTopTeePHPereatitAPPT
//���������
//PATestPATestPTetPTePePee

//idea:
//����ֻҪͳ��������ĸ�ĸ����Ϳ���
//Ȼ���������
//ÿ���һ����ĸ�ͽ�����--�Ϳ���

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	istringstream is(s);

	int patest[6] = { 0 };

	char c;
	while (is >> c)
	{
		if (c == 'P')
			++patest[0];
		if (c == 'A')
			++patest[1];
		if (c == 'T')
			++patest[2];
		if (c == 'e')
			++patest[3];
		if (c == 's')
			++patest[4];
		if (c == 't')
			++patest[5];
	}

	while (patest[0] > 0 || patest[1] > 0 || patest[2] > 0 || patest[3] > 0 || patest[4] > 0 || patest[5] > 0)
	{
		if (patest[0] > 0)
		{
			cout << "P";
			--patest[0];
		}
		if (patest[1] > 0)
		{
			cout << "A";
			--patest[1];
		}
		if (patest[2] > 0)
		{
			cout << "T";
			--patest[2];
		}
		if (patest[3] > 0)
		{
			cout << "e";
			--patest[3];
		}
		if (patest[4] > 0)
		{
			cout << "s";
			--patest[4];
		}
		if (patest[5] > 0)
		{
			cout << "t";
			--patest[5];
		}
	}
}