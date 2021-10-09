#include <iostream>
#include <vector>

using namespace std;

void resize();
void read();
void play();
void printGrid(vector<vector<int>> &firstGrid, int &contor);
void determineState(vector<vector<int>> &firstGrid);

int n;
vector<vector<int>> firstGrid;

int main(){
    read();
    play();
}

void resize(vector<vector<int>> &grid) {
    grid.resize(n + 1);
    for (auto &line : grid) {
        line.resize(n + 1, 0);
    }
}

void read() {
    cin >> n;
    resize(firstGrid);
    int numberCells;
    cin >> numberCells;
    for (int i = 0; i < numberCells; ++i) {
        int x, y;
        cin >> x >> y;
        firstGrid[x][y] = 1;
    }
}

void printGrid(vector<vector<int>> &grid, int &contor){
    cout << "\nStep " << contor << "\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

void play() {
    int contor = 0;
    while (contor < 20) {
        printGrid(firstGrid, contor);
        determineState(firstGrid);
        contor++;
    }

    printGrid(firstGrid, contor);
}

void compareGrid(vector<vector<int>> &firstGrid, vector<vector<int>> &secondGrid){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            firstGrid[i][j] = secondGrid[i][j];
        }
    }
}

int getState(int i, int j) {
    return ( (i < 0 || i >= n) || (j < 0 || j >= n)) 
        ? 0 : firstGrid[i][j];
}

int getAliveNeighbours(int i, int j) {
    int count = 0;

    count += getState(i - 1, j - 1);
    count += getState(i, j - 1);
    count += getState(i + 1, j - 1);
    count += getState(i - 1, j);
    count += getState(i + 1, j);
    count += getState(i - 1, j + 1);
    count += getState(i, j + 1);
    count += getState(i + 1, j + 1);

    return count;

}

void determineState(vector<vector<int>> &firstGrid){
    vector<vector<int>> secondGrid;
    resize(secondGrid);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int alive = getAliveNeighbours(i, j);
            if (getState(i, j) == 1) {
                if (alive < 2) {
                    secondGrid[i][j] = 0;
                } else if (alive > 3) {
                    secondGrid[i][j] = 0;
                } else if (alive == 2 || alive == 3){
                    secondGrid[i][j] = 1;
                }
            } else {
                if (alive == 3) {
                    secondGrid[i][j] = 1;
                }
            }

        }
    }
    //firstGrid = secondGrid;
    compareGrid(firstGrid, secondGrid);
}