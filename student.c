/* student.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

typedef struct{
	char* name;
	int midTest_score;
	int finTest_score;
}node;

char* stu_nametable;
node* nodetable;
node* root = NULL;

int compare(const void *cp1, const void *cp2){
	return strcmp(((node *)cp1)->name, ((node *)cp2)->name);
}

void print_node(const void *, VISIT, int);

int main(){
	
	int stu_count;
	printf("학생 수를 입력하세요 : ");
	scanf("%d", &stu_count);

	stu_nametable = (char *) malloc(sizeof(char) * stu_count * 100);
	nodetable = (node *) malloc(sizeof(node) * stu_count);

	char *studentptr = stu_nametable;
	node *nodeptr = nodetable;
	node **ret;
	int i = 0;

	for(int i = 0; i < stu_count; i++){
		printf("학생 정보를 입력하세요 : \n");
		scanf("%99s %d %d", studentptr, &nodeptr->midTest_score, &nodeptr->finTest_score);

		nodeptr->name = studentptr;

		ret = (node**) tsearch ((void *) nodeptr, (void **) &root, compare);
		printf("\"%s\"", (*ret)->name);

		if(*ret == nodeptr)
			printf("TREE에 추가되었습니다.\n");
		else 
			printf("TREE에 이미 존재합니다.\n");

		studentptr += strlen(studentptr) + 1;
		nodeptr++;
	}

	twalk((void *) root, print_node);

	free(stu_nametable);
	free(nodetable);

	return 0;
}

void print_node(const void *nodeptr, VISIT order, int level){
	if(order == preorder || order == leaf){
		printf("학생 이름 = %-10s, 중간 점수 = %d, 기말 점수 = %d\n",
				(*(node **)nodeptr)->name,
				(*(node **)nodeptr)->midTest_score,
				(*(node **)nodeptr)->finTest_score);
	}
}
