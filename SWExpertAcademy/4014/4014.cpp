#include <iostream>

using namespace std;

int map[20][20];
const int ROW = 0;
const int COL = 1;
const int invROW = 2;
const int invCOL = 3;
int dx[4] = {1, 0 , -1, 0}; // ROW, COL, invROW, invCOL
int dy[4] = {0, 1, 0, -1};

int ans;
int T, N, X;

bool check(int i, int dir){
    int x = (dir==0) ? 0 : i;
    int y = (dir==0) ? i : 0;
    int h_prev , h_cur;
    h_prev = h_cur = map[y][x];
    int installed[N];
    for(int k=0; k<N; k++) installed[k] =0;

    while( x<N && y<N ){
        if( (h_prev - h_cur) == 1 ){ // 내려가는 경사로
            int w=0;
            int _x = x;
            int _y = y;
            while(w<X){
                if( (map[_y][_x] != h_cur) || _y<0 || _y>=N || _x<0 || _x>=N || installed[(dir==0)? _x : _y] ==1 ) return false;
                installed[(dir==0)? _x : _y] = 1;
                _x += dx[dir]; _y += dy[dir];
                w++;
            }

        }
        else if( (h_prev - h_cur == -1) ){ // 올라가는 경사로
            int w=0;
            int _x = x+dx[dir+2];
            int _y = y+dy[dir+2];
            while(w<X){
                if( (map[_y][_x] != h_cur-1) || _y<0 || _y>=N || _x<0 || _x>=N || installed[(dir==0)? _x : _y] == 1) return false;
                installed[(dir==0)? _x : _y] = 1;
                _x += dx[dir+2]; _y += dy[dir+2];
                w++;
            }
        }
        else if( h_prev - h_cur == 0) {}
        else return false;

        x = x + dx[dir];
        y = y + dy[dir];
        h_prev = h_cur;
        h_cur = map[y][x];
    }
    return true;
}
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >>N >> X;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) {
                cin >> map[i][j];
            }
        }

        ans =0;
        for(int  i=0; i<N; i++){
            if(check(i, ROW)) ans++;
            if(check(i, COL)) ans++;
        }

        cout<<"#"<<t+1<<" "<<ans<<"\n";
    }

    return 0;
}