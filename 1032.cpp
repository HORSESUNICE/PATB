//1032. �ھ�������ļ�ǿ(20)
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

//Ϊ������ʵ˵���ھ�����������ļ�ǿ��PAT��֯��һ���ھ�����ܴ�����
//��������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��
//
//�����ʽ��
//
//�����ڵ�1�и���������10^5��������N��������������
//���N�У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ����������������ѧУ�ı�ţ���1��ʼ������ţ���
//��������ɼ����ٷ��ƣ����м��Կո�ָ���
//
//�����ʽ��
//
//��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ�����Ŀ��֤��Ψһ��û�в��С�
//
//����������
//6
//3 65
//2 80
//1 100
//2 70
//3 40
//3 0
//���������
//2 150

//idea:
//��Ϊ��֪������ѧУ��
//����ʹ��100001����������¼��ѧУ�ķ���
//��������ֱ������map
//��¼�������ֻҪ�����߷ֵ���žͿ�����

//����������map����ǿͨ��

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> wjj;

	int index, grade;

	for (int i = 0; i != n; ++i)
	{
		cin >> index >> grade;
		wjj[index] += grade;
	}

	auto it = wjj.cbegin();
	int indexmax, grademax;
	indexmax = it->first;
	grademax = it->second;
	while (it != wjj.cend())
	{
		if (it->second > grademax)
		{
			indexmax = it->first;
			grademax = it->second;
		}
		++it;
	}

	cout << indexmax << " " << grademax;
}