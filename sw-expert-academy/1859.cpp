#include<cstdio>
int T, i, j, index, input, num[1000000], maxnum[1000000];
long long sum[10]; //주의

//최댓값 인덱스 구하기(현재~끝까지)
int max(int N){
    index=N-1;
    for(j=N-1;j>=0;j--){
        if(num[index]<num[j])
            index=j;

        maxnum[j] = index;
    }
}

int main(){
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d",&input);
        for(j=0;j<input;j++){
            scanf("%d",&num[j]);
        }
        max(input);
        for(j=0;j<input;j++){
        if(num[j]<num[maxnum[j]])
            sum[i] +=num[maxnum[j]]-num[j];
        }

    }
    //출력
    for(i=1;i<=T;i++){
        printf("#%d %lld\n",i,sum[i]);
    }
    return 0;
}