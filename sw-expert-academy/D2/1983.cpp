#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

priority_queue <pair<double, int>> q[11];
int T, i, j, N, K, ind;
double mid, fin, hw, sum;
char result[11][3];

//점수 확인 함수
void score(int N, int i, int ind){
    int v=(N/10);
    int value;
    if(ind<=v)
        value=1;
    else
        value=(ind)%v==0 ?(ind)/v :(ind)/v+1;
    switch(value)
    {
        case 1:
            strcpy(result[i],"A+");
            break;
        case 2:
            strcpy(result[i],"A0");
            break;
        case 3:
            strcpy(result[i],"A-");
            break;
        case 4:
            strcpy(result[i],"B+");
            break;
        case 5:
            strcpy(result[i],"B0");
            break;
        case 6:
            strcpy(result[i],"B-");
            break;
        case 7:
            strcpy(result[i],"C+");
            break;
        case 8:
            strcpy(result[i],"C0");
            break;
        case 9:
            strcpy(result[i],"C-");
            break;
        case 10:
            strcpy(result[i],"D0");
            break;
    }
}
int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d %d", &N, &K);
        for(j=1;j<=N;j++){
            scanf("%lf", &mid);
            scanf("%lf", &fin);
            scanf("%lf", &hw);
            sum = (mid*0.35) +(fin*0.45) +(hw*0.2);
            q[i].push({sum, j});
        }
        ind=0;
        //점수 계산
        while(q[i].size()){
            ind++;
            int here= q[i].top().second;
            if(here ==K)
                score(N, i, ind);
            q[i].pop();
        }
        printf("#%d %s\n",i, result[i]);
    }
     for(i=1;i<=T;i++){
        printf("#%d %s\n",i, result[i]);
     }

    return 0;
}