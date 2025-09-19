#include <iostream>
#include <string>

using namespace std;
int T, x, y, d, maxX, minX, maxY, minY;
int offer_X[4] = {0, 1, 0, -1};
int offer_Y[4] = {-1, 0, 1, 0};
string s;

void init(){
    maxX = 0, minX = 0, maxY = 0, minY = 0, d = 0;
    x =0, y = 0;
}

// 거북이
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--){
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                d = (d == 0) ? 3 : d - 1;
            }else if(s[i] == 'R'){
                d = (d == 3) ? 0 : d + 1;
            }else{
                if(s[i] == 'F'){
                    x += offer_X[d];
                    y += offer_Y[d]; 
                }else{
                    x -= offer_X[d];
                    y -= offer_Y[d];
                }
                
                maxX = max(maxX, x);
                minX = min(minX, x);
                maxY = max(maxY, y);
                minY = min(minY, y);
            }
        }
       
       
        cout << (maxX-minX) *(maxY-minY) << "\n";

        init();
    }

    return 0;
}