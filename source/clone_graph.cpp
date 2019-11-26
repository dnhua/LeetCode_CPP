#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
    return helper(node, map);
}

UndirectedGraphNode * helper(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& map) {
    if (node == NULL) return NULL;
    if (map.count(node)) return map[node];
    UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
    map[node] = clone;
    for (UndirectedGraphNode *neighbor : node->neighbors) {
        clone->neighbors.push_back(helper(neighbor, map));
    }
    return clone;
}
