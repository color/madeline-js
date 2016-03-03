// Nested API

#if !defined(__nested_parser_h__)
#define __nested_parser_h__

#include <string>
#include <vector>

#include "TableParser.h"


class NestedParser: public TableParser
{
    public:
        NestedParser(std::vector<std::string> const &header,
                     std::vector<std::string> const &content);
}; // NestedParser


NestedParser::NestedParser(std::vector<std::string> const &header,
                           std::vector<std::string> const &content)
{
    _columns = header.size();
    _rows = content.size() / _columns;
    _columnType = std::vector<char>(_columns, '\0');
    _title = std::vector<std::string>(header);
    _element = std::vector<std::string>(content);
} // NestedParser::NestedParser

#endif

