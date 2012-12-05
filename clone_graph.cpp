/*
 * clone graph: http://www.leetcode.com/2012/05/clone-graph-part-i.html
 * Song Qiang <qiang.song@usc.edu> 2012-09-04
 *
 */

struct Node {
    vector<Node *> neighbors;
};


Node* 
clone_graph(const Node* head)
{
    if (head == NULL) return NULL;

    std::queue<Node*> q;
    std::unordered_map<Node*, Node*> t;
    
    q.push_back(new Node(*head));
    const Node* new_head = q.back();
    t[head] = new_head;

    do
    {
        const Node* ptr = q.front();
        q.pop_front();
        
        const Node* new_ptr = t[ptr];
        
        for (size_t i = 0; i < ptr->neighbors.size(); ++i)
            if (t.find(ptr->neighbors[i]) != t.end())
            {
                new_ptr->neighbors[i] = t[ptr->neighbors[i]];
            }
            else
            {
                q.push_back(new Node(*ptr->neighbors[i]));
                t[ptr->neighbors[i]] = q.back();
                new_ptr->neighbors[i] = q.back();
            }
    } while (!q.empty());
    
    return new_head;
}
