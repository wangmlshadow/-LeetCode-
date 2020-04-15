#include "normal.h"

/*

���һ��֧���������ֲ��������ݽṹ��

void addWord(word)
bool search(word)
search(word) �����������ֻ�������ʽ�ַ������ַ���ֻ������ĸ . �� a-z �� . ���Ա�ʾ�κ�һ����ĸ��
*/

class WordDictionary {
public:
    class Node {
    public:
        char val;
        vector<Node*> next;

        Node(char ch){
            val = ch;
            next = vector<Node*>(27, NULL);   // �洢��a-z �Լ� '\0'
        }
    };

    /** Initialize your data structure here. */
    WordDictionary() {
        head = new Node('\0');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        int len = word.length();
        addNode(head, word, len);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int len = word.length();
        return searchNode(head, word, len);
    }

private:
    Node* head;

    void addNode(Node* node, string subWord, int len) {
        if (len == 0) {
            if (node->next[26] == NULL)
                node->next[26] = new Node('\0');
        }
        else {
            int pos = subWord[0] - 'a';

            if (node->next[pos] == NULL) 
                node->next[pos] = new Node(subWord[0]);
            
            addNode(node->next[pos], subWord.substr(1), len - 1);
        }
    }

    bool searchNode(Node* node, string subWord, int len) {
        if (len == 0) {
            return node->next[26] != NULL;
        }
        else {
            char ch = subWord[0];

            if (ch != '.') {
                int pos = ch - 'a';

                if (node->next[pos] == NULL)
                    return false;
                else
                    return searchNode(node->next[pos], subWord.substr(1), len - 1);
            }
            else {
                bool sign = false;

                for (int i = 0; i < 26; i++) {                   
                    if (node->next[i] != NULL) {
                        sign = sign || searchNode(node->next[i], subWord.substr(1), len - 1);
                    }

                    if (sign)
                        return sign;
                }

                return sign;
            }
        }
    }
}; 

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */