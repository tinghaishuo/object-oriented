#include<iostream>
#include"calculate area.h"
using namespace std;
int main()
{
	Calculation calculation;
	double r;
	cin >> r;
	cout<<"the area of the circle is " << calculation.Calculate(r) << endl;
	system("pause");
	return 0;
}