//1012. ���ַ���(20)
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

//����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�
//
//A1 = �ܱ�5����������������ż���ĺͣ�
//A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1 - n2 + n3 - n4...��
//A3 = ��5������2�����ֵĸ�����
//A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
//A5 = ��5������4��������������֡�
//�����ʽ��
//
//ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��
//������N��������1000�Ĵ�����������������ּ��Կո�ָ���
//
//�����ʽ��
//
//�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�
//
//������ĳһ�����ֲ����ڣ�������Ӧλ�������N����
//
//��������1��
//13 1 2 3 4 5 6 7 8 9 10 20 16 18
//�������1��
//30 11 2 9.7 9
//��������2��
//8 1 2 4 5 6 7 9 16
//�������2��
//N 11 2 N 9

//idea:
//��Ҫ����������ݹ���
//��ҪС��ĳ���������������ע�������±�Խ��ķ���

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> array;
	int num;
	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		array.push_back(num);
	}

	vector<int> a, b, c, d, e;
	auto it = array.begin();
	while (it != array.end())
	{
		switch (*it%5)
		{
		case 0:
			if (*it % 2 == 0)
				a.push_back(*it);
			break;
		case 1:
			b.push_back(*it);
			break;
		case 2:
			c.push_back(*it);
			break;
		case 3:
			d.push_back(*it);
			break;
		case 4:
			e.push_back(*it);
			break;
		default:
			break;
		}
		++it;
	}

	int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
	double a4 = 0;
	
	auto it1 = a.begin();
	while (it1 != a.end())
	{
		a1 += *it1;
		++it1;
	}

	auto it2 = b.begin();
	int symbol = -1;
	while (it2 != b.end())
	{
		symbol *= -1;
		a2 += *it2*symbol;
		++it2;
	}

	a3 = static_cast<int>(c.size());

	auto it4 = d.begin();
	while (it4 != d.end())
	{
		a4 += *it4;
		++it4;
	}
	a4 /= static_cast<int>(d.size());

	//����ҪС�Ķδ���ָ��Խ��
	//���û�е�������
	//�Ǹ�a5���ĳ�ʼֵ�ͻ�ָ��e.end()
	if (!e.empty())
	{
		auto it5 = e.begin();
		a5 = *it5;
		while (it5 != e.end())
		{
			if (a5 < *it5)
				a5 = *it5;
			++it5;
		}
	}

	if (a.empty())
		cout << "N ";
	else
		cout << a1 << " ";

	if (b.empty())
		cout << "N ";
	else
		cout << a2 << " ";

	if (c.empty())
		cout << "N ";
	else
		cout << a3 << " ";

	if (d.empty())
		cout << "N ";
	else
		//Ϊ�����һλС����C++�ĸ�ʽ̫�鷳�˾�����printf
		printf("%.1lf ", a4);

	if (e.empty())
		cout << "N";
	else
		cout << a5;
}
