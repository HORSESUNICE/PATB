//1003. 我要通过！(20)
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

//“答案正确”是自动判题系统给出的最令人欢喜的回复。
//本题属于PAT的“答案正确”大派送 —— 
//只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
//
//得到“答案正确”的条件是：
//
//1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
//2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
//3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，
//   其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
//
//现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
//输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n(<10)，是需要检测的字符串个数。
//接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
//
//输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
//
//输入样例：
//8
//PAT
//PAAT
//AAPATAA
//AAPAATAAAA
//xPATx
//PT
//Whatever
//APAAATAA
//输出样例：
//YES
//YES
//YES
//YES
//NO
//NO
//NO
//NO

//idea:
//这题的难点在于理解题意中的条件3，读了好几遍总算真正理解了
//题意要求或者PAT两侧加相同数目的A,
//或者PAT中间每增加一个A就需要在右侧增加P左侧相同数目的A
//最后一点：还要保证中间至少有一个A

#include <iostream>
#include <string>

using namespace std;

bool st(const string &s)
{
	decltype(s.size()) i = 0, l = 0, m = 0, r = 0;
	for (; i != s.size(); ++i)
		//判断字符串是否含有异常字符
		if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T')
			return false;
	
	//字符串均由三个字符组成，将i归零统计三段A的数量
	i = 0;
	for (; i != s.size(); ++i)
		if (s[i] == 'P')
			break;
	//l代表P左侧A的个数
	l = i;
	for (; i != s.size(); ++i)
		if (s[i] == 'T')
			break;
	m = i - l - 1;
	//r代表T右侧A的个数
	r = s.size() - l - m - 2;
	
	//字符串中间至少要有一个A
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