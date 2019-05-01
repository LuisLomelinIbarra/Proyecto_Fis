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
    Objetos buscarObjeto(string,string);
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
    Objetos Catalogo::buscarObjeto(string sNombreObjeto,string sNombreVend){
        for(int i=0; i<iCapacidad;i++){
           
            if(sNombreObjeto==colleccionDeObjetos[i].getNombre()&&sNombreVend==colleccionDeObjetos[i].getPropietario()){
                
                return colleccionDeObjetos[i];
            }
        }
        
    }

    bool Catalogo::publicarObjeto(Objetos nObjeto){
        if(iCapacidad<(int)sizeof(colleccionDeObjetos)){
            colleccionDeObjetos[iCapacidad]=Objetos(nObjeto.getNombre(),nObjeto.getPrecio(),nObjeto.getDescripcion(),nObjeto.getPropietario());
            iCapacidad++;
            return true;
        }else{
            for(int i=0; i<(int)sizeof(colleccionDeObjetos);i++){
                if(colleccionDeObjetos[i].getNombre()=="N/A"&&colleccionDeObjetos[i].getPropietario()=="N/A"){
                    colleccionDeObjetos[i]=Objetos(nObjeto.getNombre(),nObjeto.getPrecio(),nObjeto.getDescripcion(),nObjeto.getPropietario());
                    return true;
                }
            }
            return false;
        }
    }
    bool Catalogo::editarObjeto(Objetos nObjeto){
        for(int i=0; i<iCapacidad;i++){
            if(colleccionDeObjetos[i].getPropietario()==nObjeto.getPropietario()){
                colleccionDeObjetos[i]=Objetos(nObjeto.getNombre(),nObjeto.getPrecio(),nObjeto.getDescripcion(),nObjeto.getPropietario());
                return true;
            }
        }
        return false;
    }


#endif