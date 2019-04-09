#include <iostream>

// When you use recursion
// the web server resulted in Runtime error

using namespace std;

struct warmHole{
    int wh_num;
    int x;
    int y;
}typedef warmHole;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;
int dx[4] = {0, +1, 0, -1};
int dy[4] = {-1, 0, +1, 0};

int map[102][102];
warmHole warmholes[10];
int next_dir[5][4] = { {DOWN, LEFT, RIGHT, UP},
                      {RIGHT, LEFT, UP, DOWN},
                      {LEFT, DOWN, UP, RIGHT},
                      {DOWN, UP, LEFT, RIGHT},
                      {DOWN, LEFT, UP, RIGHT}};

int start_x;
int start_y;
int T, N, loc_score;


warmHole findWH(int p_x, int p_y, int wh){
    for(int i=0; i<10; i++){
        if(warmholes[i].x != p_x && warmholes[i].y != p_y && warmholes[i].wh_num == wh){
            return warmholes[i];
        }
    }
}

void run(int y, int x, int d, bool depth){

    if(depth != true && y==start_y && x==start_x) return;
    if(map[y][x] == -1) return; //black hole

    int d_n, x_n, y_n;
    if(x == N || x == -1 || y == N || y == -1){//wall
        loc_score++;
        if(x == N) {d_n = LEFT; x_n = x-1; y_n= y; }
        else if (x == -1) {d_n = RIGHT ; x_n = x+1; y_n = y;}

        if(y == N) {d_n = UP; x_n = x; y_n = y-1;}
        else if (y == -1) {d_n = DOWN; x_n = x; y_n = y+1;}
    }
    else if(map[y][x] < 6 && 1 <= map[y][x]){ // block
        loc_score++;
        d_n = next_dir[map[y][x]-1][d];
        x_n = x + dx[d_n];
        y_n = y + dy[d_n];
    }
    else if(map[y][x] >= 6 && map[y][x] <=10){ // warm hole
        warmHole pair = findWH(x, y, map[y][x]);
        d_n = d;
        x_n = pair.x + dx[d_n];
        y_n = pair.y + dy[d_n];
    }
    else{ // empty
        d_n = d;
        x_n = x + dx[d];
        y_n = y + dy[d];
    }

    run(y_n, x_n, d_n, false);

}

int main(){
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> N;
        int num_wh=0;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];

                if(map[i][j] >=6 && map[i][j] <=10){ // warmhole
                    warmholes[num_wh].wh_num = map[i][j];
                    warmholes[num_wh].x = j;
                    warmholes[num_wh].y = i;
                    num_wh++;
                }
            }
        }

        int ans=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] ==0) {
                    for (int k = 0; k < 4; k++) {
                        start_x = j;
                        start_y = i;
                        loc_score = 0;
                        run(i, j, k, true);

                        if (loc_score > ans) ans = loc_score;
                    }
                }
            }
        }

        cout<<"#"<<t+1<<" "<<ans<<"\n";
    }

    return 0;
}
