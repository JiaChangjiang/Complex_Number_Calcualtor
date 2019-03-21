//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem2
//	Filename:	complex_P2.h  
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	declare the class and the member function
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class ComplexNumber {
public:
	ComplexNumber() { };
	virtual ~ComplexNumber() {};
	ComplexNumber(double real, double imaginary);
	ComplexNumber(const ComplexNumber& source);

	ComplexNumber operator+(const ComplexNumber& z) const;
    ComplexNumber operator+(double z) const;
    friend ComplexNumber operator+(double z, const ComplexNumber& a);
	//using key word friend to make the outside function can visit the private member of the class .

	ComplexNumber operator-(const ComplexNumber& z) const;
	ComplexNumber operator-(const double z) const;
	friend ComplexNumber operator-(const double z, const ComplexNumber& a);


	ComplexNumber ComplexNumber::operator/(ComplexNumber& z) const;
	ComplexNumber ComplexNumber::operator/(const double z) const;
	friend ComplexNumber operator/(double a, ComplexNumber& b);


	ComplexNumber operator*(const ComplexNumber& z) const;
	ComplexNumber operator*(const double z) const;
	friend ComplexNumber operator*(double a, const ComplexNumber& b);


	friend void GetPolarCoordinates(ComplexNumber& a);
	//using key word friend to make the outside function can visit the private member of the class .
	void PrintComplexNumber();
	double GetNorm() ;
	ComplexNumber GetConjugate();
	ComplexNumber GetInverse();
private:
	double myreal;
	double myimg;
};





