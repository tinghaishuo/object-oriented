#include<iostream>
#include"Scan.h"
#include"Print.h"
int main()
{
	string strData;
	cin>>strData;
	Scan scan;//����scan����
	Print print;//����print����
	queue<string> quData;// ��������ı��ʽ
	quData = scan.ToStringQueue(strData);//��ȡĿ�����
	if (! quData.empty())
	{

		print.PrintData(quData);//���Ŀ�����
	}
	system("pause");
	return 0;
}