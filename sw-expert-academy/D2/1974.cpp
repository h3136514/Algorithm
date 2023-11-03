#include<cstdio>
int T, i, j, k, row, col, result[11]={1,1,1,1,1,1,1,1,1,1,1}, num[9][9], check[10];

void Checkinit() //숫자 확인 초기화
{
    for(k=0;k<10;k++)
        check[k] =0;
}

void Checkbox() // 3x3 격자의 숫자 겹치는지 확인
{   row=0;
    col=0;
    while(true){
        Checkinit();
        for(j=row;j<row+3;j++){
            for(k=col;k<col+3;k++){
                if(check[num[j][k]] == 0)
                    check[num[j][k]] = 1;
                else
                {
                    result[i] =0;
                    return;
                }
            }
        }
        col +=3;
        if(col>=9){
            row +=3;
            col=0;
            if(row >=9) //끝까지 다 확인
                break;
        }
    }
}
void Checkrow() //가로줄 숫자 겹치는지 확인
{
    for(j=0;j<9;j++){
        Checkinit();
        for(k=0;k<9;k++){
            if(check[num[k][j]] == 0)
                check[num[k][j]] = 1;
            else
            {
                result[i] =0;
                return;
            }
        }
    }
}
void Checkcol() //세로줄 숫자 겹치는지 확인
{
    for(j=0;j<9;j++){
        Checkinit();
        for(k=0;k<9;k++){
            if(check[num[j][k]] == 0)
                check[num[j][k]] = 1;
            else
            {
                result[i] =0;
                return;
            }
        }
    }
}


int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        for(j=0;j<9;j++)
            for(k=0;k<9;k++)
                scanf("%d", &num[j][k]);
        Checkbox();
        Checkrow();
        Checkcol();
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i, result[i]);
    }
    return 0;
}