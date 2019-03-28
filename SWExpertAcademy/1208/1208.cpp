#include <iostream>

int T=10;

using namespace std;

int main(){
  
  for(int t=0;t<T; t++){
    int n_dump;
    int talls[100];

    cin >> n_dump;

    for(int n=0; n<100; n++){
      cin >> talls[n];
    }

    int ans=0;

    for(int d=0; d<=n_dump; d++){

      int min_tall=100;
      int min_tall_n;
      int max_tall=0;
      int max_tall_n;

      for(int n=0; n<100; n++){
        if(min_tall > talls[n]) {
          min_tall = talls[n];
          min_tall_n = n;
        }

        if(max_tall < talls[n]) {
          max_tall = talls[n];
          max_tall_n = n;
        }
      }

      if(d != n_dump){
        // dump
        talls[max_tall_n] -= 1;
        talls[min_tall_n] += 1;
      }
      else{ // d = n_dump
        ans = max_tall - min_tall;
      }
    }

    cout<<"#"<<t+1<<" "<<ans<<"\n";
    }

   return 0;
}
