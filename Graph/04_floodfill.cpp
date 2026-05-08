#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void floodFiller(vector<vector<int>> &image, int i, int j,
                     int m, int n, int currColor, int newColor) {

        // Base condition (boundary + invalid cases)
        if (i < 0 || i >= m || j < 0 || j >= n ||
            image[i][j] != currColor || image[i][j] == newColor)
            return;

        // Color the current cell
        image[i][j] = newColor;

        // Explore 4 directions
        floodFiller(image, i - 1, j, m, n, currColor, newColor); // up
        floodFiller(image, i + 1, j, m, n, currColor, newColor); // down
        floodFiller(image, i, j - 1, m, n, currColor, newColor); // left
        floodFiller(image, i, j + 1, m, n, currColor, newColor); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();

        int currColor = image[sr][sc];

        // Optimization: if same color, no work needed
        if (currColor == newColor) return image;

        floodFiller(image, sr, sc, m, n, currColor, newColor);
        return image;
    }
};

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> image(m, vector<int>(n));

    cout << "Enter matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cout << "Enter start row, start col, new color: ";
    cin >> sr >> sc >> newColor;

    Solution obj;
    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);

    cout << "\nUpdated Image:\n";
    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}