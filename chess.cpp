#include <iostream>
#include <string>
using namespace std;


class Chess {
    public:
        string inputs[32] = { };
    
        void inputReader() {
            string positions[32] = { };
            string input;
            cout << "Put in all piece positions: ";
            getline(cin, input);
            string piece;
            int counter = 0;
            string sep = ", ";
            int i;
            int j = 0;
            for (i=0; i<input.length(); i++) {
                if (input[i] == ',') {
                    piece = input.substr(j, i);
                    inputs[counter] = piece;
                    counter++;
                    j = i + 2;
                }
            }
            piece = input.substr(j, input.length());
            inputs[counter] = piece;
        }
    
        void setBoard(char aBoard[8][8]) {
            int i, j, k, l;
            for (i=0; i<8; i++) { for (j=0; j<8; j++) { aBoard[i][j] = ' '; } }
            char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
            for (k=0; k<32; k++) {
                string piece = inputs[k];
                cout << piece << endl;
                int row = stoi(piece[3]);
                int col;
                for (l=0; l<8; l++) { if (letters[l] == piece[2]) { col = stoi(l); } }
                cout << row << " " << col << endl;
                if (piece[0] == 'b') {
                    aBoard[8-row][col-1] = piece[1];
                } else {  // piece[0] == 'w'
                    aBoard[8-row][col-1] = toupper(piece[1]);
                }
            }
        }
        
        void printBoard(char aBoard[8][8]) {
            int i, j;
            cout << "   a  b  c  d  e  f  g  h\n";
            cout << " _________________________\n";
            for(i=0; i<8; i++) {
                cout << 8 - i << "|";
                for(j=0; j<8; j++) {
                    cout << aBoard[i][j] << " |";
                }
                cout << 8 - i << "\n";
            }
            cout << " -------------------------\n";
            cout << "   a  b  c  d  e  f  g  h\n";
    }
};

int main() {
    Chess chess;
    char board[8][8] = { };
    chess.inputReader();
    chess.setBoard(board);
    chess.printBoard(board);
}
