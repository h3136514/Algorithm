#include<cstdio>
#include<queue>
using namespace std;

queue <int> q[11];
int T, N, i, j, num, here, cnt;

int main(){
    T=10;
    for(i=1;i<=T;i++){
        scanf("%d",&N);
        for(j=0;j<8;j++)
        {
            scanf("%d",&num);
            q[i].push(num);
        }
        cnt=1;
        while(true)
        {
            if(cnt>5)
                cnt=1;
            here=q[i].front();
            q[i].pop();
            if(here-cnt<=0){
                q[i].push(0);
                break;
            }
            q[i].push(here-cnt);
            cnt++;
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d ",i);
        while(!q[i].empty()){
            here=q[i].front();
            q[i].pop();
            printf("%d ",here);
        }
        printf("\n");
    }
    return 0;
}
