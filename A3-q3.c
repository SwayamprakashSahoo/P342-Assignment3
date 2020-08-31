//Program to find the inverse of a matrix and verify that their product is the identity matrix

#include <stdio.h>
#include <stdlib.h>

void pivot(float mat[][20], float inv[][20], int var);
void GaussJordan(float mat[][20], float inv[][20], int var);
void Matrix_mult(float mat[][20], float inv[][20], int var);

int main()
{
	int var=3;
	float mat[20][20],mat_copy[20][20];
	FILE* temp1 = fopen("Set3.txt", "r");
	if (temp1 == NULL)
		exit(1);

	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			fscanf(temp1, "%f ", &mat[i][j]);
		}
	}

	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			mat_copy[i][j] = mat[i][j];
		}
	}

	printf("\nThe matrix A is:\n");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			printf("%d   ", (int)(mat[i][j]));
		}
		printf("\n");
	}

	float inv[20][20];
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (i == j)
				inv[i][j] = 1;
			else
				inv[i][j] = 0;
		}
	}

	printf("The augmented matrix yields:\n");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			printf(" %d", (int)(mat[i][j]));
		}
		printf("   |  ");
		for (int j = 0; j < var; j++)
		{
			printf(" %d", (int)(inv[i][j]));
		}
		printf("\n");
	}

	GaussJordan(mat_copy, inv, var);
	Matrix_mult(mat, inv, var);
	return(0);

}

void pivot(float mat[][20], float inv[][20], int var)
{
	for (int i = 0; i < var - 1; i++)
	{
		if (mat[i][i] == 0)
		{
			for (int j = i + 1; j < var; j++)
			{
				if (abs(mat[j][i]) > mat[i][i])
				{
					for (int k = i; k < var + 1; k++)
					{
						float temp1 = mat[i][k];
						mat[i][k] = mat[j][k];
						mat[j][k] = temp1;
						float temp2 = inv[i][k];
						inv[i][k] = inv[j][k];
						inv[j][k] = temp2;
						continue;
					}
				}
			}
		}
	}
}

void GaussJordan(float mat[][20], float inv[][20], int var)
{
	for (int i = 0; i < var; i++)
	{
		pivot(mat,inv, var);
	}

	float c1;
	for (int j = 0; j < var; j++)
	{
		for (int i = 0; i < var; i++)
		{
			if (i != j)
			{
				c1 = mat[i][j] / mat[j][j];
				
				for (int k = 0; k < var; k++)
				{
					mat[i][k] = mat[i][k] - c1 * mat[j][k];
					inv[i][k] = inv[i][k] - c1 * inv[j][k];
				}
			}
		}
	}

	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			inv[i][j] = inv[i][j] / mat[i][i];
		}
	}

	printf("\nThe inverse of matrix A is:\n");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			printf("%d   ", (int)(inv[i][j]));
		}
		printf("\n");
	}
}

void Matrix_mult(float mat[][20], float inv[][20], int var)
{
	float product[20][20];
	printf("\nThe product of matrix A and its inverse is:\n");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			product[i][j] = 0;
			for (int k = 0; k < var; k++)
				product[i][j] = product[i][j] + mat[i][k] * inv[k][j];
			printf("%d ", (int)(product[i][j]));
		}
		printf("\n");
	}
}
