#include <iostream>

using namespace std;
int N, a, b, c, result = 0, num[7];

void init(){
    for(int i = 1; i <= 6; i++){
        num[i] = 0;
    }
}

int check(){
    int sum = 0;
    int target = 0;
    for(int i = 1; i <= 6; i++){
        if(num[i])
            target = max(target, i);
        if(num[i] == 2){
            sum = 1000 + (i*100);
        }else if(num[i] == 3){
            sum = 10000 + (i*1000);
        }
    }
    if(sum == 0){
        sum = target*100;
    }

    return sum;
}

// 주사위 게임
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        num[a]++, num[b]++, num[c]++;
        
        result = max(result, check());
        init();
    }

    cout << result << "\n";

    return 0;
}