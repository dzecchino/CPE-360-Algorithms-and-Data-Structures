#include<iostream>
using namespace std;

class Chunk{
public:
  int value;
  Chunk *next;

  Chunk() {
    value = 0;
    next = NULL;
  }
};

void printContents(Chunk *start){
  if(start == NULL){
  cout << "This is an empty list!" << endl;
  return;
  }
  else{
    while(start!=NULL){
    cout << start->value << "-->";
    start = start->next;
    }
    cout << "NULL" << endl;
  }
}

int main(){

  Chunk *head, *another;

  //STEP 1: Get a chunk
  head = new Chunk;
  head->value = 1;
  //STEP 1: A second chunk
  head->next = new Chunk;
  head->next->value = 2;
  // STEP 1: A third chunk
  head->next->next = new Chunk;
  head->next->next->value = 3;
  printContents(head);

  //STEP 2: Add and remove a chunk from the FRONT
  //get a brand new chunk in the heap
  another = new Chunk;
  another->next = head;
  head = another;
  printContents(head);


  //deleting that newly created chunk
  another = head;
  head = head->next;
  delete another;
  printContents(head);


  //STEP 3: Insert and delete a chunk all the way to the end
  another = new Chunk;
  head->next->next->next = another;
  printContents(head);

  another = head->next->next->next;
  head->next->next->next = NULL;
  delete another;
  printContents(head);


  //STEP 4: Insert and delete a chunk from the middle
  another = new Chunk;
  another->next = head->next->next;
  head->next->next = another;
  printContents(head);


  another = head->next->next;
  head->next->next = another->next;
  delete another;
  printContents(head);

}
