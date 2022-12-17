#pragma once

#include <iostream>
#include <vector>
#include "IParsable.h"

class ParserFactory
{
private:
    vector<IParsable *> parsers;

public:
    void registerWith(IParsable *parser)
    {
        parsers.push_back(parser);
    }

    IParsable *create(string type)
    {
        for (auto parser : parsers)
        {
            if (parser->getType() == type)
            {
                return parser;
            }
        }

        return nullptr;
    }
};