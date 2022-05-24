#include <iostream>
#include "src/pugixml.hpp"

using namespace std;

void getRootName(){
    pugi::xml_document doc;
    doc.load_file("Fattura1.xml");
    pugi::xml_node node = doc.first_child();
    cout<<"Root Name: "<<node.name()<<endl;
}

void getNodeValue(){
    pugi::xml_document doc;
    doc.load_file("Fattura1.xml");
    pugi::xml_node node=doc.first_child();
    cout << node.name()<<endl;
    pugi::xml_node node1=node.child("FatturaElettronicaBody").child("DatiPagamento").child("DettaglioPagamento").child("ImportoPagamento");
    cout<<"VALORE: "<<node1.child_value()<<endl;
}
int main()
{
   // stampaRadice();
    //stampaFigli();
    getNodeValue();
    cout<<" \n*********FINE ELABORAZIONE***********************\n";
    cin.get();
    cin.get();
    return 0;

}


