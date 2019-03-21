//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem2
//	Filename:	main_P2.cpp
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	the main function of problem 2
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include"complex_P2.h"
#include"other_function_P2.h"
using namespace std;
int main() {
	ComplexNumber Z1(2, 2);
	ComplexNumber Z2(3, -1);
	ComplexNumber Z3(Z1);

	cout << "the value of Z2 is  "<<endl;
	Z2.PrintComplexNumber();
	cout << "the norm of Z2 is  " << endl <<Z2.GetNorm() << endl;
	cout << "the value of conjugate of Z2 is   " << endl;
	(Z2.GetConjugate()).PrintComplexNumber();

	cout << "the inverse of Z3 is " << endl;
	Z3.GetInverse().PrintComplexNumber();
	cout << "the polar coordinate 0f Z3 is in the form of( radius,degree) is ";
	// the result of polar coordinate will be shown in absolute number and degree measure
	GetPolarCoordinates(Z3);
	Z3.PrintComplexNumber();

	cout << "Z1 * Z2 is  ";
	(Z1*Z2).PrintComplexNumber();
	cout << "4 * Z2 is  " ;
	(4 * Z2).PrintComplexNumber();
	cout << "Z1^4 is  " ;
	Power(Z1, 4).PrintComplexNumber();
	cout << endl;

	cout << "exp(Z1) is "  ;
	exp(Z1).PrintComplexNumber();
	cout << "sine(Z1) is " ;
	sine(Z1).PrintComplexNumber();
	cout << "cosine(Z1) is " ;
	cosine(Z1).PrintComplexNumber();
	cout << endl;
	cout << "the result of cosine(Z1) +isine(Z1)  is   ";
	ComplexNumber temp(0, 1);
	(cosine(Z1) + temp*sine(Z1)).PrintComplexNumber();
	cout << "the result of exp(Z1) is " ;
	exp(Z1).PrintComplexNumber();
	cout << endl;
	cout << "the reason why they are not euqal is that  :"<<endl<<"Z1=2+2i,  exp(Z1)=exp(2+2i)=exp(2)*exp(2i)=exp(2)*(cos2+i*sin2)"<<endl<<" according to euler's formula.exp(ix)=cos(x)+isin(x)" << endl;
	cout << "the result of  exp(Z1*i) is  " << endl;
	exp(Z1*temp).PrintComplexNumber();
	cout << "which is equal to the result of cosine(Z1) +isine(Z1)" << endl;
	return 0;
}