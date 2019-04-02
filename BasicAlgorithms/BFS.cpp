#include <iostream>
#include <queue>

// BFS - queue

using namespace std;

queue<int> q;
int T, N;

void BFS(int map[][30], int* visited, int start){

    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {

        int j = q.front();
        q.pop();
        cout<<j<<" ";

        for (int i = 1; i <= N; i++) {
            if (map[j][i] != 0 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

}

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        cout<<"N : "<<N<<"\n";
        int start;
        cin >> start;

        int map[30][30];
        int visited[N+1];
        for(int i=0; i<N+1; i++){
            for(int j=0; j<N+1; j++){
                map[i][j] = 0;
            }
            visited[i] = 0;
        }

        int p,c;
        cin >> p >> c;
        while(p!=-1 && c!=-1){
            map[p][c] = map[c][p] = 1;
            cin >> p >> c;
        }

        cout<<"#"<<t+1<<" ";
        BFS(map, &visited[0], start);
        cout<<"\n";
    }

    return 0;

}