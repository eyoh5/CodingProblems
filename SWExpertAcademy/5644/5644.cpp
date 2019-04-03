#include <iostream>

using namespace std;

struct Pos{
    int x;
    int y;
}typedef Pos;

struct BC{
    int ID;
    Pos pos;
    int C; // 충전범위
    int P; // 성능
}typedef BC;

#define STAY 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define DEBUG 0

int dx[5] = {0, 0, 1, 0, -1}; // STAY, UP, RIGHT, DOWN, LEFT
int dy[5] = {0, -1, 0, +1, 0};

int map[11][11]; // 인덱싱은 1~10까지 사용.
int usr_a[101]; // init 상태 0 인덱스에 저장됨.
int usr_b[101];
BC BCs[8];

int T, M, A;

int calcDist(Pos src, Pos dst){
    int r = (src.x <= dst.x ) ? dst.x - src.x : src.x - dst.x;
    int l = (src.y <= dst.y ) ? dst.y - src.y : src.y - dst.y;

    return r + l;
}
void findBCs(Pos pos, int* dst, int* num){

    for(int a=0; a<A; a++){
        if( calcDist(pos, BCs[a].pos) <= BCs[a].C){
            if(DEBUG) cout<<a<<"-th BC is connectable from ("<<pos.x<<","<<pos.y<<") : d = "<<calcDist(pos, BCs[a].pos)<<"\n";
            dst[*num] = a;
            (*num)++;
        }
    }
}

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> M >> A;

        usr_a[0] = 0; // init 상태 STAY
        for(int m=0; m<M; m++){
            cin >> usr_a[m+1];
        }
        usr_b[0] = 0; // init 상태 STAY
        for(int m=0; m<M; m++){
            cin >> usr_b[m+1];
        }

        for(int a=0; a<A; a++){ // 기지국 정보 등록
            int x, y, c, p;
            cin >> x >> y >> c >> p;
            BCs[a].pos.x = x;
            BCs[a].pos.y = y;
            BCs[a].C = c;
            BCs[a].P = p;
            BCs[a].ID = a;
        }

        Pos pos_a, pos_b;
        pos_a.x = pos_a.y = 1; // usr a init. pos
        pos_b.x = pos_b.y = 10; // usr b init. pos

        if(DEBUG){
            cout<<"usr_a : ";
            for(int m=0; m<M+1; m++){
                cout<<usr_a[m]<<" ";
            }
            cout<<"\n";

            cout<<"usr_b : ";
            for(int m=0; m<M+1; m++){
                cout<<usr_b[m]<<" ";
            }
            cout<<"\n";

            cout<<"BCs : \n";
            for(int a=0; a<A; a++){
                cout<<BCs[a].pos.x<<" "<<BCs[a].pos.y<<" "<<BCs[a].C<<" "<<BCs[a].P<<"\n";
            }

        }

        int tot_charge = 0;

        for(int m=0; m<M+1; m++){ // 모든 시간 마다
            pos_a.x += dx[usr_a[m]];
            pos_a.y += dy[usr_a[m]];
            pos_b.x += dx[usr_b[m]];
            pos_b.y += dy[usr_b[m]];

            int BCs_a[8];
            int BCs_b[8];
            int n_a=0;
            int n_b=0;

            findBCs(pos_a, &BCs_a[0], &n_a);
            findBCs(pos_b, &BCs_b[0], &n_b);

            int delta_charge = 0;
            if(n_a != 0 && n_b !=0) {
                for (int i = 0; i < n_a; i++) {
                    for (int j = 0; j < n_b; j++) {
                        if (BCs_a[i] == BCs_b[j]) {
                            delta_charge = delta_charge < BCs[BCs_a[i]].P ? BCs[BCs_a[i]].P : delta_charge;
                        } else {
                            delta_charge =
                                    delta_charge < BCs[BCs_a[i]].P + BCs[BCs_b[j]].P ? BCs[BCs_a[i]].P + BCs[BCs_b[j]].P
                                                                                     : delta_charge;
                        }
                    }
                }
            }
            else if (n_a!= 0 && n_b==0 ) {
                int max_p =0;
                for(int i=0; i<n_a; i++){
                    if(BCs[BCs_a[i]].P > max_p) max_p = BCs[BCs_a[i]].P;
                }
                delta_charge = max_p;
            }
            else if (n_a == 0 && n_b !=0){
                int max_p =0;
                for(int i=0; i<n_b; i++){
                    if(BCs[BCs_b[i]].P > max_p) max_p = BCs[BCs_b[i]].P;
                }
                delta_charge = max_p;
            }
            else {;// delta_charge = 0
            }

            tot_charge += delta_charge;

            if(DEBUG){
                cout<<"[at "<<m<<"] "<<"A("<<pos_a.x<<","<<pos_a.y<<")  B("<<pos_b.x<<","<<pos_b.y<<")\n";
                cout<<"A's possible BCs: ";
                for(int i=0; i<n_a; i++){
                    cout<<BCs_a[i]<<" ";
                }
                cout<<"\n";
                cout<<"B's possible BCs: ";
                for(int i=0; i<n_b; i++) {
                    cout << BCs_b[i] << " ";
                }
                cout<<"\n";

                cout<<"d_charge : "<<delta_charge<<"\n";
                cout<<"tot_charge : "<<tot_charge<<"\n";
            }

        } // end of M loop

        cout<<"#"<<t+1<<" "<<tot_charge<<"\n";
    } // end of test case loop
}
