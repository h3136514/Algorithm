#include<cstdio>
int N, x, y, q1, q2, q3, q4, axis, i;

int main() {
    scanf("%d", &N);

    for(i=1;i<=N;i++){
        scanf("%d %d", &x, &y);
        if(x==0 || y==0)
            axis++;
        else if(x > 0) {
            if(y > 0)
                q1++;
            else
                q4++;
        }else {
            if(y > 0)
                q2++;
            else
                q3++;
        }
    }

    printf("Q1: %d\n", q1);
    printf("Q2: %d\n", q2);
    printf("Q3: %d\n", q3);
    printf("Q4: %d\n", q4);
    printf("AXIS: %d\n", axis);

    return 0;
}