#include<iostream>
#include<string>

using namespace std;
int N, sum, l;
string s;

// 컵홀더
int main(){
    cin >> N;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'S'){
            sum++;
        }else{
            if(l == 0){
                sum += 2;
            }else
                sum++;
            
            l = 1;
            i++;
        }
    }

    cout << sum << "\n";

    return 0;
}