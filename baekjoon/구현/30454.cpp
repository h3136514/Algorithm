#include <iostream>
#include <string>

using namespace std;
int N, L, maxL, l, cnt;
char ago ='0';
string s;

int main(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> s;
        
        ago = '0';
        l = 0;
        for(int j = 0; j < L; j++){
            if(ago == s[j])
                continue;

            if(ago == '0'){
                l++;
                ago = '1';
            }else{
                ago = '0';
            }
        }

        if(maxL == l){
            cnt++;
        }
        if(maxL < l){
            cnt = 1;
            maxL = l;
        }
    }

    cout << maxL << " " << cnt << "\n";

    return 0;
}
