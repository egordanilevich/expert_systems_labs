#ifndef PC_COMPONENTS_H
#define PC_COMPONENTS_H

#include <QtCore/QString>
#include <QtCore/QMap>
#include<QtCore/QVector>


#include <string>
#include <vector>
#include <algorithm>

struct Processor
{
    std::string vendor;
    std::string name;
    std::string socket;
    double price;
    int performanceIndex;
    std::vector<std::string> usage;
};

struct GraphicsCard
{
    std::string vendor;
    std::string name;
    double price;
    int performanceIndex;
    std::vector<std::string> usage;
};

struct SSD
{
    std::string name;
    double price;
    int capacity_GB;
    int performanceRating;
    std::vector<std::string> usage;
};

struct HDD
{
    std::string name;
    double price;
    int capacity_GB;
    int performanceRating;
    std::vector<std::string> usage;
};

struct Motherboard
{
    std::string name;
    std::string socket;
    double price;
    int performanceIndex;
    std::vector<std::string> usage;
};

struct OptimalConfiguration {
    Processor processor;
    GraphicsCard graphicsCard;
    SSD ssd;
    HDD hdd;
    Motherboard motherboard;
    QString RAM;
    QString programs;
    double price;

};

#endif // PC_COMPONENTS_H
