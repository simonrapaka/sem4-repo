#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void enter(vector<int>& vc)
{
	cout << "Enter x to stop entering\n";

	for(int i = 0;;i++)
	{
		string in;
		int v;

		cout << "Enter a number: ";
		cin >> in;

		if(in[0] == 'x') break;

		sscanf(in.c_str(), "%d", &v);

		vc.push_back(v);
	}
}

void printv(vector<int>& v1)
{
	cout << "Elements in the vector: ";

	for(auto& e : v1)
	{
		cout << e << " ";
	}
}

void vecrem(vector<int>& v1)
{
	int r;
	printv(v1);
	cout << "\nEnter the element you want to remove: ";
	cin >> r;

	remove(v1.begin(),v1.end(),r);
	cout << "\n";
	printv(v1);
}

void vecsort(vector<int>& v1)
{
	sort(v1.begin(),v1.end());
	cout << "Sorted\n";
	printv(v1);
}

void vecf(vector<int>& v1)
{
	int f;
	cout << "Enter element you want to find: ";
	cin >> f;

	for(auto& e: v1)
		if(e==f)
			{
				cout << "Found!\n";
				return;
			}

	cout << "Not Found\n";
}
int main()
{
	vector<int> v1;
	int ch;

	cout << "1)Enter data\n2)Print\n3)Sort\n4)Remove\n5)Find\n6)Exit\n";
	cin >> ch;

	switch(ch)
	{
		case 1:
			enter(v1);
			break;

		case 2:
			printv(v1);
			break;

		case 3:
			vecsort(v1);
			break;

		case 4:
			vecrem(v1);
			break;

		case 5:
			vecf(v1);
			break;

		case 6:
			return 0;


		default:
			break;
	}


	return 0; 
}