#include <iostream>

using namespace std;

const int MAX_TREE=100;
const int NUM_CHILD=2;

struct TreeNode{
    int parent;
    int child[NUM_CHILD];
}typedef TreeNode;

class Tree{
private:
    TreeNode _tree[MAX_TREE];
    int num_vertex;
public:
    Tree(int n_v);
    ~Tree();
    void addNode(int parent, int child);
    int getRoot();
    void preOrder(int root);
    void postOrder(int root);
    void inOrder(int root);
}typedef Tree;

Tree::Tree(int n_v){
    for(int i=0;i<MAX_TREE;i++){
        _tree[i].parent =-1;
        for(int j=0; j<NUM_CHILD; j++){
            _tree[i].child[j]=-1;
        }
    }

    num_vertex = n_v;
}

Tree::~Tree(){}

void Tree::addNode(int parent, int child){
    for(int j=0; j<NUM_CHILD; j++){
        if( _tree[parent].child[j] == -1) {
            _tree[parent].child[j] = child;
            break;
        }
    }
    _tree[child].parent = parent;

}

int Tree::getRoot(){
    for(int i=1; i<num_vertex; i++){
        if(_tree[i].parent == - 1) return i;
    }

    return -1;
}

void Tree::preOrder(int root){

    cout<<root<<" ";

    for(int j=0; j<NUM_CHILD; j++){
        if(_tree[root].child[j] != -1) preOrder(_tree[root].child[j]);
    }
}

void Tree::postOrder(int root){

    for(int j=0; j<NUM_CHILD; j++){
        if(_tree[root].child[j] != -1) postOrder(_tree[root].child[j]);
    }
    cout<<root<<" ";
}

void Tree::inOrder(int root){

    for(int j=0; j<NUM_CHILD; j++){
        if( _tree[root].child[j] != -1) inOrder(_tree[root].child[j]);
        if(j==0) cout<<root<<" ";
    }
}

int T, N, E;

int main(){

    cin >> T;

    for(int t=0; t<T; t++){
        cin >> N >> E;

        Tree tree(N);
        for(int e=0; e<E; e++){
            int p, c;
            cin >> p >> c;
            tree.addNode(p,c);
        }

        cout<<"#"<<t+1<<" ";
        tree.preOrder(tree.getRoot());
        cout<<"\n";
        tree.postOrder(tree.getRoot());
        cout<<"\n";
        tree.inOrder(tree.getRoot());
        cout<<"\n";
    }

    return 0;
}