//1013. ������(20)
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

//��Pi��ʾ��i�����������θ�����������M <= N <= 10^4�������PM��PN������������
//
//�����ʽ��
//
//������һ���и���M��N������Կո�ָ���
//
//�����ʽ��
//
//�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�
//
//����������
//5 27
//���������
//11 13 17 19 23 29 31 37 41 43
//47 53 59 61 67 71 73 79 83 89
//97 101 103

//idea:
//����ؼ����Ǻ�1007һ������дһ���ж������ĺ���
//��Ϊ��͵���Ͱ�ǰ10000��������ȫ��������ˣ��ٰ�Ҫ��ȡ��

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//�ж��Ƿ�Ϊ����
bool f(int n)
{
	if (n == 2)
		return true;
	for (int i = 2; i != static_cast<int>(sqrt(n)) + 1; ++i)
		if (n%i == 0)
			return false;
	return true;
}

int main()
{
	vector<int> ss;
	int count = 0;
	int num = 2;
	while (count != 10001)
	{
		if (f(num))
		{
			ss.push_back(num);
			++count;
		}
		++num;
	}
	int m, n;
	cin >> m >> n;
	//ans���ڼ�¼��Ҫ�������������
	vector<int> ans;
	auto it = ss.begin() + m - 1;
	while (it != ss.begin() + n)
	{
		ans.push_back(*it);
		++it;
	}

	auto itans = ans.begin();
	while (itans != ans.end())
	{
		//ÿ�еĵ�һ������
		if ((itans - ans.begin()) % 10 == 0)
			cout << *itans;
		//ÿ�е����һ������
		else if ((itans - ans.begin()) % 10 == 9)
			cout << " " << *itans << endl;
		else
			cout << " " << *itans;
		++itans;
	}
}