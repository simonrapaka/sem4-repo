/*******************************************
 * Name: Simon Henry
 * Roll No: 1
 * Batch H1
 * Panel H
 * Date: 13/2/23
********************************************/

#include<iostream>

using namespace std;

class Complex
{
	private:
	float real,imag;
	public:
	Complex()
	{
		real = imag = 0;
	}
	Complex(float r, float i)
	{
		real = r;
		imag = i;
	}
	void getComplex();
	void printComplex();
	void printComplexR();
	Complex operator+(Complex &c1);
	Complex operator-(Complex &c1);
	Complex operator*(Complex &c1);
	Complex operator/(Complex &c1);
};

void Complex::getComplex()
{
	cout << "Enter Real Part: ";
	cin >> real;
	cout << "Enter Imaginary Part: ";
	cin >> imag;
}

void Complex::printComplex()
{
	cout << "Complex Number: " << real;
	imag < 0 ? cout << " - " : cout << " + ";
	imag < 0 ? cout << imag*(-1) : cout << imag;
	cout << "i\n";
}

void Complex::printComplexR()
{
	cout << "\nResult: " << real;
	imag < 0 ? cout << " - " : cout << " + ";
	imag < 0 ? cout << imag*(-1) : cout << imag;
	cout << "i\n";
}

Complex Complex::operator+(Complex &c1)
{
	Complex c;
	c.real = real + c1.real;
	c.imag = imag + c1.imag;
	return c;
}

Complex Complex::operator-(Complex &c1)
{
	Complex c;
	c.real = real - c1.real;
	c.imag = imag - c1.imag;
	return c;
}

Complex Complex::operator*(Complex &c1)
{
	Complex c;
	c.real = real * c1.real - (imag * c1.imag);
	c.imag = real * c1.imag + imag * c1.real;
	return c;
}

Complex Complex::operator/(Complex &c1)
{
	Complex c;
	c.real = (real * c1.real + imag * c1.imag)/(c1.real*c1.real + c1.imag*c1.imag);
	c.imag = (imag * c1.real - real * c1.imag)/(c1.real*c1.real + c1.imag*c1.imag);
	return c;
}


int main()
{
	Complex c1,c2,c3;
	int ch,e=1;

	while(e)
	{
		cout << "\n1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n5)Exit\n\nWhat do you want to do? ";
		cin >> ch;
		cout << "\n";
		switch (ch)
		{
		case 1:
			c1.getComplex();
			c1.printComplex();
			cout << "\n";
			c2.getComplex();
			c2.printComplex();
			c3 = c1+c2;
			c3.printComplexR();
			break;

		case 2:
			c1.getComplex();
			c1.printComplex();
			cout << "\n";
			c2.getComplex();
			c2.printComplex();
			c3 = c1-c2;
			c3.printComplexR();
			break;

		case 3:
			c1.getComplex();
			c1.printComplex();
			cout << "\n";
			c2.getComplex();
			c2.printComplex();
			c3 = c1*c2;
			c3.printComplexR();
			break;

		case 4:
			c1.getComplex();
			c1.printComplex();
			cout << "\n";
			c2.getComplex();
			c2.printComplex();
			c3 = c1/c2;
			c3.printComplexR();
			break;

		case 5:
			e=0;
			break;

		default:
			break;
		}
	}

	return 0;
}