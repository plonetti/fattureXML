#include <iostream>
#include "src/pugixml.hpp"
#include <dirent.h>
#include <vector>
#include <typeinfo>

#include <stdio.h>
#include <windows.h>

using namespace std;

vector<string> files;
string vFiles[]={};

void stampaRadice(){
    pugi::xml_document doc;
    doc.load_file("Fattura1.xml");
    pugi::xml_node node = doc.first_child();
    cout<<"NOME DEL PRIMO NODO:"<<node.name()<<endl;
}
void stampaFigli(){
    pugi::xml_document doc;
    doc.load_file("Fattura1.xml");
    pugi::xml_node node = doc.first_child().first_child().first_child();
    cout<<"VALORE DEL TERZO FIGLIO: "<<node.child_value()<<endl;
}

void stampaNodo(){
    pugi::xml_document doc;
    doc.load_file("Fattura1.xml");
    pugi::xml_node node=doc.first_child();
    cout << node.name()<<endl;
    pugi::xml_node node1=node.child("FatturaElettronicaBody").child("DatiPagamento").child("DettaglioPagamento").child("ImportoPagamento");
    cout<<"VALORE DEL NODO:"<<node1.child_value()<<endl;
}
int main()
{
   // stampaRadice();
    //stampaFigli();
    stampaNodo();
    cout<<" \n*********FINE ELABORAZIONE***********************\n";
    cin.get();
    cin.get();
    return 0;

}


