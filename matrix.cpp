/* matrix.cpp */

#include <iostream>
#include <vector>
using namespace std;

int main(void){
	
	int row;
	int col;
	int num;

	cout << "행 = ";
	cin >> row;

	cout << "열 = ";
	cin >> col;

	vector<vector<int>> matrix1(row);
	vector<vector<int>> matrix2(row);

	for(int i = 0; i < row; i++){
		matrix1[i] = vector<int>(col);
		matrix2[i] = vector<int>(col);
	}

	cout << "행렬 1 input : \n";

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> num;
			matrix1[i][j] = num;
		}
	}

	cout << "행렬 2 input : \n";

        for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                        cin >> num;
                        matrix2[i][j] = num;
		}			
        }

	cout << "행렬 1 + 행렬 2 result : \n";

        for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                        cout << matrix1[i][j] + matrix2[i][j] << " ";
		}
		cout << endl;
        }
}
