//
// Created by eb029107 on 4/3/2024.
//

#ifndef FAST_SEARCH_USING_TRIES_OMEREMREBOZKURT_TRIENODE_H
#define FAST_SEARCH_USING_TRIES_OMEREMREBOZKURT_TRIENODE_H

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

    /**
     * inserts provided string to trie structure, it divides the string into the letters and puts them into nodes
     * @param key word in string to be inserted in trie
     */
    void insertKey(string& key);

    /**
     * searches provided string in trie, if it exists it returns true
     * @param key word in string to be searched in trie
     * @return If the word exists in tree it returns true, otherwise it returns false
     */
    bool searchKey(const string& key);

    /**
     * finds prefix in tree and finds all word that starts with prefix
     * @param prefix prefix in string form to be searched in trie
     * @return returns a vector<string> which holds all words that start with given prefix
     */
    vector<string> search_words_with_prefix(const string& prefix);

    /**
     * finds word which starts with given prefix in a recursive way
     * @param currentNode Node that will be searched after
     * @param prefix prefix that will be searched under the node
     * @param result vector<string> which holds all words that start with given prefix
     */
    void collect_words(TrieNode* currentNode, const string& prefix, vector<string>& result);
};


#endif //FAST_SEARCH_USING_TRIES_OMEREMREBOZKURT_TRIENODE_H
