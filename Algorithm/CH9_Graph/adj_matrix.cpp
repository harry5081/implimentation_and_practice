#include <iostream>
// #include <stdlib>
#include <vector>

class Graph{
    private:
        int vertex_num;
        // int **matrix;
        std::vector<std::vector<int>> matrix;
    public:
        Graph(int);
        void print_matrix();
        bool add_edge(int from, int to, int weight=1);
};

Graph::Graph(int v){
    vertex_num = v;
    // matrix = (int**) malloc(sizeof(int*)*vertex_num);
    // for(int i=0; i<vertex_num; i++){
    //     // *(matrix+i) = (int*) malloc(sizeof(int)*vertex_num);
    //     *(matrix+i) = (int*) calloc(vertex_num, sizeof(int)); // initialize as 0
    // }

    matrix.resize(vertex_num, std::vector<int> (vertex_num, 0));

}

void Graph::print_matrix(){
    for(int i=0; i<vertex_num; i++){
        for(int j=0; j<vertex_num; j++){
            std::cout << matrix[i][j]<< "\t";
        }
        std::cout << std::endl;
    }

    // for(int i=0; i<vertex_num; i++){
    //     for(int j=0; j<vertex_num; j++){
    //         std::cout << *((*matrix+i)+j)<< "\t";
    //     }
    //     std::cout << std::endl;
    // }
}

bool Graph::add_edge(int from, int to, int weight){
    if(matrix[from][to]){
        std::cout<< "Error!! Edge already exists"<< std::endl;
        return false;
    }
    matrix[from][to] = weight;
    matrix[to][from] = weight; // undirected graph
    return true;

}

int main(){

    Graph my_graph(5);
    // my_graph.print_matrix();
    my_graph.add_edge(1,4);
    // my_graph.add_edge(0,3);
    my_graph.print_matrix();

    return 0;
}