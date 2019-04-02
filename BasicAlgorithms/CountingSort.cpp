#include <iostream>

using namespace std;

void CountingSort(int* src, int* dst, int size){

    int count[10];
    for(int i=0; i<10; i++) count[i] = 0; // count init.

    for(int n=0; n<size; n++){
        count[src[n]] +=1;
    }

    // count의 누적합
    for(int i=1; i<10;  i++){
        count[i] = count[i] + count[i-1];
    }

    for(int n=0; n<size; n++){
        dst[--count[src[n]]] = src[n];
    }
}

int T, N;

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;

        int data[N];
        for(int n=0; n<N; n++){
            cin >> data[n];
        }

        cout<<"#"<<t+1<<" ";
        int sorted[N];
        CountingSort(&data[0], &sorted[0], N);
        for(int n=0; n<N; n++){
            cout<<sorted[n]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
