#include <iostream>
#include <vector>

using namespace std;

int rows = 4;
int cols = 4;

vector<vector<int>>A;
vector<int> C;
vector<int> D;

void fillA(vector<vector<int>> &A) {
	for (int i = 0; i < cols; i++) {
		vector<int>InputVector;
		for (int j = 0; j < rows; j++) {
			InputVector.push_back(rand() % 5);
		}
		A.push_back(InputVector);
	}
}

vector<int> calculateC(vector<vector<int>> &arr) {
	int mul = 0;
	for (int i = 0; i < cols; i++) {
		mul = 1;
		for (int j = 0; j < rows; j++) {
			mul*= arr[j][i];
		}
		C.push_back(mul);
	}
	return C;
}

vector<int> calculateD(vector<vector<int>> &A) {
	int sum = 0;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) if (j != 4) sum += A[i][j];
		D.push_back(sum);
		sum = 0;
	}
	return D;
}

void showOneDimensionalArray(vector<int> oneDimArray, char ArrName) {
	cout << "\n" << ArrName << " = \n";
	switch (ArrName) {
		case 'C':
		case 'D':
			for (int i = 0; i < oneDimArray.size(); i++) cout << oneDimArray[i] << "\t";
			cout << "\n";
			break;
	}
}

void ShowA(vector<vector<int>> arr) {
	cout << "A = " << '\n';
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

}

int main() {
	fillA(A);
	ShowA(A);
	showOneDimensionalArray(calculateC(A), 'C');
	showOneDimensionalArray(calculateD(A), 'D');
	return 0;
}
