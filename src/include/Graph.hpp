#ifndef GRAPH
#define GRAPH
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <list>
namespace vaccineDistribution
{
    class Graph
    {
    private:
        int numberOfNodes;

    public:
        int numberOfCD;
        int numberOfPV;
        int getNumberOfNodes();
        void setNumberOfNodes(int newNumberOfNodes);
        std::vector<std::vector<int>> adjacencyList;
        std::vector<int> getCycles();
        bool isCyclicUtil(int v, bool visited[], bool *recStack);
        bool isCyclic();

        std::vector<int> findAllReacheableNodes(int depthMax);
        Graph();
        ~Graph();
    };
} // namespace vaccineDistribution
#endif