#include<cstdio>
 
 #define MAX 1000001
 #define MAXNUM 1000000007

 int N, M, K, a, b, c, i;
 long long input[MAX], tree[MAX*4];

// 구간 곱 세그먼트 트리 생성
long long init(int node, int start, int end){
    if(start==end)
        return tree[node]=input[start];
    
    return tree[node]=(init(node*2, start, (start+end)/2) * init(node*2+1, (start+end)/2+1, end)) % MAXNUM;
}

//구간 곱 찾기 
long long multiply(int node, int start, int end, int left, int right){
    if(start > right || end < left )
        return 1;
    if(left <= start && right >= end)
        return tree[node];
    
    return (multiply(node*2, start, (start+end)/2, left, right) * multiply(node*2+1, (start+end)/2+1, end, left, right)) % MAXNUM;
}

//업데이트
long long update(int node, int start, int end, int target, int change){
    if(target<start||target > end )
        return tree[node];  //변경되지 않은 값을 반환

    if(start == end)
        return tree[node] = change;  //값을 변경
    
    if(start != end)
        return tree[node]=(update(node*2, start, (start+end)/2, target, change) * update(node*2+1, (start+end)/2+1, end, target, change)) % MAXNUM;
    

    
}

int main(){
    scanf("%d%d%d", &N, &M, &K); 
    for(i=1;i<=N;i++)
        scanf("%d", &input[i]);

    init(1,1,N);    //세그먼트 트리생성
    

    for(i=1;i<=M+K;i++){
        scanf("%d%d%d", &a, &b, &c);
        if(a==1){
            update(1,1,N,b,c);
            input[b]=c;
        }else{
            printf("%lld\n",multiply(1,1,N,b,c));
        }
            
    }
    return 0;
 }
 