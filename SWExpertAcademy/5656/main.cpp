#include <iostream>

int T, N, W, H;
int map[15][12];
int sim_map[15][12];

#define DEBUG 1

using namespace std;


void break_block(int target_h_, int target_w);
void run_sim(int target_w);
void Init_user_map();
void delete_bubble();

void Init_user_map(){
    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            sim_map[h][w] = map[h][w];
        }
    }
}

void run_sim(int target_w){

    int target_h;

    for(int h=H-1; h>=0; h--){
        if(sim_map[h][target_w] == 0 ) {
            target_h = h+1;
            break;
        }
    }

    break_block( target_h, target_w);
    delete_bubble();

    if(DEBUG){
        cout<<"After break block at (" <<target_h<<", "<<target_w<<")\n";
        for(int h=0; h<H; h++){
            for(int w=0; w<W; w++){
                cout<<sim_map[h][w]<<" ";
            }
            cout<<"\n";
        }
    }

}

void break_block(int target_h, int target_w){

    if(sim_map[target_h][target_w] <= 1) sim_map[target_h][target_w] = 0;
    else{
        int size = sim_map[target_h][target_w];

        sim_map[target_h][target_w] = 0; // break my-self

        for(int s= -size + 1; s<= size -1 ; s++){// break blocks under the active area ((excluding my-self))
            if( s!=0 ) {
                break_block(target_h + s, target_w);
                break_block(target_h, target_w + s);
            }
        }
    }

}

void delete_bubble(){
    for(int w=0; w<W; w++){
        for(int h=H-1; h>=0; h++){
            if(sim_map[h][w] == 0){

            }
        }
    }
}

int main(){

    // Init
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



        for(int n=0; n<N; n++){

            Init_user_map();

            if(DEBUG){
                cout<<"Sim Map\n";
                for(int h=0; h<H; h++){
                    for(int w=0; w<W; w++){
                        cout<<sim_map[h][w]<<" ";
                    }
                    cout<<"\n";
                }
            }

            for(int w=0; w<W; w++){

                run_sim(w);

            }
        }


    }
}