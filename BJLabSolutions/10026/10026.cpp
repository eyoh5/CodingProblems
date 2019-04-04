#include <iostream>

using namespace std;

int map[100][100];
bool visited[100][100];

int N;
int ans_norm;
int ans_odd;

int dx[4] = {-1, +1, 0, 0}; // left, right, up, down
int dy[4] = {0, 0, -1, +1};

void GtoR(int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if (map[i][j] == 1) map[i][j] =0;
        }
    }
}

void DFS(int x, int y, int c){

    visited[y][x] = true;

    for(int d=0; d<4; d++){
        if(visited[y+dy[d]][x+dx[d]] == false && y+dy[d] >=0 && y+dy[d] <N && x+dx[d] >=0 && x+dx[d]<N){ // boundary condition
            if(c == map[y+dy[d]][x+dx[d]]) {
                DFS(x + dx[d], y + dy[d], map[y + dy[d]][x + dx[d]]);
            }
        }
    }
}

int main(){

    cin >> N;

    // read map info. & init. visited
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char tmp;
            cin >> tmp;
            switch(tmp){
                case('R') : map[i][j] = 0; break;
                case('G') : map[i][j] = 1; break;
                case('B') : map[i][j] = 2; break;
            }
            visited[i][j] = false;
        }
    }

    ans_norm = ans_odd = 0; // ans init.

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]) {
                DFS(j, i, map[i][j]);
                ans_norm++;
            }
        }
    }

    GtoR(N);
    for(int i=0; i<N; i++){ // visited init.
        for(int j=0; j<N; j++){
            visited[i][j] = false;
        }
    }


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]) {
                DFS(j, i, map[i][j]);
                ans_odd++;
            }
        }
    }

    cout<<ans_norm<<" "<<ans_odd<<"\n";

    return 0;
}