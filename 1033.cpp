//1033. �ɼ��̴���(20)
//
//ʱ������
//200 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CHEN, Yue

//�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡�
//���ڸ���Ӧ�������һ�����֡��Լ���������Щ��������Ľ�����ֻ���������
//
//�����ʽ��
//
//������2���зֱ������������Щ�����Լ�Ӧ����������֡�
//���ж�ӦӢ����ĸ�Ļ����Դ�д������ÿ�������ǲ�����105���ַ��Ĵ���
//���õ��ַ�������ĸ[a - z, A - Z]������0 - 9��
//�Լ��»��ߡ�_��������ո񣩡���, ������.������ - ������ + ���������ϵ�������
//��Ŀ��֤��2����������ִ��ǿա�
//
//ע�⣺����ϵ��������ˣ���ô��д��Ӣ����ĸ�޷��������
//
//�����ʽ��
//
//��һ��������ܹ�������Ľ�����֡����û��һ���ַ��ܱ��������������С�
//
//7+IE.
//7_This_is_a_test.
//���������
//_hs_s_a_tst

//idea:
//�����1029�����෴
//��������һ���Ĵ���ʽ
//��һ�������¼�»���
//�����밴˳���жϺ����
//�����и����Ե���û�л��������ҪС��

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string error, stringin, stringout;
	//cin >> error >> stringin;
	//Ҫע���һ��Ϊ�յ����
	getline(cin, error);
	cin >> stringin;

	int sym[41] = { 0 };

	for (string::size_type i = 0; i != error.size(); ++i)
	{
		if (error[i] >= 'A'&&error[i] <= 'Z')
			sym[error[i] - 'A'] = 1;
		else if (error[i] >= '0'&&error[i] <= '9')
			sym[26 + error[i] - '0'] = 1;
		else if (error[i] == '_')
			sym[36] = 1;
		else if (error[i] == ',')
			sym[37] = 1;
		else if (error[i] == '.')
			sym[38] = 1;
		else if (error[i] == '-')
			sym[39] = 1;
		else if (error[i] == '+')
			sym[40] = 1;
	}


	for (string::size_type i = 0; i != stringin.size(); ++i)
	{
		if (stringin[i] >= 'A'&&stringin[i] <= 'Z')
		{
			if (sym[stringin[i] - 'A'] == 0 && sym[40] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] >= 'a'&&stringin[i] <= 'z')
		{
			if (sym[stringin[i] - 'a'] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] >= '0'&&stringin[i] <= '9')
		{
			if (sym[26 + stringin[i] - '0'] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] == '_')
		{
			if (sym[36] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] == ',')
		{
			if (sym[37] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] == '.')
		{
			if (sym[38] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] == '-')
		{
			if (sym[39] == 0)
				stringout.push_back(stringin[i]);
		}
		//else if (stringin[i] == '+')
		//{
		//	if (sym[40] == 0)
		//		stringout.push_back(stringin[i]);
		//}
	}

	if (stringout.empty())
		cout << endl;
	else
		cout << stringout;
}