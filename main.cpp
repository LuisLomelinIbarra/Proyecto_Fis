#include <iostream>
#include <fstream>
#include <iterator>
#include "Objetos.h"
#include "Catalogo.h"
#include "CuentaDeUsuario.h"

using namespace std;
Catalogo catalogoDeProductos;
CuentaDeUsuario baseDeUsuarios[100];
int iCantidadUsuarios;
int iMenu=0;


//Metodos para verificar detalles de cuenta
bool verificarCorreo(string sCorreo){
    for(int i=0; i<iCantidadUsuarios;i++){
        string sCompare=baseDeUsuarios[i].getCorreoElectronico();
        if(sCorreo==sCompare){
            return true;
        }
    }
    return false;
}
bool verificarCuenta(string sCorreo,string sContra){
    for(int i=0; i<iCantidadUsuarios;i++){
        if(sCorreo==baseDeUsuarios[i].getCorreoElectronico()&&baseDeUsuarios[i].verificarContrasena(sContra)){
            return true;
        }
    }
    return false;
}

void menuDelSistema(){
    int iChoice;
    do{
        cout <<"\n---------------------\nQue acción Desea realizar:\n1.- Modificar Detalles de la cuenta\n2.- Explorar Catalogo\n3.-Manejar tus productos publicados\n4.-Checar tu lista de deseos\n>>:";
        cin >>iChoice;
        switch(iChoice){
            //Proceso Para manejar la cuenta
            case 1:{

                break;
            }


            //Proceso para explorar el catalogo
            case 2:{

                break;
            }

            //Proceso para manejar los productos publicados
            case 3:{

                break;
            }

            //Proceso para manejar la lista de deseos
            case 4:{

                break;
            }

        }
    }while(iChoice!=6);
}

