#include <iostream>

// DFS - recursion

using namespace std;

int T, N;

void DFS(int map[][30], int* visited, int start){

    cout<<start<<" ";
    for(int i=1; i<=N; i++){
        if(visited[i]==0 && map[start][i] != 0) {
            visited[i] = 1;
            DFS(map, visited, i);
        }

    }
}

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        int start;
        cin >> start;

        int map[30][30];
        int visited[30];
        for(int i=0; i<30; i++){ // map init
            for(int j=0; j<30;j++){
                map[i][j] = 0;
            }
            visited[i] = 0;
        }

        int p, c;
        cin >> p >> c;
        while(p!=-1 && c!=-1){
            map[p][c] = map[c][p] = 1;
            cin >> p >> c;
        }

        cout<<"#"<<t+1<<" ";
        visited[start] = 1;
        DFS(map, &visited[0], start);
        cout<<"\n";
    }
}

