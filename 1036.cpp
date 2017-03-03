//1036. 跟奥巴马一起编程(15)
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

//美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。
//2014年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：
//在屏幕上画一个正方形。现在你也跟他一起画吧！
//
//输入格式：
//
//输入在一行中给出正方形边长N（3 <= N <= 20）和组成正方形边的某种字符C，间隔一个空格。
//
//输出格式：
//
//输出由给定字符C画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，
//我们输出的行数实际上是列数的50%（四舍五入取整）。
//
//输入样例：
//10 a
//输出样例：
//aaaaaaaaaa
//a        a
//a        a
//a        a
//aaaaaaaaaa

//idea:
//我们的水平比Obama总得稍微厉害一点吧
//也就一个四舍五入求个行数

#include <iostream>

using namespace std;

int main()
{
	double n;
	int row;
	int line;
	char c;
	cin >> n >> c;

	row = static_cast<int>(n);
	line = static_cast<int>(n / 2 + 0.5);

	if (row < 5)
	{
		for (int i = 0; i != row; ++i)
			cout << c;
		cout << endl;
		for (int i = 0; i != row; ++i)
			cout << c;
	}
	else
	{
		for (int i = 0; i != row; ++i)
			cout << c;
		cout << endl;
		for (int i = 0; i != line - 2; ++i)
		{
			cout << c;
			for (int j = 0; j != row - 2; ++j)
				cout << " ";
			cout << c;
			cout << endl;
		}
		for (int i = 0; i != row; ++i)
			cout << c;
	}
}