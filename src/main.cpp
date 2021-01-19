#define MAX_CD 10
#define MAX_PV 100

#include <iostream>
#include "./include/HealthUnity.hpp"

using namespace vaccineDistribution;

int main()
{
    int PVQuantity;
    int CDQuantity;
    int temperatureIncrement;
    std::cin >> PVQuantity >> CDQuantity >> temperatureIncrement;

    if (PVQuantity > MAX_PV || PVQuantity < 1 || CDQuantity > MAX_CD || CDQuantity < 1 || temperatureIncrement < 1)
    {
        return 0;
    }
    int totalHealthUnities = PVQuantity + CDQuantity;

    int x = 3;
    return 0;
}