// I pledge my honor that I have abided by the Stevens Honor System.
// Dominic Zecchino -- May 10, 2020

#include<iostream>
using namespace std;

class TreeChunk {
public:
  int data;
  TreeChunk *left;
  TreeChunk *right;

  TreeChunk(){
    data = 0;
    left = right = NULL;
  }
};

//Tree of TreeChunk
class BST {
public:
  TreeChunk *root;
  BST(){
    root = NULL;
  }
  //1. Add function
  void add(int x) {
    if(root == NULL){
      // Emptytree!
      root = new TreeChunk;
      root->data = x;
      cout << "Just added value: " << x << endl;
      return;
    }

    TreeChunk *slow, *fast;  //slow will be one step behind fast so that fast can fall off the structure
                            //while slow is still on the previous node
    slow = fast = root;     //sets slow and fast to start at root

    while (fast != NULL){
      if (x < fast->data){
        slow = fast;
        fast = fast->left;
      }
      else if (x > fast->data){
        slow = fast;
        fast = fast->right;
      }
      else {
        cout << "We do not allow duplicates." << endl;
        return;
      }
    }
    if (x < slow->data){
      slow->left = new TreeChunk;
      slow->left->data = x;
    }
    else{
      slow->right = new TreeChunk;
      slow->right->data = x;
    }
    cout << "Successfully added: " << x << endl;
  }
  //2. Search function
  bool search(int key, TreeChunk *start){

    //anchor value
    if (start == NULL){
      cout << "Could not find the value you are looking for." << endl;
      return false;
    }
    //recursive step
    else {
      if( key == start->data){
        cout << "Success! Value found in the tree" << endl;
        return true;
      }
      if (key < start->data){
        search(key, start->left);
      }
      else {
        search(key, start->right);
      }
    }
  }
  //3. Display function
  void preorder(TreeChunk *start){
    //anchor value
    if(start ==NULL){
      return;
    }
    else {
      //root, left, right
      cout << start->data << endl;
      preorder(start->left);
      preorder(start->right);

    }
  }

  void postorder(TreeChunk *start){
    //anchor value
    if(start ==NULL){
      return;
    }
    else {
      //left, right, root
      postorder(start->left);
      postorder(start->right);
      cout << start->data << endl;
    }
  }
  void inorder(TreeChunk *start){
    if(start ==NULL){
      return;
    }
    else {
      //left, root, right
      inorder(start->left);
      cout << start->data << endl;
      inorder(start->right);
    }
  }
  //4. Deleting function
  struct TreeChunk* minRightSubtree(TreeChunk* node) {
    struct TreeChunk* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct TreeChunk* caseIII(struct TreeChunk* root, int key){
    if (root == NULL) {
      return root;
    }
    if (key > root->data){
        root->right = caseIII(root->right, key);
    }
    else if (key < root->data){
        root->left = caseIII(root->left, key);
    }
    else
    {
        if (root->left == NULL)  {
            struct TreeChunk *helper = root->right;
            return helper;
        }
        else if (root->right == NULL){
            struct TreeChunk *helper = root->left;
            return helper;
        }
        struct TreeChunk* helper = minRightSubtree(root->right);
        root->data = helper->data;
        root->right = caseIII(root->right, helper->data);
    }
    return root;
}

