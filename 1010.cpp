//1010. 一元多项式求导(25)
//
//时间限制
//400 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard

//设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn - 1。）
//
//输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
//
//输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。
//数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
//
//输入样例：
//3 4 - 5 2 6 1 - 2 0
//输出样例：
//12 3 - 10 1 6 0

//idea:
//对于一般多项式求导的处理比较简单，但有几个点需要注意
//1.多项式最后一项可能为常数项，如果之前有求导的部分结果则常数项求导结果不能写到输出
//2.对于指数不为0的项求导都有结果
//3.如果只存在常数项要按要求输出0 0

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct poly
{
	int coef;
	int exp;
};

int main()
{
	string s;
	getline(cin, s);
	istringstream is(s);
	vector<poly> pl;
	int c = 0, e = 0;

	//将多项式按次数输入
	while (is >> c >> e)
	{
		pl.push_back({c,e});
	}

	ostringstream os;
	auto it = pl.begin();

	while (it != pl.end())
	{
		if (it->exp != 0)
			//ostringstream就可以视为一个字符串
			//str()用于取出其中的字符串
			if (!os.str().empty())
				os << " " << it->coef*it->exp << " " << it->exp - 1;
			else
				//如果结果字符串尚未添加过内容则最前面不能增加空格
				os << it->coef*it->exp << " " << it->exp - 1;
		it++;
	}

	if (os.str().empty())
		cout << "0 0";
	else
		cout << os.str();
}