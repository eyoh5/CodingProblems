#include <iostream>

struct ListNode{
    ListNode* prev;
    ListNode* next;
    int data;
}typedef ListNode;

class List{
private:
    ListNode* head;
    ListNode* tail;
    int num_node=0;
public:
    List();
    ~List();
    void addNode(int value);
    void removeNode(int value);
    ListNode* getHead();
    int getLength();
};

List::List(){
    head = tail = NULL;
}

List::~List(){
    ListNode* it = head;
    while(it != NULL){
        delete it;
        it = it->next;
    }
}

void List::addNode(int value){

    ListNode* newNode = new ListNode;
    newNode->data = value;

    if(head == NULL && tail == NULL){
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }

    else{
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    num_node++;
}

void List::removeNode(int value){

    ListNode* it = head;
    while(it != NULL){
        if(it->data == value){

            if(it == head){
                (it->next)->prev = NULL;
                head = it->next;
                delete it;
            }
            else if(it == tail){
                (it->prev)->next = NULL;
                tail = it->prev;
                delete it;
            }
            else {
                //remove
                (it->prev)->next = it->next;
                (it->next)->prev = it->prev;
                delete it;
            }

            num_node--;
            break;
        }
        it = it->next;
    }
}

ListNode* List::getHead(){
    return head;
}

int List::getLength() {
    return num_node;
}

int T, N;

using namespace std;

int main(){
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> N;

        List list;
        for(int n=0; n<N; n++){
            int tmp;
            cin >> tmp;
            list.addNode(tmp);
        }

        cout<<"#"<<t+1<<" ";
        ListNode* it = list.getHead();
        while(list.getLength() > 2){
            list.removeNode(it->data);
            it = it->next;
        }

        it = list.getHead();
        while(it != NULL){
            cout<<it->data<<" ";
            it = it->next;
        }
        cout<<"\n";
    }
    return 0;
}
