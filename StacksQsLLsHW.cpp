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

class LinkedList {
public:
    Chunk* head;
    int length;

    LinkedList() {
      head = NULL;
      length = 0;
    }

    void insertAtHead(int value) {
      Chunk *temp = new Chunk;
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

    void addAtPosition(int value, int position) {
      Chunk *temp = new Chunk;
      temp->value = value;

      if(position > 0 && position <= length + 1) {
        if(position == 1) {
          temp->next = head;
          head = temp;
        }
        else if(position > 1 && position < length + 1) {
          Chunk *helper = head;
          int i = 1;
          while(i < position - 1) {
            helper = helper->next;
            cout << "The helper function is at value: " << helper->value << endl;
            i++;
          }
        }

          temp->next = helper->next;
          helper->next = temp;
        }
        else {
          Chunk *helper = head;
          while(helper->next != NULL) {
            helper = helper->next;
          }
          helper->next = temp;
        }
        length++;
    }

    void removeFromPosition(int position) {
      Chunk *slow, *temp;
      slow = temp = head;

      if (position > 0 && position <= length) {
        if(position == 1 && length == 1) {
          delete head;
          head = NULL;
        }
        else if (position == 1 && length > 1) {
          head = head->next;
          delete temp;
        }
        else {
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
      if(head == NULL) {
        cout << "Empty, nothing to display" << endl;
      }
      else {
        Chunk *temp;
        temp = head;
        while(temp != NULL) {
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

  void push(int x) {
    Chunk* temp = new Chunk;
    temp->value = x;

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

    if(top == NULL) {
      cout << "Stack's already empty." << endl;
    }
    else {
      top = top->next;
      delete temp;
      cout << "Top of stack deleted succesfully." << endl;
    }
  }

  void displayContents() {
    if(top == NULL) {
      cout << "Empty, nothing to display" << endl;
    }
    else {
      Chunk *temp;
      temp = top;
      while(temp != NULL) {
        cout << temp->value << "-->";
        temp = temp->next;
      }
      cout << "NULL" << endl;
      cout << "-----------------------------" << endl;
    }
  }
};

class Queue {
  public: Chunk *head, *tail;
  Queue() {
    head = NULL;
    tail = NULL
    }

    void enqueue(int value){
      Chunk *temp = new Chunk;
      temp->value = value;

      if(head == NULL) {
        head = temp;
        tail = temp;
      }
      else {
        temp->next = temp;
        tail = temp;
      }
    }

    void dequeue(){
      Chunk *temp = head;

      if(head==NULL){
        cout << "Empty Q, nothing to  delete" << endl;
      }
      else if(head->next == NULL){
        cout << "Deleting: " << head->value << endl;
        delete head;
        head = NULL;
        tail = NULL;
      }
      else {
        temp = head;
        head = head=>next;
        delete temp;
        }
      }

    void displayContents() {
      if(head == NULL) {
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

int main() {
  LinkedList LL;
  Stack S;
  Queue Q;
  int choice, value, position;

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
                            LL.insertAtHead(headValue);
                            break;
                   case 2 :
                            cout << "What position in the linked list would you like to remove?" << endl;
                            cin << removePosition;
                            LL.removeFromPosition(removePosition);
                            break;
                   case 3 :
                            cout << "What position in the linked list would you like to add to?" << endl;
                            cin << added;
                            LL.addAtPosition(added);
                            break;
                   case 4:
                            LL.displayContents();
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
                          S.push(pushValue);
                          break;
                  case 2 :
                          cout << "Removing the desired value?" << endl;
                          S.pop();
                          break;
                  case 3 :
                          S.displayContents();
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
          cin >> input;

          switch(value){
            case 1 :
                    cout << "What is the value you'd like to enqueue?" << endl;
                    cin << enqueueValue;
                    Q.enqueue(enqueueValue);
                    break;
            case 2 :
                    cout << "Dequeueing..." << endl;
                    Q.dequeue();
                    break;
            case 3 :
                    Q.printContents();
                    break;
            default:
                    exit(1);
          }
      }
    }
  }
}
