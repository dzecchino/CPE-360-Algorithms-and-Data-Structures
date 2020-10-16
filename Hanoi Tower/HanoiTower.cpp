#include<iostream>

using namespace std;

void hanoi(int N, char S, char I, char D)
{
	static int counter;

	if(N==1) {
		///base-case or anchor-value
		cout << "Move disc " << N << " from " << S << " ---> " << D << endl;
	}
	else {
		//recursion relationship
		hanoi(N-1, S, D, I); //n-1 from S--->I
		cout << ++counter << "Move disc " << N << " from " << S << " ---> " << D << endl; //n S--->D
		hanoi(N-1, I, S, D);

}

}


int main() {
	int N;
	char S = 'S', I = 'I', D = 'D';

	cout << "How many discs?"  << endl;
	cin >> N;

	hanoi(N, S, I, D);

	return 0;
}
