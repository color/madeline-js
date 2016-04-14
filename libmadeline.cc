#include <string>

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include "madeline/src/DrawingMetrics.h"
#include "madeline/src/Parser.h"
#include "madeline/src/PedigreeSet.h"


std::string pedigree_SVG(emscripten::val header,
                         emscripten::val content,
                         emscripten::val labels)
{
    DrawingMetrics::setColor(true);
    DrawingMetrics::setEmbeddedState(true);
    DrawingMetrics::setScalableState(false);

    if (emscripten::vecFromJSArray<std::string>(header).size() == 0 ||
        emscripten::vecFromJSArray<std::string>(header).size() == 0)
    {
        return std::string();
    } // if

    Parser dataTableParser;
    dataTableParser.from_string(emscripten::vecFromJSArray<std::string>(header),
                                emscripten::vecFromJSArray<std::string>(content));

    DataTable* const dataTable = dataTableParser.getTable(0);
    if (dataTable->getTableType() == DataTable::PEDIGREE)
    {
        PedigreeSet pedigreeSet;
        std::string sortField = "";

        dataTable->toggleColumnsForPedigree(emscripten::vecFromJSArray<std::string>(labels));
        pedigreeSet.addPedigreesFromDataTable(dataTable, 0, sortField);
        return pedigreeSet.draw(dataTable);
    } // if
    return std::string();
} // pedigree_SVG


EMSCRIPTEN_BINDINGS(stl_wrappers)
{
    emscripten::register_vector<std::string>("VectorString");
}

EMSCRIPTEN_BINDINGS(module)
{
    emscripten::function("draw", &pedigree_SVG);
}

