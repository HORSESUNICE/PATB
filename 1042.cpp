//1042. �ַ�ͳ��(20)
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

//���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��
//
//�����ʽ��
//
//������һ���и���һ�����Ȳ�����1000���ַ������ַ�����ASCII���������ɼ��ַ����ո���ɣ�
//���ٰ���1��Ӣ����ĸ���Իس��������س��������ڣ���
//
//�����ʽ��
//
//��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ���
//����в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��
//
//����������
//This is a simple TEST.There ARE numbers and other symbols 1 & 2 & 3...........
//���������
//e 7

//idea:
//��Ϊ��ͳ����Ƶ����Ӣ����ĸ
//ֱ���������¼�Ϳ�����
//ֻ�����ֵ�Ǿͱ���һ������Ϳ�����

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	istringstream is(s);
	char c;
	int word[26] = { 0 };
	while (is >> c)
	{
		if ((c >= 'A'&&c <= 'Z'))
			++word[c - 'A'];
		if ((c >= 'a'&&c <= 'z'))
			++word[c - 'a'];
	}

	char wordmax = 'a';
	int max = 0;

	for (int i = 0; i != 26; ++i)
	{
		if (word[i] > max)
		{
			wordmax = 'a' + i;
			max = word[i];
		}
	}

	cout << wordmax << " " << max;
}
