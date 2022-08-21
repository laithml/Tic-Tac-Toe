#include <iostream>

using namespace std;

class Board {
    char matrix[3][3];
    int round;
    bool gameOver = false;

public:
    Board() {
        round = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                matrix[i][j] = ' ';
            }
        }
    }

    bool isGameOver() {
        return gameOver;
    }

    void setCell(int index) {
        char input;
        index--;
        if (round % 2 == 0)
            input = 'X';
        else
            input = 'O';
        int row = (index / 3);
        int col = index % 3;
        matrix[row][col] = input;
        round++;
        if (round == 9)
            gameOver = true;
        char winner = checkStatus();
        if (winner != ' ' && gameOver) {
            cout << "Congratulation, \"" << winner << "\" Win!" << endl;
        } else if (winner == ' ' && gameOver) {
            cout << "GAME OVER, TIE!" << endl;
        }
        printBoard();
        if (gameOver) {
            Board();
        }
    }

    char getCell(int index) {
        index--;
        int row = (index / 3);
        int col = index % 3;
        return matrix[row][col];
    }

    void printBoard() {
        cout << "choose where you want put your element using numbers from 1 to 9\n" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != 2) {
                    cout << "    " << matrix[i][j] << "    " << "|";
                } else
                    cout << "    " << matrix[i][j] << endl;
            }
            if (i != 2)
                cout << "--------------------------------" << endl;
        }
        cout << "\n=====================++++++++++++++++++=====================\n" << endl;
    }

    char checkStatus() {
        int winning_cases[8] = {123, 456, 789, 147, 258, 369, 753, 159};
        int i = 0;
        char element = ' ', prev = ' ';
        bool winner = false;
        int index, num;
        while (i < 8) {
            num = winning_cases[i];
            for (int j = 0; j < 3; j++) {
                index = num % 10;
                num /= 10;
                prev = element;
                element = getCell(index);
                if ((element == ' ' || element != prev) && j != 0) {
                    winner = false;
                    break;
                } else
                    winner = true;

            }
            if (winner) {
                gameOver = true;
                return element;
            }
            i++;
        }

        return ' ';

    }


};

int main() {
    int input;
    cout << "______WELCOME TO TIC TAC TOE GAME!______" << endl;
    while (1) {
        cout << "1-new Game" << endl;
        cout << "2-exit" << endl;
        cin >> input;
        if (input == 1) {
            Board *board = new Board();
            board->printBoard();
            while (!board->isGameOver()) {
                cin >> input;
                board->setCell(input);
            }
        } else
            break;


    }
}
