/* 
 * File:   main.cpp
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 04:34 PM
 */

#include<cstdlib>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<typeinfo>
#include<iostream>
#include <stdexcept>
#include"dtEdificio.h"
#include"dtDepartamento.h"
#include"dtDireccion.h"
#include"dtReporteInmobiliaria.h"
#include"dtPropiedadApto.h"
#include"dtPropiedadCasa.h"
#include"dtPropiedad.h"
#include"Fabrica.h"
#include"PropInmo.h"
#include"Propiedad.h"
#include"ICollection.h"
#include"Inmobiliaria.h"
#include"Interesado.h"
#include"ListDicc.h"
#include"Usuarios.h"
#include"ListaIterator.h"
#include"ContProp.h"

using namespace std;

//CASOS DE USO
void iniciarSesion();
void cerrarSesion();
void altaInmobiliaria();
void altaInteresado();
void altaEdificio();
void altaPropiedad();
dtPropiedad consultarPropiedad();
Lista * consultarPropiedadDisponible();
void modificarPropiedad();
void eliminarPropiedad();
void enviarMsjInteresado();
void enviarMsjInmobiliaria();
dtReporteInmobiliaria obtenerReporteInmo();


// MENU GENERAL DE OPCIONES ADMIN/INTER/INMO/CARGAR PRUEBA
void opcionesGenerales(); 
void cargaDatosPrueba();
int administradorOpciones(string, string);
int inmobiliariaOpciones(string, string);
int interesadoOpciones(string, string);
void adminOpciones(int opAdmin);
void inmoOpciones(int opInmo);
void interOpciones(int opInter);
//Usuarios
Usuarios * recorrerUsuarios(string, string);

/////////////////////////////////////////

int idSesion=0;
string us, pwd; // LOS DEFINO COMO VARIABLES GLOBALES PARA MOSTRAR EL USUARIO EN CADA CU

int main(int argc, char** argv) {
    
	int opcion=1;

	while (opcion !=  0){
		opcionesGenerales();
		cin >> opcion;
		switch (opcion){
			case 1 : iniciarSesion();break;
                        case 0 : break;
                }
                
	}
	
    return 0;
}

///////////////////// NUEVO /////////////////////

void opcionesGenerales(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<endl<<endl;
    cout << "1 - Iniciar Sesion" << endl;
    cout << "0 - Salir" << endl; 
}

