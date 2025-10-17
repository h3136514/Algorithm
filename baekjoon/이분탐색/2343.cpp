#include <iostream>

#define MAX 1000000000
using namespace std;
int N, M;
long long s, e, num[100001], maxNum, answer = MAX;

// 기타 레슨
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num[i];
        maxNum = max(maxNum, num[i]);
    }

    s = 1, e = MAX;
    while(s <= e){
        long long mid = (s + e) / 2;

        if(mid < maxNum){   // 블루레이 크기는 모든 단일 강의 크기보다 커야됨
            s = mid + 1;
            continue;
        }

        long long sum = 0, cnt = 1;
        for(int i = 0; i < N; i++){
            if(sum + num[i] > mid){
                cnt++;
                sum = num[i];
            }else{
                sum += num[i]; 
            }
        }

        if(cnt <= M){
            answer = min(answer, mid);
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}