#include<cstdio>
#include<memory.h>

#define MAX 2001

int N, i, input[MAX];
long long result, dp[MAX][MAX];

int goright(int x){
    return (x+1) % N;   //맨끝에서 오른쪽으로 가면 0이 나와야된다.(N=5이고 현재 4일때 오른쪽으로 가면 0이나옴)
}

int goleft(int x){
    return (x+N-1) % N;     //음수가 나오면 안되므로 N을 더함
}

long long JOI(int start, int end);
long long IOI(int start, int end);

long long JOI(int start, int end){
     // 끝까지 온경우
    if(start == goright(end))
        return dp[start][end]=0;
    // 이미 갱신이 된경우
    if(dp[start][end] != -1)
        return dp[start][end];

    // 더 큰 경우를 선택
    long long left =IOI(goleft(start), end) + input[goleft(start)];
    long long right=IOI(start, goright(end)) +input[goright(end)];
    if(left>right)
        return dp[start][end] =left;
    else
        return dp[start][end] =right;



}

long long IOI(int start, int end){
    // 끝까지 온경우
    if(start == goright(end))
        return 0;
    // 인접한 오른쪽값을 선택한경우
    if(input[goright(end)] > input[goleft(start)])
        return JOI(start, goright(end));
    else //왼쪽값을 선택한경우
        return JOI(goleft(start), end);

}


int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d",&N);

    for(i=0;i<N;i++)
        scanf("%d",&input[i]);

    for(i=0;i<N;i++){
        long long  answer =input[i] + IOI(i,i);
        if(result <answer)
            result = answer;
    }
    printf("%lld\n",result);
    return 0;
}