/* matrix.c */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int row, col;
	
	printf("행  = ");
	scanf("%d", &row);

	printf("열  = ");
	scanf("%d", &col);

	int **matrix1 = malloc(sizeof(int *) * row);
	int **matrix2 = malloc(sizeof(int *) * row);
	
	for(int i = 0; i < row; i++){
		matrix1[i] = malloc(sizeof(int) * col);
		matrix2[i] = malloc(sizeof(int) * col);
	}

	printf("행렬 1 input : \n");
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			scanf("%d", &matrix1[i][j]);
		}
	}

	printf("행렬 2 input : \n");

	for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                        scanf("%d", &matrix2[i][j]);
                }
        }
	printf("행렬 1 + 행렬 2 result : \n");

	for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                        printf("%d ", matrix1[i][j] + matrix2[i][j]);
                }
		printf("\n");
        }
	for (int k = 0; k < row; k++){
		free(matrix1[k]);
		free(matrix2[k]);
	}

	free(matrix1);
	free(matrix2);

	return 0;
}
