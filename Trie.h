#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    bool end;
    Node* children[26]{};
    Node() {
        end = false;
        for (auto & i : children)
            i = nullptr;
    }
};

struct Trie {
    Node* head;
    Trie() {
        head = new Node();
    }
    void insert(const string& word) {
        Node* node = head;
        for (char i : word) {
            int ind = i - 65;
            if (node->children[ind] == nullptr)
                node->children[ind] = new Node();
            node = node->children[ind];
        }
        node->end = true;
    }
    bool search(const string& word, bool& complete) {
        Node* node = head;
        for (char i : word) {
            int ind = i - 65;
            if (node->children[ind] == nullptr)
                return false;
            node = node->children[ind];
        }
        complete = node->end;
        return true;
    }
};