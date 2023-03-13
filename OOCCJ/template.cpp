#include<iostream>
#include<cassert>
#include<vector>

using namespace std;

template<class S>

S arr_max(S arr[], int n)
{
    S answer;

    assert(n>0);

    answer = arr[0];

    for (int i=0;i<n;i++)
        if(arr[i] > answer)
            answer = arr[i];

    return answer;
}

template<class D>

void swap(D *a, D *b)
{
    D temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>

class Mul
{
    public:
        T mul(T *a, T *b);
};

template<class T>

T Mul<T>::mul(T *a, T *b)
{
    T ans;

    ans = *a * *b;

    return ans;
}



int main()
{
    double darr[] = {0.2,0.1,5.6}, d1 = 0.2, d2 = 0.3;
    int iarr[] = {5,6,7,9}, i1 = 7, i2 = 9;

    vector<int> v1;

    Mul<double> dm;

    double dans = arr_max(darr,3);

    cout << "Maximum: " << dans;

    cout << "\nBefore Swap: " << d1 << " " << d2;

    swap(&d1, &d2);

    cout << "\nAfter Swap: " << d1 << " " << d2;

    cout << "\n" << d1 << " x " << d2 << ": " << dm.mul(&d1,&d2);

    cout << "\n\n\n";

    cout << "Enter x to stop entering\n";

    for(int i = 0;;i++)
    {
        string in;
        int v;

        cout << "Enter a number: ";
        cin >> in;

        if(in[0] == 'x') break;

        sscanf(in.c_str(), "%d", &v);

        v1.push_back(v);
    }

    cout << "Elements in the vector: ";

    for(auto& e : v1)
    {
        cout << e << " ";
    }

    return 0;
}