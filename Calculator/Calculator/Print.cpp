#include"Print.h"
void Print::PrintData(queue<string> output)
{
	while (! output.empty())
	{
		string strData = output.front();
		cout<<strData<<endl;//��ӡ������Ԫ��
		output.pop();//ɾ��������Ԫ��
	}
}