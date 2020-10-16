#include<iostream>
using namespace std;

int main()
{
	int var = 10;
	int *pal;  //friendly kind of variable 
	/*
	 * pal is a "pointer"
	 * pal can ONLY store addresses, and never literal value
	*/
	

	pal = &var; //now, pal knows the address of var
	//var = 20;	
	
	*pal = 20; // pal pays a visit to var and changes the value of var to 20

	cout << "Value of var after pal paid a visit: " << var << endl;
	
	/*
	cout << "Value of the variable: " << var << endl;
	cout << "Address of this variable " << &var << endl;
	*/

	//var = 20

}
