#include "utils/bits/stdc++.hpp"
#include <iostream>
//#include <SFML/Graphics.hpp>


using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;
const int GRID_SIZE = 50;
vector<vector<int>> grid(GRID_SIZE, vector<int>(GRID_SIZE, 0)); // Use vector

 void drawGrid(sf::RenderWindow &window) {
     sf::RectangleShape cell(sf::Vector2f(WIDTH / GRID_SIZE, HEIGHT / GRID_SIZE));
     for (int i = 0; i < GRID_SIZE; i++) {
         for (int j = 0; j < GRID_SIZE; j++) {
             if (grid[i][j] == 1) {
                 cell.setFillColor(sf::Color::Green); // Alive = green
             } else {
                 cell.setFillColor(sf::Color::White); // Dead =  white
             }
             cell.setPosition(i * (WIDTH / GRID_SIZE), j * (HEIGHT / GRID_SIZE));
             window.draw(cell);
         }
     }
 }

void findNextGen(vector<vector<int>> &mat, vector<vector<int>> &nextGen) {
    int m = mat.size();
    int n = mat[0].size();

    //directions of eight possible neighbors
    vector<vector<int>> directions =
    {{0, 1}, {1, 0}, {0, -1},
     {-1, 0}, {1, 1}, {-1, -1},
     {1, -1}, {-1, 1}};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            int live = 0; //init live neighbours to 0
            for (auto dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                //check if the neighbor is live
                if (x >= 0 && x < m && y >= 0 && y < n && (mat[x][y] == 1)) {
                    live++;
                }
            }

            // cell death logic (less than 2 or greater than 3)
            if (mat[i][j] == 1 && (live < 2 || live > 3)) {
                nextGen[i][j] = 0;
            }


            // cell live logic (cell dead, live neighbours = 3)
            else if (mat[i][j] == 0 && live == 3) {
                nextGen[i][j] = 1;
            }

            // else the state of cells will remain same.
            else {
                nextGen[i][j] = mat[i][j];
            }
        }
    }
    mat.swap(nextGen);
}

void initRandomGrid(vector <vector<int>> &mat, int m , int n) {
    srand(time(0)); //random seed
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = rand() % 2; //rand value between 0 and 1
        }
    }
}

void printGrid(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int cell : row) {
            cout << (cell == 1 ? '*' : '.') << " ";
        }
        cout << endl;
    }
}

int main() {
    //sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game of Life");
    
    // HARD CODED Rows and Columns //
    //int m = 10; //rows
    //int n = 10; //columns

    // RANDOM GRID and USER INPUT Rows and Columns //
    int m;
    int n;
    cout << "Enter rows and columns: " << endl;
    cin >> m >> n;

    if (m < 3 || n < 3) {
        cout << "Invalid input. Enter a value greater than 3." << endl;
        cin >> m >> n;
    }
    vector<vector<int>> mat(m, vector<int>(n, 0)); //Current
    vector<vector<int>> nextGen(m, vector<int>(n, 0));  //Next

    initRandomGrid(mat, m, n);

    int gens;
    cout << "Enter number of gens: " << endl;
    cin >> gens;

    if (gens <= 1) {
        cout << "Number of Generations equals 1. \nEnter a value greater to continue."
        << endl;
        cin >> gens;
    }

    for (int gen = 0; gen < gens; gen++) {
        cout << "\033[2J\033[H";
        cout << "Generation " << gen + 1 << ":\n";
        printGrid(mat);
        findNextGen(mat, nextGen);

        if (gen == 4 || gen == 9 || gen == 14 || gen == 19 || gen == 24) {
            char continueGame;
            cout << "Press 'q' to quit or any key to continue: ";
            cin >> continueGame;
            if (continueGame == 'q' || continueGame == 'Q') {
                break;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
