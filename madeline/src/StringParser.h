#if !defined(__string_parser_h__)
#define __string_parser_h__

#include <string>
#include <vector>

#include "TableParser.h"


class StringParser: public TableParser
{
    public:
        StringParser(std::vector<std::string> const &header,
                     std::vector<std::string> const &content);
}; // StringParser


StringParser::StringParser(std::vector<std::string> const &header,
                           std::vector<std::string> const &content)
{
    _columns = header.size();
    _rows = content.size() / _columns;
    _columnType = std::vector<char>(_columns, '\0');
    _title = std::vector<std::string>(header);
    _element = std::vector<std::string>(content);
} // StringParser::StringParser

#endif

