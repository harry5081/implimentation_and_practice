#include <iostream>
// #include <stdlib>
#include <vector>
#include <list>

typedef struct{
    int to;
    int weight;
}edge;

class Graph{
    private:
        int vertex_num;
        std::vector<std::list<edge*>> edges;
    
    public:
        Graph(int);
        void print_edges();
        bool add_edge(int from, int to, int weight=1);
};

Graph::Graph(int v){
    vertex_num = v;
    edges.resize(vertex_num);

}

void Graph::print_edges(){
    for(int i=0; i<vertex_num; i++){
        std::cout << i+1 << "\t";
        auto itr = edges[i].begin();
        // list<edge*>::iterator
        for(; itr!=edges[i].end(); itr++){
            std::cout << "->" << (*itr)->to+1 << "," << (*itr)->weight;
        }
        std::cout << std::endl;
    }
    
}

bool Graph::add_edge(int from, int to, int weight){
    edges[from-1].push_back(new edge{to-1, weight});
    // edges[to-1].push_back(new edge{from-1, weight}); // undirected graph
    return true;

}

int main(){

    Graph my_graph(5);
    // my_graph.print_matrix();
    my_graph.add_edge(1,4,5);
    // my_graph.add_edge(0,3);
    my_graph.print_edges();

    return 0;
}