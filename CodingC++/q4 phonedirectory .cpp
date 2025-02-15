#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {  // Use < 26 instead of <= 26
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {  // Corrected constructor to take no arguments
        root = new TrieNode('\0');  // Root node with null character
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';  // Assume the word is in lowercase
        TrieNode* child;

        // If present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // If absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];  // Corrected the reference from `char->children` to `curr->children`

            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();  // Corrected to function call
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastCh = str[i];
            prefix.push_back(lastCh);

            // Check for lastCh
            TrieNode* curr = prev->children[lastCh - 'a'];

            // If not found
            if (curr == NULL) {
                break;
            }

            // If found, then print all suggestions
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            prev = curr;
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    // Creation of Trie
    Trie* t = new Trie();

    // Insert all contacts in Trie
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }

    // Return the suggestions
    return t->getSuggestions(queryStr);
}

int main() {
    vector<string> contactList = {"cod", "coding", "codding", "code", "coly"};
    string queryStr = "cod";

    vector<vector<string>> str = phoneDirectory(contactList, queryStr);

    // Print the result
    for (const auto& suggestions : str) {
        for (const auto& word : suggestions) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}