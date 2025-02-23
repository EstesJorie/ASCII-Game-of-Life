#include "utils/bits/stdc++.hpp"
#include <iostream>
using namespace std;

// Function to find the next generation
void findNextGen(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> nextGen(m, vector<int>(n, 0));

    // Directions of eight possible neighbors
    vector<vector<int>> directions =
    {{0, 1}, {1, 0}, {0, -1},
     {-1, 0}, {1, 1}, {-1, -1},
     {1, -1}, {-1, 1}};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            // Count the number of live neighbors
            int live = 0;
            for (auto dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                // Check if the neighbor is live
                if (x >= 0 && x < m && y >= 0 && y < n && (mat[x][y] == 1)) {
                    live++;
                }
            }

            // If current cell is live and number of live neighbors
            // is less than 2 or greater than 3, then the cell will die
            if (mat[i][j] == 1 && (live < 2 || live > 3)) {
                nextGen[i][j] = 0;
            }


            // If current cell is dead and number of live neighbors
            // is equal to 3, then the cell will become live
            else if (mat[i][j] == 0 && live == 3) {
                nextGen[i][j] = 1;
            }

            // else the state of cells will remain same.
            else {
                nextGen[i][j] = mat[i][j];
            }
        }
    }

    // Print the next generation matrix using '*' = live cells and '.' = dead cells
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << (mat[i][j] == 1 ? '*' : '.') << " ";
        }
        cout << endl;
    }
    mat = nextGen;
}

void initRandomGrid(vector <vector<int>> &mat, int m , int n) {
    srand(time(0)); //random seed
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = rand() % 2; //rand value between 0 and 1
        }
    }
}

int main() {

    // HARD CODED Rows and Columns //
    //int m = 10; //rows
    //int n = 10; //columns

    // RANDOM GRID and USER INPUT Rows and Columns //
    int m;
    int n;
    cout << "Enter rows and columns: " << endl;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n, 0));

    initRandomGrid(mat, m, n);

    int gens;
    cout << "Enter number of gens: " << endl;
    cin >> gens;

    for (int gen = 0; gen < gens; gen++) {
        cout << "Generation " << gen + 1 << ":\n";
        findNextGen(mat);
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    //cout << "Number of rows: " << m << endl
    //     << "Number of columns: " << n << endl;
}