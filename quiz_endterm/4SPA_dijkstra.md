We use Dijkstra’s algorithm when we have weighted graph with only positive
weights, and have to find the shortest path from one source vertex to
others.

• We choose neighbor nodes greedily
using a priority queue to always expand
the “closest” node;
• Once a node is finalized, its shortest
distance is never updated.


Applications:
• GPS navigation;
• Routing in networks;
• Path-planning.