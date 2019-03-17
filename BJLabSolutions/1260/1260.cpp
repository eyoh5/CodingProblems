#include<iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int N, M, S;
bool* visited_bfs;
bool* visited_dfs;
vector< list<int> > graph;
queue<int> q;

void DFS(int u){

  cout<<u<<" ";
  visited_dfs[u] = true;

  for(list<int>::iterator it=graph[u].begin(); it != graph[u].end(); it++){
    if(visited_dfs[*it] == false) DFS(*it);
  
  }

}

void BFS(){

  q.push(S);
  visited_bfs[S] = true;


  while(!q.empty()){
    int u = q.front();
    q.pop();
    cout<<u<<" ";

    for(list<int>::iterator it = graph[u].begin(); it != graph[u].end() ; it++){
      if(visited_bfs[*it] == false) {
        q.push(*it);
        visited_bfs[*it] = true;
      }
    }

  }

}

int main(){

  cin>> N >> M >> S;

  // Initialization
  graph.resize(N+1);
  
  visited_dfs = new bool[N+1];
  visited_bfs = new bool[N+1];

  for(int n=0; n<N+1; n++) visited_dfs[n] = visited_bfs[n] = false;

  for(int m=0; m<M; m++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // sorting
  for(int n=0; n<N+1; n++){
    graph[n].sort();
  }


  // DFS
  DFS(S);

  cout<<"\n";
  // BFS 
  BFS();

  return 0;
}

