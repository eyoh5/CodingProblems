#include <iostream>

// success 41/50 test case 

using namespace std;

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT= 3;
int dx[4] = {0, -1, 0, 1}; // UP, LEFT, DOWN, RIGHT
int dy[4] = {-1, 0, 1, 0};

int T, N, K, M;


struct ListNode{
    int x;
    int y;
    int num_c;
    int dir;
    ListNode* prev;
    ListNode* next;
}typedef ListNode;

class List{
private:
    ListNode* head;
    ListNode* tail;
    int num_nodes;
public:
    List();
    ~List();
    void addNode(int x, int y, int num_c, int dir);
    void move();
    void merge();
    int giveAns();
};

List::List(){
    num_nodes =0;
    head = tail = NULL;
}

List::~List(){}

void List::addNode(int x, int y, int num_c, int dir){
    ListNode* newNode = new ListNode;
    newNode->x = x;
    newNode->y = y;
    newNode->num_c = num_c;
    newNode->dir = dir;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev=NULL;
        head = tail = newNode;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    num_nodes++;
}

void List::move(){
    ListNode* it=head;

    while(it!=NULL){
        it->x += dx[it->dir];
        it->y += dy[it->dir];

        if(it->x == 0 || it->x == N-1 || it->y == 0 || it->y == N-1){
            it->num_c = (it->num_c)/2;
            it->dir = (it->dir + 2) % 4 ; // reverse direction
        }

        it = it->next;
    }
}

void List::merge(){
    ListNode* i = head;
    while(i != NULL){
        ListNode* j = i->next;
        while( j!=NULL) {
            ListNode *tmp = j;
            if ( (i->x == j->x) && (i->y == j->y) ) {// j && i -th colonies located at the same point

                if(i->x == 2 && i->y ==5);

                if (i->num_c > j->num_c) {
                    i->num_c += j->num_c;
                } else { // i->num_c < j->num_c
                    i->num_c += j->num_c;
                    i->dir = j->dir;
                }

                //remove j-th node
                if (j == head) {
                    head = j->next;
                    j->next->prev = NULL;
                    delete j;
                } else if (j == tail) {
                    j->prev->next = NULL;
                    tail = j->prev;
                    delete j;
                } else {
                    j->prev->next = j->next;
                    j->next->prev = j->prev;
                    delete j;
                }
            }
            j = tmp->next;
        }
        i = i->next;
    }
}

int List::giveAns() {
    ListNode* it = head;
    int ans =0;
    while(it != NULL){
        ans += it->num_c;
        it = it->next;
    }
    return ans;
}
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N >> M >> K;
        List groups;
        for(int k=0; k<K; k++){
            int x_in, y_in, num_in, dir_in;
            cin >> y_in >> x_in >> num_in >> dir_in;
            switch(dir_in){
                case(1): dir_in = UP; break;
                case(2): dir_in = DOWN; break;
                case(3): dir_in = LEFT; break;
                case(4): dir_in = RIGHT; break;
            }
            groups.addNode(x_in, y_in, num_in, dir_in);
        }

        for(int m=0; m<M; m++){
            groups.move();
            groups.merge();
        }

        cout<<"#"<<t+1<<" "<<groups.giveAns()<<"\n";

    }

    return 0;
}
