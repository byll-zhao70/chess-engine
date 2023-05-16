// ChessEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Board {
public:
    vector<vector<string>> board;
    unordered_map<string, vector<string>> blackPieces;
    unordered_map<string, vector<string>> whitePieces;
    bool whiteMove;
    double evaluation;
    Board() {
        whiteMove = false;
        evaluation = 0;
        for (int i = 0; i < 8; i++)
        {
            vector<string> row;
            if (i == 0)
            {
                row.push_back("WR");
                row.push_back("WN");
                row.push_back("WB");
                row.push_back("WK");
                row.push_back("WQ");
                row.push_back("WB");
                row.push_back("WN");
                row.push_back("WR");
            }
            else if (i == 1)
            {
                for (int j = 0; j < 8; j++)
                {
                    row.push_back("WP");
                }
            }
            else if (i == 6)
            {
                for (int j = 0; j < 8; j++)
                {
                    row.push_back("BP");
                }
            }
            else if (i == 7)
            {
                row.push_back("BR");
                row.push_back("BN");
                row.push_back("BB");
                row.push_back("BK");
                row.push_back("BQ");
                row.push_back("BB");
                row.push_back("BN");
                row.push_back("BR");
            }
            else
            {
                for (int j = 0; j < 8; j++)
                {
                    row.push_back("");
                }
            }
            board.push_back(row);
        }
        whitePieces["P"].push_back("a2");
        whitePieces["P"].push_back("b2");
        whitePieces["P"].push_back("c2");
        whitePieces["P"].push_back("d2");
        whitePieces["P"].push_back("e2");
        whitePieces["P"].push_back("f2");
        whitePieces["P"].push_back("g2");
        whitePieces["P"].push_back("h2");
        blackPieces["P"].push_back("a7");
        blackPieces["P"].push_back("b7");
        blackPieces["P"].push_back("c7");
        blackPieces["P"].push_back("d7");
        blackPieces["P"].push_back("e7");
        blackPieces["P"].push_back("f7");
        blackPieces["P"].push_back("g7");
        blackPieces["P"].push_back("h7");
        whitePieces["R"].push_back("a1");
        whitePieces["R"].push_back("h1");
        whitePieces["N"].push_back("b1");
        whitePieces["N"].push_back("g1");
        whitePieces["B"].push_back("c1");
        whitePieces["B"].push_back("f1");
        whitePieces["Q"].push_back("d1");
        whitePieces["K"].push_back("e1");
        blackPieces["R"].push_back("a8");
        blackPieces["R"].push_back("h8");
        blackPieces["N"].push_back("b8");
        blackPieces["N"].push_back("g8");
        blackPieces["B"].push_back("c8");
        blackPieces["B"].push_back("f8");
        blackPieces["Q"].push_back("d8");
        blackPieces["K"].push_back("e8");
    }
    vector<string> getAllMoves()
    {
        vector<string> output;
        if (whiteMove)
        {
            //pawn
            for (int i = 0; i < whitePieces["P"].size(); i++)
            {
                string pos = whitePieces["P"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                if (pos.substr(1) == "2" && board[row + 2][col].size() == 0)
                {
                    output.push_back("P" + pos + pos.substr(0, 1) + "4");
                }
                if (board[row + 1][col].size() == 0)
                {
                    string newRow = to_string((stoi(pos.substr(1)) + 1));
                    if (newRow != "8")
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow);
                    else
                    {
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow + "=Q");
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow + "=R");
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow + "=B");
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow + "=N");
                    }
                }
                if (col > 0 && board[row + 1][col - 1].size() != 0 && board[row + 1][col - 1].substr(0, 1) == "B")
                {
                    char newCol = pos.at(0) - 1;
                    if (row != 6)
                    {
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col - 1].substr(1, 2) + to_string(row + 2));
                    }
                    else
                    {
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col - 1].substr(1, 2) + to_string(row + 2) + "=Q");
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col - 1].substr(1, 2) + to_string(row + 2) + "=R");
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col - 1].substr(1, 2) + to_string(row + 2) + "=B");
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col - 1].substr(1, 2) + to_string(row + 2) + "=N");
                    }
                }
                if (col < 7 && board[row + 1][col + 1].size() != 0 && board[row + 1][col + 1].substr(0, 1) == "B")
                {
                    char newCol = pos.at(0) + 1;
                    if (row != 6)
                    {
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col + 1].substr(1, 2) + to_string(row + 2));
                    }
                    else
                    {
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col + 1].substr(1, 2) + to_string(row + 2) + "=Q");
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col + 1].substr(1, 2) + to_string(row + 2) + "=R");
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col + 1].substr(1, 2) + to_string(row + 2) + "=B");
                        output.push_back("P" + pos + "x" + newCol + "" + board[row + 1][col + 1].substr(1, 2) + to_string(row + 2) + "=N");
                    }
                }
            }

            //knight

            for (int i = 0; i < whitePieces["N"].size(); i++)
            {
                string pos = whitePieces["N"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                if (row > 0 && col > 1 && (board[row - 1][col - 2].size() == 0 || board[row - 1][col - 2].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) - 2;
                    if (board[row - 1][col - 2].size() != 0)
                        output.push_back("N" + pos + "x" + board[row - 1][col - 2].substr(1, 2) + string(1, newCol) + to_string(row));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row));
                }
                if (row > 0 && col < 6 && (board[row - 1][col + 2].size() == 0 || board[row - 1][col + 2].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + 2;
                    if (board[row - 1][col + 2].size() != 0)
                        output.push_back("N" + pos + "x" + board[row - 1][col + 2].substr(1, 2) + string(1, newCol) + to_string(row));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row));
                }
                if (row > 1 && col > 0 && (board[row - 2][col - 1].size() == 0 || board[row - 2][col - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) - 1;
                    if (board[row - 2][col - 1].size() != 0)
                        output.push_back("N" + pos + "x" + board[row - 2][col - 1].substr(1, 2) + string(1, newCol) + to_string(row - 1));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row - 1));
                }
                if (row > 1 && col < 7 && (board[row - 2][col + 1].size() == 0 || board[row - 2][col + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + 1;
                    if (board[row - 2][col + 1].size() != 0)
                        output.push_back("N" + pos + "x" + board[row - 2][col + 1].substr(1, 2) + string(1, newCol) + to_string(row - 1));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row - 1));
                }
                if (row < 7 && col > 1 && (board[row + 1][col - 2].size() == 0 || board[row + 1][col - 2].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) - 2;
                    if (board[row + 1][col - 2].size() != 0)
                        output.push_back("N" + pos + "x" + board[row + 1][col - 2].substr(1, 2) + string(1, newCol) + to_string(row + 2));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row + 2));
                }
                if (row < 7 && col < 6 && (board[row + 1][col + 2].size() == 0 || board[row + 1][col + 2].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + 2;
                    if (board[row + 1][col + 2].size() != 0)
                        output.push_back("N" + pos + "x" + board[row + 1][col + 2].substr(1, 2) + string(1, newCol) + to_string(row + 2));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row + 2));
                }
                if (row < 6 && col < 7 && (board[row + 2][col + 1].size() == 0 || board[row + 2][col + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + 1;
                    if (board[row + 2][col + 1].size() != 0)
                        output.push_back("N" + pos + "x" + board[row + 2][col + 1].substr(1, 2) + string(1, newCol) + to_string(row + 3));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row + 3));
                }
                if (row < 6 && col > 0 && (board[row + 2][col - 1].size() == 0 || board[row + 2][col - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) - 1;
                    if (board[row + 2][col - 1].size() != 0)
                        output.push_back("N" + pos + "x" + board[row + 2][col - 1].substr(1, 2) + string(1, newCol) + to_string(row + 3));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row + 3));
                }
            }

            //bishop

            for (int i = 0; i < whitePieces["B"].size(); i++)
            {
                string pos = whitePieces["B"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                int currRow = row;
                int currCol = col;
                while (currRow < 7 && currCol < 7 && (board[currRow + 1][currCol + 1].size() == 0 || board[currRow + 1][currCol + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol + 1].size() == 0)
                    {
                        output.push_back("B" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                        currCol++;
                    }
                    else
                    {
                        output.push_back("B" + pos + "x" + board[currRow + 1][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow < 7 && currCol > 0 && (board[currRow + 1][currCol - 1].size() == 0 || board[currRow + 1][currCol - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol - 1].size() == 0)
                    {
                        output.push_back("B" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                        currCol--;
                    }
                    else
                    {
                        output.push_back("B" + pos + "x" + board[currRow + 1][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && currCol < 7 && (board[currRow - 1][currCol + 1].size() == 0 || board[currRow - 1][currCol + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol + 1].size() == 0)
                    {
                        output.push_back("B" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                        currCol++;
                    }
                    else
                    {
                        output.push_back("B" + pos + "x" + board[currRow - 1][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && currCol > 0 && (board[currRow - 1][currCol - 1].size() == 0 || board[currRow - 1][currCol - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol - 1].size() == 0)
                    {
                        output.push_back("B" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                        currCol--;
                    }
                    else
                    {
                        output.push_back("B" + pos + "x" + board[currRow - 1][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
            }

            //rook

            for (int i = 0; i < whitePieces["R"].size(); i++)
            {
                string pos = whitePieces["R"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                int currRow = row;
                int currCol = col;
                while (currRow > 0 && (board[currRow - 1][currCol].size() == 0 || board[currRow - 1][currCol].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol].size() == 0)
                    {
                        output.push_back("R" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                    }
                    else
                    {
                        output.push_back("R" + pos + "x" + board[currRow - 1][currCol].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow < 7 && (board[currRow + 1][currCol].size() == 0 || board[currRow + 1][currCol].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol].size() == 0)
                    {
                        output.push_back("R" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                    }
                    else
                    {
                        output.push_back("R" + pos + "x" + board[currRow + 1][currCol].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currCol > 0 && (board[currRow][currCol - 1].size() == 0 || board[currRow][currCol - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow + 1;
                    if (board[currRow][currCol - 1].size() == 0)
                    {
                        output.push_back("R" + pos + string(1, newCol) + to_string(newRow));
                        currCol--;
                    }
                    else
                    {
                        output.push_back("R" + pos + "x" + board[currRow][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currCol < 7 && (board[currRow][currCol + 1].size() == 0 || board[currRow][currCol + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow + 1;
                    if (board[currRow][currCol + 1].size() == 0)
                    {
                        output.push_back("R" + pos + string(1, newCol) + to_string(newRow));
                        currCol++;
                    }
                    else
                    {
                        output.push_back("R" + pos + "x" + board[currRow][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
            }

            //queen

            for (int i = 0; i < whitePieces["Q"].size(); i++)
            {
                string pos = whitePieces["Q"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                int currRow = row;
                int currCol = col;
                while (currRow < 7 && currCol < 7 && (board[currRow + 1][currCol + 1].size() == 0 || board[currRow + 1][currCol + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol + 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                        currCol++;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow + 1][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow < 7 && currCol > 0 && (board[currRow + 1][currCol - 1].size() == 0 || board[currRow + 1][currCol - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol - 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                        currCol--;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow + 1][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && currCol < 7 && (board[currRow - 1][currCol + 1].size() == 0 || board[currRow - 1][currCol + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol + 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                        currCol++;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow - 1][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && currCol > 0 && (board[currRow - 1][currCol - 1].size() == 0 || board[currRow - 1][currCol - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol - 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                        currCol--;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow - 1][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && (board[currRow - 1][currCol].size() == 0 || board[currRow - 1][currCol].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow - 1][currCol].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow < 7 && (board[currRow + 1][currCol].size() == 0 || board[currRow + 1][currCol].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow + 1][currCol].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currCol > 0 && (board[currRow][currCol - 1].size() == 0 || board[currRow][currCol - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow + 1;
                    if (board[currRow][currCol - 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currCol--;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currCol < 7 && (board[currRow][currCol + 1].size() == 0 || board[currRow][currCol + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow + 1;
                    if (board[currRow][currCol + 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currCol++;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
            }

            //king

            for (int i = 0; i < whitePieces["K"].size(); i++)
            {
                string pos = whitePieces["K"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                if (row > 0 && col > 0 && (board[row - 1][col - 1].size() == 0 || board[row - 1][col - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) - 1;
                    int newRow = row;
                    if (board[row - 1][col - 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row - 1][col - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row > 0 && col < 7 && (board[row - 1][col + 1].size() == 0 || board[row - 1][col + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + 1;
                    int newRow = row;
                    if (board[row - 1][col + 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row - 1][col + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row > 0 && (board[row - 1][col].size() == 0 || board[row - 1][col].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0);
                    int newRow = row;
                    if (board[row - 1][col].size() != 0)
                        output.push_back("K" + pos + "x" + board[row - 1][col].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row < 7 && col > 0 && (board[row + 1][col - 1].size() == 0 || board[row + 1][col - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) - 1;
                    int newRow = row + 2;
                    if (board[row + 1][col - 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row + 1][col - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row < 7 && col < 7 && (board[row + 1][col + 1].size() == 0 || board[row + 1][col + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + 1;
                    int newRow = row + 2;
                    if (board[row + 1][col + 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row + 1][col + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row < 7 && (board[row + 1][col].size() == 0 || board[row + 1][col].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0);
                    int newRow = row + 2;
                    if (board[row + 1][col].size() != 0)
                        output.push_back("K" + pos + "x" + board[row + 1][col].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (col > 0 && (board[row][col - 1].size() == 0 || board[row][col - 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) - 1;
                    int newRow = row + 1;
                    if (board[row][col - 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row][col - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (col < 7 && (board[row][col + 1].size() == 0 || board[row][col + 1].substr(0, 1) != "W"))
                {
                    char newCol = pos.at(0) + 1;
                    int newRow = row + 1;
                    if (board[row][col + 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row][col + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
            }
        }
        else
        {
            //pawn
            for (int i = 0; i < blackPieces["P"].size(); i++)
            {
                string pos = blackPieces["P"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                if (pos.substr(1) == "7" && board[row - 2][col].size() == 0)
                {
                    output.push_back("P" + pos + pos.substr(0, 1) + "5");
                }
                if (board[row - 1][col].size() == 0)
                {
                    string newRow = to_string((stoi(pos.substr(1)) - 1));
                    if (newRow != "1")
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow);
                    else
                    {
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow + "=Q");
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow + "=R");
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow + "=B");
                        output.push_back("P" + pos + pos.substr(0, 1) + newRow + "=N");
                    }
                }
                if (col > 0 && board[row - 1][col - 1].size() != 0 && board[row - 1][col - 1].substr(0, 1) == "W")
                {
                    char newCol = pos.at(0) - 1;
                    if (row != 1)
                    {
                        output.push_back("P" + pos + "x" + board[row - 1][col - 1].substr(1, 2) + newCol + "" + to_string(row));
                    }
                    else
                    {
                        output.push_back("P" + pos + "x" + board[row - 1][col - 1].substr(1, 2) + newCol + "" + to_string(row) + "=Q");
                        output.push_back("P" + pos + "x" + board[row - 1][col - 1].substr(1, 2) + newCol + "" + to_string(row) + "=R");
                        output.push_back("P" + pos + "x" + board[row - 1][col - 1].substr(1, 2) + newCol + "" + to_string(row) + "=B");
                        output.push_back("P" + pos + "x" + board[row - 1][col - 1].substr(1, 2) + newCol + "" + to_string(row) + "=N");
                    }
                }
                if (col < 7 && board[row - 1][col + 1].size() != 0 && board[row - 1][col + 1].substr(0, 1) == "W")
                {
                    char newCol = pos.at(0) + 1;
                    if (row != 1)
                    {
                        output.push_back("P" + pos + "x" + board[row - 1][col + 1].substr(1, 2) + newCol + "" + to_string(row));
                    }
                    else
                    {
                        output.push_back("P" + pos + "x" + board[row - 1][col + 1].substr(1, 2) + newCol + "" + to_string(row) + "=Q");
                        output.push_back("P" + pos + "x" + board[row - 1][col + 1].substr(1, 2) + newCol + "" + to_string(row) + "=R");
                        output.push_back("P" + pos + "x" + board[row - 1][col + 1].substr(1, 2) + newCol + "" + to_string(row) + "=B");
                        output.push_back("P" + pos + "x" + board[row - 1][col + 1].substr(1, 2) + newCol + "" + to_string(row) + "=N");
                    }
                }
            }

            //knight

            for (int i = 0; i < blackPieces["N"].size(); i++)
            {
                string pos = blackPieces["N"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                if (row > 0 && col > 1 && (board[row - 1][col - 2].size() == 0 || board[row - 1][col - 2].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) - 2;
                    if (board[row - 1][col - 2].size() != 0)
                        output.push_back("N" + pos + "x" + board[row - 1][col - 2].substr(1, 2) + string(1, newCol) + to_string(row));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row));
                }
                if (row > 0 && col < 6 && (board[row - 1][col + 2].size() == 0 || board[row - 1][col + 2].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + 2;
                    if (board[row - 1][col + 2].size() != 0)
                        output.push_back("N" + pos + "x" + board[row - 1][col + 2].substr(1, 2) + string(1, newCol) + to_string(row));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row));
                }
                if (row > 1 && col > 0 && (board[row - 2][col - 1].size() == 0 || board[row - 2][col - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) - 1;
                    if (board[row - 2][col - 1].size() != 0)
                        output.push_back("N" + pos + "x" + board[row - 2][col - 1].substr(1, 2) + string(1, newCol) + to_string(row - 1));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row - 1));
                }
                if (row > 1 && col < 7 && (board[row - 2][col + 1].size() == 0 || board[row - 2][col + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + 1;
                    if (board[row - 2][col + 1].size() != 0)
                        output.push_back("N" + pos + "x" + board[row - 2][col + 1].substr(1, 2) + string(1, newCol) + to_string(row - 1));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row - 1));
                }
                if (row < 7 && col > 1 && (board[row + 1][col - 2].size() == 0 || board[row + 1][col - 2].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) - 2;
                    if (board[row + 1][col - 2].size() != 0)
                        output.push_back("N" + pos + "x" + board[row + 1][col - 2].substr(1, 2) + string(1, newCol) + to_string(row + 2));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row + 2));
                }
                if (row < 7 && col < 6 && (board[row + 1][col + 2].size() == 0 || board[row + 1][col + 2].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + 2;
                    if (board[row + 1][col + 2].size() != 0)
                        output.push_back("N" + pos + "x" + board[row + 1][col + 2].substr(1, 2) + string(1, newCol) + to_string(row + 2));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row + 2));
                }
                if (row < 6 && col < 7 && (board[row + 2][col + 1].size() == 0 || board[row + 2][col + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + 1;
                    if (board[row + 2][col + 1].size() != 0)
                        output.push_back("N" + pos + "x" + board[row + 2][col + 1].substr(1, 2) + string(1, newCol) + to_string(row + 3));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row + 3));
                }
                if (row < 6 && col > 0 && (board[row + 2][col - 1].size() == 0 || board[row + 2][col - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) - 1;
                    if (board[row + 2][col - 1].size() != 0)
                        output.push_back("N" + pos + "x" + board[row + 2][col - 1].substr(1, 2) + string(1, newCol) + to_string(row + 3));
                    else
                        output.push_back("N" + pos + string(1, newCol) + to_string(row + 3));
                }
            }

            //bishop

            for (int i = 0; i < blackPieces["B"].size(); i++)
            {
                string pos = blackPieces["B"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                int currRow = row;
                int currCol = col;
                while (currRow < 7 && currCol < 7 && (board[currRow + 1][currCol + 1].size() == 0 || board[currRow + 1][currCol + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol + 1].size() == 0)
                    {
                        output.push_back("B" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                        currCol++;
                    }
                    else
                    {
                        output.push_back("B" + pos + "x" + board[currRow + 1][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow < 7 && currCol > 0 && (board[currRow + 1][currCol - 1].size() == 0 || board[currRow + 1][currCol - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol - 1].size() == 0)
                    {
                        output.push_back("B" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                        currCol--;
                    }
                    else
                    {
                        output.push_back("B" + pos + "x" + board[currRow + 1][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && currCol < 7 && (board[currRow - 1][currCol + 1].size() == 0 || board[currRow - 1][currCol + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol + 1].size() == 0)
                    {
                        output.push_back("B" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                        currCol++;
                    }
                    else
                    {
                        output.push_back("B" + pos + "x" + board[currRow - 1][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && currCol > 0 && (board[currRow - 1][currCol - 1].size() == 0 || board[currRow - 1][currCol - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol - 1].size() == 0)
                    {
                        output.push_back("B" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                        currCol--;
                    }
                    else
                    {
                        output.push_back("B" + pos + "x" + board[currRow - 1][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
            }

            //rook

            for (int i = 0; i < blackPieces["R"].size(); i++)
            {
                string pos = blackPieces["R"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                int currRow = row;
                int currCol = col;
                while (currRow > 0 && (board[currRow - 1][currCol].size() == 0 || board[currRow - 1][currCol].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol].size() == 0)
                    {
                        output.push_back("R" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                    }
                    else
                    {
                        output.push_back("R" + pos + "x" + board[currRow - 1][currCol].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow < 7 && (board[currRow + 1][currCol].size() == 0 || board[currRow + 1][currCol].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol].size() == 0)
                    {
                        output.push_back("R" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                    }
                    else
                    {
                        output.push_back("R" + pos + "x" + board[currRow + 1][currCol].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currCol > 0 && (board[currRow][currCol - 1].size() == 0 || board[currRow][currCol - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow + 1;
                    if (board[currRow][currCol - 1].size() == 0)
                    {
                        output.push_back("R" + pos + string(1, newCol) + to_string(newRow));
                        currCol--;
                    }
                    else
                    {
                        output.push_back("R" + pos + "x" + board[currRow][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currCol < 7 && (board[currRow][currCol + 1].size() == 0 || board[currRow][currCol + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow + 1;
                    if (board[currRow][currCol + 1].size() == 0)
                    {
                        output.push_back("R" + pos + string(1, newCol) + to_string(newRow));
                        currCol++;
                    }
                    else
                    {
                        output.push_back("R" + pos + "x" + board[currRow][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
            }

            //queen

            for (int i = 0; i < blackPieces["Q"].size(); i++)
            {
                string pos = blackPieces["Q"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                int currRow = row;
                int currCol = col;
                while (currRow < 7 && currCol < 7 && (board[currRow + 1][currCol + 1].size() == 0 || board[currRow + 1][currCol + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol + 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                        currCol++;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow + 1][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow < 7 && currCol > 0 && (board[currRow + 1][currCol - 1].size() == 0 || board[currRow + 1][currCol - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol - 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                        currCol--;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow + 1][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && currCol < 7 && (board[currRow - 1][currCol + 1].size() == 0 || board[currRow - 1][currCol + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol + 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                        currCol++;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow - 1][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && currCol > 0 && (board[currRow - 1][currCol - 1].size() == 0 || board[currRow - 1][currCol - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol - 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                        currCol--;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow - 1][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow > 0 && (board[currRow - 1][currCol].size() == 0 || board[currRow - 1][currCol].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col;
                    int newRow = currRow;
                    if (board[currRow - 1][currCol].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow--;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow - 1][currCol].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currRow < 7 && (board[currRow + 1][currCol].size() == 0 || board[currRow + 1][currCol].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col;
                    int newRow = currRow + 2;
                    if (board[currRow + 1][currCol].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currRow++;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow + 1][currCol].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currCol > 0 && (board[currRow][currCol - 1].size() == 0 || board[currRow][currCol - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col - 1;
                    int newRow = currRow + 1;
                    if (board[currRow][currCol - 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currCol--;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow][currCol - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
                currRow = row;
                currCol = col;
                while (currCol < 7 && (board[currRow][currCol + 1].size() == 0 || board[currRow][currCol + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + currCol - col + 1;
                    int newRow = currRow + 1;
                    if (board[currRow][currCol + 1].size() == 0)
                    {
                        output.push_back("Q" + pos + string(1, newCol) + to_string(newRow));
                        currCol++;
                    }
                    else
                    {
                        output.push_back("Q" + pos + "x" + board[currRow][currCol + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                        break;
                    }
                }
            }

            //king

            for (int i = 0; i < blackPieces["K"].size(); i++)
            {
                string pos = blackPieces["Q"][i];
                int row = stoi(pos.substr(1)) - 1;
                int col = pos.at(0) - 'a';
                if (row > 0 && col > 0 && (board[row - 1][col - 1].size() == 0 || board[row - 1][col - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) - 1;
                    int newRow = row;
                    if (board[row - 1][col - 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row - 1][col - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row > 0 && col < 7 && (board[row - 1][col + 1].size() == 0 || board[row - 1][col + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + 1;
                    int newRow = row;
                    if (board[row - 1][col + 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row - 1][col + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row > 0 && (board[row - 1][col].size() == 0 || board[row - 1][col].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0);
                    int newRow = row;
                    if (board[row - 1][col].size() != 0)
                        output.push_back("K" + pos + "x" + board[row - 1][col].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row < 7 && col > 0 && (board[row + 1][col - 1].size() == 0 || board[row + 1][col - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) - 1;
                    int newRow = row + 2;
                    if (board[row + 1][col - 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row + 1][col - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row < 7 && col < 7 && (board[row + 1][col + 1].size() == 0 || board[row + 1][col + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + 1;
                    int newRow = row + 2;
                    if (board[row + 1][col + 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row + 1][col + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (row < 7 && (board[row + 1][col].size() == 0 || board[row + 1][col].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0);
                    int newRow = row + 2;
                    if (board[row + 1][col].size() != 0)
                        output.push_back("K" + pos + "x" + board[row + 1][col].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (col > 0 && (board[row][col - 1].size() == 0 || board[row][col - 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) - 1;
                    int newRow = row + 1;
                    if (board[row][col - 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row][col - 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
                if (col < 7 && (board[row][col + 1].size() == 0 || board[row][col + 1].substr(0, 1) != "B"))
                {
                    char newCol = pos.at(0) + 1;
                    int newRow = row + 1;
                    if (board[row][col + 1].size() != 0)
                        output.push_back("K" + pos + "x" + board[row][col + 1].substr(1, 2) + string(1, newCol) + to_string(newRow));
                    else
                        output.push_back("K" + pos + string(1, newCol) + to_string(newRow));
                }
            }
        }
        return output;
    }

    double getEvaluation() {
        double output = 0;
        //white pawns
        for (int i = 0; i < whitePieces["P"].size(); i++)
        {
            string pos = whitePieces["P"][i];
            double pawnEval = 1 + (stod(pos.substr(1)) - 2) / 10;
            output += pawnEval;
        }

        //black pawns

        for (int i = 0; i < blackPieces["P"].size(); i++)
        {
            string pos = blackPieces["P"][i];
            double pawnEval = 1 + (7 - stod(pos.substr(1))) / 10;
            output -= pawnEval;
        }

        //white knights

        for (int i = 0; i < whitePieces["N"].size(); i++)
        {
            string pos = whitePieces["N"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double knightEval = 3 - abs(3.5 - row) / 20 - abs(3.5 - col) / 20;
            output += knightEval;
        }

        //black knights

        for (int i = 0; i < blackPieces["N"].size(); i++)
        {
            string pos = blackPieces["N"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double knightEval = 3 - abs(3.5 - row) / 20 - abs(3.5 - col) / 20;
            output -= knightEval;
        }

        //white bishops

        for (int i = 0; i < whitePieces["B"].size(); i++)
        {
            string pos = whitePieces["B"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double bishopEval = 3;
            if (row == col || row + col == 7)
            {
                bishopEval += 0.3;
            }
            else if (abs(row - col) == 1 || abs(row + col - 7) == 1)
            {
                bishopEval += 0.4;
            }
            else if (abs(row - col) == 2 || abs(row + col - 7) == 2)
            {
                bishopEval += 0.2;
            }
            else
            {
                bishopEval += 0.1;
            }
            output += bishopEval;
        }

        //black bishops

        for (int i = 0; i < blackPieces["B"].size(); i++)
        {
            string pos = blackPieces["B"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double bishopEval = 3;
            if (row == col || row + col == 7)
            {
                bishopEval += 0.3;
            }
            else if (abs(row - col) == 1 || abs(row + col - 7) == 1)
            {
                bishopEval += 0.4;
            }
            else if (abs(row - col) == 2 || abs(row + col - 7) == 2)
            {
                bishopEval += 0.2;
            }
            else
            {
                bishopEval += 0.1;
            }
            output -= bishopEval;
        }

        //white rooks

        for (int i = 0; i < whitePieces["R"].size(); i++)
        {
            string pos = whitePieces["R"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double rookEval = 5;
            rookEval -= abs(3.5 - col) / 10;
            output += rookEval;
        }

        //black rooks

        for (int i = 0; i < blackPieces["R"].size(); i++)
        {
            string pos = blackPieces["R"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double rookEval = 5;
            rookEval -= abs(3.5 - col) / 10;
            output -= rookEval;
        }

        //white queens

        for (int i = 0; i < whitePieces["Q"].size(); i++)
        {
            string pos = whitePieces["Q"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double rookEval = 5;
            rookEval -= abs(3.5 - col) / 10;
            double bishopEval = 3;
            if (row == col || row + col == 7)
            {
                bishopEval += 0.3;
            }
            else if (abs(row - col) == 1 || abs(row + col - 7) == 1)
            {
                bishopEval += 0.4;
            }
            else if (abs(row - col) == 2 || abs(row + col - 7) == 2)
            {
                bishopEval += 0.2;
            }
            else
            {
                bishopEval += 0.1;
            }
            double queenEval = rookEval + bishopEval + 1;
            output += queenEval;
        }

        //black queens

        for (int i = 0; i < blackPieces["Q"].size(); i++)
        {
            string pos = blackPieces["Q"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double rookEval = 5;
            rookEval -= abs(3.5 - col) / 10;
            double bishopEval = 3;
            if (row == col || row + col == 7)
            {
                bishopEval += 0.3;
            }
            else if (abs(row - col) == 1 || abs(row + col - 7) == 1)
            {
                bishopEval += 0.4;
            }
            else if (abs(row - col) == 2 || abs(row + col - 7) == 2)
            {
                bishopEval += 0.2;
            }
            else
            {
                bishopEval += 0.1;
            }
            double queenEval = rookEval + bishopEval + 1;
            output -= queenEval;
        }

        //white king

        for (int i = 0; i < whitePieces["K"].size(); i++)
        {
            string pos = whitePieces["K"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double kingEval = 9999;
            output += kingEval;
        }

        //black king

        for (int i = 0; i < blackPieces["K"].size(); i++)
        {
            string pos = blackPieces["K"][i];
            int row = stoi(pos.substr(1)) - 1;
            int col = pos.at(0) - 'a';
            double kingEval = 9999;
            output -= kingEval;
        }

        return output;
    }

    void makeMove(string s)
    {
        string piece = s.substr(0, 1);
        string originPos = s.substr(1, 2);
        bool take = s.substr(3, 1) == "x";
        string finalPos;
        bool promotion = false;
        string promotionPiece = "";
        string takenPiece;
        if (take)
        {
            finalPos = s.substr(5, 2);
            if (s.substr(7, 1) == "=")
            {
                promotionPiece = s.substr(8, 1);
            }
            takenPiece = s.substr(4, 1);
        }
        else
        {
            finalPos = s.substr(3, 2);
            if (s.substr(5, 1) == "=")
            {
                promotionPiece = s.substr(6, 1);
            }
        }
        int originRow = stoi(originPos.substr(1)) - 1;
        int originCol = originPos.at(0) - 'a';
        int finalRow = stoi(finalPos.substr(1)) - 1;
        int finalCol = finalPos.at(0) - 'a';
        //change board
        board[originRow][originCol] = "";
        if (whiteMove)
        {
            if (promotion)
            {
                board[finalRow][finalCol] = "W" + promotionPiece;
            }
            else
            {
                board[finalRow][finalCol] = "W" + piece;
            }
        }
        else
        {
            if (promotion)
            {
                board[finalRow][finalCol] = "B" + promotionPiece;
            }
            else
            {
                board[finalRow][finalCol] = "B" + piece;
            }
        }
        //change black pieces
        if (whiteMove)
        {
            if (take)
            {
                for (int i = 0; i < blackPieces[takenPiece].size(); i++)
                {
                    if (blackPieces[takenPiece][i] == finalPos)
                    {
                        blackPieces[takenPiece].erase(blackPieces[takenPiece].begin() + i);
                        break;
                    }
                }
            }
        }
        else
        {
            if (promotion)
            {
                blackPieces[promotionPiece].push_back(finalPos);
            }
            else {
                for (int i = 0; i < blackPieces[piece].size(); i++)
                {
                    if (blackPieces[piece][i] == originPos)
                    {
                        blackPieces[piece][i] = finalPos;
                        break;
                    }
                }
            }
        }
        //change white pieces
        if (!whiteMove)
        {
            if (take)
            {
                for (int i = 0; i < whitePieces[takenPiece].size(); i++)
                {
                    if (whitePieces[takenPiece][i] == finalPos)
                    {
                        whitePieces[takenPiece].erase(whitePieces[takenPiece].begin() + i);
                        break;
                    }
                }
            }
        }
        else
        {
            if (promotion)
            {
                whitePieces[promotionPiece].push_back(finalPos);
            }
            for (int i = 0; i < whitePieces[piece].size(); i++)
            {
                if (whitePieces[piece][i] == originPos)
                {
                    whitePieces[piece][i] = finalPos;
                    break;
                }
            }
        }
        //change whiteMove
        whiteMove = !whiteMove;
    }
    void undoMove(string s)
    {
        string piece = s.substr(0, 1);
        string originPos = s.substr(1, 2);
        bool take = s.substr(3, 1) == "x";
        string finalPos;
        bool promotion = false;
        string promotionPiece = "";
        string takenPiece;
        if (take)
        {
            finalPos = s.substr(5, 2);
            if (s.substr(7, 1) == "=")
            {
                promotionPiece = s.substr(8, 1);
            }
            takenPiece = s.substr(4, 1);
        }
        else
        {
            finalPos = s.substr(3, 2);
            if (s.substr(5, 1) == "=")
            {
                promotionPiece = s.substr(6, 1);
            }
        }
        int originRow = stoi(originPos.substr(1)) - 1;
        int originCol = originPos.at(0) - 'a';
        int finalRow = stoi(finalPos.substr(1)) - 1;
        int finalCol = finalPos.at(0) - 'a';
        //change board
        if (whiteMove)
        {
            board[originRow][originCol] = "B" + piece;
        }
        else
        {
            board[originRow][originCol] = "W" + piece;
        }
        if (whiteMove)
        {
            if (take)
            {
                board[finalRow][finalCol] = "W" + takenPiece;
            }
            else
            {
                board[finalRow][finalCol] = "";
            }
        }
        else
        {
            if (take)
            {
                board[finalRow][finalCol] = "B" + takenPiece;
            }
            else
            {
                board[finalRow][finalCol] = "";
            }
        }
        //change blackpieces
        if (whiteMove)
        {
            if (promotion)
            {
                blackPieces[promotionPiece].pop_back();
                blackPieces[piece].push_back(originPos);
            }
            else
            {
                for (int i = 0; i < blackPieces[piece].size(); i++)
                {
                    if (blackPieces[piece][i] == finalPos)
                    {
                        blackPieces[piece][i] = originPos;
                    }
                }
            }
        }
        else
        {
            if (take)
            {
                blackPieces[takenPiece].push_back(finalPos);
            }
        }
        //change whitepieces
        if (!whiteMove)
        {
            if (promotion)
            {
                whitePieces[promotionPiece].pop_back();
                whitePieces[piece].push_back(originPos);
            }
            else
            {
                for (int i = 0; i < whitePieces[piece].size(); i++)
                {
                    if (whitePieces[piece][i] == finalPos)
                    {
                        whitePieces[piece][i] = originPos;
                    }
                }
            }
        }
        else
        {
            if (take)
            {
                whitePieces[takenPiece].push_back(finalPos);
            }
        }
        //change whitemove
        whiteMove = !whiteMove;
    }
};




int main()
{
    //set up board
    Board b;
    vector<string> moves = b.getAllMoves();
    for (int i = 0; i < moves.size(); i++)
    {
        cout << moves[i] << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
