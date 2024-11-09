#include <iostream>
#include <vector>

using namespace std;
int N, num, cnt, i = 666;
vector<int> v;

// 영화감독 숌
int main(){
    cin >> N;
    while(true){
        if(v.size() >= N)
            break;
        num = i;
        cnt = 0;
        while(num > 0){
            if(num % 10 == 6)
                cnt++;
            else
                cnt = 0;
            
            if(cnt == 3){
                v.push_back(i);
                break;
            }
            num /= 10;
        }

        i++;
    }

    cout << v[N-1] << "\n";

    return 0;
}