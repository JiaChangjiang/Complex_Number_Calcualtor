//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Project:	problem2
//	Filename:	main_P2.cpp
//	Version:	v1 (20 Feb 2019)
//	Author:		Changjiang Jia
//	Summary:	define the class ComplexNumber and the member function
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include"complex_P2.h"

	ComplexNumber::ComplexNumber(double real, double imaginary):myreal(real), myimg(imaginary) {}
	ComplexNumber::ComplexNumber(const ComplexNumber& source) {
		this->myimg = source.myimg;//copy the source the private number to new class
		this->myreal = source.myreal;      
	}


	//this  part is about the overload of operator.After asking the teacher, we can use overload to defined a operator by  another operator regardless the effiency
	ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const {
		return ComplexNumber(this->myreal + z.myreal, this->myimg + z.myimg);
		//overload operator+ for  ComplexNumber+ComplexNumber
	}
	ComplexNumber ComplexNumber::operator+(double z) const {
		return ComplexNumber(this->myreal + z, this->myimg);
		//overload operator+ for  ComplexNumber+double
	}
	ComplexNumber operator+(double z, const ComplexNumber& a) {
		return (a + z);
		//transfor the double+ComplexNumber to ComplexNumber+double
	}



	ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const {
		return ComplexNumber(this->myreal - z.myreal, this->myimg - z.myimg);

	}
	ComplexNumber ComplexNumber::operator-(const double z) const {
		return ComplexNumber(this->myreal - z, this->myimg);
	}
	ComplexNumber operator-(const double z, const ComplexNumber& a) {
		return z + (-1)*a;
		///transfor the double-ComplexNumber to double+(-1)*ComplexNumber which has been defined 
	}


	ComplexNumber ComplexNumber::operator/(ComplexNumber& z) const {
		return (*this)*(z.GetInverse());
		//using pointer *this to and function GetInverse to realize the division
	}
	ComplexNumber ComplexNumber::operator/(const double z) const {
		return (*this)*(1 / z);
		////using pointer *this to multiply (1/z) to realize the division,the multiply of complex number has been defined in overload of opertor *
	}
	ComplexNumber operator/(double a, ComplexNumber& b) {
		return  a* b.GetInverse();
	}


	ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const {
		double real = (this->myreal * z.myreal) - (this->myimg * z.myimg);
		double img = (this->myreal * z.myimg) + (this->myimg * z.myreal);
		return ComplexNumber(real, img);
	}

	ComplexNumber ComplexNumber::operator*(const double z) const {
		return ComplexNumber(this->myreal * z, this->myimg * z);

	}
	ComplexNumber operator*(double a, const ComplexNumber& b) {
		return (b * a);
	}











	void ComplexNumber::PrintComplexNumber()
	{
		cout <<"( " <<this->myreal << " , " << this->myimg << " ) " << endl;
	}

	double ComplexNumber::GetNorm()
	{
		return(sqrt(pow(this->myimg, 2) + pow(this->myreal, 2)));
	}




	ComplexNumber ComplexNumber::GetConjugate() {
		return(ComplexNumber(this->myreal, -this->myimg));

	}



	ComplexNumber ComplexNumber::GetInverse() {
		return (this->GetConjugate()) / pow(this->GetNorm(),2);
		//using the Conjugate of the complex number to be dividended by the norm of the complex number.this is to realize the GetInverse which will be used in (complex number)/(complex number)
		
		
	}




\