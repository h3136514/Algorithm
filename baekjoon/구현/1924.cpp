#include<cstdio>
int x, y, i, cnt;
int month(int m) {
    int day;
    switch (m)
    {
    case 1 :
    case 3 :
    case 5 :
    case 7 :
    case 8 :
    case 10 :
    case 12 :
        day = 31;
        break;
    case 4 :
    case 6 :
    case 9 :
    case 11 :
        day = 30;
        break;
    default:
        day = 28;
        break;
    }

    return day;
}

int main() {
    scanf("%d %d", &x, &y);
    for(i=1;i<x;i++){
        cnt += month(i);
    }
    cnt += y;
    int day = cnt%7;
    if(day == 0)
        printf("%s\n", "SUN");
    else if(day == 1)
        printf("%s\n", "MON");
    else if(day == 2)
        printf("%s\n", "TUE");
    else if(day == 3)
        printf("%s\n", "WED");
    else if(day == 4)
        printf("%s\n", "THU");
    else if(day == 5)
        printf("%s\n", "FRI");
    else if(day == 6)
        printf("%s\n", "SAT");   

    return 0;
}