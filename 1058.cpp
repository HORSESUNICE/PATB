//1058. ѡ����(20)
//
//ʱ������
//300 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CHEN, Yue

//���Ķ�ѡ���ǱȽ��鷳�����飬���������д�����������ʦ���Ķ�ѡ�⣬����ָ���ĵ���������ࡣ
//
//�����ʽ��
//
//�����ڵ�һ�и�������������N�� <= 1000����M�� <= 100����
//�ֱ���ѧ�������Ͷ�ѡ��ĸ��������M�У�ÿ��˳�θ���һ���������ֵ��������5������������
//ѡ�������������2�Ҳ�����5��������������ȷѡ�������������ѡ�����������������������ȷѡ�
//ע��ÿ���ѡ���СдӢ����ĸa��ʼ˳�����С��������1���ո�ָ���
//���N�У�ÿ�и���һ��ѧ���Ĵ����������ÿ��𰸸�ʽΪ��(ѡ�е�ѡ����� ѡ��1 ����)����
//����Ŀ˳�������ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ���������ѡ�е�ѡ��������ʵ��ѡ�����������
//
//�����ʽ��
//
//���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�С�ע������ʱֻ��ѡ��ȫ����ȷ���ܵõ�����ķ�����
//���һ��������������Ŀ�Ĵ�������ͱ�ţ���Ŀ���������˳���1��ʼ��ţ���
//����в��У��򰴱�ŵ���˳����������ּ��ÿո�ָ�������β�����ж���ո�
//���������Ŀ��û���˴��������һ�������Too simple����
//
//����������
//3 4
//3 4 2 a c
//2 5 1 b
//5 3 2 b c
//1 5 4 a b d e
//(2 a c) (2 b d) (2 a c) (3 a b e)
//(2 a c) (1 b) (2 a b) (4 a b d e)
//(2 b d) (1 e) (2 b c) (4 a b c d)
//���������
//3
//6
//5
//2 2 3 4

//idea:
//������Ϊ�Ǹ�ʽ��������
//���Ƕ�ÿ�����������������
//����(ʱ������һ���ַ����룬Ȼ����ݶ������ִ�С��ÿ�������ַ�����һ��ѡ�Ȼ������������һ�γ���
//�Դ˽���ѭ��

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//���ڼ�¼��ѡ��ĸ�������
struct que
{
	int index;
	int score;
	int total;
	int cor;
	char word[5] = { 0 };
	int wrong = 0;
};

bool com(const que &q1, const que &q2)
{
	if (q1.wrong > q2.wrong)
		return true;
	else if ((q1.wrong == q2.wrong) && q1.index < q2.index)
		return true;
	else
		return false;
}

struct st
{
	int choose;
	char word[5] = { 0 };
};

int main()
{
	int n, m;

	string s;
	getline(cin, s);
	istringstream is(s);
	is >> n >> m;

	vector<que> vq;

	for (int i = 0; i != m; ++i)
	{
		getline(cin, s);
		istringstream dxt(s);
		que q;
		q.index = i + 1;
		dxt >> q.score >> q.total >> q.cor;
		for (int j = 0; j != q.cor; ++j)
			dxt >> q.word[j];

		vq.push_back(q);
	}



	for (int i = 0; i != n; ++i)
	{
		getline(cin, s);
		//istringstream st(s);

		vector<st> vs;

		int sum = 0;
		int sym = 0;

		int choose = 0;

		//���ø�ʽ��������д���
		for (int j = 0; j != s.size(); ++j)
		{
			if (s[j] == '(')
			{
				st ans;
				ans.choose = s[j + 1] - '0';

				for (int k = 0; k != ans.choose; ++k)
					ans.word[k] = s[j + 1 + 2 * (k + 1)];
				vs.push_back(ans);

				j += 2 * (ans.choose + 1);
			}
		}

		//�Ƚϴ�
		for (int i = 0; i != m; ++i)
		{
			if (vs[i].choose != vq[i].cor)
			{
				sym = 1;
				vq[i].wrong++;
			}
			else
			{
				int j = 0;
				for (; j != vq[i].cor; ++j)
					if (vs[i].word[j] != vq[i].word[j])
					{
						vq[i].wrong++;
						break;
					}
				if (j == vq[i].cor)
					sum += vq[i].score;
			}
		}

		cout << sum << endl;
	}

	sort(vq.begin(), vq.end(), com);

	int l = 0;
	if (vq[l].wrong)
	{
		cout << vq[l].wrong;
		while (vq[l].wrong == vq[0].wrong)
		{
			cout << " " << vq[l].index;
			++l;
		}
	}
	else
		cout << "Too simple";


}