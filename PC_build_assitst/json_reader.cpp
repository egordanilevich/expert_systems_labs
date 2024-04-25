#include "json_reader.h"
#include <iostream>

std::vector<Processor> JsonReader::readProcessors(const std::string &data)
{
    rapidjson::Document document;
    std::vector<Processor> processors;

    if(!document.Parse(data.c_str()).HasParseError() && document.IsArray())
    {
        for (rapidjson::Value &processorObj : document.GetArray())
        {
            Processor processor;
            processor.vendor = processorObj["vendor"].GetString();
            processor.name = processorObj["name"].GetString();
            processor.socket = processorObj["socket"].GetString();
            processor.price = processorObj["price"].GetDouble();
            processor.performanceIndex = processorObj["performance_index"].GetInt();

            const rapidjson::Value& usageArray = processorObj["usage"];
            for (rapidjson::SizeType j = 0; j < usageArray.Size(); j++)
            {
                processor.usage.push_back(usageArray[j].GetString());
            }

            processors.push_back(processor);
        }
    }
    else
    {
        std::cout << "Parse error - processors!\n";
    }
    return processors;
}

std::vector<GraphicsCard> JsonReader::readGraphicsCards(const std::string &data)
{
    rapidjson::Document document;
    std::vector<GraphicsCard> graphicsCards;

    if(!document.Parse(data.c_str()).HasParseError() && document.IsArray())
    {
        for (rapidjson::Value &graphicsCardObj : document.GetArray())
        {
            GraphicsCard graphicsCard;
            graphicsCard.vendor = graphicsCardObj["vendor"].GetString();
            graphicsCard.name = graphicsCardObj["name"].GetString();
            graphicsCard.price = graphicsCardObj["price"].GetDouble();
            graphicsCard.performanceIndex = graphicsCardObj["performance_index"].GetInt();

            const rapidjson::Value& usageArray = graphicsCardObj["usage"];
            for (rapidjson::SizeType j = 0; j < usageArray.Size(); j++)
            {
                graphicsCard.usage.push_back(usageArray[j].GetString());
            }

            graphicsCards.push_back(graphicsCard);
        }
    }
    else
    {
        std::cout << "Parse error - graphics cards!\n";
    }
    return graphicsCards;
}

std::vector<SSD> JsonReader::readSSDs(const std::string &data)
{
    rapidjson::Document document;
    std::vector<SSD> SSDs;

    if(!document.Parse(data.c_str()).HasParseError() && document.IsArray())
    {
        for (rapidjson::Value &SSDObj : document.GetArray())
        {
            SSD ssd;
            ssd.name = SSDObj["name"].GetString();
            ssd.price = SSDObj["price"].GetDouble();
            ssd.capacity_GB = SSDObj["capacity_GB"].GetInt();
            ssd.performanceRating = SSDObj["performance_index"].GetInt();

            const rapidjson::Value& usageArray = SSDObj["usage"];
            for (rapidjson::SizeType j = 0; j < usageArray.Size(); j++)
            {
                ssd.usage.push_back(usageArray[j].GetString());
            }

            SSDs.push_back(ssd);
        }
    }
    else
    {
        std::cout << "Parse error - SSDs!\n";
    }
    return SSDs;
}

std::vector<HDD> JsonReader::readHDDs(const std::string &data)
{
    rapidjson::Document document;
    std::vector<HDD> HDDs;

    if(!document.Parse(data.c_str()).HasParseError() && document.IsArray())
    {
        for (rapidjson::Value &HDDObj : document.GetArray())
        {
            HDD hdd;
            hdd.name = HDDObj["name"].GetString();
            hdd.price = HDDObj["price"].GetDouble();
            hdd.capacity_GB = HDDObj["capacity_GB"].GetInt();
            hdd.performanceRating = HDDObj["performance_index"].GetInt();

            const rapidjson::Value& usageArray = HDDObj["usage"];
            for (rapidjson::SizeType j = 0; j < usageArray.Size(); j++)
            {
                hdd.usage.push_back(usageArray[j].GetString());
            }

            HDDs.push_back(hdd);
        }
    }
    else
    {
        std::cout << "Parse error - HDDs!\n";
    }
    return HDDs;
}

std::vector<Motherboard> JsonReader::readMotherboards(const std::string &data)
{
    rapidjson::Document document;
    std::vector<Motherboard> motherboards;

    if(!document.Parse(data.c_str()).HasParseError() && document.IsArray())
    {
        for (rapidjson::Value &motherboardsObj : document.GetArray())
        {
            Motherboard motherboard;
            motherboard.name = motherboardsObj["name"].GetString();
            motherboard.socket = motherboardsObj["socket"].GetString();
            motherboard.price = motherboardsObj["price"].GetDouble();
            motherboard.performanceIndex = motherboardsObj["performance_index"].GetInt();

            const rapidjson::Value& usageArray = motherboardsObj["usage"];
            for (rapidjson::SizeType j = 0; j < usageArray.Size(); j++)
            {
                motherboard.usage.push_back(usageArray[j].GetString());
            }

            motherboards.push_back(motherboard);
        }
    }
    else
    {
        std::cout << "Parse error - motherboards!\n";
    }
    return motherboards;
}
