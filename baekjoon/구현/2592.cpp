#include <iostream>
#include <map>

using namespace std;
int num, cnt, sum, A, B;
map<int, int> m;

int main(){
    for(int i = 0; i < 10; i++){
        cin >> num;
        m[num]++;
        cnt = max(cnt, m[num]);
        sum += num;
    }

    for(auto a : m){
        if(a.second == cnt){
            B = a.first;
            break;
        }
    }
    A = sum/10;

    cout << A << "\n";
    cout << B << "\n";

    return 0;
}