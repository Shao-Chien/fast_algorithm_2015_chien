#include <stdio.h>
#include <math.h>
int main()
{
	//����
	/*���ѭ�
	���ѭ�
	*/
	int i, j, k; // Z
	double a, b, c; // R
	double x[10], u[10]; //vector
	double A[10][10]; //matrix
	// Moving Average, example, �T�ӥ���
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
		x[i] = cos(M_PI*2*i/10); // ��ƹB�⤴�����,���D����double [try]: cos(2*i/10*M_PI) 
	}
	for (i=0;i<8)
	{
		u[i]=x[i]+x[i+1]+x[i+2];
	}
	 
	
	 
}
