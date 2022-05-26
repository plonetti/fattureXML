#include <iostream>
#include "src/pugixml.hpp"

#include <filesystem>
using std::filesystem::directory_iterator;

using namespace std;


void getRootName(){
    pugi::xml_document doc;
    doc.load_file("Fattura1.xml");
    pugi::xml_node node = doc.first_child();
    cout<<"Root Name: "<<node.name()<<endl;
}
void getRootName1(){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("FATT/Fattura1.xml");

    pugi::xml_node node = doc.first_child();
    cout<<"Root Name: "<<node.name()<<endl;
}
void getNodeValue(){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("FATT/Fattura1.xml");
    pugi::xml_node node=doc.first_child();
    cout << node.name()<<endl;
    pugi::xml_node nodeChild=node.child("FatturaElettronicaBody").child("DatiPagamento").child("DettaglioPagamento").child("ImportoPagamento");
    cout<<"NODE:ImportoPagamento" <<endl;
    cout<<"VALUE: "<<nodeChild.child_value()<<endl;
}

void listDir(){  
    string path = "FATT";
    for (const auto & file : directory_iterator(path))
        cout << file.path().string() << endl;
}

void getImportoAllFatt(){
   string path = "FATT";
   // const char* path = R"(FATT)";
    double totale=0;
    const char* nodeValue;
    for (const auto & file : directory_iterator(path)){
        pugi::xml_document doc;
        //cout<<file.path().string().c_str();
       
        pugi::xml_parse_result result = doc.load_file(file.path().string().c_str()); 
        pugi::xml_node node=doc.first_child();
        
        pugi::xml_node nodeChild=node.child("FatturaElettronicaBody").child("DatiPagamento").child("DettaglioPagamento").child("ImportoPagamento");
        
        nodeValue=nodeChild.child_value();
        string fs(nodeValue);
        totale += atof(fs.c_str());
       
    }
    cout<<"IMPORTO TOTALE DELLE FATTURE :" << totale<< endl;
    //system("move \"FATT\\*" "FATT1"); 
}

int main()
{
    getImportoAllFatt();
    cout<<" \n*********FINE ELABORAZIONE***********************\n";
    //cin.get();
    //cin.get();
    return 0;
}

