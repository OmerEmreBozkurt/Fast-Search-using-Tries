**Fast Search Using Tries**

**Description**
In this project, you will implement a program that can do fast search on words in a dictionary. The dictionary will be stored in a data structure called Trie, where each node (except the root node) is a letter from English alphabet and any word can be read by following the path from root to a node (not necessarily a leaf node).

![image](https://github.com/OmerEmreBozkurt/fast-search-using-tries-EmreBozkurt/assets/94068773/0024c2b0-259e-4199-ab9e-720c1b3cc520)

In the figure above, you find a trie constructed from words, (ace, acid, art, go, god, good, gosh, gossip, great, greed, greek). The letters are represented with red color if the word ends with that letter, otherwise with white color.

**Dictionary**
Dictionary file contains n + 1 lines, where the first line contains the number of words in the dictionary. Then the next n lines contains words one by one.

_Sample Dictionary:_
11
ace
acid
art
go
god
good
gosh
gossip
great
greed
greek 

**Input and Output**
Input file contains n + 1 lines, where the first line contains the number of test cases n. Then the next n lines contain test cases one by one. Each line contains two items separated via space. First item is the operator to be applied. It is either search or prefix. Second is the string to be searched or the prefix to be searched.

_Sample Input File #1:_
3
search act
prefix ac
prefix go

_Sample Input File #2:_
2
search acid
prefix a

Output file contains n lines, where each line corresponds to one test case output as follows:
•	If the operator is search
o	if the word to be searched is in the trie, output is 'true' 
o	Otherwise, output is 'false'. 
•	If the operator is prefix, output is a sorted list of words starting with that prefix in the trie.

_Sample Output File #1:_
false
ace acid
go god good gosh gossip

_Sample Output File #2:_
true
ace acid art 
