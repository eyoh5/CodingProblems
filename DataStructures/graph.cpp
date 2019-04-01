#include<iostream>

// Graph

using namespace std;

struct ListNode{
    ListNode* prev;
    ListNode* next;
    int data;
}typedef ListNode;

class List{
private:
    ListNode* head;
    ListNode* tail;
    int num_node;
public:
    List();
    ~List();
    void addNode(int value);
    void removeNode(int value);
    ListNode* getHead();
};

List::List(){
    head = tail = NULL;
}

List::~List(){}

ListNode* List::getHead(){ return head; }

void List::addNode(int value){
    ListNode* newNode = new ListNode;
    newNode->data = value;
    if(head==NULL && tail==NULL){
        head = newNode;
        tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }

    num_node++;
}

void List::removeNode(int value) {
    ListNode* it = head;
    while(it != NULL){
        if(it->data == value){

            if(it==head){
                (it->next)->prev = NULL;
                head = it->next;
                delete it;
            }
            else if(it==tail){
                (it->prev)->next = NULL;
                tail = it->prev;
                delete it;
            }
            else{
                (it->next)->prev = it->prev;
                (it->prev)->next = it->next;
                delete it;
            }

            num_node--;
        }
    }
}

class Graph{
private:
    List* ListAry;
    int num_vertex;
public:
    Graph(int n_v);
    ~Graph();
    void addEdge(int parent, int child);
    void print(int parent);
};

Graph::Graph(int n_v) {
    num_vertex = n_v;
    ListAry = new List[num_vertex];
}

Graph::~Graph() {}

void Graph::addEdge(int parent, int child) {
    ListAry[parent].addNode(child);
    ListAry[child].addNode(parent);
}

void Graph::print(int parent){
    ListNode* it = ListAry[parent].getHead();
    while(it !=NULL){
        cout<<it->data<<" ";
        it =  it->next;
    }
    cout<<"\n";
}

int T, V, E, Q;

int main(){
    cin >> T;

    for(int t=0; t<T; t++){

        cin >> V >> E >> Q;
        Graph graph(V);
        for(int e=0; e<E; e++){
            int p, c;
            cin >> p >> c;
            graph.addEdge(p, c);
        }


        cout<<"#"<<t+1<<"\n";
        for(int q=0; q<Q; q++){
            int p;
            cin >> p;
            graph.print(p);
        }
    }


    return 0;
}