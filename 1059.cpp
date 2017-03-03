//1059. C���Ծ���(20)
//
//ʱ������
//200 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CHEN, Yue

//C���Ծ������㽭��ѧ�����ѧԺ���ֵ�һ�����ֵľ�������Ȼ������ּ��Ϊ�˺��棬�佱����Ҳ���ƶ��úܻ�����
//
//0. �ھ���Ӯ��һ�ݡ����ش󽱡�������ܾ޴��һ��ѧ���о����ļ���������
//1. ����Ϊ������ѧ����Ӯ����õĽ�Ʒ ���� С������ż��
//2. �����˽��õ��ɿ�����
//
//�������������������Լ�һϵ�в����ߵ�ID����Ҫ������Щ������Ӧ�û�õĽ�Ʒ��
//
//�����ʽ��
//
//�����һ�и���һ��������N��<=10000�����ǲ�����������
//���N�и�������������ÿ�а�����˳�����һλ�����ߵ�ID��4λ������ɣ���
//����������һ��������K�Լ�K����Ҫ��ѯ��ID��
//
//�����ʽ��
//
//��ÿ��Ҫ��ѯ��ID����һ���������ID: ��Ʒ�������н�Ʒ
//�����ǡ�Mystery Award�������ش󽱣��������ǡ�Minion����С���ˣ���
//�����ǡ�Chocolate�����ɿ��������������ID���������������ӡ��Are you kidding?����ˣ���أ�����
//�����ID�Ѿ�����ˣ�����Ʒ�Ѿ�����ˣ�����ӡ��ID: Checked�������ܶ�Զ�ռ����
//
//����������
//6
//1111
//6666
//8888
//1234
//5555
//0001
//6
//8888
//0001
//1111
//2222
//8888
//2222
//���������
//8888: Minion
//0001: Chocolate
//1111: Mystery Award
//2222: Are you kidding?
//8888: Checked
//2222: Are you kidding?

//idea:
//���Ȱ����뽫id������
//֮��������һ��������Ϊ�Ƿ��콱�ı��
//��id����int��������Ͳ��ᳬʱ��
//�������id����string����map����

#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

bool ss(int n)
{
	if (n == 1)
		return false;
	if (n == 2)
		return true;

	for (int i = 2; i != static_cast<int>(sqrt(n)) + 1; ++i)
		if (n%i == 0)
			return false;

	return true;
}

int main()
{
	map<string, string> mapid;
	map<string, int> mapcheck;
	string s;
	int n;

	getline(cin, s);
	n = stoi(s);

	for (int i = 0; i != n; ++i)
	{
		getline(cin, s);
		if (i == 0)
		{
			mapid[s] = "Mystery Award";
			mapcheck[s] = 1;
		}
		else
		{
			if (ss(i + 1))
			{
				mapid[s] = "Minion";
				mapcheck[s] = 1;
			}
			else
			{
				mapid[s] = "Chocolate";
				mapcheck[s] = 1;
			}
		}

	}

	getline(cin, s);
	int k = stoi(s);
	for (int i = 0; i != k; ++i)
	{
		getline(cin, s);

		if (mapcheck[s]==0)
			cout << s << ": Are you kidding?" << endl;
		else
		{
			if (mapcheck[s] == 1)
			{
				cout << s << ": " << mapid[s] << endl;
				++mapcheck[s];
			}
			else
			{
				cout << s << ": Checked" << endl;
			}
		}
	}
}