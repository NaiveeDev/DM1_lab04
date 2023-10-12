#include <vector>
#include <string>
#include <Windows.h>
#include <iostream>


using std::cout; using std::cin; using std::endl;
using std::vector; using std::string; 


void PrintMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool isReflexive(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][i] != 1) {
            return false;
        }
    }
    return true;
}

bool isSymmetric(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                for (int k = 0; k < matrix.size(); k++) {
                    if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

vector<vector<int>> FindSquare(vector<vector<int>>& matrix) {
    vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            for (int k = 0; k < matrix[i].size(); k++) {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> FindCube(vector<vector<int>>& matrix) {
    
    vector<vector<int>> MatrixSquare = FindSquare(matrix);
    return FindSquare(MatrixSquare);
    
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    std::cout.setf(std::ios_base::boolalpha);

    vector<vector<int>> matrix = {
        {1, 0, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 0}
    };


    cout << "Початкова матриця:" << endl;
    PrintMatrix(matrix);

    cout << (isReflexive(matrix) ? "Відношення є рефлексивним" : "Відношення не є рефлексивним") << endl;
    cout << (isSymmetric(matrix) ? "Відношення є симетричним" : "Відношення не є симетричним") << endl;
    cout << (isTransitive(matrix) ? "Відношення є транзитивним" : "Відношення не є транзитивним") << endl;


    vector<vector<int>> MatrixSquare = FindSquare(matrix);
    cout << "Квадрат відношення:" << endl;
    PrintMatrix(MatrixSquare);

    vector<vector<int>> MatrixCube = FindCube(matrix);
    cout << "Куб відношення:" << endl;
    PrintMatrix(MatrixCube);

    return 0;
}
