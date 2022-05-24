#include <iostream>
#include "src/pugixml.hpp"

using namespace std;

void getRootName(){
    pugi::xml_document doc;
    doc.load_file("Fattura1.xml");
    pugi::xml_node node = doc.first_child();
    cout<<"Root Name: "<<node.name()<<endl;
}
void getRootName1(){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("Fattura1.xml");

    pugi::xml_node node = doc.first_child();
    cout<<"Root Name: "<<node.name()<<endl;
}
void getNodeValue(){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("Fattura1.xml");
    pugi::xml_node node=doc.first_child();
    cout << node.name()<<endl;
    pugi::xml_node nodeChild=node.child("FatturaElettronicaBody").child("DatiPagamento").child("DettaglioPagamento").child("ImportoPagamento");
    cout<<"NODE:ImportoPagamento" <<endl;
    cout<<"VALUE: "<<nodeChild.child_value()<<endl;
}
int main()
{
    getNodeValue();
    cout<<" \n*********FINE ELABORAZIONE***********************\n";
    cin.get();
    cin.get();
    return 0;
}


