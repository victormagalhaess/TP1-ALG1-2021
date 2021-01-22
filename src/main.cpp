#define MAX_CD 10
#define MAX_PV 100

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include "./include/Graph.hpp"

using namespace vaccineDistribution;

int main()
{
    int PVQuantity, CDQuantity, temperatureIncrement;
    std::cin >> CDQuantity >> PVQuantity >> temperatureIncrement;

    if (PVQuantity > MAX_PV || PVQuantity < 1 || CDQuantity > MAX_CD || CDQuantity < 1 || temperatureIncrement < 1)
    {
        return 0;
    }

    int totalHealthUnities = PVQuantity + CDQuantity;
    int maxNumberOfHUByTemperature = 30 / temperatureIncrement; // (-60 - (-90)) / X
    Graph *graph = new Graph();
    graph->setNumberOfNodes(totalHealthUnities);
    graph->numberOfCD = CDQuantity;
    std::cin.ignore(INT16_MAX, '\n');

    for (int i = 0; i < totalHealthUnities; i++)
    {
        std::string line;
        std::vector<int> edges;
        getline(std::cin, line);
        std::istringstream iss(line);
        for (std::string line; iss >> line;)
        {
            edges.push_back(stoi(line));
        }
        graph->adjacencyList.push_back(edges);
    }

    if (maxNumberOfHUByTemperature == 0)
    {
        std::cout << 0
                  << std::endl
                  << '*'
                  << std::endl
                  << 0;
        return 0;
    }

    std::vector<int> allReachableHU = graph->findAllReacheableNodes(maxNumberOfHUByTemperature);

    std::sort(allReachableHU.begin(), allReachableHU.end());
    allReachableHU.erase(std::unique(allReachableHU.begin(), allReachableHU.end()), allReachableHU.end());

    std::cout << allReachableHU.size() << std::endl;
    for (auto it = allReachableHU.begin(); it != allReachableHU.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl
              << graph->isCyclic();

    return 0;
}