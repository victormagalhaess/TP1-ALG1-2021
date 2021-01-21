#include "../include/Graph.hpp"
using namespace vaccineDistribution;

Graph::Graph(){};

Graph::~Graph(){};

int Graph::getNumberOfNodes()
{
    return this->numberOfNodes;
}

void Graph::setNumberOfNodes(int newNumberOfNodes)
{
    this->numberOfNodes = newNumberOfNodes;
}

std::vector<int> Graph::findAllReacheableNodes(int depthMax)
{
    std::vector<bool> justChecked(this->numberOfNodes, false);
    std::vector<int> allReachedNodes;

    for (int i = 0; i < this->numberOfCD; i++)
    {

        std::queue<int> firstLevelQueue;
        std::queue<int> secondLevelQueue;
        std::vector<int>::iterator it;

        for (it = this->adjacencyList[i].begin(); it != this->adjacencyList[i].end(); it++)
        {
            firstLevelQueue.push(*it);
        }

        for (int j = 0; j < depthMax; j++)
        {
            while (!firstLevelQueue.empty())
            {
                int actualElement = firstLevelQueue.front();
                int listIndex = actualElement + this->numberOfCD - 1;
                firstLevelQueue.pop();
                if (actualElement != 0)
                {
                    allReachedNodes.push_back(actualElement);

                    if (!justChecked[listIndex])
                    {
                        justChecked[listIndex] = true;
                        for (std::vector<int>::iterator jit = this->adjacencyList[listIndex].begin(); jit != this->adjacencyList[listIndex].end(); jit++)
                        {
                            secondLevelQueue.push(*jit);
                        }
                    }
                }
            }
            firstLevelQueue.swap(secondLevelQueue);
        }
    }
    return (allReachedNodes);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        std::vector<int>::iterator i;
        for (i = this->adjacencyList[v].begin(); i != this->adjacencyList[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[this->numberOfNodes];
    bool *recStack = new bool[this->numberOfNodes];
    for (int i = 0; i < this->numberOfNodes; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < this->numberOfNodes; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}