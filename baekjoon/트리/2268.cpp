#include <iostream>

#define MAX 1000001
using namespace std;
int N, M;
long long a, b, c, A[MAX], tree[MAX*4];

long long init(int node, int s, int e){
    if(s == e)
        return tree[node] = A[s];
    
    int mid = (s+e)/2;

    return tree[node] = init(node*2, s, mid) + init(node*2 + 1, mid+1, e);
}

long long sum(int node, int s, int e, int left, int right){
    if(s > right || e < left)
        return 0;
    
    if(left <= s && e <= right)
        return tree[node];
    
    int mid = (s + e) / 2;
    
    return sum(node*2, s, mid, left, right) + sum(node*2 +1, mid+1, e, left, right);
}

void update(int node, int s, int e, int target, int v){
    if(target < s || target > e)
        return;
    
    tree[node] += v;
    int mid = (s+e)/2;

    if(s != e){
        update(node*2, s, mid, target, v);
        update(node*2+1, mid+1, e, target, v);
    }
}

// 수들의 합 7
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    init(1, 1, N);
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        if(a == 0){
            if(b <= c)
                cout << sum(1, 1, N, b, c) << "\n";
            else
                cout << sum(1, 1, N, c, b) << "\n";
        }
        else{
            int v = c - A[b];
            A[b] = c;

            update(1, 1, N, b, v);
        }        
    }
}