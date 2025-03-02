#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib> /
#include <ctime>

using namespace std;

void findNextGen(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> nextGen(m, vector<int>(n, 0));

    vector<vector<int>> directions = { //directions of possible neighbours
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;

            // Count live neighbors
            for (const auto& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && mat[ni][nj] == 1) {
                    liveNeighbors++;
                }
            }

            // Apply the rules of Conway's Game of Life
            if (mat[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                nextGen[i][j] = 1; // Cell remains alive
            } else if (mat[i][j] == 0 && liveNeighbors == 3) {
                nextGen[i][j] = 1; // Cell becomes alive
            } else {
                nextGen[i][j] = 0; // Cell dies
            }
        }
    }

    mat = nextGen; // Update the original grid with the next generation
}

// Function to initialize the grid with random values
void initRandomGrid(vector<vector<int>> &mat, int m, int n) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = rand() % 2; // Randomly initialize cells to 0 or 1
        }
    }
}

// Function to print the current grid
void printGrid(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int cell : row) {
            cout << (cell == 1 ? '*' : '.') << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;

    cout << "Enter rows and columns: " << endl;
    cin >> m >> n;

    if (m < 3 || n < 3) {
        cout << "Invalid input. Enter a value greater than 3." << endl;
        cin >> m >> n;
    }

    vector<vector<int>> mat(m, vector<int>(n, 0)); //grid init

    initRandomGrid(mat, m, n); //populate with rand values

    int gens; //generation logic
    cout << "Enter number of gens: " << endl;
    cin >> gens;

    if (gens <= 1) { //gen validation
        cout << "Number of Generations equals 1. Enter a value greater to continue." << endl;
        cin >> gens;
    }

    for (int gen = 0; gen < gens; gen++) {
        cout << "\033[2J\033[H"; // Clear the console screen
        cout << "Generation " << gen + 1 << ":\n";
        printGrid(mat); // Print the current grid
        findNextGen(mat); // Calculate the next generation
        this_thread::sleep_for(chrono::milliseconds(500)); // Pause for half a second
    }

    return 0;
}