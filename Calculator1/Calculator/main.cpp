#include<iostream>
#include"Scan.h"
#include"Calculation.h"
using namespace std;
int main(int argc, char* argv[])
{
	Calculation calculation;
	Scan scan;
	string strData1;
	string strData2;
	strData1=argv[1];
	queue<string> quData;
	if (strData1 == "-a")  //�ж��Ƿ���-a
	{
		strData2=argv[2];
		cout << strData2;
		quData = scan.ToStringQueue(strData2);  //�У����ٴ�������ʽ������ٽ��м��㡣
		cout <<"="<<" "<<calculation.CalculateExpression(quData) << endl;
	}
	else
	{
		quData = scan.ToStringQueue(strData1);
		cout << "=" << " "<<calculation.CalculateExpression(quData) << endl; //û�У���ֱ�ӽ��м��㡣
	}
	system("pause");
	return 0;
}
