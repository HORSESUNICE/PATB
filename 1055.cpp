//1055. ������(25)
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

//�ļ�����ʱ���κ���Ҫ������Ը�����N����K�ŵĶ�������Ŷӹ������£�
//
//ÿ������ΪN / K������ȡ���������������ȫ��վ�����һ�ţ�
//���������˵ĸ��Ӷ�����ǰ���κ��˰���
//ÿ���������վ�м䣨�м�λ��Ϊm / 2 + 1������mΪ������������������ȡ������
//ÿ�����������м���Ϊ�ᣬ����߷��������Һ��������վ���м��˵�����
//������5�����Ϊ190��188��186��175��170�������Ϊ175��188��190��186��170��
//�����������������ߣ��������������м��˵��ұߣ���
//�����������ͬ�������ֵ��ֵ����������С����ﱣ֤��������
//�ָ���һ�������ˣ����д����������ǵĶ��Ρ�
//
//�����ʽ��
//
//ÿ���������1������������ÿ������������1�и�������������N�� <= 10000������������K�� <= 10������������
//���N�У�ÿ�и���һ���˵����֣��������ո񡢳��Ȳ�����8��Ӣ����ĸ������ߣ�[30, 300]�����ڵ���������
//
//�����ʽ��
//
//������յĶ��Ρ���K������������Կո�ָ�����ĩ�����ж���ո�
//ע�⣺��������������ߣ����ŵ���������Ϸ���ǰ��������·���
//
//����������
//10 3
//Tom 188
//Mike 170
//Eva 168
//Tim 160
//Joe 190
//Ann 168
//Bob 175
//Nick 186
//Amy 160
//John 159
//���������
//Bob Tom Joe Nick
//Ann Mike Eva
//Tim Amy John

//idea:
//���������Ƕ����ݰ���ߴӸߵ�������
//Ȼ����������1050�ķ���
//����������
//��Ϊ���һ�������������в�ͬ�����⴦��
//֮��ÿ�а�Ҫ�󣬴��м俪ʼ����
//���ñ��-1���������ҵ���������

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct person
{
	string name;
	int height;
};

bool compare(const person &p1, const person &p2)
{
	if (p1.height > p2.height)
		return true;
	else if ((p1.height == p2.height) && p1.name < p2.name)
		return true;
	else
		return false;
}

int main()
{
	int n, k, row, rowmax;
	cin >> n >> k;
	row = n / k;
	rowmax = n / k + n%k;
	vector<person> vp;
	vector<string> vs(rowmax, "");
	vector<vector<string>> pic(k, vs);

	for (int i = 0; i != n; ++i)
	{
		string pn;
		int ph;
		cin >> pn >> ph;
		vp.push_back({ pn,ph });
	}

	sort(vp.begin(), vp.end(), compare);
	int start;

	int sump = 0;
	for (int i = 0; i != k; ++i)
	{
		int turn = 1;
		int index = 0;
		if (i == 0)
		{
			start = rowmax / 2;
			int count = 0;
			while (count != rowmax)
			{
				pic[i][start] = vp[sump].name;
				turn *= -1;
				index += 1;
				start += turn*index;
				++count;
				++sump;
			}
		}
		else
		{
			start = row / 2;
			int count = 0;
			while (count != row)
			{
				pic[i][start] = vp[sump].name;
				turn *= -1;
				index += 1;
				start += turn*index;
				++count;
				++sump;
			}
		}
	}

	for (int i = 0; i != k; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j != rowmax; ++j)
			{
				if (j == 0)
					cout << pic[i][j];
				else
					cout << " " << pic[i][j];
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j != row; ++j)
			{
				if (j == 0)
					cout << pic[i][j];
				else
					cout << " " << pic[i][j];
			}
			cout << endl;
		}
	}
}