#include <iostream>
#include <vector>
using namespace std;
class NQueens {
public:
 NQueens(int n) : boardSize(n) {
 board.resize(n, vector<bool>(n, false));
 }
 void solve() {
 if (placeQueens(0)) {
 printSolution();
 } else {
 cout << "No solution exists." << endl;
 }
 }
private:
 int boardSize;
 vector<vector<bool> >board;
 bool isSafe(int row, int col) {
 for (int i = 0; i < row; i++) {
 if (board[i][col]) return false; // Check column
 if (col - (row - i) >= 0 && board[i][col - (row - i)]) return false; // Check left diagonal
 if (col + (row - i) < boardSize && board[i][col + (row - i)]) return false; // Check right 
//diagonal
 }
 return true;
 }
 bool placeQueens(int row) {
 if (row >= boardSize) return true; // All queens are placed
 for (int col = 0; col < boardSize; col++) {
 if (isSafe(row, col)) {
 board[row][col] = true; // Place queen
 if (placeQueens(row + 1)) return true; // Recur to place rest of the queens
 board[row][col] = false; // Backtrack
 }
 }
 return false; // No position was found
 }
 void printSolution() {
 for (int i = 0; i < boardSize; i++) {
 for (int j = 0; j < boardSize; j++) {
 if (board[i][j]) {
 cout << " Q ";
 } else {
 cout << " . ";
 }
 }
 cout << endl;
 }
 }
};
int main() {
 int n = 8; // Size of the board
 NQueens nQueens(n);
 nQueens.solve();
 return 0;
}
