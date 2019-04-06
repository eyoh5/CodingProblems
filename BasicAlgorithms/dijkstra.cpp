#include <iostream>

// dijkstra with weighted graph

using namespace std;

struct Node{
    int value;
    int cost;
    Node* next;
}typedef Node;

struct List{
    Node* head;
}typedef List;
class Graph{
private:
    List* _g;
    int n_vertex;
public:
    Graph(int n);
    ~Graph();
    void addCon(int p, int c, int cost);
    void print();
    void dijkstra(int start, int* dist);
}typedef Graph;

Graph::Graph(int n) {
    n_vertex = n+1;
    _g = new List[n_vertex];
    for(int i=0; i<n_vertex;i++){
        _g[i].head = NULL;
    }
}

Graph::~Graph(){}

void Graph::addCon(int p, int c, int cost) {

    Node* newNode = new Node;
    newNode->value=c;
    newNode->next = NULL;
    newNode->cost = cost;

    Node* it = _g[p].head;
    if(it == NULL) {
        _g[p].head = newNode;
        return;
    }

    while(it->next != NULL){
        it = it->next;
    }
    it->next = newNode;
}

void Graph::print(){

    for(int i=0; i<n_vertex; i++){
        cout<<i<<" : ";
        Node* it = _g[i].head;
        while(it!=NULL){
            cout<<it->value<<" ";
            it = it->next;
        }
        cout<<"\n";
    }
}

void Graph::dijkstra(int start, int* dist) {

    int visited[n_vertex];

    for(int i=0; i<n_vertex; i++){
        visited[i] = 0;
        dist[i] = 1000000;
    }

    dist[start] = 0;

    for(int i=1; i<n_vertex; i++) {
        if(visited[i] == 0) {
            int min = 1000000;
            int min_v = 0;
            for (int j = 1; j < n_vertex; j++) {
                if (min > dist[j] && visited[j] == 0) {
                    min = dist[j];
                    min_v = j;
                }
            }

            visited[min_v] = 1;

            Node *it = _g[min_v].head;
            while (it != NULL) {
                if (dist[it->value] > dist[min_v] + it->cost) {
                    dist[it->value] = dist[min_v] + it->cost;
                }
                it = it->next;
            }
        }
    }

}

int T, N, S, E, M;

int main(){
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> N >> S >> E;
        cin >> M;

        Graph graph(N);
        for(int m=0; m<M; m++) {
            int p, c, cost;
            cin >> p >> c >> cost;
            graph.addCon(p,c, cost);
        }

        int dist[N+1];
        graph.dijkstra(S, &dist[0]);
        cout<<"#"<<t+1<<" "<<dist[E]<<"\n";
        for(int i=1; i<N+1; i++){
            cout<<dist[i]<<" ";
        }

    }

    return 0;

}