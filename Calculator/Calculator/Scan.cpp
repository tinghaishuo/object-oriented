#include"Scan.h"
queue<string>Scan::ToStringQueue(const string&input)
{
	queue<string>q;
	int Len(0);
	for(size_t i=0; i<input.length(); i++) //����ַ�ɨ����ʽinput����ȡ���ֺͷ���
	{
		bool Num=((input[i]>='0')&&(input[i]<='9')||(input[i]=='.'));
		int a=Len;
		if(Num)//�ж��Ƿ������ֻ�С����
		{
			Len++;
			if(Len>10)
			{
				cout<<"Find a number is too long to handle!"<<endl;

				//��������λ������10ʱ�򱨴�
				while(!q.empty())
				{
					q.pop();//�������ǿգ���������ݡ�
				}
				return q;
			}
		}
		else
		{
			Len=0;
		}
		if(a>=Len)
		{
			if(a>Len)
			{
				q.push(input.substr(i-a,a));
			}
			q.push(input.substr(i,1));
		}//�����������������ݴ�����У�������������򵥶����С�
		if(i==input.length()-1)
		{
			if(Len!=0)
			{
				q.push(input.substr(i-a,Len));
			}
			return q;//���ض���
		}//�����һ���ַ����е�������



	}
}
