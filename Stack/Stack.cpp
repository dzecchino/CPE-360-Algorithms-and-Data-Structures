#include <iostream>
//#include <stdlib. h> Only for linux for the "exit" function
using namespace std;

/*
3 Most Important Things for Any Data Structure
	1. Add stuff to structure
	2. Remove stuff from structure
	3. Display stuff from structure
*/

/*
Stacks: Add and remove from the front (LIFO - Last in First out)
	E.g. stack of plates -> addition and removal of plates always happens on the top (or PEZ Dispenser)
	Like recommendations (Amazon and youtube)

	Add -> push()
	Remove -> pop()
	Display -> display()
*/

class Chunk {
public:
	int count; //Use count++ and count-- for push and pop
	int value; //amazon would use product recommendations
	Chunk* next;

	Chunk() {
		value = 0;
		next = NULL;
	}
};

//Stack of "chunks"
class Stack {
public:
	Chunk* top;

	Stack() {
		top = NULL; //If you just created stack, top = NULL
	}

	//1. PUSH: Add a new element
	void push(int x) { //add this value 'x' into the structure
		Chunk* another;
		another = new Chunk;
		another->value = x;

		if (top == NULL) { //Case 1: Structure is empty: simply make this new value the "top"
			top = another;
		}
		else { //Case 2: Structure is not empty
			another->next = top;
			top = another;
		}
	}

	//2. POP: Remove an element
	void pop() {
		Chunk* another;
		another = top;

		if (top == NULL) { //Case 1: Structure is empty: do nothing
			cout << "Stack is empty" << endl;
			return;
		}
		else { //Case 2: Structure is not empty
			top = top->next;
			cout << "About to delete: " << another->value << endl;
			delete another;
		}
	}

	//3. DISPLAY: show me the contents
	void display() {
		if (top == NULL) { //Case 1: Structure is empty
			cout << "Empty stack: nothing to display" << endl;
			return;
		}
		else { //Case 2: Structure is not empty
			Chunk* another;
			another = top;

			while (another != NULL) {
				cout << another->value << "-->";
				another = another->next;
			}
			cout << "NULL" << endl;
		}
	}

	void display3() {
		if (top == NULL) { //Case 1: Structure is empty
			cout << "Empty stack" << endl;
		}
		else if (top->next == NULL) {
			cout << "Only 1 item in stack" << endl;
		}
		else if (top->next->next == NULL) {
			cout << "Only 2 items in stack" << endl;
		}
		else {
			cout << top->next->next->value << endl;
		}
	}

};

/*
Queues: Add and remove from opposite ends (FIFO - First in First out)
*/

/*
Linked Lists: Add and remove anything from anywhere
*/

int main() {
	Stack myStack;
	int choice, value;

	//We add 5, 6, 3, 9, 10 (10 would be at the top of the stack)
	myStack.push(5);
	myStack.push(6);
	myStack.push(3);
	myStack.push(9);
	myStack.push(10);

	myStack.display();
	myStack.display3();

	while (1) { //Infinite loop
		cout << "Press 1 to add" << endl;
		cout << "Press 2 to pop" << endl;
		cout << "Press 3 to display" << endl;
		cout << "Anything else to quit" << endl;

		cin >> choice;
		
		switch (choice) { //More graceful way to handle massive amounts of if else statements
			case 1: cout << "Add what?" << endl;
					cin >> value;
					myStack.push(value);
					break; //Always break between cases if you don't want it to continue through the other cases

			case 2: myStack.pop();
					break;

			case 3: cout << "-------------------" << endl;
					myStack.display();
					cout << "-------------------" << endl;
					break;

			default: cout << "Goodbye!" << endl;
					 exit(1);
		}
	}
}