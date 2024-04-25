#include <include/rapidjson/document.h>
#include "PC_components.h"



class JsonReader
{
public:
    static std::vector<Processor> readProcessors(const std::string &data);
    static std::vector<GraphicsCard> readGraphicsCards(const std::string &data);
    static std::vector<SSD> readSSDs(const std::string &data);
    static std::vector<HDD> readHDDs(const std::string &data);
    static std::vector<Motherboard> readMotherboards(const std::string &data);
};
