//1044. ��������(20)
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
//����������13���Ƽ����ģ�
//
//�����˵�0�������˳�Ϊtret��
//����������1��12�Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
//�����˽���λ�Ժ��12����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��
//��������˵����֡�29������ɻ����ľ��ǡ�hel mar�����������ġ�elo nov����Ӧ�������֡�115����
//Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣
//
//�����ʽ��
//
//�����һ�и���һ��������N��<100�������N�У�ÿ�и���һ��[0, 169)�����ڵ����� ���� 
//�����ǵ����ģ������ǻ����ġ�
//
//�����ʽ��
//
//��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�
//
//����������
//4
//29
//5
//elo nov
//tam
//���������
//hel mar
//may
//115
//13

//idea:
//���Ȿ���ϻ��ǽ���ת��������
//ֻҪע��һЩ����ĸ�ʽ������Ϳ�����������0������

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string m1[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string m2[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void num(string &s)
{
	int n = 0;
	if (s[0] >= '0'&&s[0] <= '9')
	{
		n = stoi(s);
		int s, g;
		s = n / 13;
		g = n % 13;
		if (s > 0)
		{
			cout << m2[s - 1];
			//Ҫ���ĸպñ�13������ʱ���λ��0����Ҫ���tret
			if (g > 0)
				cout << " " << m1[g] << endl;
			else
				cout << endl;
		}
		else
		{
			cout << m1[g] << endl;
		}
	}
	else
	{
		istringstream is(s);
		vector<string> vs;
		string hx;
		while (is >> hx)
			vs.push_back(hx);

		if (vs.size() == 1)
		{
			int i = 0, j = 0;
			for (; i != 13; ++i)
			{
				if (m1[i] == vs[0])
				{
					n = i;
					break;
				}
			}
			if (i == 13)
			{
				for (; j != 12; ++j)
				{
					if (m2[j] == vs[0])
					{
						n += 13*(j+1);
						break;
					}
				}
			}
		}

		if (vs.size() == 2)
		{
			int i = 0, j = 0;
			for (; i != 12; ++i)
			{
				if (m2[i] == vs[0])
				{
					n += 13 * (i + 1);
					break;
				}
			}
			for (; j != 13; ++j)
			{
				if (m1[j] == vs[1])
				{
					n += j;
					break;
				}
			}

		}

		cout << n << endl;
	}
}

int main()
{
	int n;
	string count;
	getline(cin, count);
	n = stoi(count);

	for (int i = 0; i != n; ++i)
	{
		string s;
		getline(cin, s);
		num(s);
	}
}