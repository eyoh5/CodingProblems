#include <iostream>

using namespace std;

bool map[100][100]; // it acts as a visited flag also.
int M, N, K;
int n_regions;
int regions[100];
int dx[4] = {-1, 0, +1, 0}; // LEFT, DOWN, RIGHT, UP
int dy[4] = {0, -1, 0, +1};

void dfs(int y, int x, int* size){
    *size = *size +1;
    map[y][x] = true;
    for(int d=0; d<4; d++){
        if(map[y+dy[d]][x+dx[d]] == false && y+dy[d]>=0 && y+dy[d]<M && x+dx[d]>=0 && x+dx[d]<N) {
            dfs(y + dy[d], x + dx[d], size);
        }
    }
}

void sort(){ // insertion sort
    for(int i=1; i<n_regions; i++){
        int tmp = regions[i];
        int j=i-1;
        while(tmp < regions[j] && j>=0){
            regions[j+1] = regions[j];
            j--;
        }
        regions[j+1]=tmp;
    }
}
int main(){

    cin >> M >> N >> K;

    for(int k=0; k<K; k++){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        for(int i=sy; i<ey; i++){
            for(int j=sx; j<ex; j++){
                map[i][j] = 1;
            }
        }
    }

    n_regions = 0; // init. ans

    for(int m=0; m<M; m++){
        for(int n=0; n<N; n++){
            if(map[m][n] == false) {
                int size =0;
                dfs(m, n, &size);
                regions[n_regions++] =size;
            }
        }
    }

    // print ans.
    sort();
    cout<<n_regions<<"\n";
    for(int i=0; i<n_regions; i++){
        cout<<regions[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
