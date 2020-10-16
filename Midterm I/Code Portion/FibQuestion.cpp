#include<iostream>
using namespace std;

int sum = 0;
int num1 = 0;
int num2 = 1;

int getNthTermFibonnaci(int n) {
    if (n == 1) {
        cout << num1 << " ";
    }
    else {
        sum = num1 + num2;
        cout << num1 << " ";
        num1 = num2;
        num2 = sum;
        getNthTermFibonnaci(n-1);
        return num2;
    }
}


int main()
{
    cout<< getNthTermFibonnaci(10) << endl;

}
