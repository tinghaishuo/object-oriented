#include<iostream> 
#include"Scan.h"
#include"Calculation.h"
#include"Print.h"
#include<string>
#include<fstream>
#pragma warning(disable:4996)
using namespace std;
int main(int argc, char* argv[])
{
	Calculation calculation;
	Scan scan;
	Print print;
	string strData1;
	string strData2;
	strData1 = argv[1];
	queue<string> quData;
	int r;
	if (strData1 == "-a")  //�ж��Ƿ���-a 
	{
		strData2 = argv[2];
		print.PrintData(strData2);
		quData = scan.ToStringQueue(strData2);  //�У����ٴ�������ʽ������ٽ��м��㡣 
		r = calculation.CalculateExpression(quData);
		print.Printres(r);
	}
	else if (strData1 == "-f")
	{
		string strData3;
		strData3 = scan.open(argv[2]);
		quData = scan.ToStringQueue(strData3);
		r = calculation.CalculateExpression(quData);
		print.Printout(argv[3], r);
	}
	else
	{
		quData = scan.ToStringQueue(strData1);
		r = calculation.CalculateExpression(quData); //û�У���ֱ�ӽ��м��㡣
		print.Printres(r);
	}
	system("pause");
	return 0;
}



