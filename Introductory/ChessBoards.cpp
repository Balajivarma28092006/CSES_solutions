#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

vector<string> board(8);
int countWays = 0;

bool isSafe(vector<string> &board, int row, int col){
    for(int i = 0; i < row; i++){
        if(board[i][col] == 'Q') return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q') return false;
    }

    for(int i = row - 1, j = col + 1; i >= 0 && j <  8; i--, j++){
         if(board[i][j] == 'Q') return false;
    }  
    return true;
}

void solve(vector<string> & board, int row){
    if(row == 8){
        countWays++;
        return;
    }

    for(int col = 0; col < 8; col++ ){
        if(board[row][col] == '*') continue;

        if(isSafe(board, row, col)){
            board[row][col] = 'Q';
            solve(board, row+1);
            board[row][col] = '.';
        }
    }
}

int main() {
    fastio;
    for (int i = 0; i < 8; i++) cin >> board[i];
    
    solve(board, 0);
    cout << countWays << endl;
    return 0;
}