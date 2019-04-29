#ifndef Objetos_h
#define Objetos_h
#include <string>
#include <iostream>
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
    //Metodos modificadores y accesores
    string getNombre();
    double getPrecio();
    string getDescripcion();
    string getPropietario();

    void getNombre(string);
    void getPrecio(double);
    void getDescripcion(string);

};

    //Constructor
    Objetos::Objetos(){
        sNombre="NA";
        dPrecio=0.0;
        sDescripcion="N/A";
        sCorreoVendedor="N/A";
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

    void Objetos::getNombre(string nNombre){
        sNombre=nNombre;
    }
    void Objetos::getPrecio(double nPrecio){
        dPrecio=nPrecio;
    }
    void Objetos::getDescripcion(string nDescripcion){
        sDescripcion= nDescripcion;
    }

#endif