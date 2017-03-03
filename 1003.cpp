//1003. ��Ҫͨ����(20)
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

//������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ���
//��������PAT�ġ�����ȷ�������� ���� 
//ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�
//
//�õ�������ȷ���������ǣ�
//
//1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
//2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
//3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ�
//   ���� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
//
//���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
//�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n(<10)������Ҫ�����ַ���������
//������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�
//
//�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��
//
//����������
//8
//PAT
//PAAT
//AAPATAA
//AAPAATAAAA
//xPATx
//PT
//Whatever
//APAAATAA
//���������
//YES
//YES
//YES
//YES
//NO
//NO
//NO
//NO

//idea:
//������ѵ��������������е�����3�����˺ü�����������������
//����Ҫ�����PAT�������ͬ��Ŀ��A,
//����PAT�м�ÿ����һ��A����Ҫ���Ҳ�����P�����ͬ��Ŀ��A
//���һ�㣺��Ҫ��֤�м�������һ��A

#include <iostream>
#include <string>

using namespace std;

bool st(const string &s)
{
	decltype(s.size()) i = 0, l = 0, m = 0, r = 0;
	for (; i != s.size(); ++i)
		//�ж��ַ����Ƿ����쳣�ַ�
		if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T')
			return false;
	
	//�ַ������������ַ���ɣ���i����ͳ������A������
	i = 0;
	for (; i != s.size(); ++i)
		if (s[i] == 'P')
			break;
	//l����P���A�ĸ���
	l = i;
	for (; i != s.size(); ++i)
		if (s[i] == 'T')
			break;
	m = i - l - 1;
	//r����T�Ҳ�A�ĸ���
	r = s.size() - l - m - 2;
	
	//�ַ����м�����Ҫ��һ��A
	if (m > 0 && r == m*l)
		return true;
	else
		return false;
}

int main()
{
	string s;
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> s;
		if (st(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}