#include<cstdio>

int num[3], sum, max, maxidx, i, cnt;
int main(){
    while(true){
        max=0;
        maxidx=0;
        sum=0;
        cnt=0;
        for(i=0;i<3;i++){
            scanf("%d", &num[i]);
            if(max < num[i]){
                max=num[i];
                maxidx = i;
            }
            if(num[i]==0)
                cnt++;
        }
        if(cnt==3)
            break;
        for(i=0;i<3;i++){
            if( maxidx == i)
                continue;
            sum +=(num[i]*num[i]);
        }
        if((max*max) == sum)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;

}