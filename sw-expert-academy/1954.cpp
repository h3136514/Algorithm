#include<cstdio>
int T, i, j, k, num[11], N[10][10], count, row, col;


int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d",&num[i]);
    }
    
    for(i=1;i<=T;i++){
        printf("#%d\n", i);
        //달팽이 만들기
         N[0][0]=++count;
        while(true){
            while(N[row][++col] ==0 && col<num[i]) //오른쪽 증가
            {
                 N[row][col]=++count;
            }
            col--;
            while(N[++row][col] ==0 && row<num[i]) //아랫쪽 증가
            {
                N[row][col]=++count;
            }
            row--;
            while(N[row][--col] ==0 && col >=0 )   //왼쪽 증가
            {
                N[row][col]=++count;
            }
            col++;
            while(N[--row][col] ==0 && col >=0 )   //윗쪽 증가
            {
                N[row][col]=++count;
            }
            row++;
            //탈출
            if(count ==num[i]*num[i])
                break;
        }
        row=0;
        col=0;
        count=0;
        //출력 & 초기화
        for(j=0;j<num[i];j++){
            for(k=0;k<num[i];k++)
            {
                printf("%d ", N[j][k]);
                N[j][k]=0;
            }
            printf("\n");
        }
    }
    
    return 0;
}