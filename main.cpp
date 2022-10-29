#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

int main() {
    Trie trie;
    string line;
    ifstream in("dictionary.txt");
    if (!in)
        cout << "bruh" << endl;
    while (in >> line) {
        trie.insert(line);
    }
    char board[4][4];
    bool visited[4][4];
    string letters;
    bool valid = false;
    while (!valid) {
        cout << "Input letters: " << endl;
        cin >> letters;
        if (letters.length() != 16) {
            cout << "Invalid letter count!" << endl;
            continue;
        }
        for (int i = 0; i < letters.length(); i++) {
            if (!isalpha(letters[i])) {
                cout << "Invalid character!" << endl;
                break;
            }
            if (letters[i] == letters[letters.length()-1])
                valid = true;
            letters[i] = char(toupper(letters[i]));
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = letters[4*i+j];
            visited[i][j] = false;
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}

void traverse () {

}