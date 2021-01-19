#ifndef HEALTH_UNITY
#define HEALTH_UNITY
namespace vaccineDistribution
{
    class HealthUnity
    {
    private:
        int id;
        bool isDistributionCenter;
        bool justChecked;

    public:
        int getId();
        bool getDistributionCenterStatus();
        bool getCheckedStatus();
        void setId(int newId);
        void setDistributionCenterStatus(bool newDistributionCenterStatus);
        void setCheckedStatus(bool newCheckedStatus);

        HealthUnity();
        HealthUnity(int id, bool isDistributionCenter);
        ~HealthUnity();
    };
} // namespace vaccineDistribution
#endif