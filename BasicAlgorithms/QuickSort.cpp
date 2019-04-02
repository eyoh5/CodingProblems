#include <iostream>

using namespace std;

int T, N;

void QuickSort(int* data, int start, int end) {

    int i = start;
    int j = end;
    int tmp;

    if( start < end ) {
        while (i < j) {
            while (data[i] <= data[start] && i < end) {
                i++;
            }

            while (data[j] > data[start]) {
                j--;
            }

            if (i < j) {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }

        tmp = data[start];
        data[start] = data[j];
        data[j] = tmp;

        QuickSort(data, start, j - 1);
        QuickSort(data, j + 1, end);
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
        QuickSort(&data[0], 0, N-1);
        for(int n=0; n<N; n++){
            cout<<data[n]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