int administradorOpciones(string us, string pwd){
    Usuarios *usu;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isAdmin = f->getContUsuario();  //EJEMPLO
    int opAdmin=0;
    
    try{
        if(isAdmin->validarPwd(pwd)==true){
            isAdmin->iniciarSesion(us, pwd);
            cout<<"Sesion iniciada correctamente ";
            invalid_argument("Contrasena incorrecta");
        }
    }catch(invalid_argument & e){
        cout<<e.what();
        } 
    
    system("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "\nMENU - USUARIO ADMINISTRADOR" << endl;
    cout << "1 - Alta inmobiliaria" << endl;
    cout << "2 - Alta interesado" << endl;
    cout << "3 - Obtener reporte inmobiliaria" << endl;
    cout << "4 - Cerrar sesion" << endl; 
    cin>>opAdmin;
    adminOpciones(opAdmin);

}
Lista consultarPropiedadDisponible(){
     string letraDpto, codigoZona,codigoProp;
    //Departamento *depto;
     
    
    cout << "Caso Uso Consultar Propiedad Interesado\n";
    
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    ICollection* colDtDep= NULL;
   
    try{
    colDtDep = i->listaDepartamentos();
    
    IIterator *dt =colDtDep->iterator();
    cout<<"Departamentos Disponibles\n";
    
    while(dt->hasNext()){
        dtDepartamento *dtD=dynamic_cast<dtDepartamento*>(dt->getCurrent());
        cout<<dtD->getletraDepartamento()<<"-"<<dtD->getnombreDepartamento()<<"\n";
        dt->next();        
    }
    cout<<"Elegir Letra Departamento\n";
    cin>>letraDpto;
    i->seleccionarDepartamentos(letraDpto);
    ICollection* colDtZona= NULL;
    colDtZona= i->listaZonasDepartamentos();
    IIterator *dtZ =colDtZona->iterator();
    cout<<"Zonas Disponibles\n";
    while(dtZ->hasNext()){
        dtZonas *dtZona=dynamic_cast<dtZonas*>(dtZ->getCurrent());
        cout<<dtZona->getCodigoZona()<<"-"<<dtZona->getNombreZona()<<"\n";
        dtZ->next();        
    }
    
    cout<<"Elegir Código Zona\n";
    cin>>codigoZona;
    i->seleccionaZona(codigoZona);

    ICollection* colDtPropDispo=NULL;
    colDtPropDispo=i->listaPropiedadesDisponibles();
    IIterator *dtprop=colDtPropDispo->iterator();
    
    while (dtprop->hasNext()) {
        dtPropiedadDisponible* dtpro=dynamic_cast<dtPropiedadDisponible*>(dtprop->getCurrent());
        cout<<dtpro->getCodigoProp()<<"-"<<dtpro->getAlquilerOVenta();
        dtprop->next();

        }
    cout<<"Elegir Código Propiedad\n";
    cin>>codigoProp;
    i->seleccionaPropiedadDisponible(codigoProp);
       
    }
  

<<<<<<< HEAD
}
void inmobiliariaOpciones(string us, string pwd){
=======
int inmobiliariaOpciones(string us, string pwd){
>>>>>>> fe34853a63c88723e46550e1d1017a7e36ef272d
    string op="s";
    string confPwd;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isInmo = f->getContUsuario();  //EJEMPLO
    
    cout<<"\n Inicia sesion por primera vez?";
    while(op=="s"){ 
        try{
            cin>>op;
            cout<<"Ingrese contraseña";
            cin>>pwd;
            cout<<"Confirmar contraseña";
            cin>>confPwd;
            if(isInmo->verificarContrasena(pwd, confPwd)==true){
                isInmo->activarUsuario(pwd, us);
                isInmo->iniciarSesion(us, pwd);
                cout<<"Sesion iniciada correctamente ";
                invalid_argument("COSO");
        }
        }catch(invalid_argument & e){
            cout<<e.what();
        } 
    }
    isInmo->validarPwd(pwd);
    isInmo->iniciarSesion(us, pwd);
    cout<<"Sesion iniciada correctamente ";
    
    int opInmo=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INMOBILIARIA" << endl;
    cout << "1 - Alta propiedad" << endl;
    cout << "2 - Modificar propiedad" << endl; 
    cout << "3 - Eliminar propiedad" << endl;
    cout << "4 - Consultar propiedad" << endl; 
    cout << "5 - Alta edificio" << endl;
    cout << "6 - Enviar mensaje inmobiliaria" << endl;
    cout << "7 - Cerrar sesion" << endl;
    cin>>opInmo;
    inmoOpciones(opInmo); 
}

int interesadoOpciones(string us, string pwd){
    string op="s";
    string confPwd;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isInter = f->getContUsuario();  //EJEMPLO
    
    cout<<"\n Inicia sesion por primera vez?";
    while(op=="s"){ 
        try{
            cin>>op;
            cout<<"Ingrese contraseña";
            cin>>pwd;
            cout<<"Confirmar contraseña";
            cin>>confPwd;
            if(isInter->verificarContrasena(pwd, confPwd)==true){
                isInter->activarUsuario(pwd, confPwd);
                isInter->iniciarSesion(us, pwd);
                cout<<"Sesion iniciada correctamente ";
                invalid_argument("Las contraseñas no coinciden");
        }
        }catch(invalid_argument & e){
            cout<<e.what();
        } 
    }
    isInter->validarPwd(pwd);
    isInter->iniciarSesion(us, pwd);
    cout<<"Sesion iniciada correctamente ";
    
    int opInter=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INTERESADO" << endl;
    cout << "1 - Consultar propiedad" << endl;
    cout << "2 - Enviar mensaje interesado" << endl; 
    cout << "3 - Cerrar sesion" << endl; 
    cin>>opInter;
    //interOpciones(opInter);
    interOpciones(opInter);
    
}

void adminOpciones(int opAdmin){
    while (opAdmin !=  0){
        switch (opAdmin){
                case 1 : altaInmobiliaria(); break;
                case 2 : altaInteresado(); break;
                case 3 : obtenerReporteInmo(); break;
                case 4 : cerrarSesion(); break;
           }
        }
}

void inmoOpciones(int opInmo){
    
     //int opInmo=1;
     dtPropiedad propiedad;
     string prop;
     string nombre;
     int pisos;
     int gastosComunes;
     string msjInmo;
        
    while (opInmo !=  0){
                //cin >> opInmo;
        switch (opInmo){
                case 1 : altaPropiedad(); break;
                case 2 : modificarPropiedad(); break;
                case 3 : eliminarPropiedad(); break;
                case 4 : consultarPropiedad(); break;
                case 5 : altaEdificio(); break;
                case 6 : enviarMsjInmobiliaria(); break;
                case 7 : cerrarSesion(); break;
           }
        }
}

void interOpciones(int opInter){
    
    // int opInter=1;
     string propiedad;
     string msjInter;
        
    while (opInter !=  0){
                //cin >> opAdmin;
        switch (opInter){
                case 1 : consultarPropiedad(); break;
                case 2 : enviarMsjInteresado(); break;
                case 3 : cerrarSesion(); break;
           }
        }
}

void cargaDatosPrueba(){}

void iniciarSesion(){
//    Fabrica* f = Fabrica::getInstance();
//    IContUsuario * is = f->getContUsuario();  //EJEMPLO
    
    Usuarios * usuTipo;
    string usuario;
    int opUsr=1;
    string datos = "n";
    // PRECARGA DE DATOS
    
    cout<<"Desea precargar datos? ";
    cin>>datos;
       
    if (datos=="s"){
        cout<<"precargarDatos();";
    }
    
    // SOLICITO DATOS - AGREGAR TRY
    cout<<"\nIngrese email: ";
    cin>>us;
    cout<<"\nIngrese contrasenia: ";
    cin>>pwd;
    
    usuario = usuTipo->getTipo();
    
    if( usuario == "Administrador"){
        opUsr == 1;
    }
    if(usuario == "Interesado"){
        opUsr == 2;
    }
    if(usuario == "Inmobiliaria"){
        opUsr == 3;
    }
    
   /* system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\nSeleccione tipo de usuario: ";
    cout<<"\n1 - Administrador"<<endl;
    cout<<"2 - Inmobiliaria"<<endl;
    cout<<"3 - Interesado"<<endl;*/
        
    while (opUsr !=  0){
                cin >> opUsr;
        switch (opUsr){
                case 1 : administradorOpciones(us,pwd); break;
                case 2 : inmobiliariaOpciones(us,pwd); break;
                case 3 : interesadoOpciones(us,pwd); break;
           }
        }
    
}

void altaInmobiliaria (){
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * in = f->getContUsuario();  //EJEMPLO
    string nombre, ciudad, calle, numero, email;
   // sistema* s= new sistema();
    dtDireccion* dir;
    
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria\n";
    cout<<"Ingrese Nombre: ";
    cin>>nombre;
    cout<<"Ingrese Email: ";
    cin>>email;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);

   // in->altaInmobiliaria(nombre,dir);
    //taInmobiliaria(nombre, dir)

    in->altaInmobiliaria(nombre, dir, email);
    cout<<"Inmobiliaria dada de Alta ";
}

void altaPropiedad(){
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();  //EJEMPLO
    Departamento* depto;
    Lista * listaDep;
    Lista* listaZona;
    
    dtEdificio edif;
    string letraDep, codigoZona,ciudad, calle, numero,nEdif, VoA;
    int cAmb,cBanios,cDorm;
    float mEdif,mVerdes,valor;
    char opt,garage;
    dtPropiedadCasa * dtPropC;
    dtPropiedadApto * dtPropA;
    dtDireccion* dir;
    bool lgarage,ventAlq;
        
//    listaDep = i->listaDepartamentos();
    cout<<"Ingrese la letra del Departamento: ";
    cin>>letraDep;
    i->seleccionarDepartamentos(letraDep);
    listaZona = i->listaZonasDepartamentos();
    cout<<"Seleccione la Zona: ";
    i->seleccionaZona(codigoZona);
    cout<<"\n Ingresa Una Casa o Un Apto? C / A \n";
    cin>>opt;
    if (opt == 'C'){
    cout<<"\nDatos Casa\n";
    cout<<"Ingrese Cantidad Ambientes: \n";
    cin>>cAmb;
    cout<<"Ingrese Cantidad Baños: \n";
    cin>>cBanios;
    cout<<"Ingrese Cantidad Dormitorios: \n";
    cin>>cDorm;
    cout<<"Tiene Garage : S/N \n";
    cin>>garage; 
    if(garage =='S')
        lgarage = true;
    else
        lgarage = false;
    
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);
    cout<<"Ingrese Metros Cuadrados Edif: \n";
    cin>>mEdif;
    cout<<"Ingrese Metros Verdes: \n";
    cin>>mVerdes;
    cout<<"Indique si  Venta o Alquiler : V/A \n";
    cin>> VoA;
    if (VoA == "A"||VoA=="a"){
    ventAlq = true;
    cout<<"Ingrese Valor del Alquiler \n";
    cin>>valor; 
    }else{
    ventAlq = false;
    cout<<"Ingrese Valor de Venta \n";
    cin>>valor;
    }
    dtPropC = new dtPropiedadCasa(cAmb,cBanios,cDorm,lgarage,dir,mEdif,mVerdes,valor,ventAlq);
    i->altaPropiedadCasa(dtPropC);
   
    }else{
    cout<<"\nDatos Apartamentos\n";
    cout<<"Ingrese Cantidad Ambientes: \n";
    cin>>cAmb;
    cout<<"Ingrese Cantidad Baños: \n";
    cin>>cBanios;
    cout<<"Ingrese Cantidad Dormitorios: \n";
    cin>>cDorm;
    cout<<"Tiene Garage : S/N \n";
    cin>>garage; 
    if(garage =='S')
        lgarage = true;
    else
        lgarage = false;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,calle,numero);
    cout<<"Ingrese Metros Cuadrados Edif: \n";
    cin>>mEdif;
    cout<<"Indique si  Venta o Alquiler : A/V \n";
    cin>>ventAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
    dtPropA = new dtPropiedadApto(cAmb,cBanios,cDorm,lgarage,dir,mEdif,nEdif,valor,ventAlq);
    i->altaPropiedadApto(dtPropA);
    }
}

