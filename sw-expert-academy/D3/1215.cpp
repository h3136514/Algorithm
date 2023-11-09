#include<cstdio>

int T, N, i, j, k, l, cnt, a, b,result[11];
char alp[8][9];
bool check;
int main(){
    T=10;
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        for(j=0;j<8;j++){
            for(k=0;k<=8;k++){
                scanf("%c", &alp[j][k]);
            }
        }
        cnt=0;
        //가로줄 체크
        for(j=0;j<8;j++){
            a=0; // 다음 시작점을 +1씩 바꿔줌 
            for(k=1;k<=8-(N-1);k++)
            {   check=false;
                for(l=k+(N-1);l>=k;l--){
                    if(alp[j][l]==alp[j][k+N-l+a])
                        continue;
                    else{
                        check=true;
                        break;
                    }
                }
                if(!check)
                    cnt++; 
                a++;
            }
        }
        result[i] +=cnt;
        cnt=0;
        //새로줄 체크
        for(j=1;j<=8;j++){
            b=0; // 다음 시작점을 +1씩 바꿔줌 
            for(k=0;k<=8-N;k++)
            {   check=false;
                for(l=k+N-1;l>=k;l--)
                {
                    if(alp[k+(N-1)-l+b][j] == alp[l][j])
                        continue;
                    else{
                        check=true;
                        break;
                    }  
                }
                if(!check)
                    cnt++; 
                b++;
            }
        }
        result[i] +=cnt;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n", i, result[i]);
    }

    return 0;
}