#include<cstdio>

#define MAX_N 100001
#define MAX_NUM  1000000001     //입력한 정수 값의 최대범위 + 1

int N,M,a,b,i,maxnum[MAX_N],minnum[MAX_N],input[MAX_N],tree[MAX_N*4][2];   // tree[node][0]: 최솟값 구간 트리, tree[node][1]: 최댓값 구간 트리

//구간 최솟값 설정
int mininit(int node, int start, int end){
    if(start == end)
        return tree[node][0]=input[start];
    else{
        int left = mininit(node*2, start, (start+end)/2);
        int right= mininit(node*2+1, (start+end)/2+1, end );
        if(left < right)
            return tree[node][0] = left;
        else
            return tree[node][0] = right;
    }
}
//구간 최솟값 가져오기
int min(int node, int start, int end, int left, int right){
    if(right < start || end < left) //범위에 벗어나면
        return MAX_NUM;
    if(left <= start && right>= end)
        return tree[node][0];

    int leftmin = min(node*2, start, (start+end)/2, left , right);
    int rightmin = min(node*2+1,(start+end)/2+1, end, left, right);
    if(leftmin < rightmin)
        return leftmin;
    else
        return rightmin;
}

//구간 최댓값 설정
int maxinit(int node, int start, int end){
    if(start == end)
        return tree[node][1]=input[start];
    else{
        int left = maxinit(node*2, start, (start+end)/2);
        int right= maxinit(node*2+1, (start+end)/2+1, end );
        if(left > right)
            return tree[node][1] = left;
        else
            return tree[node][1] = right;
    }
}
//구간 최댓값 가져오기
int max(int node, int start, int end, int left, int right){
    if(right < start || end < left) //범위에 벗어나면
        return 0;
    if(left <= start && right>= end)
        return tree[node][1];

    int leftmin = max(node*2, start, (start+end)/2, left , right);
    int rightmin = max(node*2+1,(start+end)/2+1, end, left, right);
    if(leftmin > rightmin)
        return leftmin;
    else
        return rightmin;
}
int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)
        scanf("%d", &input[i]);
    
    mininit(1,1,N);  //최솟값 구간 트리생성
    maxinit(1,1,N);  //최댓값 구간 트리생성
    
    //구할 구간 입력
    for(i=1;i<=M;i++){
        scanf("%d%d",&a,&b);
        minnum[i]=min(1,1,N,a,b);
        maxnum[i]=max(1,1,N,a,b);
    }
    for(i=1;i<=M;i++)
        printf("%d %d\n",minnum[i], maxnum[i]);
    
    return 0;
}
