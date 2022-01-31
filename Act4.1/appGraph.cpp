// Act 4.1 - Grafo: sus representaciones y sus recorridos 
// Salvador Fernando Camacho Hernandez A01634777
// Sabado 13 de noviembre del 2021

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>

struct Edge {
    int src,    //source
        dest;   //destination
};

class Graph {
    public:
        std::vector< std::vector<int> > adjList;
        void loadGraph(int, int, std::string);
        Graph(int, int, std::string);
        /*
        Graph(std::vector<Edge> const& edges, int n) {
            adjList.resize(n);    //The adjacencies list is the length of the vertices

            //Hacer el grafo no dirigido
            for (auto& edge : edges) {
                adjList[edge.src].push_back(edge.dest);
                adjList[edge.dest].push_back(edge.src);
            }
        }
        */
};

Graph::Graph(int numVertix, int numEdge, std::string archivo) {
    loadGraph(numVertix, numEdge, archivo);
}

void Graph::loadGraph(int numVertix, int numEdge, std::string archivo) {
    std::vector<Edge> edges;

    std::ifstream ifs;
    ifs.open(archivo);
    std::string line;

    int cont = 0; //Counter to stop the while cycle if the number of edges is reached

    while (getline(ifs, line) && cont < numEdge) {
        cont++;
        std::stringstream s;
        s << line;
        int source, destination;
        s >> source >> destination;
        //Create edge to add to the vector edges
        Edge edge;
        edge.src = source;
        edge.dest = destination;
        edges.push_back(edge);
    }

    ifs.close();

    adjList.resize(numVertix); //The adjacencies list is the length of the vertices

    //Hacer el grafo no dirigido
    for (auto& edge : edges) {
        adjList[edge.src].push_back(edge.dest);
        adjList[edge.dest].push_back(edge.src);
    } 
}

void BFS(Graph const& graph, int v, std::vector<bool>& discovered) { // O(n^2)
    std::queue<int> q;
    //The current vertix is mark as discovered
    discovered[v] = true;
    q.push(v);

    while (!q.empty()) { // O(n)
        v = q.front();
        q.pop();
        std::cout << v << " ";

        // do for every edge (v -> u)
		for (int u : graph.adjList[v]) { // O(n)
			if (!discovered[u]) {
				discovered[u] = true;
				q.push(u);
			}
        }
    }
}

void DFS(Graph const& graph, int v, std::vector<bool>& discovered) { // O(n^2)
    //The current vertix is mark as discovered
    discovered[v] = true;
    std::cout << v << " ";

    // do for every edge (v -> u)
	for (int u : graph.adjList[v]){
		if (!discovered[u])
			DFS(graph, u, discovered);
	}
}


int main() {

    //Number of vertices, including the 0
    int n1 = 13;
    //Number of edges
    int e1 = 11;

    //Create and load the graph
    Graph graph1(n1, e1, "edges1.txt");
    
    //Vectors to know if a vertix has been discovered
    std::vector<bool> discovered1(n1);
    std::vector<bool> discoveredB1(n1, false);

    std::cout << "Grafo 1";

    //Recorrido DFS
    std::cout << std::endl << "Recorrido DFS: " << std::endl;

    for (int i = 0; i < n1; i++) {
		if (discovered1[i] == false)
			DFS(graph1, i, discovered1);
    }

    //Recorrido BFS
	std::cout << std::endl << "Recorrido BFS: " << std::endl;

	for (int i = 0; i < n1; i++) {
		if (discoveredB1[i] == false)
			BFS(graph1, i, discoveredB1);
	}

    return 0;
}
