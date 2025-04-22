#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, startX, endX, answer;
long long sum, M;
vector<int> tree;

// 나무 자르기
int main(){
    cin >> N >> M;
    tree.resize(N);

    for(int i = 0; i < N; i++)
        cin >> tree[i];
    
    sort(tree.begin(), tree.end());

    startX = 0;
    endX = tree[N-1];   // 최대길이
    while(startX <= endX){
        int mid = (startX + endX) / 2;

        sum = 0;
        for(int i = 0; i < N; i++){
            if(tree[i] > mid)
                sum += tree[i] - mid;  
        }

        if(sum >= M){    //  M미터보다 가져간 나무가 같거나 많으면
            answer = max(answer, mid);
            startX = mid+1;  // cut 가능 구간을 더 올림(더 적게 자름)
        }else{
            endX = mid-1; // cut 가능 구간을 내림(더 많이 자름)
        }
    }

    cout << answer << "\n";

    return 0;
}