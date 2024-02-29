#include<cstdio>
int x, y, w, h, min;

int main(){
    scanf("%d %d %d %d", &x, &y, &w, &h);
    min = x;
    if (y < min) min = y;
	if (w - x < min) min = w - x;
	if (h - y < min) min = h - y;
    printf("%d\n", min);
    
    return 0;
}