//1052. ������ (20)
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

//�����ձ������ͨ���ɡ��֡������ۡ������ڡ�������Ҫ������ɡ�
//����������Ǽ���һ����������ǰ����и�ʽ����ģ�
//
//[����]([����][��][����])[����]
//�ָ�����ѡ�õķ��ż��ϣ����㰴�û���Ҫ��������顣
//
//�����ʽ��
//
//����������ǰ����˳���Ӧ�����֡��ۡ��ڵĿ�ѡ���ż���
//ÿ����������һ�Է�����[]�ڡ���Ŀ��֤ÿ�����϶�������һ�����ţ���������10�����ţ�
//ÿ�����Ű���1��4���ǿ��ַ���
//
//֮��һ�и���һ��������K��Ϊ�û�����ĸ��������K�У�
//ÿ�и���һ���û��ķ���ѡ��˳��Ϊ���֡����ۡ��ڡ����ۡ����֡���
//����ֻ������������Ӧ�����е���ţ���1��ʼ�������ּ��Կո�ָ���
//
//�����ʽ��
//
//��ÿ���û�������һ����������ɵı��顣���û�ѡ�����Ų����ڣ��������Are you kidding me? @\/@����
//
//����������
//[�r][�q][o][~\][/~]  [<][>]
// [�s][�t][^][-][=][>][<][@][��]
//[��][��][_][��][^]  ...
//4
//1 1 2 2 2
//6 8 1 5 5
//3 3 4 3 3
//2 10 3 9 3
//���������
//�r(�s���t)�q
//<(@��=)/~
//o(^��^)o
//Are you kidding me? @\/@

//idea:
//��Ϊ�����������Ǳ���֮���ǿ��ܴ��ڿո��
//��������ֻ������[]���ϱ�������������
//���֮��û�пո��Ǵ��������������1058��������

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	vector<string> hand, eye, mouth;

	string s;
	getline(cin, s);
	string sym;
	int start = 0;
	for (int i = 0; i != s.size(); ++i)
	{
		if (s[i] == '[')
		{
			start = 1;
			continue;
		}
		else if (s[i] == ']')
			start = 0;
		if (start == 1)
			sym.push_back(s[i]);
		if (s[i] == ']')
		{
			hand.push_back(sym);
			sym = "";
		}
	}

	getline(cin, s);
	for (int i = 0; i != s.size(); ++i)
	{
		if (s[i] == '[')
		{
			start = 1;
			continue;
		}
		else if (s[i] == ']')
			start = 0;
		if (start == 1)
			sym.push_back(s[i]);
		if (s[i] == ']')
		{
			eye.push_back(sym);
			sym = "";
		}
	}

	getline(cin, s);
	for (int i = 0; i != s.size(); ++i)
	{
		if (s[i] == '[')
		{
			start = 1;
			continue;
		}
		else if (s[i] == ']')
			start = 0;
		if (start == 1)
			sym.push_back(s[i]);
		if (s[i] == ']')
		{
			mouth.push_back(sym);
			sym = "";
		}
	}

	int num;
	getline(cin, s);
	num = stoi(s);

	//string���������������;
	//istringstream is;
	unsigned arr[5] = { 0 };
	for (int i = 0; i != num; ++i)
	{
		getline(cin, s);
		istringstream is(s);
		is >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
		//����ע������0Ӧ�����Are you kidding me? @\\/@
		if (arr[0] <= 0 || arr[1] <= 0 || arr[2] <= 0 || arr[3] <= 0 || arr[4] <= 0)
			cout << "Are you kidding me? @\\/@" << endl;
		else if (arr[0] <= hand.size() && arr[1] <= eye.size() && arr[2] <= mouth.size() && arr[3] <= eye.size() && arr[4] <= hand.size())
			cout << hand[arr[0] - 1] << "(" << eye[arr[1] - 1] << mouth[arr[2] - 1] << eye[arr[3] - 1] << ")" << hand[arr[4] - 1] << endl;
		else
			cout << "Are you kidding me? @\\/@" << endl;
	}
}