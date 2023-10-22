/* student.cpp */

#include <iostream>
#include <iterator>
#include <numeric>
#include <map>

using namespace std;

typedef struct{
	char name[20];
	int midTest_score;
	int finTest_score;
}node;

int main(){

	int stu_count;
	map<int, node> student_map;

	cout << "학생 수를 입력하세요 : ";
	cin >> stu_count;

	for(int i = 0; i < stu_count; i++){
		node student_node;

		cout << "학생 정보를 입력하세요 : ";
		cin >> student_node.name >> student_node.midTest_score >> student_node.finTest_score;

		student_map.emplace(i,student_node);
	}

	for(auto &student : student_map){
		cout << "이름 : " << student.second.name 
			<< ", 중간 점수 : " << student.second.midTest_score
			<< ", 기말 점수 : " << student.second.finTest_score<<endl;
	}
	
	return 0;
}
