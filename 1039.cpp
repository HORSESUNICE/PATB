//1039. ��������20��
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

//С������Щ������һ���Լ�ϲ�����鴮�������ӵ�̯���кܶമ������ɫ���鴮��
//���ǲ��ϰ��κ�һ����ɢ����������С��Ҫ���æ�ж�һ�£�ĳ���������Ƿ������ȫ���Լ���Ҫ�����ӣ�
//����ǣ���ô�������ж��ٶ�������ӣ�������ǣ���ô������ȱ�˶������ӡ�
//
//Ϊ���������������[0 - 9]��[a - z]��[A - Z]��Χ�ڵ��ַ�����ʾ��ɫ��
//������ͼ1�У���3����С���������鴮����ô��1����������Ϊ������ȫ������Ҫ�����ӣ�������8�Ų���Ҫ�����ӣ�
//��2����������Ϊû�к�ɫ���ӣ���������һ�ź�ɫ�����ӡ�
//
//
//ͼ 1
//�����ʽ��
//
//ÿ���������1������������
//ÿ�����������ֱ���2�����Ⱥ����̯�����鴮��С���������鴮��������������1000�����ӡ�
//
//�����ʽ��
//
//�������������һ���������Yes���Լ��ж��ٶ�������ӣ�
//���������������һ���������No���Լ�ȱ�˶������ӡ������1���ո�ָ���
//
//��������1��
//ppRYYGrrYBR2258
//YrR8RrY
//�������1��
//Yes 8
//��������2��
//ppRYYGrrYB225
//YrR8RrY
//�������2��
//No 2

//idea:
//������ʵ������map��¼����һ��
//�������д����������
//������sort��unique_copy�õ���Ҫ����������
//Ȼ����count������Ҫ�ĺ�ʵ���ṩ�Ĳ��

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

//��¼��Ҫ���������ͺͲ���������
struct symbol
{
	char c;
	int count;
};

int main()
{
	string act, want;
	cin >> act >> want;
	//sort(act.begin(),act.end());
	sort(want.begin(),want.end());

	string actuni, wantuni;
	//unique_copy(act.begin(), act.end(), back_inserter(actuni));
	unique_copy(want.begin(), want.end(), back_inserter(wantuni));

	//����wantuni�Ƿ���ȷ
	//cout << wantuni << endl;

	vector<symbol> vs;

	for (int i = 0; i != wantuni.size(); ++i)
	{
		vs.push_back({ wantuni[i],count(act.begin(),act.end(),wantuni[i]) - count(want.begin(),want.end(),wantuni[i]) });
	}

	//���count�Ƿ���ȷ
	//for (int i = 0; i != vs.size(); ++i)
	//{
	//	cout << vs[i].count << endl;
	//}

	//sum���ڼ�¼����������
	int sum = 0;
	for (int i = 0; i != vs.size(); ++i)
	{
		if (vs[i].count < 0)
			sum += -vs[i].count;
	}

	if (sum == 0)
		cout << "Yes " << act.size() - want.size();
	else
		cout << "No " << sum;
}