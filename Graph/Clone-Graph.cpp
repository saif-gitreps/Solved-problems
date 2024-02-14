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
public:
    Node* dfs(Node *source, map<Node*, bool> &vis, map<Node*, Node*> &copies){
        if (source == nullptr)
            return nullptr;

        if (copies.find(source) != copies.end())
            return copies[source];

        vis[source] = true;
        Node* sourceNode = new Node(source->val);
        copies[source] = sourceNode;
        for(auto node: source->neighbors){
            if(vis[node] == false){
                sourceNode->neighbors.push_back(dfs(node, vis, copies));
            } else {
                sourceNode->neighbors.push_back(copies[node]);
            }
        }
    return sourceNode;
}

    Node* cloneGraph(Node* node) {
        map<Node*, bool> vis;
        map<Node*, Node*> copies;
        return dfs(node, vis, copies);
    }
};
