#include<string>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class Calculation
{
public:
	int CalculateExpression(queue<string>q);
private:
	bool isOperator(char c);
	int precede(char op);
	double Convert(string s);
	double Calculate(double x, char op, double y);
	void compare(char x, string y, string z);
	stack<string>optr;  //存操作符
	stack<string>numb;//存字符数字
	stack<double>final; //存转换后的数字
};
