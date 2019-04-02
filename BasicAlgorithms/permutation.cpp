#include <iostream>

// permutation nPr

using namespace std;

void swap(char* a, char*b){
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void print(char* str, int size){
    for(int i=0; i<size; i++){
        cout<<str[i];
    }
    cout<<"\n";
}
void permutation(char* str, int n, int r, int depth){
    if(r == depth){
        print(str, n);
    }

    for(int i=depth; i<n; i++) {
        swap(&str[i], &str[depth]);
        permutation(str, n, r, depth + 1);
        swap(&str[i], &str[depth]);
    }

}


int T;

int main(){

    cin >> T;
    for(int t=0; t<T; t++){

        char str[11];
        cin >> str;

        int n;
        cin >> n;
        str[n] = 0;

        int k;
        cin >> k;

        permutation(&str[0], n, n, 0);
    }

    return 0;
}

