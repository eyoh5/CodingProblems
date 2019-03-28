#include <iostream>

// remove DEBUG related statements
// when you upload this file to the www.swexpertacademy.com
// because it results in over-execution time

int T, N, M, K;
int incubator[350][350]; // activation start time
int tmp[350][350];
int lifeness[350][350]; // X values
int init_origin_x;
int init_origin_y;
int ans;

using namespace std;

#define DEBUG 1

void run_sim(int k);
void copy(int src[350][350], int dest[350][350]);
void grow(int n, int m, int t);
int count(int t);
void Init();

void Init(){
    for(int n=0; n<350; n++){
        for(int m=0; m<350; m++){
            incubator[n][m] = 0;
            lifeness[n][m] = 0;
            tmp[n][m] =0;
        }
    }

    init_origin_x =0;
    init_origin_y =0;
    ans =0;
}

void run_sim(int k){
  int t = K-k;

  if( t==K ) { // final
    ans = count(t);
    return;
  }

  else if( t==0 ){
      copy(incubator, lifeness);
      run_sim(k-1);
  }

  else {

      copy(lifeness, tmp);

   if(DEBUG){
       cout<<"Before grow at t="<<t<<"\n";
       for(int n=init_origin_y-t; n<init_origin_y+N+t; n++){
           for(int m=init_origin_x-t; m<init_origin_x+M+t; m++){
               cout<< incubator[n][m] <<" ";
           }
           cout<<"\n";
       }
   }

   for(int n=init_origin_y-t; n<init_origin_y+N+t; n++){
      for(int m=init_origin_x-t; m<init_origin_x+M+t; m++){
          if(n>=0 && n<=350 && m>=0 && m<=350){ //boundary
              if(incubator[n][m] >=0 && incubator[n][m] <= t && incubator[n][m]+lifeness[n][m] > t) { // active cell
                  grow(n, m, t+1);
              }
          }
      }
   }

   if(DEBUG){
       cout<<"After grow\n";
       for(int n=init_origin_y-t-1; n<init_origin_y+N+t+1; n++){
           for(int m=init_origin_x-t-1; m<init_origin_x+M+t+1; m++){
               cout<< incubator[n][m] <<" ";
           }
           cout<<"\n";
       }
   }

   run_sim(k-1);

  }
}

void copy(int src[350][350], int dest[350][350]){
  for(int n=0;n<350; n++){
    for(int m=0; m<350; m++){
      dest[n][m] = src[n][m];
    }
  }
}

void grow(int n, int m, int t){

  for(int d=-1; d<=1; d++){
    if(d!=0) {
      if(tmp[n+d][m]==0) {
          lifeness[n+d][m] = (lifeness[n+d][m] > lifeness[n][m]) ? lifeness[n+d][m] : lifeness[n][m];
          incubator[n+d][m]  = lifeness[n+d][m] + t;
      }
      if(tmp[n][m+d]==0) {
          lifeness[n][m+d] = (lifeness[n][m+d] > lifeness[n][m]) ? lifeness[n][m+d] : lifeness[n][m];
          incubator[n][m+d] = lifeness[n][m+d] + t;
      }
    }
  }

}

int count(int t){

  int result=0;

  for(int n=0; n<350; n++){
    for(int m=0; m<350; m++){
      if(incubator[n][m]+lifeness[n][m] > t ) result++;
    }
  }

  return result;
}

int main(){

  cin >> T;

  for(int t=0; t<T; t++){
    cin >> N >> M >> K;

    Init();

    init_origin_x = (350-M)/2;
    init_origin_y = (350-N)/2;

    for(int n=0; n<N; n++){
      for(int m=0; m<M; m++){
        cin >> incubator[init_origin_y+n][init_origin_x+m];
      }
    }

    if(DEBUG){
        for(int n=0; n<N; n++){
            for(int m=0; m<M; m++){
                cout<<incubator[init_origin_y+n][init_origin_x+m]<<" ";
            }
            cout<<"\n";
        }
    }

    run_sim(K);

    cout<<"#"<<t+1<<" "<<ans<<"\n";
  }

}
