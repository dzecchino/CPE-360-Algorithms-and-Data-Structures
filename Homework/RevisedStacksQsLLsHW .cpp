#include <iostream>
using namespace std;

class Chunk {
public:
	int value;
	Chunk* next;

	Chunk() {
		value = 0;
		next = NULL;
	}
};

class LinkedList {
public:
	int length;
	Chunk* head;

	LinkedList() {
		head = NULL;
		length = 0;
	}
	//Starting below is the functions for the linked list part of the homrwork
	void insertAtHead(int value) {
		Chunk* temp = new Chunk;
		temp->value = value;
		if (head == NULL) {
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
		length++;
	}
	void addAtPosition(int position, int value) {
		Chunk* temp = new Chunk;
		temp->value = value;
		if (position > 0 && position <= length + 1) {
			if (position == 1) {
				insertAtHead(value);
			}
			else {
				Chunk* helper = head;
				for (int i = 1; i < position - 1; i++) {
					helper = helper->next;
				}
				if (helper->next == NULL) {
					helper->next = temp;
				}
				else {
					temp->next = helper->next;
					helper->next = temp;
				}
			}
			length++;
		}
		else {
			cout << "Invalid Position" << endl;
		}
	}

	void removeFromPosition(int position) {
		Chunk* temp, *follow;
		temp = follow = head;

		if (position > 0 && position <= length) {
			if (position == 1 && length == 1) {
				delete head;
				head = NULL;
			}
			else if (position == 1 && length > 1) {
				head = head->next;
				delete temp;
			}
			else {
				for (int i = 1; i <= position - 1; i++) {
					follow = temp;
					temp = temp->next;
				}
				follow->next = temp->next;
				delete temp;
			}
			length--;// DO NOT FORGET
		}
		else {
			cout << "Will not delete: invalid position" << endl;
		}
	}

	void displayContents() {
		if (head == NULL) {
			cout << "Empty, nothing to display." << endl;
		}
		else {
			cout << "-----------------------------" << endl;
			Chunk* temp;
			temp = head;

			while (temp != NULL) {
				cout << temp->value << "-->";
				temp = temp->next;
			}
			cout << "NULL" << endl;
			cout << "------------------------------" << endl;
		}
	}
};

//Stack
class Stack {
public:
	Chunk* top;
	Stack() {
		top = NULL;
	}
	//Below is the start of the functions for the Stack portion of the homeworks
	void push(int value) {
		Chunk* temp = new Chunk;
		temp->value = value;

		if (top == NULL) {
			top = temp;
		}
		else {
			temp->next = top;
			top = temp;
		}
	}

	void pop() {
		Chunk* temp = top;

		if (top == NULL) {
			cout << "Empty Stack, nothing to pop." << endl;
		}
		else if (top->next == NULL) {
			delete top;
			top = NULL;
		}
		else {
			temp = top;
			top = top->next;
			delete temp;
		}
	}

	void displayContents() {
		if (top == NULL) {	//Case 1: Structure is empty
			cout << "Empty Stack, nothing to display." << endl;
		}
		else {
			Chunk* temp;
			temp = top;

			cout << "------------------------" << endl;
			while (temp != NULL) {
				cout << temp->value << "-->";
				temp = temp->next;
			}
			cout << "NULL" << endl;
			cout << "------------------------" << endl;
		}
	}
};

class Queue {
public:
	Chunk* head;
	Chunk* tail;

	Queue() {
		head = NULL;
		tail = NULL;
	}

	//This is the beginning of the functions for the Queue portion of the homework
	void enqueue(int value) {
		Chunk* temp = new Chunk;
		temp->value = value;

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void dequeue() {
		Chunk* temp = head;

		if (head == NULL) {
			cout << "Empty Queue, nothing to remove." << endl;
		}
		else if (head->next == NULL) {
			delete head;
			head = NULL;
			tail = NULL;
		}
		else {
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void printContents() {
		if (head == NULL) {
			cout << "Empty Queue, nothing to display." << endl;
		}
		else {
			Chunk* temp;
			temp = head;

			cout << "------------------------" << endl;
			while (temp != NULL) {
				cout << temp->value << "-->";
				temp = temp->next;
			}
			cout << "NULL" << endl;
			cout << "------------------------" << endl;
		}
	}
};

int main() {
	LinkedList LL;
	Stack S;
	Queue Q;
	int value, position, choice;

	while (1) {
		cout << "Press 1 to work with linked lists" << endl;
		cout << "Press 2 to work with the stack" << endl;
		cout << "Press 3 to work with a queue" << endl;
		cout << "anything else to quit" << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			while (1) {
				cout << "Press 1 to insert at the head" << endl;
				cout << "Press 2 to insert at some position" << endl;
				cout << "Press 3 to remove from some position" << endl;
				cout << "Press 4 to display the contents" << endl;
				cout << "Anything else to quit" << endl;

				cin >> choice;

				switch (choice) {
				case 1:
					cout << "What is the value you'd like to pass into the head?" << endl;
					cin >> value;
					LL.insertAtHead(value);
					break;

				case 2:
					cout << "What value in the linked list would you like to add?" << endl;
					cin >> value;
					cout << "What position?" << endl;
					cin >> position;
					LL.addAtPosition(position, value);
					break;

				case 3:
					cout << "What position in the linked list would you like to remove?" << endl;
					cin >> position;
					LL.removeFromPosition(position);
					break;

				case 4:
					LL.displayContents();
					break;

				default:
					exit(1);
				}
			}
			break;

		case 2:
			while (1) {
				cout << "Press 1 to push to the stack" << endl;
				cout << "Press 2 to pop from the stack" << endl;
				cout << "Press 3 to display contents" << endl;
				cout << "Anything else to quit" << endl;
				cin >> choice;

				switch (choice) {
				case 1:
					cout << "What is the value you'd like to push to the stack?" << endl;
					cin >> value;
					S.push(value);
					break;

				case 2:
				cout << "Removing the desired value." << endl;
					S.pop();
					break;

				case 3:
					S.displayContents();
					break;

				default: cout << "Returning to main menu" << endl;
					exit(1);
				}
			}
			break;

		case 3:
			while (1) {
				cout << "Press 1 to enqueue" << endl;
				cout << "Press 2 to dequeue" << endl;
				cout << "Press 3 to display contents" << endl;
				cout << "anything else to quit" << endl;

				cin >> choice;

				switch (choice) {
				case 1:
					cout << "What is the value you'd like to enqueue?" << endl;
					cin >> value;
					Q.enqueue(value);
					break;

				case 2:
				cout << "Dequeueing..." << endl;
					Q.dequeue();
					break;

				case 3:
					Q.printContents();
					break;

				default: cout << "Returning to main menu" << endl;
					exit(1);
				}
			}
			break;

		default:
			exit(1);
		}
	}
	return 0;
}
