#pragma once
#include <string>
#include <vector>
#include "XMLReader.h"

struct Relationship
{
    uint32_t rid;
};

struct State
{
    uint32_t sid;
    uint32_t armycount;
    uint32_t cx;
    uint32_t cy;
    std::string name;
    std::vector<Relationship> relationships;
};

struct Country
{
    uint32_t cid;
    uint32_t numstates;
    std::string name;
    std::vector<State> states;
};

class MapMetaLoader : public bali::XMLReader
{
public:
    static bool load(const char *fn, std::vector<Country> & countries) {
        return XMLReader::LoadXMLFile(fn, (void*)&countries, MapMetaLoader::start_element_handler, MapMetaLoader::end_element_handler, MapMetaLoader::character_data_handler);
    }

    static void character_data_handler(void *data, const char *content, int length)
    {

    }

    static void end_element_handler(void *data, const char *element)
    {

    }

    static void start_element_handler(void *data, const char *element, const char **attribute)
    {
        std::string elementName(element);
        std::vector<Country> * countries = (std::vector<Country>*)data;
        if (elementName == "countries")
        {
            // countries is already allocated
        }
        else if (elementName == "country")
        {
            countries->push_back(Country());
            Country & c = countries->back();
            for (size_t i = 0; attribute[i]; i += 2)
            {
                if (std::string(attribute[i]) == "name")
                {
                    c.name = std::string(attribute[i + 1], NULL, 10);
                }
                else if (std::string(attribute[i]) == "cid")
                {
                    c.cid = std::strtol(attribute[i + 1], NULL, 10);
                }
            }
        }
        else if (elementName == "state")
        {
            countries->back().states.push_back(State());
            State & state = countries->back().states.back();
            for (size_t i = 0; attribute[i]; i += 2)
            {
                if (std::string(attribute[i]) == "name")
                {
                    state.name = std::string(attribute[i + 1], NULL, 10);
                }
                else if (std::string(attribute[i]) == "sid")
                {
                    state.sid = std::strtol(attribute[i + 1], NULL, 10);
                }
                else if (std::string(attribute[i]) == "cx")
                {
                    state.cx = std::strtol(attribute[i + 1], NULL, 10);
                }
                else if (std::string(attribute[i]) == "cy")
                {
                    state.cy = std::strtol(attribute[i + 1], NULL, 10);
                }
            }
        }
        else if (elementName == "relationships")
        {

        }
        else if (elementName == "relationship")
        {
            State & state = countries->back().states.back();
            state.relationships.push_back(Relationship());
            Relationship & relationship = state.relationships.back();
            for (size_t i = 0; attribute[i]; i += 2)
            {
                if (std::string(attribute[i]) == "rid")
                {
                    relationship.rid = std::strtol(attribute[i + 1], NULL, 10);
                }
            }
        }
    }
};









