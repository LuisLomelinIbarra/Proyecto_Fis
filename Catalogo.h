#ifndef Catalogo_h
#define Catalogo_h
#include "Objetos.h"
using namespace std;

class Catalogo{
    protected:
    Objetos colleccionDeObjetos[100];
    int iCapacidad;

    public:
    Catalogo();
    Objetos buscarObjeto(string);
    bool publicarObjeto(Objetos);
    bool editarObjeto(Objetos);

};

    Catalogo::Catalogo(){
        iCapacidad=0;
    }
    Objetos Catalogo::buscarObjeto(string sNombreObjeto){
        for(int i=0; i<iCapacidad;i++){
            if(sNombreObjeto==colleccionDeObjetos[i].getNombre()){
                return colleccionDeObjetos[i];
            }
        }
    }
    bool Catalogo::publicarObjeto(Objetos nObjeto){
        if(iCapacidad<size(colleccionDeObjetos)){
            colleccionDeObjetos[iCapacidad]=nObjeto;
            iCapacidad++;
            return true;
        }else{

            return false;
        }
    }
    bool Catalogo::editarObjeto(Objetos nObjeto){
        for(int i=0; i<iCapacidad;i++){
            if(colleccionDeObjetos[i].getPropietario()==nObjeto.getPropietario()){
                colleccionDeObjetos[i]=nObjeto;
                return true;
            }
        }
        return false;
    }


#endif