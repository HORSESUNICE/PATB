//1052. 卖个萌 (20)
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

//萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。
//简单起见，我们假设一个表情符号是按下列格式输出的：
//
//[左手]([左眼][口][右眼])[右手]
//现给出可选用的符号集合，请你按用户的要求输出表情。
//
//输入格式：
//
//输入首先在前三行顺序对应给出手、眼、口的可选符号集。
//每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；
//每个符号包含1到4个非空字符。
//
//之后一行给出一个正整数K，为用户请求的个数。随后K行，
//每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——
//这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。
//
//输出格式：
//
//对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。
//
//输入样例：
//[╮][╭][o][~\][/~]  [<][>]
// [╯][╰][^][-][=][>][<][@][⊙]
//[Д][▽][_][ε][^]  ...
//4
//1 1 2 2 2
//6 8 1 5 5
//3 3 4 3 3
//2 10 3 9 3
//输出样例：
//╮(╯▽╰)╭
//<(@Д=)/~
//o(^ε^)o
//Are you kidding me? @\/@

//idea:
//因为样例告诉我们表情之间是可能存在空格的
//这样我们只能利用[]加上标记来存入表情了
//如果之间没有空格那处理可以稍作简化像1058那样处理

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

	//string流不能先声明后绑定;
	//istringstream is;
	unsigned arr[5] = { 0 };
	for (int i = 0; i != num; ++i)
	{
		getline(cin, s);
		istringstream is(s);
		is >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
		//这里注意输入0应该输出Are you kidding me? @\\/@
		if (arr[0] <= 0 || arr[1] <= 0 || arr[2] <= 0 || arr[3] <= 0 || arr[4] <= 0)
			cout << "Are you kidding me? @\\/@" << endl;
		else if (arr[0] <= hand.size() && arr[1] <= eye.size() && arr[2] <= mouth.size() && arr[3] <= eye.size() && arr[4] <= hand.size())
			cout << hand[arr[0] - 1] << "(" << eye[arr[1] - 1] << mouth[arr[2] - 1] << eye[arr[3] - 1] << ")" << hand[arr[4] - 1] << endl;
		else
			cout << "Are you kidding me? @\\/@" << endl;
	}
}