#include <iostream>

int scores[1001];
int counts[101];

int T;

using namespace std;

int main(){

  cin >> T;

  for(int t=0; t<T; t++){
    int testcase;
    cin >> testcase;

    // count init.
    for(int i=0; i<101; i++){
      counts[i] = 0;
    }

    for(int n=0; n<1000; n++){ 
      int tmp;
      cin >> tmp;
      scores[n] = tmp;
      counts[tmp] += 1;
    }

    int max_count = 0;
    int ans =0;

    for(int i=0; i<101; i++){
      if(max_count <= counts[i]){
        max_count = counts[i];
        ans = i;
      }
    }

    cout<<"# "<<testcase<<ans<<"\n";

  }

  return 0;

}
