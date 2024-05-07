#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countPaths(vector<string>& matrix, int row, int col, int index, string target) {
    if (index == target.size()-1 && matrix[row][col] == target[index]) {
        return 1;
    }

    if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] != target[index])
        return 0;

    //char original = matrix[row][col];
    //matrix[row][col] = '*';

    int paths = countPaths(matrix, row + 1, col, index + 1, target) +
                countPaths(matrix, row - 1, col, index + 1, target) +
                countPaths(matrix, row, col + 1, index + 1, target) +
                countPaths(matrix, row, col - 1, index + 1, target);

    //matrix[row][col] = original;

    return paths;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> matrix(n);
    for (int i = 0; i < n; ++i)
        cin >> matrix[i];

    string target = "tencent";
    int totalPaths = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            totalPaths += countPaths(matrix, i, j, 0, target);
        }
    }

    cout << totalPaths << endl;

    return 0;
}