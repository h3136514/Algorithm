#include<cstdio>

int n, k, i, j, erase[1002];

int main() {
	scanf("%d %d", &n, &k);
	for (i = 2; i<= n; i++) {
		if (erase[i])   //이미 지웠으면 패스
			continue;

        //지운값의 배수들도 지움
		for (j = 1; j * i <= n; j++) {
			if (erase[j*i]) //이미 지웠으면 패스
				continue;

			erase[j * i] = 1; //지우기
			k--;
			if (k==0) {
				printf("%d", j * i);
			}
		}
	}
}