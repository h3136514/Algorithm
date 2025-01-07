// 구현, 문자열
#include <iostream>

using namespace std;
int cnt, c;
char str[256];

// 모음의 개수
int main(){
    while(true){
        for(c = 0; c < 256; c++){
            cin >> str[c];
            if(str[c] == '#' || str[c] == '.' || str[c] == '!' || str[c] == '?')
                break;
            
        }
        
        if(str[0] == '#')
            break;
        
        cnt = 0;
        for(int i = 0; i < c; i++){
            if(str[i] =='a' || str[i] =='A' || str[i] =='e' || str[i] =='E' || str[i] =='i' || str[i] =='I' || str[i] =='o' || str[i] =='O' || str[i] =='u' || str[i] =='U'){
                cnt++;
                continue;
            }
        }
        
        cout << cnt << "\n";
    }

    return 0;
}