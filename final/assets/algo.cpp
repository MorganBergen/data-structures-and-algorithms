void Graph::dijkstra(Vertex s) {
    for each Vertex v {
        v.dist = INFINITY;
        v.known = false;
    }
}

s.dist = 0;

while(there is an unknown distance vertex) {
    Vertex v = smallest unknwon distance vertex;
    v.known = true;

    for each Vertex w adjacent to v {
        if(!w.known) {
            DistType cvw = cost of edge from v to w;
            if(v.dist + cvw < w.dist) {
                // update w
                decrease(w.dist to v.dist + cvw);
                w.path = v;
            }
        }
    }
}
