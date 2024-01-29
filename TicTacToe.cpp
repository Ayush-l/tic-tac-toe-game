#include <iostream>
#include <vector>
using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(const vector<vector<char>>& board) {
    for(int i=0; i<3;++i) {
        for(int j=0;j<3;++j) {
            cout<<board[i][j];
            if(j<2)cout<< " | ";
        }
        cout<<endl;
        if(i < 2) cout<<"---------"<<endl;
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char &player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0]==player&&board[i][1]==player&&board[i][2]==player)return true; // checking in Horizontal row
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // checking in Vertical column
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // checking main Diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // checking second Diagonal
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board
    char currentPlayer = 'X',second='O'; // Player X will start the game
    int playtime=0;//to check wheather the game has end or not
    while(true){
        
        //To display board to players everytime
        cout<<"Current board:"<<endl;
        drawBoard(board);
        
        // Check if there's a winner
        // for anyone to be winner the total number of moves must be atleast 5
        if(playtime>=5){
            //Second has made the last move so the chances of being is winner is only for second
            if (checkWin(board, second)){
                cout << "Player "<<second<<" wins!" << endl;
                break;
            }
            else if(playtime==9){
                cout<<"It's a draw!"<<endl;
                break;
            }
        }

        // Get the current player's move
        int row,col;
        cout<<"Player "<<currentPlayer<<"'s turn. Enter row (1-3) and column (1-3): ";
        cin>>row>>col;
        row--; // Adjust to 0-based indexing
        col--; // Adjust to 0-based indexing
        
        // Tocheck if the move is valid or not
        if(row>=0&&row<3&&col>=0&&col<3&&board[row][col]==' '){
            board[row][col]=currentPlayer;
            // Switch player
            currentPlayer=(currentPlayer == 'X')?'O':'X';
            second=(second == 'X')?'O':'X';
            playtime++;
        }
        else {
            cout<<"Invalid move! Try again."<<endl;
        }
    }
    return 0;
}