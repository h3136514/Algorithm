#include <iostream>

using namespace std;
long long a, b, sum;
int divNum;

// 이항 쇼다운
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true){
        cin >> a >> b;
        
        if(a == 0 && b == 0)
            break;

        sum = 1;
        divNum = 1;
        if(a/2 < b)
            b = a-b;
        
        for(int i = a; i > a-b; i--){
            sum *= i;
            sum /= divNum;
            divNum++;
        }

        cout << sum << "\n";
    }

    return 0;
}