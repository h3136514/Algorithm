#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int N, CNT;
long long num;
vector<long long> V;

void binarySearch(int idx){
    long long targetNum = V[idx];
    int s = 0, e = N-1;

    while(s < e){
        long long sum = V[s] + V[e];
        
        if(sum == targetNum){
            if(s != idx && e != idx){
                CNT++;
                return;
            }

           if(s == idx)
                s++;
            else if(e == idx)
                e--;
            
        }else if(sum > targetNum){
            e -= 1;
        }else{
            s += 1;
        }
    }
}

// 좋다
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        V.push_back(num);       
    }

    sort(V.begin(), V.end());

    for(int i = 0; i < V.size(); i++){
        binarySearch(i);
    }

    cout << CNT << "\n";

    return 0;
}