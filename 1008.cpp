//1008. ����Ԫ��ѭ����������(20)
//
//ʱ������
//400 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard

//һ������A�д���N��N>0�����������ڲ�����ʹ�����������ǰ���£���ÿ������ѭ��������M��M >= 0����λ�ã�
//����A�е������ɣ�A0 A1����AN - 1���任Ϊ��AN - M ���� AN - 1 A0 A1����AN - M - 1����
//���M����ѭ��������ǰ���M��λ�ã��������Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����
//
//�����ʽ��ÿ���������һ��������������1������N(1 <= N <= 100)��M��M >= 0����
//��2������N��������֮���ÿո�ָ���
//
//�����ʽ����һ�������ѭ������Mλ�Ժ���������У�֮���ÿո�ָ������н�β�����ж���ո�
//
//����������
//6 2
//1 2 3 4 5 6
//���������
//5 6 1 2 3 4

//idea:
//��Ҫ��ȷ��������λ����������һ���Ϳ�����
//������ע��һ��M>=N������Ϳ�����

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	//M�Ĵ�Сû����ȷָ���Ƿ��NС�����ȡ���ָֹ��Խ��
	m %= n;

	//array���������ݣ�ans���������
	vector<int> array;
	vector<int> ans;
	int num;
	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		array.push_back(num);
	}
	auto it = array.end() - m;
	while (it != array.end())
	{
		ans.push_back(*it);
		++it;
	}
	it = array.begin();
	while(it!= array.end() - m)
	{
		ans.push_back(*it);
		++it;
	}

	auto itans = ans.begin();
	while (itans != ans.end() - 1)
	{
		cout << *itans << " ";
		++itans;
	}
	cout << *itans;

}