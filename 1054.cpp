//1054. ��ƽ��ֵ (20)
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

//����Ļ���Ҫ��ǳ��򵥣�����N��ʵ�����������ǵ�ƽ��ֵ�������ӵ�����Щ�������ݿ����ǷǷ��ġ�
//һ�����Ϸ�����������[-1000��1000]�����ڵ�ʵ����������ྫȷ��С�����2λ��
//�������ƽ��ֵ��ʱ�򣬲��ܰ���Щ�Ƿ������������ڡ�
//
//�����ʽ��
//
//�����һ�и���������N��<=100�������һ�и���N��ʵ�������ּ���һ���ո�ָ���
//
//�����ʽ��
//
//��ÿ���Ƿ����룬��һ���������ERROR: X is not a legal number��������X�����롣
//�����һ��������������The average of K numbers is Y����
//����K�ǺϷ�����ĸ�����Y�����ǵ�ƽ��ֵ����ȷ��С�����2λ��
//���ƽ��ֵ�޷����㣬���á�Undefined���滻Y�����KΪ1���������The average of 1 number is Y����
//
//��������1��
//7
//5 -3.2 aaa 9999 2.3.4 7.123 2.35
//�������1��
//ERROR: aaa is not a legal number
//ERROR: 9999 is not a legal number
//ERROR: 2.3.4 is not a legal number
//ERROR: 7.123 is not a legal number
//The average of 3 numbers is 1.38
//��������2��
//2
//aaa -9999
//�������2��
//ERROR: aaa is not a legal number
//ERROR: -9999 is not a legal number
//The average of 0 numbers is Undefined

//idea:
//����ؼ����ںϷ����ݵ��ж�
//���ȺϷ����ݵ����ֻ����+- 0-9 ,
//����.ֻ����һ���������λС��

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string line;
	getline(cin, line);
	int n;
	n = stoi(line);

	getline(cin, line);
	istringstream is(line);
	string s;
	int legal = 0;
	double sum = 0;
	
	for (int i = 0; i != n; ++i)
	{
		is >> s;
		int dotcount = 0;
		int j = 0;
		for (; j != s.size(); ++j)
		{
			if ((s[j] >= '0'&&s[j] <= '9') || (s[j] == '+' || s[j] == '-' || s[j] == '.'))
			{
				if (s[j] == '-' || s[j] == '+')
				{
					if (j == 0)
						continue;
					else
						break;
				}
				if (s[j] >= '0'&&s[j] <= '9')
					continue;
				if (s[j] == '.')
				{
					++dotcount;
					if (s.size() - j > 3)
						break;
				}
				if (dotcount > 1)
					break;
				else
					continue;
			}
			else
				break;
		}

		if (j == s.size())
		{
			double nn = stod(s);
			if (nn >= -1000 && nn <= 1000)
			{
				++legal;
				sum += nn;
			}
			else
				cout << "ERROR: " << s << " is not a legal number" << endl;
		}
		else
		{
			cout << "ERROR: " << s << " is not a legal number" << endl;
		}
	}
	cout << "The average of " << legal;
	if (legal == 1)
		//ע�⿴��Ŀһ���Ϸ������ʱ���ܼ�s
		cout << " number is ";
	else
		cout << " numbers is ";
	if (legal == 0)
		cout << "Undefined" << endl;
	else
	{
		double avg = sum / legal;
		printf("%.2lf\n", avg);
	}
}