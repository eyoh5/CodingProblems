#include <iostream>

// 2117. 홈 방범 서비스

using namespace std;

int map[20][20];
int T, N, M, K_MAX;

int abs(int s){
    if(s<0) return -1*s;
    else return s;
}

bool isRegion(int x, int y, int ox, int oy, int K){
    if( abs(x-ox) + abs(y-oy) < K ) return true;
    else return false;
}

int sim(int ox, int oy, int K){

    int n_house=0;
    for(int c=oy-(K-1); c<=oy+(K-1); c++){
        for(int r=ox-(K-1); r<=ox+(K-1); r++){
            if(isRegion(r, c, ox, oy, K) && c>=0 && c<N && r>=0 && r<N && (map[c][r]==1)){
                 n_house++;
            }
        }
    }

    if( M*n_house < (K*K + (K-1)*(K-1)) ) return 0; // 손해인 경우
    else return n_house; // 손해 아닌 경우

}

int main(){
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> N >> M;
        K_MAX = N;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            }
        }

        int ans =0;
        for(int k=1; k<=K_MAX+5; k++){
            for (int i = 0; i<N; i++){
                for (int j=0; j<N; j++) {
                    int loc_ans = sim(j, i,k);
                    if( loc_ans > ans ) ans = loc_ans;
                }
            }
        }

        cout<<"#"<<t+1<<" "<<ans<<"\n";
    }
    return 0;
}
