/*
 * clone graph: http://www.leetcode.com/2012/05/clone-graph-part-i.html
 * Song Qiang <qiang.song@usc.edu> 2012-09-04
 *
 */

/*

 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
  
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

#include <cmath>
#include <cassert>

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <limits>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>


using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if (node == NULL) return NULL;

        queue<UndirectedGraphNode*> newg;
        queue<UndirectedGraphNode*> oldg;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;

        oldg.push(node);
        newg.push(new UndirectedGraphNode(node->label));
        m[oldg.back()] = newg.back();

        UndirectedGraphNode* result = newg.front();
        
        while (!newg.empty()) 
        {
            for (size_t i = 0; i < oldg.front()->neighbors.size(); ++i)
                if (m.find(oldg.front()->neighbors[i]) != m.end())
                {
                    newg.front()->neighbors.push_back(
                        m[oldg.front()->neighbors[i]]);
                }
                else
                {
                    oldg.push(oldg.front()->neighbors[i]);
                    newg.push(new UndirectedGraphNode(oldg.back()->label));
                    newg.front()->neighbors.push_back(newg.back());
                    m[oldg.back()] = newg.back();
                }
            oldg.pop();
            newg.pop();
        }
        return result;
    }
};


int
main(int argn, char** argv)
{
    Solution s;
}

// struct Node {
//     vector<Node *> neighbors;
// };


// Node* 
// clone_graph(const Node* head)
// {
//     if (head == NULL) return NULL;

//     std::queue<Node*> q;
//     std::unordered_map<Node*, Node*> t;
    
//     q.push_back(new Node(*head));
//     const Node* new_head = q.back();
//     t[head] = new_head;

//     do
//     {
//         const Node* ptr = q.front();
//         q.pop_front();
        
//         const Node* new_ptr = t[ptr];
        
//         for (size_t i = 0; i < ptr->neighbors.size(); ++i)
//             if (t.find(ptr->neighbors[i]) != t.end())
//             {
//                 new_ptr->neighbors[i] = t[ptr->neighbors[i]];
//             }
//             else
//             {
//                 q.push_back(new Node(*ptr->neighbors[i]));
//                 t[ptr->neighbors[i]] = q.back();
//                 new_ptr->neighbors[i] = q.back();
//             }
//     } while (!q.empty());
    
//     return new_head;
// }


