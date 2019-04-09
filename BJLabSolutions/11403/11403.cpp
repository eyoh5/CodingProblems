#include <iostream>

// time over

using namespace std;

class Queue{
private:
    int _q[100];
    int head;
    int tail;
public:
    Queue();
    ~Queue();
    bool empty();
    bool full();
    int pop();
    void push(int val);
}typedef Queue;

Queue::Queue(){
    head = tail = 0;
};

Queue::~Queue(){}

bool Queue::empty() {
    return head == tail;
}

bool Queue::full() {
    return ((tail+1)%100) == head;
}

int Queue::pop() {
    int res = _q[head++];
    if(head == 100) head=0;
    return res;
}

void Queue::push(int val){
    _q[tail++] = val;
    if(tail == 100) tail=0;

}

int graph[100][100];
int ans[100][100];

Queue q;

int N;


void bfs(int from){

    q.push(from);

    while(!q.empty()) {
        int tmp = q.pop();
        for (int i = 0; i < N; i++) {
            if (graph[tmp][i] == 1) {
                ans[from][i]=1;
                if(i==from) continue;
                q.push(i);
            }
        }
    }

}


void Solve(){

    for(int i=0; i<N; i++){
           bfs(i);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];
            ans[i][j] = 0;
        }
    }

    Solve();

    return 0;
}
