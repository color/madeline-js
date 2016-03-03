#include <string>
#include <vector>

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include "madeline/src/DrawingMetrics.h"
#include "madeline/src/Parser.h"
#include "madeline/src/PedigreeSet.h"


std::string pedigree_SVG(emscripten::val header, emscripten::val content)
{
    DrawingMetrics::setColor(true);
    DrawingMetrics::setEmbeddedState(true);
    DrawingMetrics::setScalableState(true);

    Parser dataTableParser;
    dataTableParser.nested(emscripten::vecFromJSArray<std::string>(header),
                           emscripten::vecFromJSArray<std::string>(content));

    DataTable* dataTable = dataTableParser.getTable(0);
    if (dataTable->getTableType() == DataTable::PEDIGREE)
    {
        PedigreeSet pedigreeSet;
        pedigreeSet.addPedigreesFromDataTable(dataTable, 0, "");
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
