#include<cstdio>

#define MAX 100001
#define MAXNUM 1000000001

int N, M, a, b, i, input[MAX], num[MAX], tree[MAX*4];

// 최솟값 세그먼트 트리 생성
int init(int node, int start, int end){
    if(start==end)
        return tree[node]=input[start];
    
    int left = init(node*2, start, (start+end)/2);
    int right = init(node*2+1, (start+end)/2+1, end);
    if(left < right)
        return tree[node]=left;
    else
        return tree[node]=right;

}

//구간 최솟값 찾기
int min(int node, int start, int end, int left, int right){
    if(start > right || end < left)
        return MAXNUM;
    if(left<=start && right>=end)
        return tree[node];
    
    int leftnum = min(node*2, start, (start+end)/2, left, right);
    int rightnum = min(node*2+1, (start+end)/2+1, end, left, right);
    if(leftnum < rightnum)
        return leftnum;
    else
        return rightnum;

}



int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)
        scanf("%d",&input[i]);

    init(1, 1, N);  //세그먼트 트리 생성

    for(i=1;i<=M;i++){
        scanf("%d%d",&a,&b);
        num[i]=min(1, 1, N, a, b);
    }
    for(i=1;i<=M;i++)
        printf("%d\n",num[i]);

    return 0;
}
