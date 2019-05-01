#ifndef CuentaDeUsuario_h
#define CuentaDeUsuario_h
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include "Objetos.h"
using namespace std;

class CuentaDeUsuario{
    private:
    string sNombreDeUsuario;
    string sCorreoElectronico;
    string sContrasena;
    Objetos MisProductosEnVenta[100];
    Objetos ListaDeDeseos[100];
    int iCapacidadmisProductos,iCapacidadListaDeDeseos;

    public:
    //Constructores
    CuentaDeUsuario();
    CuentaDeUsuario(string,string,string);
    //Metodos Accesores y Modificadores
    string getNombreDeUsuario();
    string getCorreoElectronico();
    void setNombreDeUsuario(string);
    void setCorreoElectronico(string);

    //Funciones
    bool verificarContrasena(string);
    bool modificarContrasena(string,string);

    void agregarProductoAListaDeDeseos(Objetos);
    void removerProductoDeListaDeDeseos(string,string);
    void contactarVendedor(Objetos);

    void modificarProductoDeMiLista(Objetos,string);
    void agregarProductoAMiLista(Objetos); 
    void removerProductoDeMiLista(string);

    string toString();




};

//Constructores
    CuentaDeUsuario::CuentaDeUsuario(){
        sNombreDeUsuario="N/A";
        sCorreoElectronico="N/A";
        sContrasena="N/A";
        iCapacidadmisProductos=0;
        iCapacidadListaDeDeseos=0;
    }
    CuentaDeUsuario::CuentaDeUsuario(string nNombre,string nCorreo,string nContra){
        sNombreDeUsuario=nNombre;
        sCorreoElectronico=nCorreo;
        sContrasena=nContra;
        iCapacidadmisProductos=0;
        iCapacidadListaDeDeseos=0;
    }
    //Metodos Accesores y Modificadores
    string CuentaDeUsuario::getNombreDeUsuario(){
        return sNombreDeUsuario;
    }
    string CuentaDeUsuario::getCorreoElectronico(){
        return sCorreoElectronico;
    }
    void CuentaDeUsuario::setNombreDeUsuario(string nNombre){
        sNombreDeUsuario=nNombre;
    }
    void CuentaDeUsuario::setCorreoElectronico(string nCorreo){
        sCorreoElectronico=nCorreo;
    }

    //Funciones
    bool CuentaDeUsuario::verificarContrasena(string sIntento){
        if(sIntento==sContrasena){
            return true;
        }else{
            return false;
        }
    }
    bool CuentaDeUsuario::modificarContrasena(string sContrasenaVieja,string nContrasena){
        if(sContrasenaVieja==sContrasena){
            sContrasena=nContrasena;
            return true;
        }else{
            return false;
        }
    }

    void CuentaDeUsuario::agregarProductoAListaDeDeseos(Objetos nObjeto){
        if(iCapacidadListaDeDeseos<(int)sizeof(ListaDeDeseos)){
            ListaDeDeseos[iCapacidadListaDeDeseos]=Objetos(nObjeto.getNombre(),nObjeto.getPrecio(),nObjeto.getDescripcion(),nObjeto.getPropietario());
            iCapacidadListaDeDeseos++;
        }else{
            for(int i=0;i<(int)sizeof(ListaDeDeseos);i++){
                if(ListaDeDeseos[i].getNombre()=="N/A"&&ListaDeDeseos[i].getPropietario()=="N/A"){
                    ListaDeDeseos[i]=Objetos(nObjeto.getNombre(),nObjeto.getPrecio(),nObjeto.getDescripcion(),nObjeto.getPropietario());
                    i+=(int)sizeof(ListaDeDeseos);
                }
            }
        }
    }
    void CuentaDeUsuario::removerProductoDeListaDeDeseos(string sCorreoDelVendedor,string sNombreObjeto){
        for(int i=0;i<iCapacidadListaDeDeseos;i++){
            if(sCorreoDelVendedor==ListaDeDeseos[i].getPropietario()&&sNombreObjeto==ListaDeDeseos[i].getNombre()){
                ListaDeDeseos[i]=Objetos();
            }
        }
    }
    void CuentaDeUsuario::contactarVendedor(Objetos oObjeto){
        ofstream messageQue;
        messageQue.open("contactarProvedor.txt",ios::app);
        messageQue << "\nContactar de parte de: "<< sNombreDeUsuario<< " , "<< sCorreoElectronico<< "; a: "<< oObjeto.getPropietario();
        messageQue.close();
    }

    void CuentaDeUsuario::modificarProductoDeMiLista(Objetos oObjetoModificado,string sNombreDelObjetoAModificar){
        for(int i=0; i<iCapacidadmisProductos;i++){
            if(MisProductosEnVenta[i].getNombre()==sNombreDelObjetoAModificar){
                MisProductosEnVenta[i].setNombre(oObjetoModificado.getNombre());
                MisProductosEnVenta[i].setDescripcion(oObjetoModificado.getDescripcion());
                MisProductosEnVenta[i].setPrecio(oObjetoModificado.getPrecio());
            }
        }

    }
    void CuentaDeUsuario::agregarProductoAMiLista(Objetos nObjeto){
        if(iCapacidadmisProductos<(int)sizeof(MisProductosEnVenta)){
            
            MisProductosEnVenta[iCapacidadmisProductos]=Objetos(nObjeto.getNombre(),nObjeto.getPrecio(),nObjeto.getDescripcion(),sCorreoElectronico);
            
            iCapacidadmisProductos++;
        }else{
            for(int i=0;i<(int)sizeof(MisProductosEnVenta);i++){
                if(MisProductosEnVenta[i].getNombre()=="N/A"&&MisProductosEnVenta[i].getPropietario()=="N/A"){
                    MisProductosEnVenta[i]=Objetos(nObjeto.getNombre(),nObjeto.getPrecio(),nObjeto.getDescripcion(),sCorreoElectronico);
                    
                    i+=(int)sizeof(MisProductosEnVenta);
                }
            }
        }
    } 
    void CuentaDeUsuario::removerProductoDeMiLista(string sNombreDelProducto){
            for(int i=0;i<iCapacidadmisProductos;i++){
            if(sNombreDelProducto==MisProductosEnVenta[i].getNombre()){
                MisProductosEnVenta[i]=Objetos();
            }
        }
    }

    string CuentaDeUsuario::toString(){
        
        string cuentaString=sNombreDeUsuario+","+sCorreoElectronico+","+sContrasena+",";
        
        for(int i=0;i<iCapacidadListaDeDeseos;i++){
            string temp=ListaDeDeseos[i].getNombre();
            
            cuentaString+=temp;
            temp=ListaDeDeseos[i].getPropietario();
            cuentaString+="^";
            cuentaString+=temp;
            cout << cuentaString;
            if(iCapacidadListaDeDeseos>i+1){
                cuentaString+=";";
            }
            
        }
        
        cuentaString+=",";
        for(int i=0;i<iCapacidadmisProductos;i++){
            cuentaString+=MisProductosEnVenta[i].getNombre();
            if(iCapacidadmisProductos>i+1){
                cuentaString+=";";
            }
        }

        return cuentaString;
    }



#endif