//1014. ����Ħ˹��Լ��(20)
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

//����̽����Ħ˹�ӵ�һ����ֵ�������
//������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
//����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04����
//��Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ�
//��2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ
//������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ����
//�������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ�
//�ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣
//
//�����ʽ��
//
//������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����
//
//�����ʽ��
//
//��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH : MM�������С�DAY����ĳ���ڵ�3�ַ���д��
//��MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա�
//��Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣
//
//����������
//3485djDkxh4hhGE
//2984akDfkkkkggEdsb
//s&hgsfdk
//d&Hyscvnm
//���������
//THU 14:04

//idea:
//������Ŀ����˼�Ƚ�ֱ��
//������Ϊ�����ַ����ж���
//�����⻹����һЩ��������������ģ����������ַ��ķ�Χһ��Ҫ��ϸ����

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> date;
	string s;
	for (int i = 0; i != 4; ++i)
	{
		cin >> s;
		date.push_back(s);
	}
	decltype(date[0].size()) count = date[0].size() <= date[1].size() ? date[0].size() : date[1].size();
	decltype(date[0].size()) i = 0;

	//�ֲ�������ó�ʼ����ֹ���򱬵�
	//��������d,hû�г�ʼ���е�����
	//m��ʼ������Ϊ�˷�ֹ�����Լ��Ĳ������ݵ�ʱ��>60����ʹ�þֲ�����
	char d, h;
	int m = 0;
	//symbol = 1 �����d
	//symbol = 2 �����h
	int symbol = 0;
	while (i != count)
	{
		//�ڻ�ȡ�����ַ���ʱ��һ��ҪС�ģ���ر�֤�������ַ��ķ�Χ��
		//dһ��Ҫ��A-G����A-Z,һ��ֻ��7��
		//hһ��Ҫ0-9����A-N��һ���24Сʱ
		//�ҵĴ�����һ��С����
		//m���>59��m=0
		if(symbol==1||(date[0][i]>='A'&&date[0][i]<='G'))
			if (date[0][i] == date[1][i])
			{
				if (symbol == 0)
				{
					//d����Ϊ0-9��һ������A-Z
					d = date[0][i];
					++symbol;
					//�ҵ���ͬ��д��ĸ��Ҫ�ǵý�index+1������d,h��Ϊ��һ����ͬ��ĸ
					++i;
					continue;
				}
				if (symbol == 1&& ((date[0][i] >= '0'&&date[0][i] <= '9')||(date[0][i] >= 'A'&&date[0][i] <= 'N')))
				{
					h = date[0][i];
					++symbol;
					//����Ҳ��֮ǰһ��Ҫ��index+1����
					++i;
				}
				if (symbol == 2)
					break;
			}
		++i;
	}

	i = 0;
	//���ﲻ��дi!=59,���� XXX XX:59������ʱ��Ͳ��������
	while (i!=60)
	{
		if((date[2][i]>='a'&&date[2][i]<='z')|| (date[2][i] >= 'A'&&date[2][i] <= 'Z'))
			if (date[2][i] == date[3][i])
			{
				m = i;
				break;
			}
		++i;
	}

	string day;

	//���switchҲ��������������һ��
	switch (d - 'A')
	{
	case 0:
		day = "MON";
		break;
	case 1:
		day = "TUE";
		break;
	case 2:
		day = "WED";
		break;
	case 3:
		day = "THU";
		break;
	case 4:
		day = "FRI";
		break;
	case 5:
		day = "SAT";
		break;
	case 6:
		day = "SUN";
		break;
	default:
		break;
	}

	string hour;
	if (h >= '0'&&h <= '9')
		//string=char�ǿ��Ե�
		//string+char���������ַ���
		//string+int���������ַ���
		//����ע���ʽΪHH��Ҫ��֮ǰ���0
		hour = hour + '0' + h;
	else
		hour = hour + static_cast<char>((h - 'A') / 10 + '1') + static_cast<char>((h - 'A') % 10 + '0');

	string min;
	if (m < 10)
		min = min + "0" + static_cast<char>(m + '0');
	else
		//���ﲻ��дmin += m;
		//���ص���string += char
		min = min + static_cast<char>(m / 10 + '0') + static_cast<char>(m % 10 + '0');

	//���ڲ��Լ�⵽�����������ַ�
	//cout << d << h << m << endl;

	cout << day << " " << hour << ":" << min;

	//��������
	//3485djDkxh4hhG0
	//2984akDfkkkkgg0dsb
	//s&hgasdfasdfs&hgasdfasdfs&hgasdfasdfs&hgasdfasdfs&hgasdfasdfs&hgasdfasdfs&hgasdfasdfsfdk
	//d&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjklscvnm
}