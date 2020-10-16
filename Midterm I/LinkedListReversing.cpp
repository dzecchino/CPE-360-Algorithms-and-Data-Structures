#include<iostream>
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

//LinkedList
class LinkedList {
public:
    int length;
    Chunk* head;

    LinkedList() {
        head = NULL;
        length = 0;
    }

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

    void insertAtPosition(int position, int value) {
        Chunk* temp = new Chunk;
        temp->value = value;

        if (position <= length + 1 && position > 0) {
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
        Chunk* temp, * follow;
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
            length--;
        }
        else {
            cout << "Invalid Position" << endl;
        }
    }

    void displayContents() {
        if (head == NULL) {
            cout << "Empty LinkedList, nothing to display." << endl;
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
    void reverseLinkedList(){
      Chunk *t, *f;
      t=f=head;
      if (length == 0){
        cout << "There is nothing to reverse. " << endl;
      }
      else if(length == 1){
        return ;
      }
      else {
        while(f->next != NULL){
          f = f->next;
        }
        for(int i=length-2; i>=0; i--){
          t = head;
          for(int j=i; j>0; j--){
            t = t->next;
          }
          t->next->next = t;
        }
        t->next = NULL;
        head = f;
      }
    }

    void removeEveryOtherNode(){
      Chunk *temp, *follow;
      follow = head;
      temp = follow->next;
      if(length == 0 || length == 1){
        cout << "I cannot remove anything from this list." << endl;
        return ;
      }
      else {
        for(int i = 0; i<length/2; i++){

            follow->next=temp->next;
            delete temp;
            if(follow->next == NULL){
              return ;
            }
            follow = follow->next;
            temp = follow->next;
            }
      }
    }

};

int main() {
  LinkedList LL;

  LL.insertAtHead(1);
  LL.insertAtHead(2);
  LL.insertAtHead(3);
  LL.insertAtHead(4);
  LL.insertAtHead(5);
  LL.displayContents();

  LL.reverseLinkedList();
  LL.displayContents();

  LL.removeEveryOtherNode();
  LL.displayContents();
}
