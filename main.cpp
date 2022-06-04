#include <iostream>
#include "src/pugixml.hpp"
#include <filesystem>

#include <cstdio>
#include <ctime>

using std::filesystem::directory_iterator;

using namespace std;
// ********  Funzione esempio 1 *************//
void getRootName(){
    pugi::xml_document doc;
    doc.load_file("Fattura1.xml");
    pugi::xml_node node = doc.first_child();
    cout<<"Root Name: "<<node.name()<<endl;
}
// ********  Funzione esempio 2 *************//
void getNodeValue(){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("FATT/Fattura1.xml");
    pugi::xml_node node=doc.first_child();
    cout << node.name()<<endl;
    pugi::xml_node nodeChild=node.child("FatturaElettronicaBody").child("DatiPagamento").child("DettaglioPagamento").child("ImportoPagamento");
    cout<<"NODE:ImportoPagamento" <<endl;
    cout<<"VALUE: "<<nodeChild.child_value()<<endl;
}

// ********  Funzione esempio 3 *************//
void listDir(){  
    string path = "FATT";
    for (const auto & file : directory_iterator(path))
        cout << file.path().string() << endl;
}

//**** Funzione calcola importo talale delle fatture ****** //
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
}

//****** Funzioni calcola data Corrente ************* //
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d-%H%M%S", &tstruct);

    return buf;
}

// ******** Funzione rinomina fatture elaborate presenti nella cartella FATT *******//
void renameAllFile(){
    string path = "FATT";
    string s = currentDateTime();
    for (const auto & file : directory_iterator(path)){      
       rename(file.path().string().c_str(), (file.path().string()+s).c_str()); 
    }
}

// ******** Funzione sposta fatture elaborate presenti nella cartella FATT nella cartella FATT1  ******//
void moveAllFileXML(){
    system("move \"fatt\\*\" \"fatt1\" ");
}

// ******** Funzione Menu ******//
int menu(void){
  int selezione = 0;
  do{
    cout<<endl<<"1 - Trova importo totale"<<endl;
    cout<<"2 - Sposta le fatture elaborate"<<endl;
    cout<<"3 - Esci"<<endl;
    cout<<"Effettua una scelta:"<<endl;
    cin>>selezione;
    }
    while (selezione< 1 || selezione>3);
  return selezione;
}
//Programma principale
int main()
{
    int scelta;
    do{
        //system ("cls");
        scelta=menu();
        switch (scelta){
            case 1:
            {
             getImportoAllFatt();
             break;
            }
            case 2:
            {
                renameAllFile();
                moveAllFileXML();
                break;
            }
            default:
                {
                    cout << " scelta non valida \n";
                }
            break;
        }
    } while(scelta!= 3);
    
    cout<<" \n*********FINE ELABORAZIONE***********************\n";
    //cin.get();
    //cin.get();
    return 0;
}
