#include"Scan.h"
#include<string>
#include<cctype>
#include<queue>
#include<fstream>
string Scan::open(char *p)
{
	string t;
	fstream file;
	file.open(p);
	file >> t;
	return t;
}


queue<string>Scan::ToStringQueue(string input)
{
	string data = "";
	queue<string>q;
	if (input.at(0) == '-'&&input.at(1) >= '0'&&input.at(1) <= '9')
	{
		q.push("0");
	}
	for (size_t i = 0; i < input.length(); i++) //����ַ�ɨ����ʽinput����ȡ����
	{
		if (isdigit(input[i]) || (input[i] == '.'))
		{
			data += input.at(i);
			if (!isdigit(input[i + 1]) && (input[i + 1] != '.'))
			{
				q.push(data);  //���������ִ������
				data = "";
				continue;
			}
		}
		else if (input[i] != '=')
		{
			data = input.at(i);
			q.push(data);  //�������������������
			data = "";
		}
	}
	return q;
}
