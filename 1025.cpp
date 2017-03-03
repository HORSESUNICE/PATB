//1025. ��ת����(25)
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

//����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת��
//���磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4��
//���KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��
//
//�����ʽ��
//
//ÿ���������1������������
//ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 105)��
//�Լ�������K(<= N)����Ҫ��ת���������ĸ��������ĵ�ַ��5λ�Ǹ�������NULL��ַ�� - 1��ʾ��
//
//��������N�У�ÿ�и�ʽΪ��
//
//Address Data Next
//
//����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��
//
//�����ʽ��
//
//��ÿ������������˳�������ת�������������ÿ�����ռһ�У���ʽ��������ͬ��
//
//����������
//00100 6 4
//00000 4 99999
//00100 1 12309
//68237 6 - 1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//���������
//00000 4 33218
//33218 3 12309
//12309 2 00100
//00100 1 99999
//99999 5 68237
//68237 6 - 1

//idea:
//���Ȼ���Ҫ������Ŀ����˼
//��ת��������˵ֻ����ַ��ת�Ϳ�����
//��Ϊ��ת���ᵼ�½ڵ��next�ĵ�ַҲһ��ı�
//���⻹��һ��Ҫע���
//�ҵ�һ������ʱ���ǽ���ַ���뵽vector��Ҫ��ת�������
//�����ᳬʱ
//���˱��˵Ĵ�֮��һ��Ҫ�ĳ���������Ž���˳�ʱ������

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int node[100000] = { 0 };
	int data[100000] = { 0 };

	//ord�ǽڵ�����ʱ��˳��
	//res�Ƿ�ת�������˳��
	vector<int> ord;
	vector<int> res;

	int first, n, k;

	cin >> first >> n >> k;

	int add, da, next;

	for (int i = 0; i != n; ++i)
	{
		cin >> add >> da >> next;
		node[add] = next;
		data[add] = da;
	}

	while (first != -1)
	{
		ord.push_back(first);
		first = node[first];
	}

	//����Ľڵ��п��ܲ���������
	//��Ҳ̫���ˣ�һ�����Ե���������
	n = ord.size();

	for (int i = 0; i != n / k*k; ++i)
	{
		int j = i / k*k + k - 1 - i%k;
		res.push_back(ord[j]);
	}

	for (int i = n / k*k; i != n; ++i)
		res.push_back(ord[i]);

	for(int i=0;i!=n-1;++i)
		printf("%05d %d %05d\n", res[i], data[res[i]], res[i+1]);
	printf("%05d %d %d\n", res[n-1], data[res[n-1]], -1);
}