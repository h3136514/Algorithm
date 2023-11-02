#include<cstdio>
int i, num;
int main(){
   scanf("%d", &num);
   for (i = num; i >= 0; i--) {
      printf("%d ", i);
   }
   return 0;
}