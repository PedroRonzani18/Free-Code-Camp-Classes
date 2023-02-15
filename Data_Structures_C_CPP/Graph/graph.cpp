#include <vector>
#include <string>

struct Edge_1
{
    int startVertex;
    int endVertex;
};

// Edge List
struct Graph_1 // Linear search : O(n²)
{
    std::vector<std::string> vertexes;
    std::vector<Edge_1> edges;
    int weight;
};

// Adjacency Matrix
struct Graph_2
{
    std::vector<std::string> vertexes;
    std::vector<std::vector<int>> edges;
    // Matriz de 0 ou 1: 1 se linha i se liga à coluna j
    // e mais rapido do que graph_1, porem como  cria um amatrixx de VxV, gasta muita memoria
    // E bom quando grafo for denso, ou v² e tao pequeno que nao importa
};

// Adjacency List
struct Graph_3
{
    std::vector<std::string> vertexes;
    std::vector<std::vector<int>> edges;
    // semi matriz armazena dinamicamente os indices de quais vertides o item na linha i está ligado (for i=0; i<len(edg); i++)
    // em C: vetor de ponteiros, em que cada ponteiro aponta para um vetor de tamanho x diferente (int A*[8] ; A[0] = new int[3] ; A[1] = new int[2])
    // Space complexity: O(e)
    // Time complexiy: O(v)
};
