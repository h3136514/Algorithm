#include <iostream>
#include <unordered_map>

using namespace std;
int N, K, num, idx;
char c, wheel[26];
bool check = true;
unordered_map<char, bool> m;

int main(){
    cin >> N >> K;

    for(int i = 0; i < N; i++)
        wheel[i] = '?';


    for(int i = 0; i < K; i++){
        cin >> num >> c;
        
        if(!check)
            continue;

        idx = (idx + num) % N;
        if(m.find(c) == m.end() && wheel[idx] == '?'){
            wheel[idx] = c;
            m[c] = true;
        }else if(m.find(c) != m.end() && wheel[idx] == c)
            continue;
        else{
            check = false;
        }
    }



    if(!check)
        cout <<"!\n";
    else{
        for(int i = idx; i >= 0; i--)
            cout << wheel[i];
        for(int i = N-1; i > idx; i--)
            cout << wheel[i]; 
        
        cout << "\n";
    }

    return 0;
}
