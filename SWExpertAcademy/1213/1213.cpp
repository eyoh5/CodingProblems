#include <iostream>

using namespace std;

int main(){
    for(int t=0; t<10; t++){
        int testcase;
        cin >> testcase;

        char str[2000];
        char pat[20];
        cin >> pat >> str;
        int pat_len =0;
        int str_len =0;

        char it = str[0];
        while( it!='\0'){
            str_len++;
            it = str[str_len];
        }

        it = pat[0];
        while( it!='\0') {
            pat_len++;
            it = pat[pat_len];
        }

        // pattern matching start
        int ans =0;
        int i = 0;
        int j=0;
        while(str[i] != '\0'){
            if(str[i] == pat[j]){
                while(pat[j] != '\0'){
                    if(str[i+j] != pat[j]){
                        j=0;
                        break;
                    }else j++;
                }

                if(pat[j] == '\0') {ans++; j=0;}
            }
            i++;
        }

        cout<<"#"<<t+1<<" "<<ans<<"\n";

        }

    return 0;
}