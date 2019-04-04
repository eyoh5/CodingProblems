#include <iostream>

using namespace std;

char board[8][8];
int N;

int main(){
    for(int t=0; t<10; t++){
        cin >> N;

        // get board info.
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cin >> board[i][j];
            }
        }

        int ans =0;
        // find palindrome in row direction
        for(int i=0; i<8; i++) {
            for (int j = 0; j <= 8 - N; j++) {
                for (int n = 0; n < N / 2; n++) {
                    if (board[i][j+n] != board[i][j+N-n-1]){
                        break;
                    }
                    if(n == ((N/2)-1)) ans++;
                }
            }
        }

        // find palindrome in col direction
        for(int j=0; j<8; j++){
            for(int i=0; i<=8-N; i++){
                for(int n=0; n<N/2; n++){
                    if(board[i+n][j] != board[i+N-n-1][j]){
                        break;
                    }
                    if(n == ((N/2)-1)) ans++;
                }
            }
        }

        cout<<"#"<<t+1<<" "<<ans<<"\n";
    }
}