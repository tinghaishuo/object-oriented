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
	if (strData1 == "-a")  //判断是否有-a
	{
		strData2=argv[2];
		cout << strData2;
		quData = scan.ToStringQueue(strData2);  //有，则再次输入表达式并输出再进行计算。
		cout <<"="<<" "<<calculation.CalculateExpression(quData) << endl;
	}
	else
	{
		quData = scan.ToStringQueue(strData1);
		cout << "=" << " "<<calculation.CalculateExpression(quData) << endl; //没有，则直接进行计算。
	}
	system("pause");
	return 0;
}
