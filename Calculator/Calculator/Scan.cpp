#include"Scan.h"
queue<string>Scan::ToStringQueue(const string&input)
{queue<string>q;
int Len(0);
for(size_t i=0;i<input.length();i++)//逐个字符扫描表达式input，提取数字和符号
{
	bool Num=((input[i]>='0')&&(input[i]<='9')||(input[i]=='.'));
	int a=Len;
	if(Num)//判断是否是数字或小数点
	{
		Len++;
		if(Len>10)
		{
			cout<<"Find a number is too long to handle!"<<endl;
		    
			//输入数字位数大于10时则报错 
		while(!q.empty())
		{
			q.pop();//报错，若非空，则清除数据。
		}
		return q;
		}
	}
	else{ Len=0;}
	if(a>=Len)
	{
		if(a>Len)
		{
			q.push(input.substr(i-a,a));
		}
		q.push(input.substr(i,1));
	}//数字则完整的数字暂存入队列，运算符及括号则单独入列。
		if(i==input.length()-1)
		{
			if(Len!=0)
			{
				q.push(input.substr(i-a,Len));
			}
			return q;//返回队列
		}//对最后一个字符进行单独处理



}
}
