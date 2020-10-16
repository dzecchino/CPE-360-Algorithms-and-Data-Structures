#include<iostream>

using namespace std;

void fact(int N) {

	if (N < 0){
		cout << "Can't do it" << endl;
	}
	else {
		int result = 1;
		for(int i = N; i > 0; i--) {
			result = result*i;
		}
		cout << "Factorial: " << result << endl;
	}


}

int factorial(int N) {
	//anchor value
	if(N == 0){
		return 1;
	}
	//recursive step
	else
		return factorial(N-1)*N;


int main() {
	int N;

	cout << "Give me a number, I'll compute the factorial" << endl;
	cin >>  N;

	fact(N);
	cout << "Using recursion: " << factorial(N) << endl;

	for(int i = 0; i < N; i = i + 5) {
		cout << "print me please" << endl;
	}
	return 1;
}
