//1002. д�������(20)
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

//����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�
//
//�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10^100��
//
//�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�
//
//����������
//1234567890987654321123456789
//���������
//yi san wu

//idea:
//��Ŀ�Ƚϼ򵥾ͽ�����ÿ��������ͺ���Ϊƴ���Ϳ���
//ע�⣺
//���ﲻ����cin��ѭ����ȡ����
//cin��û��ȷ����ȡ�����������
//����getline��ȡһ�к��istringstream������
//��������ں�������õ���

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//string num(int i)
//{
//	switch (i)
//	{
//	case 0:
//		return "ling";
//	case 1:
//		return "yi";
//	case 2:
//		return "er";
//	case 3:
//		return "san";
//	case 4:
//		return "si";
//	case 5:
//		return "wu";
//	case 6:
//		return "liu";
//	case 7:
//		return "qi";
//	case 8:
//		return "ba";
//	case 9:
//		return "jiu";
//	default:
//		return "";
//	}
//}

string num(int i)
{
	string s[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	return s[i];
}

int main()
{
	string s;
	cin >> s;
	//istring�ڴ�����ʱ���Ҫ���ַ���
	istringstream is(s);
	char c;
	int sum = 0;
	while (is >> c)
	{
		sum += c - '0';
	}
	vector<string> n;
	//����λ����֮�͵ĸ������ֵ�ƴ�����������ŵ�vector��
	while (sum)
	{
		n.push_back(num(sum % 10));
		sum /= 10;
	}
	auto it = n.end() - 1;
	while (it != n.begin())
	{
		cout << *it << " ";
		--it;
	}
	cout << *(n.begin());
}