#include "normal.h"

/*
ʵ��һ�� Trie (ǰ׺��)������ insert, search, �� startsWith ������������

˵��:
����Լ������е����붼����Сд��ĸ a-z ���ɵġ�
��֤���������Ϊ�ǿ��ַ�����
*/

class Trie {
public:
    class Node {
    public:
        char val;
        vector<Node*> next;
    };

    /** Initialize your data structure here. */
    Trie() {
        head = new Node;
        head->val = '\0';
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertNode(head, word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchNode(head, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startWithNode(head, prefix);
    }

private:
    Node* head;

    void insertNode(Node* node, string subWord) {
        int len = subWord.length();

        if (len == 0) {
            if (haveNode(node, '\0') == NULL) {
                Node* end = new Node;
                end->val = '\0';
                node->next.push_back(end);
            }
        }
        else {
            Node* cur = haveNode(node, subWord[0]);

            if (cur != NULL) {
                insertNode(cur, subWord.substr(1));
            }
            else {
                cur = node;
                for (int i = 0; i < len; i++) {
                    Node* p = new Node;
                    p->val = subWord[i];
                    cur->next.push_back(p);
                    cur = p;
                }

                Node* p = new Node;
                p->val = '\0';
                cur->next.push_back(p);
            }
        }
    }

    Node* haveNode(Node* node, char ch) {
        int size = node->next.size();

        for (int i = 0; i < size; i++) {
            if (node->next[i]->val == ch)
                return node->next[i];
        }

        return NULL;
    }

    bool searchNode(Node* node, string subWord) {
        int len = subWord.length();

        if (len == 0) {
            return haveNode(node, '\0') != NULL;
        }
        else {
            Node* cur = haveNode(node, subWord[0]);

            if (cur == NULL)
                return false;
            else
                return searchNode(cur, subWord.substr(1));
        }
    }

    bool startWithNode(Node* node, string subWord) {
        int len = subWord.length();

        if (len == 0)
            return true;
        else {
            Node* cur = haveNode(node, subWord[0]);

            if (cur == NULL)
                return false;
            else
                return startWithNode(cur, subWord.substr(1));
        }
    }
};

// �޸� ����ǰ׺�����Կռ任ʱ�� ��ô��������next��Ϊmap<char, vector<Node*>>

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */