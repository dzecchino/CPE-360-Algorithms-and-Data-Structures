#include<iostream>
using namespace std;
/*
int getNthTermFibonacci(int n){
  if (n < 1)
        return 0;
        cout << "0" << endl;

    if (n == 1)
        cout << "1" << endl;
    if (n > 1){
      return getNthTermFibonacci(n-1)+getNthTermFibonacci(n-2);
    }

}
}
*/
/*
int sum = 0;
int a = 0;
int b = 1;

int getNthTermFibonnaci(int n) {
    if (n == 1) {
        cout << a << " ";
        return a;
    }
    else {
        cout << a << " ";
        sum = a + b;
        a = b;
        b = sum;
        getNthTermFibonnaci(n-1);
        return 0;
    }
}

int main(){
  getNthTermFibonacci(5);
  return 0;
}
*/
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
