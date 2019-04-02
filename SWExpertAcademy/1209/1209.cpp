#include <iostream>


using namespace std;

int sums[202];
int ary[100][100];

void Init(){
    for(int h=0; h<100; h++){
        for(int w=0; w<100; w++){
            ary[h][w] = 0;
        }
    }

    for(int i=0; i<202; i++){
        sums[i] =0;
    }
}

int main(){
    for(int t=0; t<10; t++){// testcase

        Init();

        int testcase;
        cin >> testcase;

        for(int h=0; h<100; h++){
            for(int w=0; w<100; w++){
                cin >> ary[h][w];
            }
        }

        int sums_idx=0;

        // row sum
        for (int h=0; h<100; h++){
            int row_sum =0;
            for(int w=0; w<100; w++){
                row_sum+=ary[h][w];
            }
            sums[sums_idx]=row_sum;
            sums_idx++;
        }

        // col sum
        for(int w=0; w<100; w++){
            int col_sum=0;
            for(int h=0; h<100; h++){
                col_sum+=ary[h][w];
            }
            sums[sums_idx]=col_sum;
            sums_idx++;
        }

        // dig sum
        int dig_sum_1=0;
        int dig_sum_2=0;
        for(int d=0; d<100; d++){
            dig_sum_1+=ary[d][d];
            dig_sum_2+=ary[d][100-d];
        }
        sums[sums_idx]=dig_sum_1;
        sums_idx++;
        sums[sums_idx]=dig_sum_2;
        sums_idx++;

        // find max
        int ans =0;
        for(int i=0; i<202; i++){
            if(sums[i] > ans) ans=sums[i];
        }

        cout<<"#"<<t+1<<" "<<ans<<"\n";
    }

    return 0;
}