#include<cstdio>
#include<vector>
using namespace std;

vector<pair<char, int>> v[11]; 
int T, i, j, k, N, num, cnt;
char alp;


int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        for(j=0;j<N;j++){
            scanf("%s %d", &alp, &num);
            v[i].push_back({alp, num});
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d\n",i);
        N=v[i].size();
        cnt=0;
        for(k=0;k<N;k++){
            alp = v[i][k].first;
            num = v[i][k].second;
            
            while(0 < num--){
                cnt++;
                if(cnt>10){
                    printf("\n");
                    num++;
                    cnt=0;
                    continue;
                }
                printf("%c", alp);
            }
        }
        printf("\n");
    }
    return 0;
}