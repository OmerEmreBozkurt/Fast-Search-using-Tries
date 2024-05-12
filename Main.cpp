//
// Created by eb029107 on 3/27/2024.
//
using namespace std;

#include <iostream>
#include <fstream>
#include "TrieNode.h"

int main() {

    TrieNode* root = new TrieNode();

    //imports dictionary
    ifstream dictFile("../dictionary.txt");
    string line;
    getline(dictFile,line);
    cout << line << endl;
    int n = stoi(line);
    cout << "n = " << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << ", ";
        getline(dictFile, line);
        root->insertKey(line);
        cout << line << " inserted" << endl;
    }
    dictFile.close();

    // defines output file
    ofstream outputFile("../output.txt");

    //reads input file, calls appropriate operations and writes result in output file
    ifstream inputFile("../input.txt");
    getline(inputFile,line);
    cout << line << endl;
    n = stoi(line);
    string operation, key;
    for (int i = 0; i < n; ++i) {
        cout << i << ", ";
        getline(inputFile, operation, ' ');
        getline(inputFile, key);
        cout << "Operation : " << operation << " String: " << key << endl;
        if (operation == "search"){
            string result;
            if (root->searchKey(key)){result = "true";}
            else {result = "false";}
            outputFile << result << endl; // writes result to output file
            cout << result << endl;
        } else if (operation == "prefix") {
            vector<string> result = root->search_words_with_prefix(key);
            for (const string& word : result) {
                outputFile << word << ' ';
                cout << word << ' ';
            }
            outputFile << endl;
            cout << endl;
        }
    }
    inputFile.close();
    outputFile.close();


    return 0;
}
