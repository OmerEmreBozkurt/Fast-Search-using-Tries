#include "TrieNode.h"
#include <iostream>


using namespace std;

TrieNode::TrieNode() {
    wordCount = 0;
    for (int i = 0; i < 26; ++i) {
        childNodes[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    delete *childNodes;
}

void TrieNode::insertKey(string &key) {
    TrieNode* currentNode = this;
    for (char c : key) {
        int index = c - 'a';
        if (currentNode->childNodes[index] == nullptr) {
            currentNode->childNodes[index] = new TrieNode();
        }
        currentNode = currentNode->childNodes[index];
    }
    currentNode->wordCount++;
}

bool TrieNode::searchKey(const string &key) {
    TrieNode* currentNode = this;
    for (char c : key) {
        int index = c - 'a';
        if (currentNode->childNodes[index] == nullptr){
            return false;
        }
        currentNode = currentNode->childNodes[index];
    }
    return currentNode->wordCount > 0;
}

//which finds prefix in tree and finds all word that starts with prefix
vector<string> TrieNode::search_words_with_prefix(const string &prefix) {
    TrieNode* currentNode = this;
    vector<string> result;

    for (char c : prefix) {
        int index = c - 'a';
        if (currentNode->childNodes[index] == nullptr) {
            return result;
        }
        currentNode = currentNode->childNodes[index];
    }

    collect_words(currentNode, prefix, result);
    return result;
}

//finds word which starts with given prefix in recursive way
void TrieNode::collect_words(TrieNode *currentNode, string prefix, vector<string> &result) {
    if (currentNode->wordCount > 0) {
        result.push_back(prefix);
    }

    for (int i = 0; i < 26; ++i) {
        if (currentNode->childNodes[i] != nullptr){
            char nextChar = i + 'a';
            collect_words(currentNode->childNodes[i], prefix + nextChar, result);
        }
    }
}




