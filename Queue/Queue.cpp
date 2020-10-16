#include<iostream>
#include<stdlib.h>
using namespace std;

//chunk
class Chunk{
public:
  int value;
  Chunk *next;

  Chunk() {
    value = 0;
    next = NULL;

  }
};

//Queue of Chunks
class Queue{
  public: Chunk *head;

  Queue() {
    head = NULL;
  }
  //1. Add chunks to the Q (enqueue)
  void enqueue(int x){
    Chunk *temp = new Chunk;
    temp->value = x;

    if(head == NULL) {
      head = temp;
    }
    else{
      temp->next = head;
      head = temp;
    }
  }
  //2. Remove a chunk from the Q (dequeue)
  void dequeue(){
    if(head==NULL){
      cout << "Empty Q, nothing to  delete" << endl;
    }
    else if(head->next == NULL){
      cout << "Deleting: " << head->value << endl;
      delete head;
      headChunk *temp = new Chunk;
    temp->value = x;

    if(head == NULL) {
      head = temp;
    }
    else{
      temp->next = head;
      head = temp;
    } = NULL;
    }
    else{
      // we'll go find the last chunk
      Chunk *chase, *follow;
      chase = follow = head;
      while(chase->next != NULL) {
        follow = chase;
        chase = chase->next;
      }
      follow->next = NULL;
      cout << "Deleting: " << chase->value << endl;
      delete chase;
    }
  }
  //3. Display the contents of the Q
  void displayContents() {
    if(head == NULL){
      cout << "Empty Q, nothing to display" << endl;
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
  Queue Q;
  int value, choice;

  while(1) {
    cout << "Press 1 to add (enQ)" << endl;
    cout << "Press 2 to remove (deQ)" << endl;
    cout << "Press 3 to display" << endl;
    cout << "anything else to quit" << endl;
    cin >> choice;
  }

  switch(choice) {
    case 1 : cout << "Add what? " << endl;
             cin >> value;
             Q.enqueue(value);
             break;

    case 2 : Q.dequeue();
             break;

    case 3 : Q.displayContents();
             break;
  }

}
