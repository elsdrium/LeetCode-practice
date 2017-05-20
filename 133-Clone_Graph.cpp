class Solution {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mapping;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if ( node == NULL ) return NULL;
        if ( mapping.find(node) != mapping.end() ) return mapping[node];
        mapping[node] = new UndirectedGraphNode(node->label);
        for ( UndirectedGraphNode *neighbor : node->neighbors ) {
            (mapping[node]->neighbors).push_back(cloneGraph(neighbor));
        }
        return mapping[node];
    }
};
