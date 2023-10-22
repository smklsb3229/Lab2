/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <string.h>

int main(){
	char math[10];
	int num1 = 0;
	int num2 = 0;
	int result = 0;

	printf("사칙연산을 입력하세요 : ");
	scanf("%s", math);

	printf("번호 두 개를 입력하세요 : ");
	scanf("%d %d", &num1, &num2);

	if(strcmp(math, "add")==0){
		result = add(num1, num2);
		printf("add = %d\n", result);
	}
	else if(strcmp(math, "sub")==0){
                result = subtract(num1, num2);
                printf("sub = %d\n", result);
        }
	else if(strcmp(math, "mult")==0){
                result = multiply(num1, num2);
                printf("mult = %d\n", result);
        }
	else if(strcmp(math, "div")==0){
                result = divide(num1, num2);
                printf("div = %d\n", result);
        }
}
