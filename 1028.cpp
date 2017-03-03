//1028. 人口普查(20)
//
//时间限制
//200 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
//
//这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，
//而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。
//
//输入格式：
//
//输入在第一行给出正整数N，取值在(0, 10^5]；
//随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、
//以及按“yyyy / mm / dd”（即年 / 月 / 日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
//
//输出格式：
//
//在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
//
//输入样例：
//5
//John 2001/05/12
//Tom 1814/09/06
//Ann 2121/01/30
//James 1814/09/05
//Steve 1967/11/20
//输出样例：
//3 Tom John

//idea:
//这题就是统计有效输入
//可以将生日作为三个数字输入后做判断
//我这里直接将生日视为字符串比较大小
//因为这里只求最年长和最年轻的人的姓名
//不要用排序，会超时
//直接遍历一遍输入得出最大和最小就可以了

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nin;

	string maxname, maxbir, minname, minbir;

	int count = 0;
	string mname, mbir;
	string birmax("1814/09/06"), birmin("2014/09/06");

	cin >> nin;

	for (int i = 0; i != nin; ++i)
	{
		cin >> mname >> mbir;
		if (mbir >= birmax&&mbir <= birmin)
		{
			++count;
			if (count == 1)
			{
				maxname = mname;
				maxbir = mbir;
				minname = mname;
				minbir = mbir;
			}
			if (mbir < maxbir)
			{
				maxname = mname;
				maxbir = mbir;
			}
			if (mbir > minbir)
			{
				minname = mname;
				minbir = mbir;
			}
		}
	}

	//当心可能没有有效人数
	if (count == 0)
		cout << 0;
	else
	{
		cout << count;
		cout << " " << maxname;
		cout << " " << minname;
	}
}