#include <stdio.h>
#include <math.h>
int main()
{
	//註解
	/*註解們
	註解們
	*/
	int i, j, k; // Z
	double a, b, c; // R
	double x[10], u[10]; //vector
	double A[10][10]; //matrix
	// Moving Average, example, 三個平均
	/* u[0] = (x[0]+x[1]+x[2])/3 
	   u[1] = (x[1]+x[2]+x[3])/3
	   ...
	   In programm, we need to give a general form:
	   u[i] = (x[i]+x[i+1]+x[i+2])/3
	   ...
	   u[?] = (x[7]+x[8]+x[9])/3
	*/
	// for loop
	// for(initial condition; end condition)
	for(i=0;i<=10;i=i+1)
	{
		x[i] = cos(M_PI*2*i/10); // 整數運算仍為整數,除非先用double [try]: cos(2*i/10*M_PI) 
		printf("x[%d]=%f\n",i,x[i]); 
	}
	for (i=0;i<8;i=i+1)
	{
		u[i]=(x[i]+x[i+1]+x[i+2])/3;
	}
	/*
		3U = [1 1 1 0 0 ... 0] x [0]
			 [0 1 1 1 0 ... 0] x [1] 
	*/
	// 以上是baby problem 
	return 0;  
}

int youth_problem(int n, int K) //副程式 
{
	int i, j, k; // Z
	double a, b, c; // R
	double x[n], u[n]; //vector
	double A[n][n]; //matrix
	// Moving Average, example, k個平均
	/* u[0] = ( x[0] + x[1] + ... + x[k-1] )/k
	   u[1] = ( x[1] + x[2] + ... + x[k] )/k
	   ...
	   ...
	   u[i] = ( x[i] + x[i+1] + ... + x[i+k-1] )/k
	   ...
	   ...
	   u[n-k] = ( x[n-k] + x[n-k+1] +... + x[n-1] )/k
	*/

	for (i=0;i<n-K;i=i+1)
	{
		/*
		u[i] = x[i] + x[i+1] + ... + x[i+k-1]
		step 0 : u[i] = x[i]
		step 1 : u[i] = x[i] + x[i+1]                    = u[i] + x[i+1]
		step 2 : u[i] = x[i] + x[i+1] + x [i+2]          = u[i] + x[i+2]
		step 3 : u[i] = x[i] + x[i+1] + x [i+2] + x[i+3] = u[i] + x[i+3]
		...
		step j : u[i]=u[i] + x[i+j]
		*/
		u[i] = x[i]; // step0
		for (j=0;j=K-1;j=j+1)
		{
			u[i]=u[i]+x[i+j];
		}
		u[i] = u[i]/K;
	}
}

int university_problem(int n, int K)//簡化加法
{
	int i, j, k; // Z
	double a, b, c; // R
	double x[n], u[n]; //vector
	double A[n][n]; 
	// Moving Average, k個平均
	/* u[0] = ( x[0] + x[1] + ... + x[k-1] )/k
	   u[1] = ( x[1] + x[2] + ... + x[k] )/k
	   u[2] = ( x[2] + x[3] + ... + x[k+1 )/k
	   
	   {思考 : 如何從u[0] ---> u[1]
	    
	   u[1] = ( k*u[0] - x[0] + x[k] )/k  ==> u[1] = u[0] + (-x[0] + x[k]) / k 
	   
	   General Form
	   
	   u[i] = u[i-1] + (-x[i-1] + x[k+i-1] )/k }
	   
	   
	   ...
	   ...
	   u[i] = ( x[i] + x[i+1] + ... + x[i+k-1] )/k
	   ...
	   ...
	   u[n-k] = ( x[n-k] + x[n-k+1] +... + x[n-1] )/k
	*/
	i = 0;
	u[i] = x[i]; // step 0
	
	for (j=1;j=K;j=j+1) // j = 1 2 ... k-1 
	{
		u[i] = u[i] + x[i+j];
	}
	u[i] = u[i]/K;
	for (i=1;i<=n-K;i=i+1)
	{
		u[i] = u[i-1] + ( x[k+i-1]-x[i-1] )/K;
	} 
	return 0;
} 
 


