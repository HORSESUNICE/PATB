//1017. A����B(20)
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

//����Ҫ�����A / B������A�ǲ�����1000λ����������B��1λ��������
//����Ҫ�������Q������R��ʹ��A = B * Q + R������
//
//�����ʽ��
//
//������1�������θ���A��B���м���1�ո�ָ���
//
//�����ʽ��
//
//��1�����������Q��R���м���1�ո�ָ���
//
//����������
//123456789050987654321 7
//���������
//17636684150141093474 3

//idea:
//������ĿҪ�󱻳����ķ�ΧԶԶ������������
//����ֻ�ܰ��ճ����ļ��㷽�����ó���
//��������Ľ��ҪС�Ĵ���

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	int b = s2[0] - '0';

	//��Ϊ0��X�����Ҫ�ֿ�����
	if (s1.size() == 1 && s1[0] < s2[0])
		cout << "0 " << s1[0] - '0';
	else
	{
		vector<int> num;
		for (vector<int>::size_type i = 0; i != s1.size(); ++i)
		{
			num.push_back(s1[i] - '0');
		}

		vector<int>::size_type i = 0;
		int sz = 0;
		//judge���ڼ�¼�Ƿ�Ϊ��ͷ��0
		//���ǽ����ͷ��0�����
		int judge = 0;

		ostringstream os;

		while (i != num.size())
		{
			sz = sz * 10 + num[i];

			os << sz / b;
			sz %= b;


			++i;
		}
		os << " " << sz;

		string s = os.str();
		string::size_type j = 0;
		while (j != s.size())
		{
			//�������
			//���Q�ĵ�һλ��0�������0�����
			if (s[j] == '0')
			{
				if (judge == 0)
					;
				else
					cout << s[j];
			}
			else
			{
				cout << s[j];
				++judge;
			}
			++j;
		}
	}
}