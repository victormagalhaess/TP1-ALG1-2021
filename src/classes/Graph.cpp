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

bool Graph::isCyclic()
{

    std::vector<int> justChecked(this->numberOfNodes, 0);
    std::stack<int> elements;
    std::vector<int> onThisCycle;
    bool hasCycles = false;

    for (int i = 0; i < numberOfCD; i++)
    {
        elements.push(i);
        onThisCycle.push_back(i);

        while (!elements.empty())
        {
            int position = elements.top();
            elements.pop();
            if (justChecked[position] == 0)
            {
                justChecked[position]++;
                for (auto it = adjacencyList[position + numberOfCD - 1].begin(); it != adjacencyList[position + numberOfCD - 1].end(); it++)
                {
                    if (*it == 0)
                    {
                        for (auto jit = onThisCycle.begin(); jit != onThisCycle.end(); jit++)
                        {
                            justChecked[*jit] = 0;
                            *jit = 0;
                        }
                    }
                    else
                    {
                        elements.push(*it);
                        onThisCycle.push_back(*it);
                    }
                }
            }
            else if (justChecked[position] == 1)
            {
                hasCycles = true;
                break;
            }
        }
    }
    return hasCycles;
}
