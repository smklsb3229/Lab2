/* dltest.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h> //동적 라이브러리를 사용하기 위한 C 표준 라이브러리 헤더 파일

int main(){
	void *handle;
	int (*add)(int, int), (*subtract)(int, int), (*multiply)(int, int), (*divide)(int, int);
	char *error;

	handle = dlopen ("./lib/libshare.so", RTLD_LAZY);

	if(!handle){
		fputs (dlerror(), stderr);
		exit(1);
	}

	char* str = (char*)malloc(10*sizeof(char));
	int num1, num2;

	printf("사칙 연산을 입력하세요 : ");
	scanf("%s", str);

	printf("두 개의 숫자를 입력하세요 : ");
	scanf("%d %d", &num1, &num2);

	if(strcmp(str, "add")==0) {
		add = dlsym(handle,"add");
		if((error = dlerror()) != NULL) {
			fprintf(stderr, "%s", error);
			exit(1);
		}
		printf("add = %d\n", (*add)(num1, num2));
	}
	else if(strcmp(str, "sub")==0) {
                subtract = dlsym(handle,"subtract");
                if((error = dlerror()) != NULL) {
                        fprintf(stderr, "%s", error);
                        exit(1);
                }
                printf("subtract = %d\n", (*subtract)(num1, num2));
        }
	else if(strcmp(str, "mult")==0) {
                multiply = dlsym(handle,"multiply");
                if((error = dlerror()) != NULL) {
                        fprintf(stderr, "%s", error);
                        exit(1);
                }
                printf("multiply = %d\n", (*multiply)(num1, num2));
        }
	else if(strcmp(str, "div")==0) {
                divide = dlsym(handle,"divide");
                if((error = dlerror()) != NULL) {
                        fprintf(stderr, "%s", error);
                        exit(1);
                }
                printf("divide = %d\n", (*divide)(num1, num2));
        }
dlclose(handle);
free(str);
}
