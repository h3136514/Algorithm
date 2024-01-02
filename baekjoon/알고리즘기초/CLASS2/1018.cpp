#include<cstdio>
int N, M, i, j, min, cnt, row, col;
char board[51][51];
bool isBlack, start;
int main(){
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++){
        scanf("%s", &board[i]);
    }

    min=2500;
    while(true){
        start=true;
        for(i=row;i<8+row;i++){
            if(i%2 == 0)
                isBlack=true;
            else
                isBlack=false;
            for(j=col;j<8+col;j++){
                if(isBlack){
                    if(board[i][j] != 'B')
                        cnt++;
                    isBlack=false;
                }else{
                    if(board[i][j] != 'W')
                        cnt++;
                    isBlack=true;
                }
            }
        }
        if(cnt < min)
            min =cnt;
        cnt=0;
        if(col+8==M){
            col=0;
            if(row+8==N)
                break;
            else
                row++;
        }else{
            col++;
        }
    }
    cnt=0;
    row=0;
    col=0;
    while(true){
        isBlack=false;
        for(i=row;i<8+row;i++){
            if(i%2 == 0)
                isBlack=false;
            else
                isBlack=true;
            for(j=col;j<col+8;j++){
                if(isBlack){
                    if(board[i][j] != 'B')
                        cnt++;
                    isBlack=false;
                }else{
                    if(board[i][j] != 'W')
                        cnt++;
                    isBlack=true;
                }
            }
        }
        if(cnt < min)
            min =cnt;
        cnt=0;
        if(col+8==M){
            col=0;
            if(row+8==N)
                break;
            else
                row++;
        }else{
            col++;
        }
    }
    printf("%d\n",min);
    return 0;
}