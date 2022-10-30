#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "Trie.h"

using namespace std;

Trie trie;
char board[4][4];
vector<string> words;

void traverse(int x, int y, bool vis[4][4], string word) {
    if (x < 0 || x > 3 || y < 0 || y > 3) return;
    word = word + board[x][y];
    bool end = false;
    if (!trie.search(word, end) || vis[x][y]) return;
    if (end && word.length() > 2) words.push_back(word);
    bool tempV[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tempV[i][j] = vis[i][j];
    tempV[x][y] = true;
    traverse(x, y+1, tempV, word);
    traverse(x, y-1, tempV, word);
    traverse(x-1, y, tempV, word);
    traverse(x+1, y, tempV, word);
    traverse(x-1, y+1, tempV, word);
    traverse(x-1, y-1, tempV, word);
    traverse(x+1, y+1, tempV, word);
    traverse(x+1, y-1, tempV, word);
}

void buildTrie() {
    string line;
    ifstream in("dictionary.txt");
    if (!in)
        cout << "bruh" << endl;
    while (in >> line)
        trie.insert(line);
}

int main() {
    buildTrie();
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
        }
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            traverse(i, j, visited, "");
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(),words.end()),words.end());
    sort(words.begin(), words.end(), []
            (const string& first, const string& second){
        return first.size() < second.size();
    });
    for (auto iter : words)
        cout << iter << endl;
    cout << "Press ENTER to exit...";
    char ch = getch();
    return 0;
}
