#include<cstdio>
int n, i, count, j, input[100000],a[1000000], b[1000000];
bool num[1000000]={true,true}; //소수 판별(true이면 소수가 아님)



int main() {
	//에라토스테네스의 체 만들기
	for (i = 2; i * i < 1000000; i++)
	{
		if (num[i])
			continue;
		for (j = i+i ; j < 1000000; j += i) {
			num[j] = true;
		}
	}

	while(true){
		scanf("%d", &input[count]); //수 입력
		if(!input[count])
			break;
	
		for (i = 2; i < input[count]; i++)
		{	
		if(!num[i] && !num[input[count]-i]) //소수 + 나머지수(입력-해당수)도 소수일때
			{
				a[count]=i;
				b[count]=input[count]-i;
				break;
			}
		}
		count++;
	}
		for (i = 0; i <count; i++){
			if(!a[i]){
			printf("Goldbach's conjecture is wrong.\n");
			continue;
			}
			printf("%d = %d + %d\n", input[i], a[i], b[i]);
				
		}
	
}