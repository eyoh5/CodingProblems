#include <iostream>

  /* What is tree? Why tree?

  Conditions for the tree

    - key values of all the node in a tree are different each other
    - On the left side of a node, there are only nodes with key value smaller than the node's key value.
    - On the right side of a node, there are only nodes with key value larger than the node's key value.


  The tree data structure provides O(n) ~ O(logn) search time.

  */

using namespace std;

#define DEBUG 1 

struct Node{
  int key;
  Node* left;
  Node* right;
} typedef Node;

class Tree{
public:
  Tree();
  ~Tree();
  Node* search(Node* root, int t_key);
  Node* insertNode(Node* root, int key);
  void deleteNode(Node* root, int key);
  Node* getRoot();
  void asscorder(Node* root);
  void descorder(Node* root);

private:
  Node* root;

};

Tree::Tree(){
  root = new Node;
  root->key = -1;
  root->left = NULL;
  root->right = NULL;
}

Tree::~Tree(){
}


Node* Tree::search(Node* root, int t_key){ // find Node with key value 't_key'

  if( (root == NULL) | (t_key == root->key) ) return root;
  else if( t_key < root->key ) return search(root->left, t_key);
  else return search(root->right, t_key);
  
}

Node* Tree::insertNode(Node* root, int key){

  Node* new_node = new Node;
  new_node->key = key;

  if(root == NULL){
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }

  else if( key < root->key ){ 
    root->left = insertNode(root->left, key); return root;
  }
  else if( key > root->key ){
    root->right = insertNode(root->right, key); return root;
  }
  else {// key == root->key 
    cout<<"The node with that key is already exist!\n";
    return NULL;
  }

}


void Tree::deleteNode(Node* root, int key){

  // there are three cases 
  // 1. the target node is leaf node
  //    : just delete it
  // 2. the target node has one sub-tree (left or right) 
  //    : switch the node with the root of the sub-tree
  // 3. the target node has two sub-tree (left and right)
  //    : find the most left node in the right-side tree
  //      

  Node* tmp = search(root, key);

  if( (tmp->left == NULL) & (tmp->right == NULL) ){ // Case 1
    delete tmp;
    tmp = NULL;
  }
  else if( (tmp->left != NULL) & (tmp->right == NULL) ){ // Case 2
    tmp = tmp->left;
  }
  else if( (tmp->right != NULL) & (tmp->left == NULL) ){
    tmp = tmp->right;
  }
  else{ //Case 3
    Node* parent = tmp;
    Node* it = tmp->right;

    while(it->left != NULL){
      parent = it;
      it = it->left;
    }

    Node* swap = it;

    if(it->right != NULL){
      it = it->right;
    }
    else{
      tmp->key = swap->key;
      delete swap;
    }

  }
    

}

Node* Tree::getRoot(){
  return root;
}


void Tree::asscorder(Node* root){

  if(root == NULL) return;

  asscorder(root->left);
  cout<<root->key<<" ";
  asscorder(root->right);

}

void Tree::descorder(Node* root){

  if(root == NULL) return;
  
  descorder(root->right);
  cout<<root->key<<" ";
  descorder(root->left);

}


int main(){

  Tree tree;

  for(int i=0; i<10; i++){
    tree.insertNode(tree.getRoot(), i);
  }

  for(int i=0; i<10; i++){
    cout<<"Find "<< i <<" : "<< (tree.search(tree.getRoot(), i))->key <<"\n";
  }

  cout<<"Print in Asscending order\n";
  tree.asscorder(tree.getRoot());
  cout<<"\n";

  cout<<"Print in Descending order\n";
  tree.descorder(tree.getRoot());
  cout<<"\n";

  for(int i=0; i<10; i++){
    cout<<"Delete "<< i <<"\n";
    tree.deleteNode(tree.getRoot(), i);
  }

  return 0;

}