/*

    INICIO DE FUNCION DEL MAIN

*/
int main(){

    cout <<"\n**Venta en un Click v.0.1\n-------------\n_______________\n";
    //Primero se carga la información de los arcchivos
    ifstream fileIn;
    string readLine;
    
    int count;

    //Cargar la info del catalogo al programa
    fileIn.open("catalogoDeObjetos.txt");
    
    while(!fileIn.eof()){
        count=0;
        string sObjName,sDescr,sCorrVend;
        double dPrecio;
        getline(fileIn,readLine);
        do{
            switch(count){
                case 0:{
                    sObjName=readLine.substr(0,readLine.find(","));
                    break;
                }
                case 1:{
                    dPrecio=stod(readLine.substr(0,readLine.find(",")));
                    break;
                }
                case 2:{
                    sDescr=readLine.substr(0,readLine.find(","));
                    readLine=readLine.substr(readLine.find(",")+1,readLine.size()-(readLine.find(",")+1));
                    sCorrVend=readLine.substr(0,readLine.find(","));
                    break;
                }
            }
            count++;
            if(readLine.find(",")!=string::npos)
            readLine=readLine.substr(readLine.find(",")+1,readLine.size()-(readLine.find(",")+1));
            
            //Provar que se esten cargando el objeto de manera correcta
            //cout<<Objetos(sObjName,dPrecio,sDescr,sCorrVend).toString()<<endl;
            
        }while(readLine.find(",")!=string::npos);
        Objetos nObj=Objetos(sObjName,dPrecio,sDescr,sCorrVend);
        catalogoDeProductos.publicarObjeto(nObj);
            


    }

    fileIn.close();

    //Cargar la info de los usuarios al programa

    fileIn.open("infousuarios.txt");
    iCantidadUsuarios=0;
    while(!fileIn.eof()){
        getline(fileIn,readLine);
        string sUserName,sCorreo,sContra,slistaDeseos,sProductos;
        count =0;
        do{
            switch(count){
                case 0:{
                    sUserName=readLine.substr(0,readLine.find(","));
                    break;
                }
                case 1:{
                    sCorreo=readLine.substr(0,readLine.find(","));
                    break;
                }
                case 2:{
                    sContra=readLine.substr(0,readLine.find(","));
                    break;
                }
                case 3:{
                    //Leer la infomración completa de los objetos de la cuenta
                    slistaDeseos=readLine.substr(0,readLine.find(","));
                    readLine=readLine.substr(readLine.find(",")+1,readLine.size()-(readLine.find(",")+1));
                    sProductos=readLine.substr(0,readLine.find(","));
                    break;
                }
            }
        count++;
        readLine=readLine.substr(readLine.find(",")+1,readLine.size()-(readLine.find(",")+1));
        
        

        }while(readLine.find(",")!=string::npos);
        baseDeUsuarios[iCantidadUsuarios]=CuentaDeUsuario(sUserName,sCorreo,sContra); //Ver que se cree el usuario de manera correcta
        
        string sNombreObj,sCorreoVend;
        bool primero=true;
        if((slistaDeseos!="")||slistaDeseos!=",")
        do{
               
              
                sNombreObj=slistaDeseos.substr(0,slistaDeseos.find("^"));
                sCorreoVend=slistaDeseos.substr(slistaDeseos.find("^")+1,slistaDeseos.size()-(slistaDeseos.find("^")+1));
                baseDeUsuarios[iCantidadUsuarios].agregarProductoAListaDeDeseos(catalogoDeProductos.buscarObjeto(sNombreObj,sCorreoVend));
                if(slistaDeseos.find(";")!=string::npos){
                    slistaDeseos=slistaDeseos.substr(slistaDeseos.find(";")+1,slistaDeseos.size()-(slistaDeseos.find(";")+1));
                    
                }

                if(slistaDeseos.find(";")==string::npos&&!primero){
                    
                    sNombreObj=slistaDeseos.substr(0,slistaDeseos.find("^"));
                    sCorreoVend=slistaDeseos.substr(slistaDeseos.find("^")+1,slistaDeseos.size()-(slistaDeseos.find("^")+1));
                }
                primero=false;
                
        }while(slistaDeseos.find(";")!=string::npos);

        primero=true;
        if(sProductos!=""||sProductos!=",")
        do{
                
                if(sProductos.find(";")!=string::npos){
                sNombreObj=sProductos.substr(0,sProductos.find(";"));
                }else{
                    sNombreObj=sProductos;
                }
                baseDeUsuarios[iCantidadUsuarios].agregarProductoAMiLista(catalogoDeProductos.buscarObjeto(sNombreObj,sCorreo));
                
                if(sProductos.find(";")!=string::npos){
                    sProductos=sProductos.substr(sProductos.find(";")+1,sProductos.size()-(sProductos.find(";")+1));
                }

                if(sProductos.find(";")==string::npos&&!primero){
                         sNombreObj=sProductos;
                         baseDeUsuarios[iCantidadUsuarios].agregarProductoAMiLista(catalogoDeProductos.buscarObjeto(sNombreObj,sCorreo));
                }
                primero=false;
                
        }while(sProductos.find(";")!=string::npos);

        
        
        
        iCantidadUsuarios++;

    }
    fileIn.close();
    //Segundo se valida la cuenta, si se quiere registrar tiene que anotar la cuenta
    do{
        cout <<"\nEscriba el numero de la operación a realizar:\n1.- Ingresar al sistema\n2.- Dar de alta una cuenta\n3.- Salir del sistema\n>>:";
        cin >>iMenu;
        cin.ignore();
        //Ingresar al sistema
        if(iMenu==1){
            string sCorreo,sContra;
            do{
                cout << "\n--------------\nIngrese su correo:\n>>:";
                getline(cin,sCorreo);
                if(!verificarCorreo(sCorreo)){
                    cout << "\n*****La cuenta que ingreso no esta registrada, vuelva a escribir su cuenta*****\n";
                }
            }while(!verificarCorreo(sCorreo));
            do{
                cout << "\n--------------------\nIngrese su contraseña:\n>>:";
                getline(cin,sContra);
                if(!verificarCuenta(sCorreo,sContra)){
                    cout << "\n*****Contraseña incorrecta, vuelva a intentar*****\n";
                }
            }while(!verificarCuenta(sCorreo,sContra));

            menuDelSistema();

        }


        //Registrar una cuenta
        if(iMenu==2){
            string sCorreo,sContra,sNombre;
            cout << "\nEscriba por favor la cuenta e correo a registrar\n>>:";
            getline(cin,sCorreo);
            cout << "\nEscriba la contraseña\n>>:";
            getline(cin,sContra);
            cout << "\nEscriba su nombre completo\n>>:";
            getline(cin,sNombre);
            baseDeUsuarios[iCantidadUsuarios]=CuentaDeUsuario(sNombre,sCorreo,sContra);
            iCantidadUsuarios++;


        }
    }while(iMenu!=3);
    return 0;
}