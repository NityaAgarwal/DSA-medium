/*
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
*/

class Solution {
private: 
    Node* func(Node* node, Node* prev, unordered_map<Node*, Node*>&m) {
        Node* newNode = new Node(0);
        if (!m.count(node)) {
            newNode -> val = node -> val;
            m[node] = newNode;
        }
        else return m[node];
        //recursive - call it for all neighbours of this node
        for (int i = 0; i<node->neighbors.size(); i++) {
            if(newNode -> val != 0) newNode -> neighbors.push_back(func(node->neighbors[i], node, m));
        }
        //return the clone's head
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL; 
        unordered_map<Node*, Node*> m;
        return func(node, NULL, m);
    }
};
