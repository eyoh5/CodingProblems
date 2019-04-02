#include <iostream>

// Binary search
// it assumes that the data is already sorted.

using namespace std;

int BinarySearch(int* data, int target, int start, int end){

    if(start > end) return -1;

    int mid = (end + start)/2;

    if(data[mid] < target) return BinarySearch(data, target, mid+1, end);
    else if (data[mid] > target) return BinarySearch(data, target, start, mid-1);
    else return mid;

}

int T, M, N;

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> M >> N;

        int data[M];
        for(int m=0; m<M; m++){
            cin >> data[m];
        }

        cout<<"#"<<t+1<<" ";
        for(int n=0; n<N; n++){
            int query;
            cin >> query;
            cout<<BinarySearch(&data[0], query, 0, M-1)<<" ";

        }
        cout<<"\n";


    }

    return 0;
}

