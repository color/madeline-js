#include <string>

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include "madeline/src/DrawingMetrics.h"
#include "madeline/src/Parser.h"
#include "madeline/src/PedigreeSet.h"
#include "madeline/src/ColorSeries.h"
#include "madeline/src/DrawingColor.h"


std::string pedigree_SVG(emscripten::val header,
                         emscripten::val content,
                         emscripten::val labels)
{
    DrawingMetrics::setBlackAndWhite(false);
    DrawingMetrics::setColor(true);
    DrawingMetrics::setEmbeddedState(true);
    DrawingMetrics::setNoLabelTruncation(true);
    DrawingMetrics::setScalableState(false);
    DrawingMetrics::setNoIconLabels(true);
    // Set the boolean switch in DrawingMetrics:
    // Taken from original Madeline main.cpp repo to force colors on Affected_ labels
    DrawingMetrics::setUseCustomIconColors(true);
    std::string colorString = "red;yellow;lime;aqua;blue;fuchsia;maroon;olive;green;teal;navy;purple";
    std::istringstream css(colorString);
    std::string t1,t2;
    ColorSeries tempCS; // temporary color series storage
    std::vector<std::string> tempV; // temporary vector for push back
    std::map<std::string,DrawingColor> tempM; // temporary map for push back
    // Break each set at semicolon delimiters:
    for(unsigned i=0; std::getline(css,t1,';');i++){
        tempV.clear();
        tempCS.clear();
        std::istringstream csst(t1);
        // For each set of colors, break at comma delimiters
        // and push colors onto a temp vector:
        while(std::getline(csst,t2,',')){
            if(t2.find("=")!=std::string::npos){
                // String contains a mapping:
                std::istringstream cssu(t2);
                std::string t3,t4;
                std::getline(cssu,t3,'=');
                std::getline(cssu,t4);
                // Push to map:
                tempM[t3]=DrawingColor(t4,t4);
            }else{
                tempV.push_back(t2);
            }
        }
        if(tempM.size()){
            DrawingMetrics::customColorMap.push_back(tempM);
            // std::cout << "MAP " << (i+1) << ":" << std::endl;
            // for (std::map<std::string,DrawingColor>::iterator it=DrawingMetrics::customColorMap[i].begin(); it!=DrawingMetrics::customColorMap[i].end(); ++it){
            //     std::cout << "   " << it->first << " => " << it->second.get() << std::endl;
            // }
            tempM.clear();
        }
        // Push the strings in reverse order onto the
        // tempCS ColorSeries:c
        std::vector<std::string>::reverse_iterator r = tempV.rbegin();
        for(; r!= tempV.rend(); ++r){
            tempCS.pushBack(*r);
        }
        // Finally, store each custom color series in the static DrawingMetrics vector:
        DrawingMetrics::customColorSeries.push_back(tempCS);
    }
    // verbose reporting:
    // std::cout << "Custom color series: " << DrawingMetrics::customColorSeries.size() << std::endl;
    // for(unsigned i=0;i<DrawingMetrics::customColorSeries.size();i++){
    //     unsigned jmax = DrawingMetrics::customColorSeries.at(i).levels();
    //     std::cout << "Custom series " << (i+1) << " has " << jmax << " levels:" << std::endl;
    //     for(unsigned j=0;j<jmax;j++){
    //         std::cout << "   " << (i+1) << "." << (j+1) << ". " << DrawingMetrics::customColorSeries[i].getColorAtLevel(j) << std::endl;
    //     }
    // }

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

