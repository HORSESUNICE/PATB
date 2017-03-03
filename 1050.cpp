//1050. ��������(25)
//
//ʱ������
//150 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CHEN, Yue

//����Ҫ�󽫸�����N�����������ǵ�����˳�����롰�������󡱡�
//��ν���������󡱣���ָ�����Ͻǵ�1�����ӿ�ʼ����˳ʱ������������䡣
//Ҫ�����Ĺ�ģΪm��n�У�����������m*n����N��m >= n����m - nȡ���п���ֵ�е���Сֵ��
//
//�����ʽ��
//
//�����ڵ�1���и���һ��������N����2�и���N�����������������������ֲ�����10^4�����������Կո�ָ���
//
//�����ʽ��
//
//�����������ÿ��n�����֣���m�С�����������1���ո�ָ�����ĩ�����ж���ո�
//
//����������
//12
//37 76 20 98 76 42 53 95 60 81 58 93
//���������
//98 95 93
//42 37 81
//53 20 76
//58 60 76

//idea:
//�����������״
//����������ָ���Ϊ��ȫƽ��������������
//�����Ϊ�ȿ�����ȡ����С�������ָ�������Ϊ�к�
//�Ͱ�����ĿҪ�������������
//��������vector��������
//Ȼ��Ҫ������
//ÿ������һ����Ȧ
//��������l r u l�������Ȧ����������
//������ʣ�µ����о��ٴ��ϵ�������

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int m, n;
	int sq = static_cast<int>(sqrt(num));
	if (num == sq*sq)
		m = sq;
	else
	{
		m = sq + 1;
		while (num%m)
			++m;
	}
	n = num / m;

	vector<int> vi;
	int numin;
	for (int i = 0; i != num; ++i)
	{
		cin >> numin;
		vi.push_back(numin);
	}
	sort(vi.rbegin(), vi.rend());

	vector<int> vr(n, 0);
	vector<vector<int>> v(m, vr);

	int rowu = 0, rowd = m - 1, linel = 0, liner = n - 1;
	int j = 0;
	while (linel < liner)
	{
		for (int i = linel; i != liner + 1; ++i)
			v[rowu][i] = vi[j++];
		for (int i = rowu + 1; i != rowd + 1; ++i)
			v[i][liner] = vi[j++];
		for (int i = liner - 1; i != linel - 1; --i)
			v[rowd][i] = vi[j++];
		for(int i=rowd-1;i!=rowu;--i)
			v[i][linel]=vi[j++];
		++linel;
		--liner;
		++rowu;
		--rowd;
	}
	if (linel == liner)
		for (int i = rowu; i != rowd + 1; ++i)
			v[i][linel] = vi[j++];

	for(int i=0;i!=m;++i)
		for (int j = 0; j != n; ++j)
		{
			if (n == 1)
				cout << v[i][j] << endl;
			else
			{
				if (j == 0)
					cout << v[i][j];
				else if (j == n - 1)
					cout << " " << v[i][j] << endl;
				else
					cout << " " << v[i][j];
			}
		}

}