void enviarMsjInmobiliaria(){}

void enviarMsjInteresado(){
    string letraDpto, codigoZona,codigoProp;
    //Departamento *depto;    
    cout << "Caso Uso Enviar Mensaje Interesado\n";
    
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    ICollection* colDtDep= NULL;
    try{
    colDtDep = i->listaDepartamentos();
    
    IIterator *dt =colDtDep->iterator();
    cout<<"Departamentos Disponibles\n";
    
    while(dt->hasNext()){
        dtDepartamento *dtD=dynamic_cast<dtDepartamento*>(dt->getCurrent());
        cout<<dtD->getletraDepartamento()<<"-"<<dtD->getnombreDepartamento()<<"\n";
        dt->next();        
    }
    
    cout<<"Elegir Letra Departamento\n";
    cin>>letraDpto;
    i->seleccionarDepartamentos(letraDpto);
    
     ICollection* colDtZona= NULL;
    colDtZona= i->listaZonasDepartamentos();
    
    
    IIterator *dtZ =colDtZona->iterator();
    cout<<"Zonas Disponibles\n";
    
    while(dtZ->hasNext()){
        dtZonas *dtZona=dynamic_cast<dtZonas*>(dtZ->getCurrent());
        cout<<dtZona->getCodigoZona()<<"-"<<dtZona->getNombreZona()<<"\n";
        dtZ->next();        
    }
    
    cout<<"Elegir Código Zona\n";
    cin>>codigoZona;
    i->seleccionaZona(codigoZona);
    
    
    ICollection* colDtPropMensaje= NULL;
    colDtPropMensaje = i->listaPropiedades();
    
    cout<<"Propiedades y Mensajes\n";
    IIterator *dtPM = colDtPropMensaje->iterator();
    while(dtPM->hasNext()){
        dtPropiedadMensaje *dtPMens=dynamic_cast<dtPropiedadMensaje*>(dtPM->getCurrent());
        cout<<dtPMens->getcodigoProp()<<"-"<<dtPMens->getdireccionProp()<<"-"<<dtPMens->getCantMensajesEnviados()<<"\n";
        dtPM->next();        
    }
    
    cout<<"Elegir Código Propiedad\n";
    cin>>codigoProp;
    
    ICollection* colDtMensajes = NULL;
    colDtMensajes = i->seleccionaPropiedad(codigoProp);
    
    
    }catch(invalid_argument & e){
	cout << e.what();
    }
}
//
void altaInteresado(){

    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n2 - Alta interesado\n";
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * i = f->getContUsuario();  //EJEMPLO
    // buscarUsr(email);
    string nombre, apellido, email;
    int edad;
    string seguir="s";

    while(seguir!="s"){
        try{
            cout<<"Ingrese nombre: ";
            cin>>nombre;
            cout<<"Ingrese apellido: ";
            cin>>apellido;
            cout<<"Ingrese edad: ";
            cin>>edad;
            cout<<"Ingrese email: ";
            cin>>email;              
            i->altaInteresado(nombre, apellido, edad, email);
            cout<<"Usuario inmobiliaria creado correctamente ";
            invalid_argument("COSO");
        }catch(invalid_argument & e){
            cout<<e.what();
        }
    }

    cout<<"\nDesea ingresar otro? ";
    cin>>seguir;
}

 dtReporteInmobiliaria obtenerReporteInmo(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n - Obtener Reporte Inmobiliaria";
    
}
//
void cerrarSesion(){}
//    string opCerrar="n";
//    cout<<"Cerrar Sesion";
//    
//    cout<<"\nDesea cerrar sesion?";
//    cin>>opCerrar;
//    if (opCerrar){
//        //recorrerSesiones(idSesion); // idSesion es una variable global
//        // Destruir todo
//    }
//}
void modificarPropiedad(){}
//    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
//    cout<<"\n Modificar Propiedad";
//    string codigoProp;
//    
//    cout<<"\nIngrese codigo propiedad: ";
//    cin>>codigoProp;
//    // recorrerPropiedades(codigoProp);
//    //     
//}
//
void eliminarPropiedad(){
    cout<<endl<< "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Eliminar Propiedad";
    string codigo;
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    
    cout<<endl<<"Ingrese el codigo de la propiedad que desee eliminar: ";
    cin>>codigo;
    //dtProp = new dtPropiedad(codigoProp);
            
    i->eliminarProp(codigo);
    
}

Lista* consultarPropiedad(){
    Fabrica *f = Fabrica::getInstance();
    IContProp *i=f->getContProp();
    i->listaPropiedadesDisponibles();
}

void altaEdificio(){
    string nombre;
    int pisos;
    float gastosComunes;
    Fabrica* f = Fabrica::getInstance();
    IContProp *i=f->getContProp();
         cout<<"Ingrese nombre del edificio: "<<endl;
         cin>>nombre;
         cout<<"Ingrese la cantidad de pisos: "<<endl;
         cin>>pisos;
         cout<<"Ingrese el valor de los gastos comunes: "<<endl;
         cin>>gastosComunes;
      //   dtEdificio *dtedi = new dtEdificio(nombre,pisos,gastosComunes);
       i->altaEdificio(nombre,pisos,gastosComunes);
       
      cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
}

