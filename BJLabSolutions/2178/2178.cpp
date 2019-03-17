#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
using namespace std;

struct Point{
  int x;
  int y;
};

int N, M;
char maze[100][100];
int depth[100][100];
bool visited[100][100];
int dx[4] = { 0, -1, 1, 0};
int dy[4] = { -1, 0, 0, 1};
queue<Point> q;

int find_min_way(Point s, Point e){

  q.push(s);
  visited[s.y][s.x] = true;
  depth[s.y][s.x] = 1;

  while(!q.empty()){
    Point cur = q.front();
    q.pop();

    for(int d=0; d<4; d++){
      Point next;
      next.x = cur.x + dx[d];
      next.y = cur.y + dy[d];

      if(maze[next.y][next.x] == '1' & next.x<M & next.y<N & next.x>=0 & next.y >=0 & !visited[next.y][next.x]){
        visited[next.y][next.x] = true;
        depth[next.y][next.x] = depth[cur.y][cur.x] + 1;
        q.push(next);
      }

    }

  }

  return depth[e.y][e.x];
}

int main(){

  cin >> N >> M;
  if(DEBUG) cout<< N << ", " << M <<"\n";


  char tmp;
  for(int n=0; n<N; n++){
    for(int m=0; m<M; m++){
      cin>>tmp;
      maze[n][m] = tmp;
      visited[n][m] = false;
    }
  }

  if(DEBUG){
    for(int n=0; n<N; n++){
      for(int m=0; m<M; m++){
        cout<< maze[n][m] << " ";
      }
      cout<<"\n";
    }
  }


  Point start;
  start.x = 0;
  start.y = 0;

  Point end;
  end.x = M-1;
  end.y = N-1;

  int dist = find_min_way(start, end);

  cout<<dist<<"\n";
 
  return 0;

}
