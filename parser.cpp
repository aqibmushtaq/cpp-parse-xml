#include <iostream>
#include <sstream>
#include "rapidxml/rapidxml_utils.hpp"

using namespace std;

int main (){
    rapidxml::xml_document<> doc;
    std::ifstream file("file.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);

    rapidxml::xml_node<> *pRoot = doc.first_node();

    // Get configurations
    rapidxml::xml_node<> *config = pRoot->first_node("Configuration");
    string schedulingPolicy = config->first_node("SchedulingPolicy")->value();
    string preemptive = config->first_node("Preemptive")->value();
    string numberOfDisks = config->first_node("NumberOfDisks")->value(); 
    string numberOfPrinters = config->first_node("NumberofPrinters")->value(); 

    cout << "SchedulingPolicy: " << schedulingPolicy << endl;
    cout << "Preemptive: " << preemptive << endl;
    cout << "NumbeofDisks: " << numberOfDisks << endl;
    cout << "NumberofPrinters: " << numberOfDisks << endl;

    // Get process details
    rapidxml::xml_node<> *processes = pRoot->first_node("Processes");
    for(rapidxml::xml_node<> *pNode=processes->first_node("Process"); pNode; pNode=pNode->next_sibling()) {
        cout << "ArrivalTime: " << pNode->first_node("ArrivalTime")->value() << endl;
        cout << "Type: " << pNode->first_node("Type")->value() << endl;
        cout << "code: " << pNode->first_node("code")->value() << endl;

    }

}
