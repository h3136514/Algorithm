#include<cstdio>

#define MAX 100001

int N, Q, x, y, a, b, i;
long long input[MAX];
long long tree[MAX*4];

//세그먼트 트리 초기화
long long init(int node, int start, int end){
    if(start==end)
        return tree[node]=input[start];
    
    return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
}

//구간 합 출력
long long sum(int node, int start, int end, int left, int right){
    if(start > right || end < left)
        return 0;

    if(start >= left && end <= right)
        return tree[node];
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

//값 변경
void update(int node, int start, int end, int target, long long v){
    if(target < start || target > end)
        return;

    tree[node] += v;
    if(start != end){
        update(node*2, start, (start+end)/2, target, v);
        update(node*2+1, (start+end)/2+1, end, target, v);
    }
    
}

int main(){
    scanf("%d%d", &N, &Q);
    for(i=1;i<=N;i++)
        scanf("%lld",&input[i]);
    
    init(1, 1, N);  //세그먼트 트리 생성    
    for(i=1;i<=Q;i++)
    {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if(x<=y)
            printf("%lld\n", sum(1,1,N,x,y));   //x~y까지 구간 합
        else
            printf("%lld\n", sum(1,1,N,y,x));   //y~x까지 구간 합
        long long temp= b-input[a];      //a->b로 변경된 값의 차이
        input[a]=b;
        update(1, 1, N, a, temp);   //a번째 수를 b로 바꿈
    }

    return 0;
}