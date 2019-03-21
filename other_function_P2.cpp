//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem2
//	Filename:	main_P2.cpp
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	the defination of the outside function
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#define _USE_MATH_DEFINES
#include"complex_P2.h"
#include"other_function_P2.h"
ComplexNumber Power(const ComplexNumber& base, const int& exponent) {

	{
		ComplexNumber p(1, 0);
		// The if statment checks the statement in the round brackets, and if it is true executes the code in the curly brackets
		if (exponent >= 0)
		{
			for (int i = 1; i <= exponent; ++i)
			{
				p = p * base;
			}
			return p;
		}
		// If the if statement is false, then the code in the else statement is executed
		else
		{
			return (Power(base, -exponent).GetInverse());//using Iteration to transfor the situation that expononet<0 to expononet>0 and get the inverse


		}

	}

}


long double fac(int a) {
	// calculate factorial a!,because the result may be very large that out of the integer range ,so using long double here
	long double fac_result = 1;
	for (int i = 1; i<a + 1; i++) {
		//using for loop to result*i
		fac_result = fac_result*i;
	}
	return fac_result;
}

ComplexNumber exp(const ComplexNumber& a) {
	//exp taylor formula
	ComplexNumber  result(0, 0);
	for (int i = 0; i < 30; i++) {
		result = result + (Power(a, i)) / fac(i);

	}
	return result;
}
ComplexNumber cosine(const ComplexNumber& a) {
	//cosine taylor formula
	ComplexNumber  result(0, 0);
	for (int i = 0; i < 30; i++) {
		result = result + pow(-1, i)*(Power(a, 2 * i)) / fac(2 * i);

	}
	return result;

}
ComplexNumber sine(const ComplexNumber& a) {
	//sine taylor formula
	ComplexNumber  result(0, 0);
	for (int i = 0; i < 30; i++) {
		result = result + pow(-1, i)*(Power(a, 2 * i + 1)) / fac(2 * i + 1);

	}
	return result;
}

void GetPolarCoordinates(ComplexNumber& a) {
	//using degree measure

	double r = a.GetNorm();//calculate the 
	if (a.myreal == 0) {//judge whether the degree is 90 or 270
		
		if (a.myimg > 0) {
			a.myimg = 90;
		}
		if (a.myimg == 0) {
			a.myimg = 0;
		}
		if (a.myimg < 0) {
			a.myimg = 270;
		}
		a.myreal = r;
	}
	if (a.myimg == 0) {
	
		if (a.myreal > 0) {
			a.myimg = 0;
		}
		if (a.myreal < 0) {
			a.myimg = 180;
		}
		a.myreal = r;
	}
	if (a.myreal > 0&&  a.myimg>0) {
		//using atan to get the degree of the complex number
		a.myimg = 180*atan(a.myimg / a.myreal)/ M_PI;
	}
	if (a.myreal < 0 && a.myimg>0) {
		// for this part,we will just calculate the absolute value of the atan(img/real),so the degree will always be positive
		a.myimg = 180-180/ M_PI*atan(abs(a.myimg )/abs( a.myreal));
	}
	if (a.myreal < 0 && a.myimg<0) {
		
		a.myimg = 180 + 180 / M_PI* atan(abs(a.myimg) / abs(a.myreal));
	}
	if (a.myreal > 0 && a.myimg<0) {

		a.myimg = 360 - 180 / M_PI* atan(abs(a.myimg) / abs(a.myreal));
	}

	a.myreal = r;

}