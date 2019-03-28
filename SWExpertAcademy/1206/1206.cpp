#include <iostream>

int T=10;

using  namespace std;

int main(){

  for(int t=0;t<T; t++){
    int num_buildings;
    cin >> num_buildings;

    int talls[num_buildings];

    for(int n=0; n<num_buildings;n++){
      cin >> talls[n];
    }

    int ans =0;

    for(int n=2; n<num_buildings-2; n++){
      int max_tall=0;
      for(int i=-2; i<=2; i++){
        if(i!=0){
          if(max_tall < talls[n+i]) max_tall = talls[n+i];
        }
      }

      if(max_tall < talls[n]) ans+= talls[n] - max_tall;
    }


    cout<<"#"<<t+1<<" "<<ans<<"\n";
  }

  return 0;


}
