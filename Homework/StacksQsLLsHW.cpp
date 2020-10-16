#include<iostream>
using namespace std;

class Chunk{
public:
  int value;
  Chunk *next;

  Chunk(){
    value = 0;
    next = NULL;
  }
};

class LinkedList{
public:
    Chunk *head;
    int length;

    LinkedList() {
      head = NULL;
      length = 0;
    }

    //Starting below is the functions for the linked list part of the homrwork
    void insertAtHead(int value){
      Chunk *temp = new Chunk;
      temp->value = value;
      if(head ==NULL){
        head = temp;
      }
      else{
        temp->next = head;
        head = temp;
      }
      length++;
    }
    void addAtPosition(int value, int position) {
      if(position > 0 && position <= length + 1){
        Chunk *temp = new Chunk;
        if(posiiton == 1){
          temp->next = head;
          head = temp;
        }
        else if(position > 1 && position < length + 1){
          Chunk *helper = head;
          i = 1;
          while(i < position - 1){
            helper = helper->next;
            cout << "The helper function is at value: " << helper->value << endl;
          }
          temp->next = helper->next;
          helper->next = temp;
        }
        else {
          Chunk *helper = head;
          while(helper->next != NULL){
            helper = helper->next;
          }
          helper->next = temp;
        }
        length++;
      }
    }

    void removeFromPosition(int position) {
      if (position > 0 && position <= length) {
        if(position == 1 && length == 1){
          delete head;
          head = NULL;
        }
        else if (position == 1 && length > 1) {
          Chunk *temp = head;
          head = head->next;
          delete temp;
        }
        else if(position > 1 && position < length) {
          Chunk *temp, *slow;
          temp = slow = head;

          for(int i = 1; i <= position; i++) {
            slow = temp;
            temp = temp->next;
          }
          slow-> next = temp->next;
          delete temp;
        }
        length--; // DO NOT FORGET
      }
      else {
          cout << "Will not delete: invalid position" << endl;
        }
    }

    void displayContents() {
      if(head == NULL){
        cout << "Empty, nothing to display" << endl;
      }
      else{
        Chunk *temp;
        temp = head;
        while(temp != NULL){
          cout << temp->value << "-->";
          temp = temp->next;
        }
        cout << "NULL" << endl;
        cout << "-----------------------------" << endl;
      }
    }

};

class Stack {
public:
  Chunk *top;
  Stack() {
    top = NULL;
  }

  //Below is the start of the functions for the Stack portion of the homework
  void push(int x) {
    temp->value = x;

    if (top == NULL){
      top = temp;
    }
    else{
      temp->next = top;
      top = temp;
    }
  }

  void pop() {
    temp = top;

    if(top == NULL){
      cout << "Stack's already empty." << endl;
    }
    else{
      top = top->next;
      delete temp;
      cout << "Top of stack deleted succesfully." << endl;
    }
  }

  void printContents() {
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

class Queue {
  public: Chunk *head, *tail;
  Queue() {
    head = NULL;
    tail = NULL;
    }
    //This is the beginning of the functions for the Queue portion of the homework

  void enqueue(int x){
    Chunk *temp = new Chunk;
    temp->value = x;

    if(head == NULL) {
      head = temp;
      tail = temp;
    }
    else{
      tail->next = head;
      tail = temp;
    }
  }
  void dequeue(){
    Chunk* temp = head;
    if(head==NULL){
      cout << "Empty Q, nothing to  delete" << endl;
    }
    else if(head->next == NULL){
      cout << "Deleting: " << head->value << endl;
      delete head;
      head = NULL;
      tail = NULL;
    }
    else{
      temp = head;
      head = head->next;
      delete temp;
    }

    else{
      // we'll go find the last chunk
      tail = helper = head;
      while(tail->next != NULL) {
        helper = tail;
        tail = tail->next;
      }
      helper->next = NULL;
      cout << "Deleting: " << tail->value << endl;
      delete tail;
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
  				cout << temp->x << "-->";
  				temp = temp->next;
  			}
  			cout << "NULL" << endl;
  			cout << "------------------------" << endl;
  		}
  	}
};






int main() {
  while(1) {
    cout << "Press 1 to work with linked lists." << endl;
    cout << "Press 2 to work with the stack." << endl;
    cout << "Press 3 to work with a queue." << endl;
    cout << "anything else to quit" << endl;
    cin >> choice;
    switch(choice) {
      case 1 :
               while(1){
                 cout << "Press 1 to insert at the head." << endl;
                 cout << "Press 2 to insert at the end." << endl;
                 cout << "Press 3 to insert somewhere in the middle." << endl;
                 cout << "Press 4 to display contents." << endl;
                 cin >> value;

                 switch(value){
                   case 1 :
                            "What is the value you'd like to pass into the head?" << endl;
                            cin << headValue;
                            insertAtHead(headValue);
                            break;
                   case 2 :
                            cout << "What position in the linked list would you like to remove?" << endl;
                            cin << removePosition;
                            removeFromPosition(removePosition);
                            break;
                   case 3 :
                   cout <<
                            cout << "What position in the linked list would you like to add to?" << endl;
                            cin << added;
                            addAtPosition(added);
                            break;
                   case 4:
                            displayContents();
                   default:
                            exit(1);
                 }
              }

      case 2 :
              while(1){
                cout << "Press 1 to push to the stack." << endl;
                cout << "Press 2 to pop from the stack." << endl;
                cout << "Press 3 to display contents." << endl;
                cin >> input;

                switch(value){
                  case 1 :
                          cout << "What is the value you'd like to push to the stack?" << endl;
                          cin << pushValue;
                          push(pushValue);
                          break;
                  case 2 :
                          cout << "Removing the desired value?" << endl;
                          pop();
                          break;
                  case 3 :
                          displayContents();
                          break;
                  default:
                          exit(1);
        }
     }

      case 3 :
        while(1){
          cout << "Press 1 to enqueue." << endl;
          cout << "Press 2 to dequeue." << endl;
          cout << "Press 3 to print contents." << endl;
          cin >> value;

          switch(value){
            case 1 :
                    cout << "What is the value you'd like to enqueue?" << endl;
                    cin << enqueueValue;
                    enqueue(enqueueValue);
                    break;
            case 2 :
                    cout << "Dequeueing..." << endl;
                    dequeue();
                    break;
            case 3 :
                    printContents();
                    break;
            default:
                    exit(1);
                  }
                }
    }
  }

}
