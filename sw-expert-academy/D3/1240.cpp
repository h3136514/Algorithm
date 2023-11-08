#include<cstdio>
#include<cstring>
using namespace std;


int T, N, M, i, j, k, l, cnt, strcnt, sum, decode[8], result[11];
bool first =true;
bool corret =true; 
char num[50][101], encode[56], s[7];

int check(){
    if(!strcmp(s,"0001101"))
        return 0;
    else if(!strcmp(s,"0011001"))
        return 1;
    else if(!strcmp(s,"0010011"))
        return 2;
    else if(!strcmp(s,"0111101"))
        return 3;
    else if(!strcmp(s,"0100011"))
        return 4;
    else if(!strcmp(s,"0110001"))
        return 5;
    else if(!strcmp(s,"0101111"))
        return 6;
    else if(!strcmp(s,"0111011"))
        return 7;
    else if(!strcmp(s,"0110111"))
        return 8;
    else if(!strcmp(s,"0001011"))
        return 9;
    else
        return 10;

}
int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        first =true;
        corret =true;
        cnt=55;
        scanf("%d %d", &N, &M);
        for(j=0;j<N;j++){
            for(k=0;k<=M;k++){  //주의: 맨뒤 뛰어쓰기 신경쓰기
                scanf("%c", &num[j][k]);
            }
        }
       
        for(j=0;j<N;j++){
            for(k=M-1;k>=0;k--){
                //뒤에서 부터 처음으로 1을 봤을때 거기 부터 56개 기억
                if(first && num[j][k]=='1')
                {
                    first= false;
                    encode[cnt--]=num[j][k];
                    continue;
                }
                if(cnt<0)
                    break;
                if(cnt<55){
                    encode[cnt--]=num[j][k];
                }
            }          
        }
        for(j=0;j<8;j++){
            strcnt=0; //비교문자열수 초기화
            for(k=j*7;k<j*7+7;k++){
                s[strcnt++]=encode[k]; //  문자열 붙이기
            }
            decode[j]=check();
            if(decode[j]==10)   //해독할 수 없는경우
                corret= false;
        }
        
        sum =(decode[0] + decode[2]+ decode[4] + decode[6])*3 +(decode[1] + decode[3]+ decode[5] + decode[7]);
        
        if(corret && sum%10==0)
            result[i]=decode[0] + decode[2]+ decode[4] + decode[6]+decode[1] + decode[3]+ decode[5] + decode[7];
        else
            result[i]=0;

    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i,result[i]);
        
    }
    return 0;
}