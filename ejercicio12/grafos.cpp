#include "grafos.h"

shared_ptr<Node> push(shared_ptr<Node> &n1, shared_ptr<Node> &n2, bool bidirecional)
{
    n1->neighbors.insert(n2);
    if(bidirecional)
        n2->neighbors.insert(n1);
    return n1;
}

void dijistra(shared_ptr<Node> &n1, vector<shared_ptr<Node>> vector_nodos)
{
    
}
