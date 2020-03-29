#include "normal.h"

/*
�������� ��ͨ ͼ��һ���ڵ�����ã����㷵�ظ�ͼ�� �������¡����
*/


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        map<int, Node*> sign; // �ж�ĳ���ڵ��Ƿ��Ѿ�
        return addNode(node, sign);
    }

    Node* addNode(Node* parent, map<int, Node*>& sign) {
        map<int, Node*>::iterator key = sign.find(parent->val);

        if (key != sign.end())
            return sign[parent->val];

        int val = parent->val;
        Node* cur = new Node(val);
        sign[val] = cur;

        for (auto i : parent->neighbors) {
            cur->neighbors.push_back(addNode(i, sign));
        }

        return cur;
    }
};