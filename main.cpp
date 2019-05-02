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

//Metodos para encontrar elementos dentro de un arreglo

int encontrarCuenta(string sCorreo,string sContra){
    for(int i=0; i<iCantidadUsuarios;i++){
        if(sCorreo==baseDeUsuarios[i].getCorreoElectronico()&&baseDeUsuarios[i].verificarContrasena(sContra)){
            return i;
        }
    }
    return -1;
}
 
 //Método Para Guardar la información
 void guardarCambios(){
     ofstream fileOut;
     fileOut.open("catalogoDeObjetos.txt");
     int x=catalogoDeProductos.getCapacidad();
     for(int i=0;i<x;i++){
         fileOut << catalogoDeProductos.buscarObjeto(i).toString();
         if(i+1<x){
             fileOut<< endl;
         }
     }
     fileOut.close();
     fileOut.open("infousuarios.txt");
     for(int i=0;i<iCantidadUsuarios;i++){
         fileOut << baseDeUsuarios[i].toString();
         if(i+1<iCantidadUsuarios){
             fileOut<< endl;
         }
     }

 }
 

/*

    Menu Que Se Utiliza una Vez que Ya se Ha ingresado al sistema

*/

void menuDelSistema(CuentaDeUsuario &user){
    int iChoice;
    int iChoice2;
    do{
        cout <<"\n---------------------\nQue acción Desea realizar:\n1.- Modificar Detalles de la cuenta\n2.- Explorar Catalogo\n3.- Manejar tus productos publicados\n4.- Checar tu lista de deseos\n5.- Cerrar sesion\n>>:";
        cin >>iChoice;
        cin.ignore();
        switch(iChoice){
            //Proceso Para manejar la cuenta
            case 1:{
                
                cout << "\n---------\nQue propiedad quiere cambiar: \n1.- Cambiar Nombre\n2.- Cambiar correo\n3.- Cambiar contraseña\n4.- Numero Telefónico\n5.- Imprimir en Pantalla los datos de la cuenta\n6.- Regresar\n>>:";
                cin >> iChoice2;
                cin.ignore();
                switch(iChoice2){
                    case 1:{
                        cout << "\nEscriba el nuevo nombre de la cuenta\n>>: ";
                        string nuevoNombre;
                        getline(cin,nuevoNombre);
                        
                        string pwsd;
                        cout << "\nEscriba la contraseña de la cuenta para asegurar el cambio\n>>:";
                        getline(cin,pwsd);
                        
                        if(user.verificarContrasena(pwsd)){
                            user.setNombreDeUsuario(nuevoNombre);
                            cout << "\n+++La Operación ha sido exitosamente realizada+++\n";
                        }else{
                            cout << "\n***Contraseña Equivocada, operacion terminada***\n";
                        }

                        cin.ignore();

                        break;
                    }
                    case 2:{
                        cout << "\nEscriba el nuevo correo de la cuenta\n>>: ";
                        string nuevoCorreo;
                        getline(cin,nuevoCorreo);
                        
                        string pwsd;
                        cout << "\nEscriba la contraseña de la cuenta para asegurar el cambio\n>>:";
                        getline(cin,pwsd);
                       
                        if(user.verificarContrasena(pwsd)){
                            user.setNombreDeUsuario(nuevoCorreo);
                            cout << "\n+++La Operación ha sido exitosamente realizada+++\n";
                        }else{
                            cout << "\n***Contraseña Equivocada, operacion terminada***\n";
                        }

                        cin.ignore();
                        break;
                    }
                    case 3:{
                        cout << "\nEscriba la nueva contraseña de la cuenta\n>>: ";
                        string nuevaContra;
                        getline(cin,nuevaContra);
                        cin.ignore();
                        string pwsd;
                        cout << "\nEscriba la contraseña de la cuenta para asegurar el cambio\n>>:";
                        getline(cin,pwsd);
                        cin.ignore();
                        if(user.verificarContrasena(pwsd)){
                            user.setNombreDeUsuario(nuevaContra);
                            cout << "\n+++La Operación ha sido exitosamente realizada+++\n";
                        }else{
                            cout << "\n***Contraseña Equivocada, operacion terminada***\n";
                        }

                        cin.ignore();
                        break;
                    }

                    case 4:{
                        cout << "\nEscriba el nuevo telefono de la cuenta\n>>: ";
                        string nuevoTel;
                        getline(cin,nuevoTel);
                        cin.ignore();
                        string pwsd;
                        cout << "\nEscriba la contraseña de la cuenta para asegurar el cambio\n>>:";
                        getline(cin,pwsd);
                        cin.ignore();
                        if(user.verificarContrasena(pwsd)){
                            user.setNombreDeUsuario(nuevoTel);
                            cout << "\n+++La Operación ha sido exitosamente realizada+++\n";
                        }else{
                            cout << "\n***Contraseña Equivocada, operacion terminada***\n";
                        }

                        cin.ignore();

                        break;
                    }

                    case 5:{
                        user.imprimirEnPantalla();
                        break;
                    }
                    default:{
                        break;
                    }
                }
                guardarCambios();
                break;
            }


            //Proceso para explorar el catalogo
            case 2:{
                cout << "\n---------\nQue accion quiziera hacer con el catalogo:\n1.- Explorar los productos en el catalogo\n2.- Buscar en el catalogo\n3.- Regresar \n>>:";
                cin >> iChoice2;
                cin.ignore();
                switch(iChoice2){
                    case 1:{
                        int cant=catalogoDeProductos.getCapacidad();
                        if(cant>0){
                            int pageNum=cant/5;
                                if(pageNum==0){
                                    pageNum++;
                                }
                                int currentPage=1;
                                char cChoice;
                                int indx=0;
                                do{
                                    
                                    cout << "\n(NOTA): Para selecionar más informacion de un producto utilize la letra señalada. Para manejar las otras opciones de este menu utilize los numeros \n";
                                    cout << "\t"<<" Pagina "<<currentPage<<" / "<<pageNum;
                                    indx=((currentPage-1)*5);
                                    for(int z=0;z<5;z++){
                                        if((z+(currentPage-1)*5<cant)){
                                            cout << endl<<(char)((int)'A'+z)<<") Nombre: "<<catalogoDeProductos.buscarObjeto(indx+z).getNombre()<<" , Precio: "<<catalogoDeProductos.buscarObjeto(indx+z).getPrecio();
                                        }
                                    }
                                    cout << "\n1.- Siguiente pagina\n2.- Pagina Anterior\n3.- Regresar\n>>:";
                                    cin>> cChoice;
                                    switch (cChoice)
                                    {
                                        case 'A':
                                        case 'B':
                                        case 'C':
                                        case 'D':
                                        case 'E':
                                        case 'a':
                                        case 'b':
                                        case 'c':
                                        case 'd':
                                        case 'e':
                                        if(cChoice>='a'&&cChoice<='e'){
                                            cChoice-='a';
                                            cChoice+='A';
                                        }
                                        catalogoDeProductos.buscarObjeto(indx+((int)(cChoice-'A'))).imprimirEnPantalla();
                                        int iChoice3;
                                        cout << "\n1) Agregar a la lista\n2) Contactar Proveedor\n3)Regresar\n>>:";
                                        cin >> iChoice3;
                                        switch(iChoice3){
                                            case 1:{
                                                user.agregarProductoAListaDeDeseos(catalogoDeProductos.buscarObjeto(indx+((int)(cChoice-'A'))));
                                                break;
                                            }
                                            case 2:{
                                                user.contactarVendedor(catalogoDeProductos.buscarObjeto(indx+((int)(cChoice-'A'))));
                                                break;
                                            }
                                            default:break;
                                        }
                                            break;
                                    
                                        case '1':{
                                            if(currentPage+1<=pageNum){
                                                currentPage++;
                                            }
                                            break;
                                        }
                                        case '2':{
                                            if(currentPage-1>0){
                                                currentPage--;
                                            }
                                            break;
                                        }
                                        default:
                                        iChoice2=3;
                                        break;
                                    }
                                    
                                }while(cChoice!='3');
                                
                                
                                
                        }
                        break;
                    }

                    //Funcion para buscar con un nombre en el catálogo
                    case 2:{
                        string nombreProd;
                        cout << "\nEscriba el nombre del producto a buscar al catalogo\n>>: ";
                        getline(cin,nombreProd);
                        
                        Objetos objetosEncontrar[100];
                        int cant=0;
                        catalogoDeProductos.buscarObjeto(nombreProd,objetosEncontrar,cant);
                       
                        cin.ignore();
                        if(cant>0){
                            int pageNum=cant/5;
                                if(pageNum==0){
                                    pageNum++;
                                }
                                int currentPage=1;
                                char cChoice;
                                int indx=0;
                                do{
                                    
                                    cout << "\n(NOTA): Para selecionar más informacion de un producto utilize la letra señalada. Para manejar las otras opciones de este menu utilize los numeros \n";
                                    cout << "\t"<<" Pagina "<<currentPage<<" / "<<pageNum;
                                    indx=((currentPage-1)*5);
                                    for(int z=0;z<5;z++){
                                        if((z+(currentPage-1)*5<cant)){
                                            cout << endl<<(char)((int)'A'+z)<<") Nombre: "<<objetosEncontrar[indx+z].getNombre()<<" , Precio: "<<objetosEncontrar[indx+z].getPrecio();
                                        }
                                    }
                                    cout << "\n1.- Siguiente pagina\n2.- Pagina Anterior\n3.- Regresar\n>>:";
                                    cin>> cChoice;
                                    switch (cChoice)
                                    {
                                        case 'A':
                                        case 'B':
                                        case 'C':
                                        case 'D':
                                        case 'E':
                                        case 'a':
                                        case 'b':
                                        case 'c':
                                        case 'd':
                                        case 'e':
                                        objetosEncontrar[indx+((int)(cChoice-'A'))].imprimirEnPantalla();
                                        int iChoice3;
                                        cout << "\n1) Agregar a la lista\n2) Contactar Proveedor\n3)Regresar\n>>:";
                                        cin >> iChoice3;
                                        switch(iChoice3){
                                            case 1:{
                                                user.agregarProductoAListaDeDeseos(objetosEncontrar[indx+((int)(cChoice-'A'))]);
                                                break;
                                            }
                                            case 2:{
                                                user.contactarVendedor(objetosEncontrar[indx+((int)(cChoice-'A'))]);
                                                break;
                                            }
                                            default:break;
                                        }
                                            break;
                                    
                                        case '1':{
                                            if(currentPage+1<=pageNum){
                                                currentPage++;
                                            }
                                            break;
                                        }
                                        case '2':{
                                            if(currentPage-1>0){
                                                currentPage--;
                                            }
                                            break;
                                        }
                                        default:
                                        iChoice2=3;
                                        break;
                                    }
                                    
                                }while(cChoice!='3');
                                
                                
                                
                        }else{
                        
                            cout << "\n***El producto que busco no fue encontrado***\n";
                        }
                        break;
                        break;
                    }
                    case 3:{
                        
                        break;
                    }
                
                }
                guardarCambios();
                break;
            }

            //Proceso para manejar los productos publicados
            case 3:{
                cout << "\n---------\nQue desea hacer con sus productos:\n1.- Agregar un producto\n2.- Modificar un producto\n3.- Quitar un productos de la lista\n4.-Desplegar la información de un producto dado su nombre\n5.-Desplegar la lista de todos los productos\n6.-Regresar\n>>:";
                cin >> iChoice2;
                cin.ignore();
                switch(iChoice2){
                    case 1:{
                        string sNombreObj,sDesc;
                        double precio;
                        cout << "\nEscriba el nombre del objeto:\n>>:";
                        getline(cin,sNombreObj);
                        //cin.ignore();
                        cout << "\nEscriba el precio del producto\n>>:";
                        cin >> precio;
                        cin.ignore();
                        cin.ignore();
                        cout << "\nEscriba la descripción del producto\n>>:";
                        getline(cin,sDesc);
                        cin.ignore();

                        Objetos nuevoProd(sNombreObj,precio,sDesc,user.getCorreoElectronico());
                        user.agregarProductoAMiLista(nuevoProd);
                        catalogoDeProductos.publicarObjeto(nuevoProd);
                        cout <<"\n El producto fue agregado exitosamente\n";

                        break;
                    }
                    case 2:{
                        string nombreProd;
                        cout << "\nEscriba el nombre del producto a modificar\n>>: ";
                        getline(cin,nombreProd);
                        cin.ignore();
                        Objetos nuevoObj=user.encontrarObjeto(nombreProd,user.getCorreoElectronico(),1);
                        if(nuevoObj.getNombre()!="N/A"&&nuevoObj.getPropietario()!="N/A"){
                            string sNombreObj,sDesc;
                            double precio;
                            cout << "\nEscriba el nombre del objeto:\n>>:";
                            getline(cin,sNombreObj);
                            cin.ignore();
                            cout << "\nEscriba el precio del producto\n>>:";
                            cin >> precio;
                            cin.ignore();
                            cout << "\nEscriba la descripción del producto\n>>:";
                            getline(cin,sDesc);
                            cin.ignore();  
                            nuevoObj=Objetos(sNombreObj,precio,sDesc,user.getCorreoElectronico());
                            user.modificarProductoDeMiLista(nuevoObj,nombreProd);  
                            catalogoDeProductos.editarObjeto(nuevoObj,nombreProd); 
                            cout << "\nEl producto fue editado exitosamente\n";
                        }else{
                            cout << "\n***El producto que busco no fue encontrado***\n";
                        }

                        break;
                    }
                    case 3:{
                        string nombreProd;
                        cout << "\nEscriba el nombre del producto a quitar de la lista\n>>: ";
                        getline(cin,nombreProd);
                        cin.ignore();
                        Objetos nuevoObj=user.encontrarObjeto(nombreProd,user.getCorreoElectronico(),1);
                        if(nuevoObj.getNombre()!="N/A"&&nuevoObj.getPropietario()!="N/A"){
                            user.removerProductoDeMiLista(nuevoObj.getNombre());
                            catalogoDeProductos.quitarObjeto(user.getCorreoElectronico(),nombreProd);
                            cout << "\nEl Producto fur quitado de la lista exitosamente \n ";
                        }else{
                            cout << "\n***El producto que busco no fue encontrado***\n";
                        }
                        

                        break;
                    }
                    case 4:{
                        string nombreProd;
                        cout << "\nEscriba el nombre del producto a desplegar\n>>: ";
                        getline(cin,nombreProd);
                        cin.ignore();
                        Objetos nuevoObj=user.encontrarObjeto(nombreProd,user.getCorreoElectronico(),1);
                        if(nuevoObj.getNombre()!="N/A"&&nuevoObj.getPropietario()!="N/A"){
                            nuevoObj.imprimirEnPantalla();
                        }else{
                            cout << "\n***El producto que busco no fue encontrado***\n";
                        }
                        break;
                    }

                    case 5:{
                        cout << "\nMis Productos:\n";
                        user.desplegarMisProductos();
                        break;
                    }
                
                }
                guardarCambios();
                break;
            }

            //Proceso para manejar la lista de deseos
            case 4:{
                cout << "\n---------\nQue desea hacer con sus lista de deseos:\n1.- Agregar un producto a la lista\n2.- Mostrar un elemento de la lista en especifico\n3.- Mostrar toda mi lista\n4.- Quitar un producto de la lista\n5.- Contactar al proveedor\n>>:";
                cin >> iChoice2;
                cin.ignore();
                
                switch(iChoice2){
                    //Agregar Elemento
                    case 1:{
                        string nombreObj,correoProv;
                        cout << "\nEscriba el nombre del producto a agregar\n>>:";
                        getline(cin,nombreObj);
                        cin.ignore();
                        cout << "\nEscriba el correo del proveerdor del producto a agregar\n>>:";
                        getline(cin,correoProv);
                        cin.ignore();
                        Objetos nuevoObj=catalogoDeProductos.buscarObjeto(nombreObj,correoProv);
                        if(nuevoObj.getNombre()!="N/A"&&nuevoObj.getPropietario()!="N/A"){
                            user.agregarProductoAListaDeDeseos(nuevoObj);
                            cout << "\nEl producto ha sido exitosmente agregado a su lista de deseos\n";
                        }else{
                            cout << "\n***El producto que busco no fue encontrado***\n";
                        }

                        break;
                    }
                    //Mostrar un elemento
                    case 2:{
                        string nombreObj,correoProv;
                        cout << "\nEscriba el nombre del producto a buscar en su lista\n>>:";
                        getline(cin,nombreObj);
                        cin.ignore();
                        cout << "\nEscriba el correo del proveerdor del producto a busca en su lista\n>>:";
                        getline(cin,correoProv);
                        cin.ignore();
                        Objetos nuevoObj=user.encontrarObjeto(nombreObj,correoProv,0);
                        if(nuevoObj.getNombre()!="N/A"&&nuevoObj.getPropietario()!="N/A"){
                            nuevoObj.imprimirEnPantalla();
                        }else{
                            cout << "\n***El producto que busco no fue encontrado***\n";
                        }
                        
                        break;
                    }
                    //Mostrar todos los elementos
                    case 3:{
                        cout << "\nMi Lista de Deseos:\n";
                        user.desplegarMiListaDeDeseos();
                        break;
                    }
                    //Quitar elemnto de la lista
                    case 4:{
                        string nombreObj,correoProv;
                        cout << "\nEscriba el nombre del producto a quitar de su lista\n>>:";
                        getline(cin,nombreObj);
                        
                        cout << "\nEscriba el correo del proveerdor del producto a quitar de su lista\n>>:";
                        getline(cin,correoProv);
                        
                        if(user.removerProductoDeListaDeDeseos(correoProv,nombreObj)){
                            cout<< "\nEl Producto Fue Exitosamente removido de su lista de deseos\n";
                        }else{
                            cout << "\n***El producto que busco no fue encontrado***\n";
                        }
                        cin.ignore();
                        break;
                    }
                    //Contactar al provedor
                    case 5:{
                         string nombreObj,correoProv;
                        cout << "\nEscriba el nombre del producto a comprar\n>>:";
                        getline(cin,nombreObj);
                        cin.ignore();
                        cout << "\nEscriba el correo del proveerdor del producto a comprar\n>>:";
                        getline(cin,correoProv);
                        cin.ignore();
                        Objetos objAComprar=catalogoDeProductos.buscarObjeto(nombreObj,correoProv);
                        if(objAComprar.getNombre()!="N/A"&&objAComprar.getPropietario()!="N/A"){
                            user.contactarVendedor(objAComprar);
                            cout << "\nSe ha mandado un mensaje al proveedor\n";
                        }else{
                            cout << "\n***El producto que busco no fue encontrado***\n";
                        }
                        break;
                    }                
                }
                guardarCambios();
                break;
            }

        }
        guardarCambios();
        cin.ignore();
    }while(iChoice!=5);
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
        string sUserName,sCorreo,sContra,slistaDeseos,sProductos,sNumTel;
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
                    sNumTel=readLine.substr(0,readLine.find(","));
                    break;
                }
                case 4:{
                    //Leer la infomración completa de los objetos de la cuenta
                    slistaDeseos=readLine.substr(0,readLine.find(","));
                    readLine=readLine.substr(readLine.find(",")+1,readLine.size()-(readLine.find(",")+1));
                    sProductos=readLine.substr(0,readLine.size());
                    break;
                }
            }
        count++;
        readLine=readLine.substr(readLine.find(",")+1,readLine.size()-(readLine.find(",")+1));
        
        

        }while(readLine.find(",")!=string::npos);
        baseDeUsuarios[iCantidadUsuarios]=CuentaDeUsuario(sUserName,sCorreo,sContra,sNumTel); //Ver que se cree el usuario de manera correcta
        
        string sNombreObj,sCorreoVend;
        bool primero=true;
        //if((slistaDeseos!="")||slistaDeseos!=",")
        do{
               
              
               
                
                if(slistaDeseos.find(";")!=string::npos){
                    
                     sNombreObj=slistaDeseos.substr(0,slistaDeseos.find("^"));
                     
                     sCorreoVend=slistaDeseos.substr(slistaDeseos.find("^")+1,(slistaDeseos.find(";")-1)-slistaDeseos.find("^"));
                    slistaDeseos=slistaDeseos.substr(slistaDeseos.find(";")+1,slistaDeseos.size()-(slistaDeseos.find(";")+1));
                    cout << sNombreObj<< " "<<sCorreoVend;
                    catalogoDeProductos.buscarObjeto(sNombreObj,sCorreoVend).imprimirEnPantalla();
                    baseDeUsuarios[iCantidadUsuarios].agregarProductoAListaDeDeseos(catalogoDeProductos.buscarObjeto(sNombreObj,sCorreoVend));
                    
                }

                if(slistaDeseos.find(";")==string::npos){
                    
                    sNombreObj=slistaDeseos.substr(0,slistaDeseos.find("^"));
                    sCorreoVend=slistaDeseos.substr(slistaDeseos.find("^")+1,slistaDeseos.size()-(slistaDeseos.find("^")+1));
                    baseDeUsuarios[iCantidadUsuarios].agregarProductoAListaDeDeseos(catalogoDeProductos.buscarObjeto(sNombreObj,sCorreoVend));
                }
                
                
        }while(slistaDeseos.find(";")!=string::npos);

        primero=true;
        //if(sProductos!=""||sProductos!=",")
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
            int indxUser=encontrarCuenta(sCorreo,sContra);
            menuDelSistema(baseDeUsuarios[indxUser]);

        }


        //Registrar una cuenta
        if(iMenu==2){
            string sCorreo,sContra,sNombre,sNumTel;
            cout << "\nEscriba por favor la cuenta e correo a registrar\n>>:";
            getline(cin,sCorreo);
            cout << "\nEscriba la contraseña\n>>:";
            getline(cin,sContra);
            cout << "\nEscriba su nombre completo\n>>:";
            getline(cin,sNombre);
            cout << "\nEscriba su numero telefonico\n>>:";
            getline(cin,sNumTel);
            /*
            
            
            ------------------------***********************************_-------------------
            Se puede agregar que identifique espaico vacios
            
            */

            if(iCantidadUsuarios<(int)sizeof(baseDeUsuarios)){
                baseDeUsuarios[iCantidadUsuarios]=CuentaDeUsuario(sNombre,sCorreo,sContra,sNumTel);
                iCantidadUsuarios++;
            }
            guardarCambios();


        }
    }while(iMenu!=3);
    return 0;
}