#include<iostream>

using namespace std;

class polygon
{
	protected:
		float height,base;
	public:
		void setdim()
		{
			cout << "Enter Height: ";
			cin >> height;
			cout << "Enter length of base: ";
			cin >> base;
		}
	
};

class triangle: public polygon
{
	public:
		int area()
		{
			return 0.5*height*base;
		}
};


int main()
{
	triangle t1;
	t1.setdim();

	cout << "The area of the triangle is " << t1.area();

	return 0;
}