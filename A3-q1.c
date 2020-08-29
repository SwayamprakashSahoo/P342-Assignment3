//Program for Gauss-Jordan problem analysis

#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("Please enter the number of variables in the equations: ");
	int n;
	scanf("%d", &n);
	float mat[20][20];
	FILE* temp1 = fopen("Set1.txt", "r");
	if (temp1 == NULL)
		exit(1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			fscanf(temp1, "%f ", &mat[i][j]);
		}
	}

	printf("Matrix representation for given set of equations is:\n ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf(" %d",(int) (mat[i][j]));
		}
		printf("   x%d", i + 1);
		printf(" = %f", mat[i][n]);
		printf("\n ");
	}
	float c, x[20];
	for (int j = 0; j < n; j++)
	{
		for ( int i = 0; i < n; i++)
		{
			if (i != j)
			{
				c = mat[i][j] / mat[j][j];
				for (int k = 0; k < n + 1; k++)
				{
					mat[i][k] = mat[i][k] - c * mat[j][k];
				}
			}
		}
	}
	printf("\nThe solution is:\n");
	for (int i = 0; i < n; i++)
	{
		x[i] = mat[i][n] / mat[i][i];
		printf("\n x%d=%f\n", i+1, x[i]);
	}
	return(0);
}


/*
****************OUTPUT*****************
Please enter the number of variables in the equations: 3
Matrix representation for given set of equations is:
  1 3 2   x1 = 2.000000
  2 7 7   x2 = -1.000000
  2 5 2   x3 = 7.000000

The solution is:

 x1=3.000000

 x2=1.000000

 x3=-2.000000
 **************************************
 */
