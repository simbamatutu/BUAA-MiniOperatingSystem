#include<stdio.h>
int main()
{
	int n,rev=0,remainer,a;
	scanf("%d",&n);
	a=n;

	while(n!=0){
		remainer=n%10;
		rev=rev*10+remainer;
		n/=10;
	}



	if(rev==a){
		printf("Y\n");
	}else{
		printf("N\n");
	}
	return 0;
}
