#include"Calculation.h"
#include"Scan.h"
#include<sstream>
#include<stack>
#include<cctype>
#include<queue>
bool Calculation::isOperator(char c)  //判断是否是操作符
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return true;
	else
		return false;
}
int Calculation::precede(char op)  //比较优先级
{
	switch (op)
	{
	case'+':
		return 1;
		break;
	case'-':
		return 1;
		break;
	case'*':
		return 2;
		break;
	case'/':
		return 2;
		break;
	case'(':
		return 0;
		break;
	case')':
		return 0;
		break;
	}
}
double Calculation::Convert(string s)  //将字符转换成数字
{
	double r;
	stringstream s1;
	s1 << s;
	s1 >> r;
	s1.clear();
	return r;
}
void Calculation::compare(char x, string y, string z)   //用递归的方法进行比较
{
	if (precede(x) >= precede(y[0]))
	{
		optr.push(z);
	}
	else
	{
		numb.push(optr.top());
		optr.pop();
		if (!optr.empty())
		{
			compare(x, optr.top(), z);
		}
		else
		{
			string s1;
			s1 += x;
			optr.push(s1);
		}
	}
}

double Calculation::Calculate(double x, char op, double y)  //进行四则运算
{
	double sum;
	switch (op)
	{
	case'+':
		sum = x + y;
		break;
	case'-':
		sum = x - y;
		break;
	case'*':
		sum = x*y;
		break;
	case'/':
		sum = x / y;
		break;
	}
	return sum;
}
int Calculation::CalculateExpression(queue<string>q) // 将scan得到的队列进行操作并得出计算结果
{
	int i, n;
	string ss[10000];
	string newss[10000];
	char temp;
	for (i = 0; !q.empty(); i++)
	{
		ss[i] = q.front();
		q.pop();
	}
	n = i - 1;
	for (i = n; i >= 0; i--)
	{
		temp = ss[i][0];
		if (isdigit(temp))
		{
			numb.push(ss[i]);
		}
		else if (temp != '('&&temp != ')')
		{
			if (optr.empty() || optr.top() == ")")
			{
				optr.push(ss[i]);
			}
			else
			{
				compare(temp, optr.top(), ss[i]);
			}
		}
		else
		{
			if (temp == ')')
			{
				optr.push(ss[i]);
			}
			else if (temp == '(')
			{
				while (optr.top() != ")")
				{
					numb.push(optr.top());
					optr.pop();
				}
				optr.pop();
			}
		}
	}
	do
	{
		numb.push(optr.top());
		optr.pop();
	} while (!optr.empty());
	for (i = 0; !numb.empty(); i++)
	{
		newss[i] = numb.top();
		numb.pop();
	}
	n = i - 1;
	for (i = n; i >= 0; i--)
	{
		char temp1 = newss[i][0];
		if (isdigit(temp1))
		{
			final.push(Convert(newss[i]));
		}
		else
		{
			double num1 = final.top();
			final.pop();
			double num2 = final.top();
			final.pop();
			double ret = Calculate(num1, temp1, num2);
			final.push(ret);
		}
	}
	return final.top();
	final.pop();
}