  void deleteNode(int key){

    //empty tree test
    if (root == NULL) {
      cout << "Empty tree, nothing to delete" << endl;
      return;
    }
    //step 1: Search and find that node
    TreeChunk *slow, *fast, *replace, *follow;
    slow = fast = root;

    while(fast != NULL && fast->data != key){
      //keep going left or right
      if(key < fast->data){
        slow = fast;
        fast = fast->left;
      }
      else{
        slow = fast;
        fast = fast->right;
      }
    }
    if (fast == NULL){
      cout << "This node does not exist in this tree: " << key << endl;
      return;
    }

    //step 2: Begin to classify the Case for delete (1, 2, or 3)
    cout << "Found the node, now trying to classify the type of delete" << endl;
    //case 1: both the left and right pointers have no children
    if(fast->right == NULL && fast->left ==NULL){
      cout << "Looks like a Case-I delete for " << key << endl;
      if (slow->right == fast){
        //the node is to the right
        slow->right = NULL;
        cout << "About to delete: " << fast->data << endl;
      }
      else{
        //the node is to the left
        slow->left = NULL;
        cout << "About to delete: " << fast->data << endl;
        delete fast;
      }
    }
    //case 2: only the left or the right have a child, not both
    else if((fast->right == NULL && fast->left != NULL) || (fast->right != NULL && fast->left == NULL)){
      cout << "Case-II delete for " << key << endl;
      if(fast->left != NULL){
        if (slow->left == fast){
          //fast is to the left of slow, and the lone child is to the left of fast
          slow->left = fast->left;
          cout << "About to delete: " << fast->data << endl;
          delete fast;
        }
        else if(slow->right == fast){
          //fast is to the right of slow, and the lone child is to the left of fast
          slow->right = fast->left;
          cout << "About to delete: " << fast->data << endl;
          delete fast;
        }
      }
      if (fast->right != NULL){
          if (slow->left == fast){
            //fast is to the left of slow, and the lone child is to the right of fast
            slow->left = fast->right;
            cout << "About to delete: " << fast->data << endl;
            delete fast;
          }
          if (slow->right == fast){
            //fast is to the right of fast, and the lone child is to the right of fast
            slow->right = fast->right;
            cout << "About to delete: " << fast->data << endl;
            delete fast;
          }
      }

    }
    //Case 3: there are two children for the node
    else{
      cout << "This is a Case-III delete for " << key << endl;
      caseIII(root, key);

    }

  }
};


int main() {
  BST myTree;

//buiilding the tree iin code
/*
  myTree.add(30);
  myTree.add(15);
  myTree.add(60);
  myTree.add(7);
  myTree.add(22);
  myTree.add(17);
  myTree.add(27);
  myTree.add(45);
  myTree.add(75);
  myTree.add(80);
*/
  //search for a few values
  //successful search
  /*
  if (myTree.search(17, myTree.root)){
    cout << "Success" << endl;
  }
  else {
    cout << "Could not find value"<< endl;
  }

  //unsuccesssful test
  if (myTree.search(9999, myTree.root)){
    cout << "Guess what, 9999 was found!" << endl;
  }
  else {
    cout << "Could not find value"<< endl;
  }

  cout << "============================== " << endl;
//  myTree.preorder(myTree.root);
//  myTree.postorder(myTree.root);
  myTree.inorder(myTree.root);
  cout << "==============================" << endl;
*/
//  myTree.deleteNode(17);
//  myTree.deleteNode(75);

//  myTree.preorder(myTree.root);

//  cout << "=================================" << endl;
//
//  myTree.deleteNode(60);
//  myTree.deleteNode(1599875);
//  myTree.preorder(myTree.root);



  int choice, value, key;

  while(1) {
    cout << "Press 1 to work within the Binary Search Tree." << endl;
    cout << "Press anything else to quit." << endl;
    cin >> choice;
    switch(choice) {
      case 1 :
               while(1){
                 cout << "Press 1 to insert a number into the tree." << endl;
                 cout << "Press 2 to search for a value within the tree." << endl;
                 cout << "Press 3 to do a preorder tree traversals." << endl;
                 cout << "Press 4 to do a postorder tree traversals." << endl;
                 cout << "Press 5 to do an inorder tree traversals." << endl;
                 cout << "Press 6 to delete a node." << endl;
                 cout << "Press anything else to quit." << endl;
                 cin >> value;

                 switch(value){
                   case 1 :
                            cout << "What number would you like add to the tree?" << endl;
                            cin >> value;
                            myTree.add(value);
                            break;
                   case 2 :
                            cout << "What value are you looking to search for within the tree?" << endl;
                            cin >> key;
                            myTree.search(key, myTree.root);
                            break;
                   case 3 :

                            cout << "This is preoder traversal." << endl;
                            myTree.preorder(myTree.root);
                            break;
                  case 4:
                            cout << "This is postorder traversal." << endl;
                            myTree.postorder(myTree.root);
                            break;
                  case 5:
                            cout << "This is inorder traversal." << endl;
                            myTree.inorder(myTree.root);
                            break;

                  case 6:
                            cout << "What node would you like to delete?" << endl;
                            cin >> key;
                            myTree.deleteNode(key);
                            break;
                  default:
                            exit(1);



                 }

              }


          default:
                          exit(1);
          }
    }
    return 0;
  }
