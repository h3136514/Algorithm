#include<cstdio>
int num[3], max, sum, i;

int main(){
    while(true){
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        if(num[0]==0 && num[1]==0 && num[2]==0)
            break;
        if((num[0] >= num[1]) && (num[0] >= num[2]))
            max = 0;
        else if((num[1] >= num[0]) && (num[1] >= num[2]))
            max =1;
        else
            max =2;
        sum=0;
        for(i=0;i<3;i++){
            if(max == i)
                continue;
            sum += num[i];
        }
        if(num[max] >= sum)
        {   
            printf("Invalid\n");
            continue;
        }
        if(num[0]==num[1] && num[1]==num[2])
            printf("Equilateral\n");
        else if(num[0]==num[1] || num[1]==num[2] || num[0]==num[2])
            printf("Isosceles\n");
        else
            printf("Scalene\n");

    }
    
    return 0;
}