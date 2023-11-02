#include<cstdio>
int num, sum;
int main(){
   scanf("%d", &num);
   while (num > 0) {
      sum += num % 10;
      num = num / 10;
   }
   printf("%d", sum);
   return 0;
}