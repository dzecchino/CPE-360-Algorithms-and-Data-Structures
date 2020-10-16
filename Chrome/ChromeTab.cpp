#include<iostream>
using namespace std;

class ChromeTab{
public:
  //attributes
  int length;
  int width;

  //constructor
  ChromeTab() {
    length = 100;
    width = 50;
    next = NULL;
  }
  //functions: let's not bother just yet
};

int main(){

  //first tab
  ChromeTab *first;
  first = new ChromeTab
  first -> length = 200;
  first -> width = 100;

  //second tab
  first -> next = new ChromeTab
  first -> next -> length = 400;
  first -> next -> width = 400;

  //third tab
  first -> next -> next = new ChromeTab;
  first -> next -> next -> length = 1000;
  first -> next -> next -> width = 300;

  //let's add a new chunk, such that this is now the FIRST tab
  ChromeTab *another;
  another = new ChromeTab;

  //let's get this new (another) tab to point to the current first
  another -> next = first;
  first =  another;

  // let's add something in the MIDDLE
  another -> next = first -> next -> next;
  first -> next -> next = another;

  // delete the last tab
  delete first -> next -> next -> next -> next;
  first -> next -> next -> next -> next = NULL;

  another = first -. next -> next;
  first -> next -> next = first -> next -> next -> next;
  delete another;

  //let's just loop through the strucutre and print stuff

}
