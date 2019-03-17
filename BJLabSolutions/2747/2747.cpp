#include <iostream>


/*
*  [Recursion]
*
*  int fibo(int n){
*  	if(n<=1) return n;
*  	return fibo(n-1) + fibo(n-2);
*  }
*/



/*
*  [Dynamic Programming] 
*  You can implement the function with simple recursion
*  In this case, however, the complexity of the algorithm is exponential
*  To reduce the complexity from exponential to linear, Dynamic programming is used
*  The following lines are descriptions of the fibonacci function with dynamic programming 
*/

int fibo(int n){

	int tmp[46];

  tmp[0] = 0;
  tmp[1] = 1;

	for(int i=2; i<=n; i++){

			tmp[i] = tmp[i-1] + tmp[i-2];

	}


    return tmp[n];
   
}

int main(){

    int n;

    scanf("%d", &n);
    printf("%d\n", fibo(n));

    return 0;
}


