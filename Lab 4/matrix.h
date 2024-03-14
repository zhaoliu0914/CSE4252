#include <vector>
#include <iostream>
// You may add other header files if needed
using namespace std;

template<typename T>
class Matrix {
    // Please finish the Matrix template
public:

    std::vector<std::vector<T>> ndArray;

    Matrix();

    Matrix(std::vector<std::vector<T>> arrays) {
        this->ndArray = arrays;
    }

    Matrix<T> mul(Matrix<T> rightMatrix) {
        std::vector<std::vector<T>> result(ndArray.size(), std::vector<T>(rightMatrix.ndArray[0].size()));

        int rowSize = ndArray.size();
        for (int i = 0; i < rowSize; i++) {
            int columnSize = ndArray[i].size();
            int newColumnSize = rightMatrix.ndArray[0].size();

            for (int k = 0; k < newColumnSize; k++) {
                T sum = 0;
                for (int j = 0; j < columnSize; j++) {
                    //std::cout << "ndArray[" << i << "][" << j << "] = " << ndArray[i][j] << std::endl;
                    //std::cout << "rightMatrixArray[" << j << "][" << k << "] = " << rightMatrix.ndArray[j][k] << std::endl;

                    sum += ndArray[i][j] * rightMatrix.ndArray[j][k];
                }

                result[i][k] = sum;
            }

        }

        /*
        for(int i=0; i<result.size(); i++){
            for(int j=0; j<result[i].size(); j++){
                std::cout << "result[" << i << "][" << j << "] = " << result[i][j] << std::endl;
            }
        }
        */

        //Matrix<T> newMatrix = Matrix<T>(result);
        Matrix<T> newMatrix(result);

        return newMatrix;
    }

    T sum() {
        T sum = 0;
        int rowSize = ndArray.size();
        for (int i = 0; i < rowSize; i++) {
            int columnSize = ndArray[i].size();
            for (int j = 0; j < columnSize; j++) {
                sum += ndArray[i][j];
            }
        }

        return sum;
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        std::vector<std::vector<T>> ndArray = matrix.ndArray;
        int rowSize = ndArray.size();
        for (int i = 0; i < rowSize; i++) {
            int columnSize = ndArray[i].size();

            for (int j = 0; j < columnSize; j++) {
                os << ndArray[i][j] << " ";
            }

            if (i < rowSize - 1) {
                os << std::endl;
            }
        }

        return os;
    }

};
