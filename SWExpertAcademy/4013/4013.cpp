#include <iostream>

using namespace std;

int magnets[5][8];
int arrows[5]; // arrow ptr. of each mangets
int T, K;

void rotate(int mg_id, int r_dir, int* visited){

    visited[mg_id] = 1;

    if(mg_id+1<5 && magnets[mg_id][(arrows[mg_id]+2)%8] != magnets[mg_id+1][(arrows[mg_id+1]+6)%8] && visited[mg_id+1] ==0){ // right neighbor should rotate in the other dir.
        rotate(mg_id+1, (r_dir*(-1)), visited);
    }
    if(mg_id-1>0 && magnets[mg_id][(arrows[mg_id]+6)%8] != magnets[mg_id-1][(arrows[mg_id-1]+2)%8] && visited[mg_id-1] == 0){ // left neighbor should rotate in the other dir.
        rotate(mg_id-1, (r_dir*(-1)), visited);
    }

    arrows[mg_id] = (r_dir == 1) ? (arrows[mg_id]+7)%8 : (arrows[mg_id]+1)%8;


}

int calc_score(){

    int res =0;
    for(int m=1; m<5;m++){
        if( magnets[m][arrows[m]] == 1) res += (1<<(m-1));
    }
    return res;
}

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> K;
        for(int m=1; m<5; m++){
            for(int i=0; i<8; i++){
                cin >> magnets[m][i];
            }
            arrows[m] = 0; // arrow ptr init.
        }

        for(int k=0; k<K; k++){
            int magnet_id, rot_dir;
            cin >> magnet_id >> rot_dir;
            int visited[5];
            for(int i=0; i<5; i++) visited[i] =0;
            rotate(magnet_id, rot_dir, &visited[0]);
        }

        cout<<"#"<<t+1<<" "<<calc_score()<<"\n";
    }
}