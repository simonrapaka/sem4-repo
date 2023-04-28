#include<iostream>
#include<fstream>

#define N 10
#define H 10

using namespace std;

class Student
{
	int roll;
	string name;
	int marks;

	public:
	Student()
	{
		roll = -1;
		name = " ";
		marks = -1;
	}
	void accept();
	void ar();
	int getroll();
	void disp();
};

void Student::accept()
{
	cout << "Enter name: ";
	cin >> name;

	cout << "Enter roll number: ";
	cin >> roll;

	cout << "Enter marks: ";
	cin >> marks;
}

void Student::ar()
{
	cout << "Enter roll: ";
	cin  >> roll;
}

int Student::getroll()
{
	return roll;
}

void Student::disp()
{
	cout << "Name: " << name << " RollNo: " << roll << " Marks: " << marks << "\n";
}

 void hashk(int h[], Student s[], int n)
{
	for(int i=0;i<n;i++)
		h[s[i].getroll()%H] = i;
}

void hashl(int h[], Student s[], int n)
{
	for(int i=0;i<n;i++)
	{
		int l = s[i].getroll()%H;
		if(h[l]==-1) h[l] = i;
		else
			while(l<H)
			{
				l = (l+1)%H;
				if(h[l]==-1) {h[l] = i; break;}
			}
	}
}

int main()
{
	Student s[N];
	int h[H],n;
	fstream fl;

	for(int i=0;i<H;i++)
		h[i] = -1;

	cout << "Enter number of students: ";
	cin >> n;

	fl.open("d.txt",ios::out|ios::binary);

	for(int i=0;i < n;i++)
	{
		cout << "Enter Details of Student " << i+1 << "\n";
		s[i].accept();
		fl.seekp(i*sizeof(Student));
		fl.write((char*)&s[i], sizeof(Student));
	}

	fl.close();

	for(int i=0;i<n;i++)
		{
			cout << "Index: " << i << " ";
			s[i].disp();
			cout << "\n";
		}

	hashl(h,s,n);

	cout << "Hash Table:\n";

	for(int i=0;i<H;i++)
	{
		cout << i << " : ";
		h[i]==-1 ? cout << "Empty\n" : cout << s[h[i]].getroll() << "\n";
	}

	fl.open("d.txt",ios::in);

	Student r;

	fl.read((char*)&r, sizeof(Student));
	
	r.disp();

	return 0;
}