#include<cstdio>
int N[10], r, num, i, cnt;

int main() {
    scanf("%d", &num);
    while(0 < num) {
      r = num % 10;
      num = num/10;

      if(r==6 || r==9){
        N[6]++;
      }else {
        N[r]++;
      }
    }
    for(i=0;i<10;i++){
        if(i==6){
            if(N[6] % 2 == 1){
                if(cnt < (N[6]/2 + 1))
                    cnt = N[6]/2 + 1;
            }else {
                if(cnt < (N[6]/2))
                    cnt = N[6]/2;
            }
        }else {
            if(cnt < N[i])
                cnt = N[i];
        }
    }
    printf("%d\n", cnt);

    return 0;
}