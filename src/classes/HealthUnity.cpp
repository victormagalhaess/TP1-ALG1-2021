#include "../include/HealthUnity.hpp"
using namespace vaccineDistribution;

HealthUnity::HealthUnity()
{
    this->justChecked = false;
    this->isDistributionCenter = false;
}

HealthUnity::HealthUnity(int id, bool isDistributionCenter)
{
    this->id = id;
    this->justChecked = false;
    this->isDistributionCenter = isDistributionCenter;
}

HealthUnity::~HealthUnity()
{
}

int HealthUnity::getId()
{
    return this->id;
}

bool HealthUnity::getCheckedStatus()
{
    return this->justChecked;
}

bool HealthUnity::getDistributionCenterStatus()
{
    return this->isDistributionCenter;
}

void HealthUnity::setId(int newId)
{
    this->id = newId;
}

void HealthUnity::setCheckedStatus(bool newCheckedStatus)
{
    this->justChecked = newCheckedStatus;
}

void HealthUnity::setDistributionCenterStatus(bool newDistributionCenterStatus)
{
    this->isDistributionCenter = newDistributionCenterStatus;
}