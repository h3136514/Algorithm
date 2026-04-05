// https://www.acmicpc.net/problem/17266
#include <iostream>
#include <vector>

using namespace std;
int N, M, answer, s, e;
vector<int> v;

// 어두운 굴다리
int main(){
    cin >> N >> M;

    v.resize(M);
    for(int i = 0; i < M; i++){
        cin >> v[i];
    }

    answer = N;
    s = 0, e = N;
    while(s <= e){
        int mid = (s + e) / 2;
        int last = 0;
        bool check = true;
        for(int i = 0; i < M; i++){
            if(v[i] - mid > last){
                check = false;
                break;
            }else{
                last = v[i] + mid;
            }
        }

        if(N-last>0)
            check = false;
        
        if(check){
            e = mid -1;
            answer = min(answer, mid);
        }else{
            s = mid + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}