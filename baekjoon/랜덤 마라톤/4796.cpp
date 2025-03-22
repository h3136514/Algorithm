// 그리디
#include <iostream>

using namespace std;
int L, P, V, cnt = 1;

// 캠핑
int main(){
    while(true){
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0)
            break;
        
        int sum = V/P * L;
        sum += (V%P > L) ? L : V%P;

        cout << "Case " << cnt++ << ": " << sum << "\n";
    }
   
    return 0;
}
