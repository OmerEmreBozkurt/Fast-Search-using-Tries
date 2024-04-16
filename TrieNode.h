#ifndef FAST_SEARCH_USING_TRIES_EMREBOZKURT_TRIENODE_H
#define FAST_SEARCH_USING_TRIES_EMREBOZKURT_TRIENODE_H

#include <string>
#include <vector>

using namespace std;

class TrieNode {
protected:
    TrieNode* childNodes[26]{};
    int wordCount;

public:
    explicit TrieNode();
    ~TrieNode();
    void insertKey(string& key);
    bool searchKey(const string& key);
    vector<string> search_words_with_prefix(const string& prefix);
    void collect_words(TrieNode* currentNode, string prefix, vector<string>& result);
};


#endif //FAST_SEARCH_USING_TRIES_EMREBOZKURT_TRIENODE_H