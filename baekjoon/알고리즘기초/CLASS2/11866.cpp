#include<cstdio>
#include<queue>
using namespace std;
int N, K, i, cnt, cnt2, num[1001];
queue <int>q;

int main(){
    scanf("%d %d", &N, &K);
    while (cnt<N)
    {   cnt2=K;
        while(cnt2>0){
            i++;
            if(i>N)
                i=1;
            if(num[i])
                continue;
            cnt2--;
        }
       
        q.push(i);
        num[i]=1;
        cnt++;
    }
    printf("<%d", q.front());
    q.pop();
    while(!q.empty()){
        printf(", %d", q.front());
        q.pop();
    }
    printf(">\n");
    return 0;
}