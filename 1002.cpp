//1002. 写出这个数(20)
//
//时间限制
//400 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
//
//输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。
//
//输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
//
//输入样例：
//1234567890987654321123456789
//输出样例：
//yi san wu

//idea:
//题目比较简单就将输入每个数字求和后翻译为拼音就可以
//注意：
//这里不能用cin来循环读取数据
//cin是没法确定读取到哪里结束的
//改用getline读取一行后绑定istringstream来解题
//这个方法在后面会多次用到！

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
	//istring在创建的时候就要绑定字符串
	istringstream is(s);
	char c;
	int sum = 0;
	while (is >> c)
	{
		sum += c - '0';
	}
	vector<string> n;
	//将各位数字之和的各个数字的拼音翻译逆序存放到vector中
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