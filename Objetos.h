#ifndef Objetos_h
#define Objetos_h
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

class Objetos{
    private:
    string sNombre;
    double dPrecio;
    string sDescripcion;
    string sCorreoVendedor;
    int iCalificacion;
    string sComentarios;

    public:
    //Constructor
    Objetos();
    Objetos(string,double,string,string);
    //Metodos modificadores y accesores
    string getNombre();
    double getPrecio();
    string getDescripcion();
    string getPropietario();

    void setNombre(string);
    void setPrecio(double);
    void setDescripcion(string);
    string toString();
    void imprimirEnPantalla();
    

};

    //Constructor
    Objetos::Objetos(){
        sNombre="N/A";
        dPrecio=0.0;
        sDescripcion="N/A";
        sCorreoVendedor="N/A";
        iCalificacion=0;
        sComentarios="N/A"; 
    }
    Objetos::Objetos(string nNombre,double nPrecio,string nDesc,string nCorreo){
        sNombre=nNombre;
        dPrecio=nPrecio;
        sDescripcion=nDesc;
        sCorreoVendedor=nCorreo;
        iCalificacion=0;
        sComentarios="N/A"; 
    }
    //Metodos modificadores y accesores
    string Objetos::getNombre(){
        return sNombre;
    }
    double Objetos::getPrecio(){
        return dPrecio;
    }
    string Objetos::getDescripcion(){
        return sDescripcion;
    }
    string Objetos::getPropietario(){
        return sCorreoVendedor;
    }

    void Objetos::setNombre(string nNombre){
        sNombre=nNombre;
    }
    void Objetos::setPrecio(double nPrecio){
        dPrecio=nPrecio;
    }
    void Objetos::setDescripcion(string nDescripcion){
        sDescripcion= nDescripcion;
    }
    string Objetos::toString(){
        //sNombre,dPrecio,sDescripcion,sCorreo,
        string objectString=sNombre+",";
        objectString+=std::to_string(dPrecio);
        objectString+=","+sDescripcion+","+sCorreoVendedor;
        return objectString;
    }
    void Objetos::imprimirEnPantalla(){
        cout <<"\n Nombre del objeto: "<<sNombre<<"\nPrecio: "<<dPrecio<<"\n Descripción: "<<sDescripcion<< "\nCorreo del propetario: "<<sCorreoVendedor<<endl;
    }

#endif