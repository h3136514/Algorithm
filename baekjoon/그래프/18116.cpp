#include <iostream>

#define MAX 1000001
using namespace std;
int N, A, B, broot, croot, parent[MAX], cnt[MAX];
char input;

int find(int a){
    if(parent[a] == a)
        return a;
    else
        return parent[a] = find(parent[a]);
}

void union_s(int b, int c){
    broot = find(b);
    croot = find(c);

    if(broot < croot){
        parent[croot] = broot;
        cnt[broot] += cnt[croot];
    }else if(broot > croot){
        parent[broot] = croot;
        cnt[croot] += cnt[broot];
    }
}

// 로봇 조립
int main(){
    for(int i = 1; i < MAX; i++){
        cnt[i] = 1;
        parent[i] = i;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        cin >> A;
        if(input == 'I'){
            cin >> B;
            union_s(A, B);
        }else{
            cout << cnt[find(A)] << "\n";
        }
    }

    return 0;
}