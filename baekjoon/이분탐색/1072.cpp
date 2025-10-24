#include <iostream>

using namespace std;
double X, Y;
long long Z, CNT;

// 게임
int main(){
    cin >> X >> Y;

    if(X != 0)
        Z = Y*100/X;

    if(Z >= 99){    // 99%는 아무리 해도 100%가 되지 않는다.
        cout <<"-1\n";
        return 0;
    }

    long long s = 1, e = X;
    CNT = X;
    while(s <= e){
        long long mid = (s + e)/2;
        double a = (Y+mid)*100;
        double b = X+mid;
        long long win = a/b;

        if(win > Z){
            CNT = min(CNT, mid);
            e = mid - 1;
            continue;
        }else{
            s = mid + 1;
        }
    }

    cout << CNT << "\n";

    return 0;
}