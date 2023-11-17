#include<cstdio>

int T, num, N, i, j, k, l, a, b,result[11];
char alp[100][101];
bool check;
int main(){
    T=10;
    for(i=1;i<=T;i++){
        scanf("%d", &num);
        for(j=0;j<100;j++){
            for(k=0;k<=100;k++){
                scanf("%c", &alp[j][k]);
            }
        }
        //가로줄 체크
        for(N=1;N<=100; N++){
            for(j=0;j<100;j++){
                a=0; // 다음 시작점을 +1씩 바꿔줌 
                for(k=1;k<=100-(N-1);k++)
                {   check=false;
                    for(l=k+(N-1);l>=k;l--){
                        if(alp[j][l]==alp[j][k+N-l+a])
                            continue;
                        else{
                            check=true;
                            break;
                        }
                }   
                if(!check){
                    if( result[i]<N)
                         result[i]=N;
                }
                a++;
            }
        }
        }
        for(N=1;N<=100; N++){
        //새로줄 체크
            for(j=1;j<=100;j++){
                b=0; // 다음 시작점을 +1씩 바꿔줌 
                for(k=0;k<=100-N;k++)
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
                    if(!check){
                        if(result[i]<N)
                            result[i]=N;
                    }
                    b++;
                }
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n", i, result[i]);
    }

    return 0;
}