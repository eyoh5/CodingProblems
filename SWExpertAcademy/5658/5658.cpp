#include <iostream>
#include <stdlib.h>

using namespace std;

#define DEBUG 1

int T, N, K;
int M; // M = N/4 ; numbers per one section
char numbers[200];

/// Stack
class Stack{
public:
    Stack();
    ~Stack();
    bool isempty();
    bool isfull();
    int size();
    void push(long int value);
    long int pop();
    void print();

private:
    int max_size = 100;
    long int _stack[100];
    int tail=0; // pointing empty space
};

Stack::Stack(){
    tail=0;
    max_size=100;
}

Stack::~Stack(){}

bool Stack::isempty(){
    return tail==0;
}

bool Stack::isfull(){
    return tail==max_size;
}

int Stack::size(){
    return tail;
}

void Stack::push(long int value){
    if(!isfull()){

        if(DEBUG) cout<<"Stack::push>> push "<<value<<"\n";

        _stack[tail] = value;
        tail++;
    }
}

long int Stack::pop(){
    if(!isempty()){

        if(DEBUG) cout<<"Stack::pop>> pop \n";
        return _stack[--tail] ;
    }
}

void Stack::print(){

    for(int s=0; s<size(); s++){
        cout<<"Stack["<<s<<"] : "<<_stack[s]<<"\n";
    }
}

/// Tree class
struct Node{
    long int key;
    Node* left;
    Node* right;
}typedef Node;

class Tree{
public:
    Tree();
    ~Tree();
    Node* insert(long int value);
    Node* _insert(Node* current, long int value);
    Node* search(long int value);
    Node* _search(Node* current, long int value);
    long int giveAns(int target);
    void inorder_rev(Stack& stack, Node* current, int target);
private:
    Node* root;

};

Tree::Tree(){
    root = NULL;
}

Tree::~Tree(){}


Node* Tree::insert(long int value){
    if(root != NULL) return _insert(root, value);
    else{
        root = new Node;
        root->left = NULL;
        root->right = NULL;
        root->key = value;
        return root;
    }

}

Node* Tree::_insert(Node* current, long int value){

    if( current == NULL ){
        if(DEBUG) cout<<"Tree::insert>> key is "<< value<<"\n";
        Node* new_node = new Node;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->key = value;
        return new_node;
    }

    if(value < current->key) {
        current->left = _insert(current->left, value);
        return current;
    }
    else if(value > current->key){
        current->right = _insert(current->right, value);
        return current;
    }

    // already exist
    if(DEBUG) cout<<"Tree::insertNode>> The node with key "<< value <<" is already exist!\n";
    return current;

}

Node* Tree::search(long int value){
    return _search(root, value);
}

Node* Tree::_search(Node* current, long int value){

    if( current->key == value) return current;
    else if( value < current->key) return _search(current->left, value);
    else if( value > current->key) return _search(current->right, value);

    // not exist
    return NULL;

}

long int Tree::giveAns(int target){

    Stack stack;

    inorder_rev(stack, root, target);

    if(DEBUG){
        stack.print();
    }


    return stack.pop();

}

void Tree::inorder_rev(Stack& stack, Node* current, int target){

    if(current != NULL){

        inorder_rev(stack, current->right, target);
        if(stack.size() < target) stack.push(current->key);
        inorder_rev(stack, current->left, target);

    }

}


int main(){

    cin >> T ;

    for(int t=0; t<T; t++){

        cin >> N >> K;
        M = N/4;

        if(DEBUG) cout<<"(T, N, K) : " << T <<" "<< N<<" "<< K<<"\n";

        for(int n=0; n<N; n++){
            cin>>numbers[n];
            if(DEBUG) cout<<"numbers["<<n<<"]: "<<numbers[n];
        }
        if(DEBUG) cout<<"\n";


        // Find all possible combinations
        Tree combinations;
        for(int r=0; r<N; r++){ // rotation
            for(int s=0; s<4; s++){ // 4 sections
                char tmp[M];
                for(int m=0; m<M; m++){ // N numbers of each section
                    int index = (r + s*M + m) % (N);
                    tmp[m] = numbers[index];
                }

                if(DEBUG) cout<<"A possible comb. :"<< tmp <<"\n";
                long int hextodec=0;
                hextodec = strtol(tmp, NULL, 16);
                combinations.insert(hextodec);
            }
        }

        // Find K-th biggest number
        cout<<"#"<<t+1<<" "<<combinations.giveAns(K)<<"\n";


    } // end of testcase loop


}
