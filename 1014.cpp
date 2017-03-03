//1014. 福尔摩斯的约会(20)
//
//时间限制
//100 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//大侦探福尔摩斯接到一张奇怪的字条：
//“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
//大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，
//因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；
//第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头
//（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
//后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。
//现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
//
//输入格式：
//
//输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
//
//输出格式：
//
//在一行中输出约会的时间，格式为“DAY HH : MM”，其中“DAY”是某星期的3字符缩写，
//即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。
//题目输入保证每个测试存在唯一解。
//
//输入样例：
//3485djDkxh4hhGE
//2984akDfkkkkggEdsb
//s&hgsfdk
//d&Hyscvnm
//输出样例：
//THU 14:04

//idea:
//这里题目的意思比较直接
//但在作为密码字符的判断上
//由题意还是有一些额外的隐含条件的，对于密码字符的范围一定要仔细限制

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

	//局部变量最好初始化防止程序爆掉
	//但我这里d,h没有初始化有点问题
	//m初始化了是为了防止后面自己的测试数据的时间>60意外使用局部变量
	char d, h;
	int m = 0;
	//symbol = 1 获得了d
	//symbol = 2 获得了h
	int symbol = 0;
	while (i != count)
	{
		//在获取密码字符的时候一定要小心：务必保证在密码字符的范围中
		//d一定要在A-G不能A-Z,一周只有7天
		//h一定要0-9或者A-N，一天的24小时
		//我的代码有一点小问题
		//m如果>59则m=0
		if(symbol==1||(date[0][i]>='A'&&date[0][i]<='G'))
			if (date[0][i] == date[1][i])
			{
				if (symbol == 0)
				{
					//d可能为0-9不一定属于A-Z
					d = date[0][i];
					++symbol;
					//找到相同大写字母后要记得将index+1，否则d,h均为第一个相同字母
					++i;
					continue;
				}
				if (symbol == 1&& ((date[0][i] >= '0'&&date[0][i] <= '9')||(date[0][i] >= 'A'&&date[0][i] <= 'N')))
				{
					h = date[0][i];
					++symbol;
					//这里也和之前一样要做index+1处理
					++i;
				}
				if (symbol == 2)
					break;
			}
		++i;
	}

	i = 0;
	//这里不能写i!=59,否则 XXX XX:59这样的时间就不能输出了
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

	//这个switch也可以用数组代替好一点
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
		//string=char是可以的
		//string+char可以生成字符串
		//string+int不能生成字符串
		//这里注意格式为HH需要在之前添加0
		hour = hour + '0' + h;
	else
		hour = hour + static_cast<char>((h - 'A') / 10 + '1') + static_cast<char>((h - 'A') % 10 + '0');

	string min;
	if (m < 10)
		min = min + "0" + static_cast<char>(m + '0');
	else
		//这里不能写min += m;
		//重载的是string += char
		min = min + static_cast<char>(m / 10 + '0') + static_cast<char>(m % 10 + '0');

	//用于测试检测到的三个密码字符
	//cout << d << h << m << endl;

	cout << day << " " << hour << ":" << min;

	//测试数据
	//3485djDkxh4hhG0
	//2984akDfkkkkgg0dsb
	//s&hgasdfasdfs&hgasdfasdfs&hgasdfasdfs&hgasdfasdfs&hgasdfasdfs&hgasdfasdfs&hgasdfasdfsfdk
	//d&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjkld&Hyhjklhjklscvnm
}