#include<iostream>
#include"Scan.h"
#include"Print.h"
int main()
{
	string strData;
	cin>>strData;
	Scan scan;//创建scan对象
	Print print;//创建print对象
	queue<string> quData;// 处理输入的表达式
	quData = scan.ToStringQueue(strData);//获取目标队列
	if (! quData.empty())
	{

		print.PrintData(quData);//输出目标队列
	}
	system("pause");
	return 0;
}