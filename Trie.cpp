#include <iostream>
#include <string>
using namespace std;

struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(){
    
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }

};

class Trie{

private:
    TrieNode* root;

public:

    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        
        TrieNode* curr = root;

        for (char c : word){
            
            int inx = c - 'a';

            if (curr -> children[inx] == NULL)
                curr -> children[inx] = new TrieNode();
    
            curr = curr -> children[inx];
        }

        curr -> isEndOfWord = true;
    }

    bool search(string word){
        
        TrieNode* curr = root;

        for (char c : word){

            int inx = c - 'a'; 

            if (curr -> children[inx] == NULL)
                return false;

            curr = curr -> children[inx];
        }

        return curr -> isEndOfWord;
    }

    bool isEmpty(TrieNode* node){
        
        for (int i = 0; i < 26; i++)
            if (node -> children[i] != NULL)
                return false;
        
        return true;
    }

    bool deleteHelper(TrieNode* curr, string word, int depth){

        if (!curr) return false;

        if (depth == word.size()){
            
            if (!curr -> isEndOfWord) return false;
            curr -> isEndOfWord = false;
            return isEmpty(curr);
        }

        int inx = word[depth] - 'a';

        if (deleteHelper(curr -> children[inx], word, depth+1)){ //اگر در ادامه ی اون نود به کلمه ی دیگه ای نمیرسیم
            
            delete curr -> children[inx];
            curr -> children[inx] = NULL;
            return (!curr -> isEndOfWord && isEmpty(curr));
        }

        return false;
    }

    void remove(string word){
        deleteHelper(root, word, 0);
    }
};

int main() { //test
    Trie t;

    t.insert("cat");
    t.insert("car");
    t.insert("dog");

    cout << t.search("cat") << endl; // 1
    cout << t.search("cap") << endl; // 0

    t.remove("cat");

    cout << t.search("cat") << endl; // 0
    cout << t.search("car") << endl; // 1
}