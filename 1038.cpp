//1038. ͳ��ͬ�ɼ�ѧ��(20)
//
//ʱ������
//250 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CHEN, Yue

//����Ҫ�����N��ѧ���ĳɼ��������ĳһ����������ѧ�����������
//
//�����ʽ��
//
//�����ڵ�1�и���������105��������N����ѧ����������
//���1�и���N��ѧ���İٷ��������ɼ����м��Կո�ָ������1�и���Ҫ��ѯ�ķ�������K��������N������������
//�����K���������м��Կո�ָ���
//
//�����ʽ��
//
//��һ���а���ѯ˳������÷ֵ���ָ��������ѧ���������м��Կո�ָ�������ĩ�����ж���ո�
//
//����������
//10
//60 75 90 55 75 99 82 90 75 50
//3 75 90 88
//���������
//3 2 0

//idea:
//�����1032����
//��ʼ��vector��count��-6��ʱ
//�ĳ������������ͨ����

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	vector<int> grade;

	int n;
	int num;
	cin >> n;

	int st[101] = { 0 };

	for (int i = 0; i != n; ++i)
	{
		scanf("%d", &num);

		++st[num];
	}

	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		scanf("%d", &num);

		grade.push_back(num);
	}

	cout << st[grade[0]];
	if (grade.size() > 1)
	{
		for (int i = 1; i != grade.size(); ++i)
			cout << " " << st[grade[i]];
	}
}