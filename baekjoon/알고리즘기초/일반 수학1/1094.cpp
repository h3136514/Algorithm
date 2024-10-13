#include <iostream>
#include <vector>

using namespace std;
int num, cnt;
vector<int> v = {64, 32, 16, 8, 4, 2, 1};

// 막대기
int main(){
    int stick = 64;
    cin >> num;
    for(int i = 0; i <v.size(); i++){
        if(v[i] <= num){
            num -= v[i];
            cnt++;
        }
        if(num == 0)
            break;
    }

    cout << cnt <<" \n";

    return 0;
}