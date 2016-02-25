#include"Print.h"
void Print::PrintData(queue<string> output)
{
	while (! output.empty())
	{
		string strData = output.front();
		cout<<strData<<endl;//打印队列首元素
		output.pop();//删除队列首元素
	}
}