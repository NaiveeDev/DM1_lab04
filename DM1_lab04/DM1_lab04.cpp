#include <vector>
#include <string>
#include <Windows.h>
#include <iostream>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;

void PrintMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

void ReflexiveClosure(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i][i] = 1;
    }
}

void SymmetricClosure(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 1 || matrix[j][i] == 1) {
                matrix[i][j] = matrix[j][i] = 1;
            }
        }
    }
}


void TransitiveClosure(std::vector<std::vector<int>>& matrix) {
    for (int k = 0; k < matrix.size(); ++k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[i][k] && matrix[k][j]) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
}

void PrintMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool isAntisymmetric(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                return false;
            }
        }
    }
    return true;
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

bool isStrictOrder(vector<vector<int>>& matrix) {
    return isAntisymmetric(matrix) && isTransitive(matrix);
}

bool isPartialOrder(vector<vector<int>>& matrix) {
    return isReflexive(matrix) && isAntisymmetric(matrix) && isTransitive(matrix);
}

bool isEquivalenceRelation(vector<vector<int>>& matrix) {
    return isReflexive(matrix) && isSymmetric(matrix) && isTransitive(matrix);
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

    /*cout << (isReflexive(matrix) ? "Відношення є рефлексивним" : "Відношення не є рефлексивним") << endl;
    cout << (isSymmetric(matrix) ? "Відношення є симетричним" : "Відношення не є симетричним") << endl;
    cout << (isTransitive(matrix) ? "Відношення є транзитивним" : "Відношення не є транзитивним") << endl;


    vector<vector<bool>> MatrixSquare = FindSquare(matrix);
    cout << "Квадрат відношення:" << endl;
    PrintMatrix(MatrixSquare);

    vector<vector<bool>> MatrixCube = FindCube(matrix);
    cout << "Куб відношення:" << endl;
    PrintMatrix(MatrixCube);*/

    ReflexiveClosure(matrix);
    std::cout << "\nРефлексивне замикання:" << std::endl;
    PrintMatrix(matrix);

    std::vector<std::vector<int>> SymmetricMatrix = matrix;
    SymmetricClosure(SymmetricMatrix);
    std::cout << "\nСиметричне замикання:" << std::endl;
    //PrintMatrix(SymmetricMatrix);

    std::vector<std::vector<int>> TransitiveMatrix = matrix;
    TransitiveClosure(TransitiveMatrix);
    std::cout << "\nТранзитивне замикання:" << std::endl;
    PrintMatrix(TransitiveMatrix);

    return 0;
}
