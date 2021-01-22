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
        std::vector<std::vector<int>> adjacencyList;

        void setNumberOfNodes(int newNumberOfNodes);
        bool isCyclic();
        std::vector<int> findAllReacheableNodes(int depthMax);

        Graph();
        ~Graph();
    };
} // namespace vaccineDistribution
#endif