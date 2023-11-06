#include<cstdio>

int T, i, j, m1, d1, m2, d2, num, sum[11];
int month_acr(int month){
    switch(month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                num=31;
                break;
            case 2:
                num=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                num=30;
                break;
        }
    return num;
}

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
        if(m1==m2)
            sum[i] = month_acr(m1);
        else{
            sum[i] += month_acr(m1)- d1+1;
            sum[i] += d2;
            if( m1< m2)// m1~m2사이 월 일수 ( ex)1~4 ) 
            {
                for(j=m1+1;j<m2;j++)
                    sum[i] += month_acr(j);
            }else   //( ex)7~1 ) 
            {
                for(j=m1+1;j<13;j++)
                    sum[i] += month_acr(j);
                for(j=1;j<m2;j++)
                    sum[i] += month_acr(j);
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i, sum[i]);
    }
    return 0;
}
