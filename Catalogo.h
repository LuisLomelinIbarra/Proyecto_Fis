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
    void buscarObjeto(string,Objetos[],int& );
    Objetos buscarObjeto(string,string);
    Objetos buscarObjeto(int);
    bool publicarObjeto(Objetos);
    bool editarObjeto(Objetos,string);
    bool quitarObjeto(string,string);
    int getCapacidad();

};

    Catalogo::Catalogo(){
        iCapacidad=0;
    }
    void Catalogo::buscarObjeto(string sNombreObjeto,Objetos arr[],int &cant){
        cant=0;
        for(int i=0; i<iCapacidad;i++){
            if(sNombreObjeto==colleccionDeObjetos[i].getNombre()){
                arr[cant]=colleccionDeObjetos[i];
                cant++;
            }
        }
        if(cant==0)
        cant=-1;
        
    }
    Objetos Catalogo::buscarObjeto(string sNombreObjeto,string sNombreVend){
        for(int i=0; i<iCapacidad;i++){
           
            if(sNombreObjeto==colleccionDeObjetos[i].getNombre()&&sNombreVend==colleccionDeObjetos[i].getPropietario()){
                
                return colleccionDeObjetos[i];
            }
        }
        return Objetos();
        
    }
    Objetos Catalogo::buscarObjeto(int indice){
        return colleccionDeObjetos[indice];
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
    bool Catalogo::editarObjeto(Objetos nObjeto,string nombreProd){
        for(int i=0; i<iCapacidad;i++){
            if(colleccionDeObjetos[i].getPropietario()==nObjeto.getPropietario()&&colleccionDeObjetos[i].getNombre()==nombreProd){
                colleccionDeObjetos[i]=Objetos(nObjeto.getNombre(),nObjeto.getPrecio(),nObjeto.getDescripcion(),nObjeto.getPropietario());
                return true;
            }
        }
        return false;
    }
    bool Catalogo::quitarObjeto(string correoVend,string nombreProd){
        for(int i=0; i<iCapacidad;i++){
            if(colleccionDeObjetos[i].getPropietario()==correoVend&&colleccionDeObjetos[i].getNombre()==nombreProd){
                colleccionDeObjetos[i]=Objetos();
                return true;
            }
        }
        return false;
    }
    int Catalogo::getCapacidad(){
        return iCapacidad;
    }


#endif