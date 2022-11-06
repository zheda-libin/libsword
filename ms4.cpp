#include "base.h"


// 方法1. c语言
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    // matrix如果是nullptr, matrixSize代表row, matrixColSize[0]代表col
    if (!matrix || matrixSize<=0 || matrixColSize[0]<=0) {
        return false;
    }
    int rows=matrixSize, row=0;
    int cols = matrixColSize[0], col=cols-1;
    while(row < rows && col >= 0) {
        if (matrix[row][col] == target){
            return true;
        } else if (matrix[row][col] > target) {
            col--;
        } else {
            row++;
        }
    }
    // 当遍历完跳出以后, 直接返回false.
    return false;
}


// 方法2. C++版本
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        if (matrix[0].empty()) {
            return false;
        }
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();

        int row = 0, col = cols-1;
        while(row<rows && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                row++;
            }
            else {
                col--;
            }
        }
        return false;
    }
};
