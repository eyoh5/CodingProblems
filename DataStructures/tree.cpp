#include <iostream>
#define DEBUG 1

using namespace std;

/* What is tree? Why tree?

Conditions for the tree

  - key values of all the node in a tree are different each other
  - On the left side of a node, there are only nodes with key value smaller than the node's key value.
  - On the right side of a node, there are only nodes with key value larger than the node's key value.


The tree data structure provides O(n) ~ O(logn) search time.

*/

struct Node{
    int key;
    Node* left;
    Node* right;
} typedef Node;

class Tree{
private:
    Node* root;

public:
    Tree();
    ~Tree();
    Node* insert(int value);
    Node* _insert(int value, Node* current);
    Node* search(int value);
    Node* _search(int value, Node* current);
    bool remove(Node* current, int value);
    void inorder();
    void _inorder(Node* current);
    void preorder();
    void _preorder(Node* current);
    void postorder();
    void _postorder(Node* current);
};

Tree::Tree(){
    root = NULL;
}

Tree::~Tree() {

}

Node* Tree::insert(int value){

    if(root != NULL){
        return _insert(value, root);
    }
    else{
        root = new Node;
        root->left = NULL;
        root->right = NULL;
        root->key = value;
        if(DEBUG) cout<<"Tree::insert>> "<<root->key<<" was added\n";
        return root;
    }
}

Node* Tree::_insert(int value, Node* current){

    if(current == NULL){
        current = new Node;
        current->left = NULL;
        current->right = NULL;
        current->key = value;
        if(DEBUG) cout<<"Tree::insert>> "<<current->key<<" was added\n";
        return current;
    }
    else if (current->key < value){
        current->right = _insert(value, current->right); return current;
    }
    else if (current->key > value){
        current->left = _insert(value, current->left); return current;
    }


    // already exist
    if(DEBUG) cout<<"Tree::insert>> "<<value<<" already exist\n";
    return current;

}

Node* Tree::search(int value){

    return _search(value, root);

}

Node* Tree::_search(int value, Node* current){

    if(current->key == value ) {cout<<"Tree::search>> "<<current->key<<" was founded\n"; return current;}
    else if (current->key < value ) return _search(value, current->right);
    else if (current->key > value ) return _search(value, current->left);

    // doesn' exist
    if(DEBUG) cout<<"Tree::search>> "<<value<<" is not exist\n";
    return NULL;
}

bool Tree::remove(Node* current, int value){

    return true;
}

void Tree::inorder(){
    _inorder(root);
}

void Tree::_inorder(Node* current){

    if( current!=NULL ){
        _inorder(current->left);
        cout<<"Tree::inorder>> " << current->key <<"\n";
        _inorder(current->right);

    }

}

void Tree::preorder(){
    _preorder(root);
}

void Tree::_preorder(Node* current){

    if(current != NULL){
        cout<<"Tree::preorder>> " << current->key <<"\n";
        _preorder(current->left);
        _preorder(current->right);
    }
}

void Tree::postorder(){
    _postorder(root);
}

void Tree::_postorder(Node* current){

    if(current != NULL){
        _postorder(current->left);
        _postorder(current->right);
        cout<<"Tree::postorder>> " << current->key <<"\n";
    }
}

int main() {

    Tree tree;

    tree.insert(4);
    tree.insert(1);
    tree.insert(12);
    tree.insert(4);
    tree.insert(5);

    cout<<"Search 4 : "<< tree.search(4)->key <<"\n";
    cout<<"Search 1 : "<< tree.search(1)->key <<"\n";
    cout<<"Search 12 : "<< tree.search(12)->key <<"\n";

    tree.inorder();
    tree.preorder();
    tree.postorder();

    return 0;
}
