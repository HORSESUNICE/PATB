//1034. ��������������(20)
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

//����Ҫ���д���򣬼���2���������ĺ͡�������̡�
//
//�����ʽ��
//
//������һ���а��ա�a1/b1 a2/b2���ĸ�ʽ��������������ʽ����������
//���з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�����������ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ0��
//
//�����ʽ��
//
//�ֱ���4���а��ա�������1 ����� ������2 = ������ĸ�ʽ˳�����2���������ĺ͡�������̡�
//ע�������ÿ�������������Ǹ��������������ʽ��k a/b��������k���������֣�a/b�����������֣�
//��Ϊ��������������ţ���������ĸΪ0���������Inf������Ŀ��֤��ȷ�������û�г������ͷ�Χ��������
//
//��������1��
//2/3 -4/2
//�������1��
//2/3 + (-2) = (-1 1/3)
//2/3 - (-2) = 2 2/3
//2/3 * (-2) = (-1 1/3)
//2/3 / (-2) = (-1/3)
//��������2��
//5/3 0/6
//�������2��
//1 2/3 + 0 = 1 2/3
//1 2/3 - 0 = 1 2/3
//1 2/3 * 0 = 0
//1 2/3 / 0 = Inf

//idea:
//����ؼ��������������һ���������ת��Ϊ��Ҫ����������ĸ�ʽ
//����Ҫ�õ������Լ���ĺ���(gcd)
//�������⻹������һ����BUG,ϣ������֪���Ļ����ҽ��һ�£���ָ�л��

#include <iostream>
#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

//���������Լ������intԽ�������long long
//��int��û�в��Ե���������
long long gcd(long long x, long long y)
{
	if (y > x)
		return gcd(y, x);
	else if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}

//��ʽ������ĺ���
void fun(long long a, long long b)
{
	long long k, x, y;
	long long m, n;

	long long sym = 1;
	if (a < 0)
	{
		m = -a;
		//���������ֵ�BUG��..

		//���������������һ��Ҫ�����ж�
		//�����a*b<0�жϲ��Ե�2�����
		//��֪������������ʲô����������Ľ��
		sym *= -1;
	}
	else
		m = a;

	if (b < 0)
	{
		n = -b;
		sym *= -1;
	}
	else
		n = b;
	
	if (!n)
		cout << "Inf";
	else
	{
		k = m / n;
		x = m%n;
		y = n;
		long long g = gcd(x, y);

		if (sym == -1)
			cout << "(-";
		if (k)
			cout << k;
		if (!x)
		{
			if (!k)
				cout << 0;
		}
		else
		{
			if(k)
				cout << " " << x / g << "/" << y / g;
			else
				cout << x / g << "/" << y / g;
		}

		if (sym == -1)
			cout << ")";
	}


}

void add(long long a1, long long b1, long long a2, long long b2)
{
	long long m = a1*b2 + a2*b1;
	long long n = b1*b2;

	fun(a1, b1);
	cout << " + ";
	fun(a2, b2);
	cout << " = ";
	fun(m, n);
	cout << endl;
}

void minu(long long a1, long long b1, long long a2, long long b2)
{
	long long m= a1*b2 - a2*b1;
	long long n = b1*b2;

	fun(a1, b1);
	cout << " - ";
	fun(a2, b2);
	cout << " = ";
	fun(m, n);
	cout << endl;
}

void mul(long long a1, long long b1, long long a2, long long b2)
{
	long long m = a1*a2;
	long long n = b1*b2;

	fun(a1, b1);
	cout << " * ";
	fun(a2, b2);
	cout << " = ";
	fun(m, n);
	cout << endl;
}

void div(long long a1, long long b1, long long a2, long long b2)
{
	long long m = a1*b2;
	long long n = a2*b1;

	fun(a1, b1);
	cout << " / ";
	fun(a2, b2);
	cout << " = ";
	if (b1 == 0 || b2 == 0)
		cout << "Inf";
	else
		fun(m, n);
	cout << endl;
}
int main()
{
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);

	add(a1, b1, a2, b2);
	minu(a1, b1, a2, b2);
	mul(a1, b1, a2, b2);
	div(a1, b1, a2, b2);
}