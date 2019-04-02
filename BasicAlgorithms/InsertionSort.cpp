#include <iostream>

using namespace std;

int T, N;

void InsertionSort(int* src, int size){
    for(int i=1; i<size; i++){
        int tmp = src[i];
        int j= i-1;
        while(j>=0 && tmp < src[j]){
            src[j+1] = src[j];
            j--;
        }
        src[j+1] = tmp;
    }
}


int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        int data[N];
        for(int n=0; n<N; n++){
            cin >> data[n];
        }

        cout<<"#"<<t+1<<" ";
        InsertionSort(&data[0], N);
        for(int n=0; n<N; n++){
            cout<<data[n]<<" ";
        }
        cout<<"\n";

    }
}