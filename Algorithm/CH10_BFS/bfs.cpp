#include <iostream>
#include <vector>
#include <list>
#include <queue>



class Graph{
    private:
        int vertex_num;
        std::vector<std::list<int>> edges;
    
    public:
        Graph(int);
        void print_edges();
        bool add_edge(int from, int to);
        void bfs(int start);
        // TODO: connected_component 10_02 24:00
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
            std::cout << "->" << (*itr)+1;
        }
        std::cout << std::endl;
    }
    
}

bool Graph::add_edge(int from, int to){
    edges[from-1].push_back(to-1);
    // edges[to-1].push_back(new edge{from-1, weight}); // undirected graph
    return true;
}

void Graph::bfs(int start){
    
    start--;
    // 0: white
    // 1: gray
    // 2: black
    std::vector<int> color(vertex_num, 0);
    std::queue<int> bfs_q;
    bfs_q.push(start);
    color[start] = 1;
    std::cout << start+1 << "->";
    while(!bfs_q.empty()){
        int current = bfs_q.front();
        bfs_q.pop();
        
        for(auto itr = edges[current].begin(); itr != edges[current].end(); itr++){
            if(color[*itr] == 0){
                std::cout << *itr+1 << "->";
                bfs_q.push(*itr);
                color[*itr]=1;
            }
        }
        color[current]=2;
    }
    std::cout << std::endl;
    return;

}
    

int main(){

    Graph my_graph(7);
    my_graph.add_edge(1,3);
    my_graph.add_edge(1,2);
    my_graph.add_edge(1,6);
    my_graph.add_edge(2,4);
    my_graph.add_edge(2,7);
    my_graph.add_edge(3,4);
    my_graph.add_edge(4,5);
    my_graph.add_edge(6,5);
    my_graph.add_edge(7,6);
    my_graph.add_edge(7,5);
    my_graph.print_edges();

    my_graph.bfs(1);

    return 0;
}