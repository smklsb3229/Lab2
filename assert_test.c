/* assert_test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

void my_assert(int expression, const char* str){
	if(!expression){
		fprintf(stderr, "%s : %s\n", str, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[]){
	FILE *f;

	if(argc < 2){
		printf("Usage: assert_test nofilename\n");
		exit(1);
	}

	f = fopen(argv[1], "r");

	my_assert(f != NULL, "fopen");

	printf("Open a file \"%s\".\n", argv[1]);

	fclose(f);
}
