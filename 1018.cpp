//1018. 锤子剪刀布(20)
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

//大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
//
//现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
//
//输入格式：
//
//输入第1行给出正整数N（ <= 105），即双方交锋的次数。
//随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
//C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
//
//输出格式：
//
//输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。
//第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。
//如果解不唯一，则输出按字母序最小的解。
//
//输入样例：
//10
//C J
//J B
//C B
//B B
//B C
//C C
//C B
//J B
//B C
//J J
//输出样例：
//5 3 2
//2 3 5
//B B

//idea:
//注意仔细判断剪刀石头布的结果
//我的这题写的实在是有点垃圾。。
//如果比较种类多的话我这样写就完了

#include <iostream>
#include <array>

using namespace std;

int main()
{
	int num;
	cin >> num;
	char m, n;
	array<int, 3> arrm = { 0 }, arrn = { 0 }, bcjm = { 0 }, bcjn = { 0 };
	for (int i = 0; i != num; ++i)
	{
		cin >> m >> n;
		if (m == 'B'&&n == 'B')
		{
			++arrm[1];
			++arrn[1];
		}
		if (m == 'C'&&n == 'C')
		{
			++arrm[1];
			++arrn[1];
		}
		if (m == 'J'&&n == 'J')
		{
			++arrm[1];
			++arrn[1];
		}
		if (m == 'B'&&n == 'C')
		{
			++arrm[0];
			++arrn[2];
			++bcjm[0];
		}
		if (m == 'B'&&n == 'J')
		{
			++arrn[0];
			++arrm[2];
			++bcjn[2];
		}
		if (m == 'C'&&n == 'B')
		{
			++arrn[0];
			++arrm[2];
			++bcjn[0];
		}
		if (m == 'C'&&n == 'J')
		{
			++arrm[0];
			++arrn[2];
			++bcjm[1];
		}
		if (m == 'J'&&n == 'B')
		{
			++arrm[0];
			++arrn[2];
			++bcjm[2];
		}
		if (m == 'J'&&n == 'C')
		{
			++arrn[0];
			++arrm[2];
			++bcjn[1];
		}
	}

	cout << arrm[0] << " " << arrm[1] << " " << arrm[2] << endl;
	cout << arrn[0] << " " << arrn[1] << " " << arrn[2] << endl;

	if (bcjm[0] >= bcjm[1] && bcjm[0] >= bcjm[2])
		cout << "B";
	else if (bcjm[1] > bcjm[0] && bcjm[1] >= bcjm[2])
		cout << "C";
	else if (bcjm[2] > bcjm[0] && bcjm[2] > bcjm[1])
		cout << "J";

	cout << " ";

	if (bcjn[0] >= bcjn[1] && bcjn[0] >= bcjn[2])
		cout << "B";
	else if (bcjn[1] > bcjn[0] && bcjn[1] >= bcjn[2])
		cout << "C";
	else if (bcjn[2] > bcjn[0] && bcjn[2] > bcjn[1])
		cout << "J";
}