#include <iostream>

int T, N, W, H;
int map[15][12];
int sim_map[15][12];

#define DEBUG 1

using namespace std;


void break_block(int target_h_, int target_w);
int run_sim(int n);
void delete_bubble();
void print_sim_map();
int count_score(); //count # of nonzero blocks


void print_sim_map(){

    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            cout<<sim_map[h][w]<<" ";
        }
        cout<<"\n";
    }
}

void copy_map(int src[15][12], int dest[15][12]){
    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            dest[h][w] = src[h][w];
        }
    }
}


int run_sim(int n){

    if(n == N) copy_map(map, sim_map);

    if(n == 0){
        return count_score();
    }


    //else
    int min_score = 99999;

    for(int target_w=0; target_w<W; target_w++) {

        int tmp[15][12];
        copy_map(sim_map, tmp);

        int target_h;

        for (int h = H - 1; h >= 0; h--) {
            if (sim_map[h][target_w] == 0) {
                target_h = h + 1;
                break;
            }
        }

        if(DEBUG){
            cout<<"Before break block \n";
            print_sim_map();
        }


        break_block(target_h, target_w);
        if (DEBUG) {
            cout << "After break block at (" << target_h << ", " << target_w << ")\n";
            print_sim_map();
        }

        delete_bubble();
        if (DEBUG) {
            cout << "After delete bubble \n";
            print_sim_map();
        }

        int score = run_sim(n-1);
        if( score < min_score ) min_score = score;

        copy_map(tmp, sim_map);
    }

    return min_score;
}

void break_block(int target_h, int target_w){

    if(0<=target_h && target_h<H && 0<=target_w && target_w<W) {

        if (sim_map[target_h][target_w] <= 1) sim_map[target_h][target_w] = 0;
        else {
            int size = sim_map[target_h][target_w];

            sim_map[target_h][target_w] = 0; // break my-self

            for (int s = -size + 1; s <= size - 1; s++) {// break blocks under the active area ((excluding my-self))
                if (s != 0) {
                    break_block(target_h + s, target_w);
                    break_block(target_h, target_w + s);
                }
            }
        }

    }
}

void delete_bubble(){
    for(int w=0; w<W; w++){
        for(int h=H-1; h>=0; h--){
            if(sim_map[h][w] == 0){
                int nonzero_h = h;
                while(sim_map[nonzero_h][w] == 0 && nonzero_h>0) nonzero_h--;
                sim_map[h][w] = sim_map[nonzero_h][w];
                sim_map[nonzero_h][w] = 0;
            }
        }
    }
}

int count_score(){

    int score=0;

    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            if(sim_map[h][w] != 0 ) score++;
        }
    }

    return score;
}

int main(){

    cin >> T;

    for (int t=0; t<T; t++){ // Each Test Case

        cin >> N >> W >> H;
        if(DEBUG) cout<<"N,W,H : "<< N<<" "<<W<<" "<<H<<" \n";

        for(int h=0; h<H; h++){
            for(int w=0; w<W; w++){
                cin >> map[h][w];
            }
        }

        if(DEBUG){
            cout<<"Readed map\n";
            for(int h=0; h<H; h++){
                for(int w=0; w<W; w++){
                    cout << map[h][w]<<" ";
                }
                cout<<"\n";
            }
        }


        int ans = run_sim(N);

        cout<<"#"<<t+1<<" "<<ans<<"\n";


    }// test case end
}
