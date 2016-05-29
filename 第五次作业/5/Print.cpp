#include"Print.h"
#include"Scan.h"
#include<fstream>
void Print::Printout(char *q, int r)
{
	ofstream file;
	file.open(q);
	file << " " << r << endl;
}
void Print::PrintData(string q)
{
	cout << q;
}
void Print::Printres(int ret)
{
	cout << " " << ret << endl;
}