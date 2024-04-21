#include<cstdio>
#include<queue>
using namespace std;
queue <int> q;
int num[5001], N, K, i, j, cnt;

int main() {
    scanf("%d %d", &N, &K);
    cnt = 0;
    j = 0;
    while(N > i++) {    // 모든 N개의 수를 구함
        while(true) //K번째 순서(cnt)를 q에 추가
        {   j++;
            if(j > N){
                j = 1;
            }
            if(num[j])
                continue;
            else 
                cnt++;
            
            if(cnt == K){
                num[j] = 1;
                q.push(j);
                break;
            }
        }
        cnt=0;
    }
    
    // 출력
    printf("<");
    for(i=1;i<=N;i++) {
        if(i==N)
            printf("%d>", q.front());
        else
            printf("%d, ", q.front());
        q.pop();
    }

    return 0;
}