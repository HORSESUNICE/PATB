//1036. ���°���һ����(15)
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

//������ͳ�°����������������˶�ѧϰ��̣��������������д���룬��Ϊ������ʷ����λ��д������������ͳ��
//2014��ף�Ϊ��ף���������ѧ�����ܡ���ʽ�������°�����д�˺ܼ򵥵ļ�������룺
//����Ļ�ϻ�һ�������Ρ�������Ҳ����һ�𻭰ɣ�
//
//�����ʽ��
//
//������һ���и��������α߳�N��3 <= N <= 20������������αߵ�ĳ���ַ�C�����һ���ո�
//
//�����ʽ��
//
//����ɸ����ַ�C�����������Ρ�����ע�⵽�м����м�������Ϊ���ý������ȥ���������Σ�
//�������������ʵ������������50%����������ȡ������
//
//����������
//10 a
//���������
//aaaaaaaaaa
//a        a
//a        a
//a        a
//aaaaaaaaaa

//idea:
//���ǵ�ˮƽ��Obama�ܵ���΢����һ���
//Ҳ��һ�����������������

#include <iostream>

using namespace std;

int main()
{
	double n;
	int row;
	int line;
	char c;
	cin >> n >> c;

	row = static_cast<int>(n);
	line = static_cast<int>(n / 2 + 0.5);

	if (row < 5)
	{
		for (int i = 0; i != row; ++i)
			cout << c;
		cout << endl;
		for (int i = 0; i != row; ++i)
			cout << c;
	}
	else
	{
		for (int i = 0; i != row; ++i)
			cout << c;
		cout << endl;
		for (int i = 0; i != line - 2; ++i)
		{
			cout << c;
			for (int j = 0; j != row - 2; ++j)
				cout << " ";
			cout << c;
			cout << endl;
		}
		for (int i = 0; i != row; ++i)
			cout << c;
	}
}