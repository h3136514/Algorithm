#include<cstdio>

int T, N, M, num[15][15], i, j, k, max[11], tmp, row, col;

//초기화
void init(){
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++){
            num[j][k]=0;
        }
    }
    row=0;
    col=0;
    tmp=0;
}

int main() {
   scanf("%d", &T);
   for (i = 1; i <= T; i++) {
      scanf("%d %d", &N, &M);
      for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            scanf("%d", &num[j][k]);
        }
      }
      //죽은 파리의 개수 분석
      while (true) {
        tmp=0;
        for (j = row; j < row + M; j++) {
            for (k = col; k < col + M; k++){
               tmp += num[j][k];
            }
         }
        if (max[i] < tmp)
            max[i] = tmp;
        //끝까지 다 살펴봄
        if (row + M > N  && col == 0)
            break;
        //맨 오른쪽까지
        if (++col + M <= N)
            continue;
        col=0;
        //맨 아래까지
        if (++row + M<= N)
            continue;
        
      }
    init(); //초기화
   }
   //출력
   for (i = 1; i <= T; i++) {
        printf("#%d %d\n",i, max[i]);
   }
   return 0;
}