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
#include "Administrador.h"

using namespace std;

//CASOS DE USO
void iniciarSesion();
void definoMenu(Usuarios*);
void cerrarSesion();
void altaInmobiliaria();
void altaInteresado();
void altaEdificio();
void altaPropiedad();
void consultarPropiedad();
void consultarPropiedadDisponible();
void modificarPropiedad();
void eliminarPropiedad(); 
void enviarMsjInteresado(); // HECHO 90%
void enviarMsjInmobiliaria(); 
dtReporteInmobiliaria obtenerReporteInmo();


// MENU GENERAL DE OPCIONES ADMIN/INTER/INMO/CARGAR PRUEBA
void opcionesGenerales(); 
void cargaDatosPrueba();
void administradorOpciones(string, string);
void inmobiliariaOpciones(string, string);
void interesadoOpciones(string, string);
void adminOpciones( );
void inmoOpciones( );
void interOpciones( );
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
    cout << "0 - Salir" << endl; 
    cout << "1 - Iniciar Sesion" << endl;
   
}


void consultarPropiedadDisponible(){
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
       
    }catch(invalid_argument & e){
            cout<<e.what();
        } 
}




void administradorOpciones(){
    
    system("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "\nMENU - USUARIO ADMINISTRADOR" << endl;
    cout << "0 - Salir" << endl; 
    cout << "1 - Alta inmobiliaria" << endl;
    cout << "2 - Alta interesado" << endl;
    cout << "3 - Obtener reporte inmobiliaria" << endl;
    cout << "4 - Cerrar sesion" << endl; 
    cout << "5 - Cargar Datos Prueba" << endl; 
    
    //adminOpciones(opAdmin);
}

void adminOpciones(){
    int opAdmin = 1;
    while (opAdmin !=  0){
        administradorOpciones();
        cin>>opAdmin;
        switch (opAdmin){
            case 1 : altaInmobiliaria(); break;
            case 2 : altaInteresado(); break;
            case 3 : obtenerReporteInmo(); break;
            case 4 : cerrarSesion(); opAdmin = 0; break;
            case 5 : cargaDatosPrueba();break;
            case 0 : break;
           }
    }
}
void inmobiliariaOpciones(){ 
    //system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INMOBILIARIA" << endl;
    cout << "0 - Salir" << endl; 
    cout << "1 - Alta propiedad" << endl;
    cout << "2 - Modificar propiedad" << endl; 
    cout << "3 - Eliminar propiedad" << endl;
    cout << "4 - Consultar propiedad" << endl; 
    cout << "5 - Alta edificio" << endl;
    cout << "6 - Enviar mensaje inmobiliaria" << endl;
    cout << "7 - Cerrar sesion" << endl;
    
    //inmoOpciones(opInmo); 
}

void inmoOpciones( ){
    int opInmo = 1;
    while (opInmo !=  0){
        inmobiliariaOpciones();
        cin>>opInmo;
        switch (opInmo){
            case 1 : altaPropiedad(); break;
            case 2 : modificarPropiedad(); break;
            case 3 : eliminarPropiedad(); break;
            case 4 : consultarPropiedad(); break;
            case 5 : altaEdificio(); break;
            case 6 : enviarMsjInmobiliaria(); break;
            case 7 : cerrarSesion();opInmo = 0; break;
        }    
    }
}

void interesadoOpciones(){
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INTERESADO" << endl;
    cout << "0 - Salir" << endl; 
    cout << "1 - Consultar propiedad" << endl;
    cout << "2 - Enviar mensaje interesado" << endl; 
    cout << "3 - Cerrar sesion" << endl; 
  
    
    //interOpciones(opInter);
    
}
void interOpciones( ){    
    int opInter=1 ;
    while (opInter !=  0){
        interesadoOpciones();
        cin>>opInter;
        switch (opInter){
                case 1 : consultarPropiedad(); break;
                case 2 : enviarMsjInteresado(); break;
                case 3 : cerrarSesion();opInter= 0; break;
           }
        }
}

//void cargaDatosPrueba(){}

void iniciarSesion(){
   Fabrica* f = Fabrica::getInstance();
   IContUsuario * is = f->getContUsuario();  //EJEMPLO
   try{
        is->altaAdministrador();
          // SOLICITO DATOS - AGREGAR TRY
         cout<<"\nIngrese email: ";
         cin>>us;
         cout<<"\nIngrese contrasenia: ";
         cin>>pwd;
    
        if (is->validarPwd(us,pwd))
            definoMenu(is->altaSesion(us));
    }catch(invalid_argument & e){
            cout<<e.what();
        } 
    
}

void definoMenu(Usuarios*  usu){
    int opUsr=0;
    if(Administrador *a =dynamic_cast<Administrador*>(usu))
        opUsr = a->getTipo();        
    
    if(Usuarios* i = dynamic_cast<Interesado*>(usu))
       opUsr = i->getTipo();
   
    if(Usuarios* in = dynamic_cast<Inmobiliaria*>(usu))    
        opUsr = in->getTipo();
    
        
   
    switch (opUsr){
            case 1 : adminOpciones(); break;
            case 2 : inmoOpciones(); break;
            case 3 : interOpciones(); break;
       }
    
    }


void altaInmobiliaria (){
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * in = f->getContUsuario();  //EJEMPLO
    string nombre, ciudad, calle, numero, email,contra;
    dtDireccion* dir;
    
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria\n";
    cout<<"Ingrese Nombre: ";
    cin>>nombre;
    
    cout<<"Ingrese Email: ";
    cin>>email;
    cout<<"Ingrese Contrasena: ";
    cin>>contra;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);

   // in->altaInmobiliaria(nombre,dir);
    //taInmobiliaria(nombre, dir)

    in->altaInmobiliaria(nombre, dir, email,contra);
    cout<<"Inmobiliaria dada de Alta\n ";
    cin.ignore(256,'\n');
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
    
    
    // PARTE DE SELECCIONAR EDIFICIO
    string nombreEd;
    int pisos;
    float gastosComunes;
    string opEd = "s";
    string nomEd;
        
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
        ICollection* colDtEdif= NULL;
        
        
       colDtEdif = i->listaEdificiosDisp();
       IIterator *dt =colDtEdif->iterator();
    cout<<"Edificios Disponibles\n";
    
    while(dt->hasNext()){
        dtEdificio *dtE=dynamic_cast<dtEdificio*>(dt->getCurrent());
        cout<<dtE->getnombreEdificio()<<"-"<<dtE->getCantPisosEdificio()<<dtE->getGastosComunesEdificio()<<"\n";
        dt->next();        
    }
    cout<<"Elegir Letra Edificio\n";
    cin>>nomEd;
    i->seleccionarEdificio(nomEd);
       
    cout<<"\n Desea dar de alta el edificio?";
    cin>>opEd;
    if(opEd == "s")
        i->altaEdificio(nombreEd, pisos, gastosComunes);
        
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
    string nombre, apellido, email,contra;
    int edad;
    string seguir="s";

    while(seguir=="s"){
        try{
            cout<<"Ingrese nombre: ";
            cin>>nombre;
            cout<<"Ingrese apellido: ";
            cin>>apellido;
            cout<<"Ingrese edad: ";
            cin>>edad;
            cout<<"Ingrese email: ";
            cin>>email;
            cout<<"Ingrese Contrasena: ";
            cin>>contra;
            i->altaInteresado(nombre, apellido, edad, email,contra);
            cout<<"Usuario inmobiliaria creado correctamente ";
        }catch(invalid_argument & e){
            cout<<e.what();
        }
        cout<<"\nDesea ingresar otro? ";
        cin>>seguir;
    }

   
}

 dtReporteInmobiliaria obtenerReporteInmo(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n - Obtener Reporte Inmobiliaria";
    
}
//
void cerrarSesion(){
    char opCerrar='n';
    cout<<"Cerrar Sesion\n";    
    cout<<"\nDesea cerrar sesion?\n";
    cin>>opCerrar;
    if (opCerrar == 's'){
        Fabrica* f = Fabrica::getInstance();
        IContUsuario * i = f->getContUsuario();  //EJEMPLO
        i->CerrarSesion();
    }
}

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

void consultarPropiedad(){
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

//////////////////////CARGAR DATOS YA SABES////////////////////////////////////////

//usuarios
void cargarUsuInmo(){
    Fabrica * f = Fabrica::getInstance();
    IContUsuario* itUInmo = f->getContUsuario();
    string email, pwd, nombre, ciudad, calle, numero;
    dtDireccion* dirInmo;
    
    email = "inm1@sis.com";
    pwd = "pass4";
    nombre = "Selmo";
    ciudad = "Paysandu";
    calle = "Benitez";
    numero = "1134";
    dirInmo = new dtDireccion(ciudad, calle, numero);
    itUInmo->altaInmobiliaria(nombre, dirInmo, email, pwd);
    
    email = "inm2@sis.com";
    pwd = "pass5";
    nombre = "Garcia";
    ciudad = "Paysandu";
    calle = "Rivera";
    numero = "1340";
    dirInmo = new dtDireccion(ciudad, calle, numero);
    itUInmo->altaInmobiliaria(nombre, dirInmo, email, pwd);
   
    email = "inm3@sis.com";
    pwd = "pass6";
    nombre = "Invernissi";
    ciudad = "Salto";
    calle = "Comercio";
    numero = "234";
    dirInmo = new dtDireccion(ciudad, calle, numero);
    itUInmo->altaInmobiliaria(nombre, dirInmo, email, pwd);
    
    email = "inm4@sis.com";
    pwd = "pass7";
    nombre = "Solei";
    ciudad = "Montevideo";
    calle = "Inca";
    numero = "3456";
    dirInmo = new dtDireccion(ciudad, calle, numero);
    itUInmo->altaInmobiliaria(nombre, dirInmo, email, pwd);
    
}

void cargarUsuInteresado(){
    Fabrica * f = Fabrica::getInstance();
    IContUsuario* itUInmo = f->getContUsuario();
    string email, pwd, nombreInt, apellidoInt, ciudad, calle, numero;
    int edadInt;
    
    email = "int1@sis.com";
    pwd = "passt1";
    nombreInt = "Julio";
    apellidoInt = "Chaz";
    edadInt = 34;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email, pwd);
    
    email = "int2@sis.com";
    pwd = "passt2";
    nombreInt = "Andrea";
    apellidoInt = "Berruti";
    edadInt = 56;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email, pwd);
    
    email = "int3@sis.com";
    pwd = "passt3";
    nombreInt = "Sonia";
    apellidoInt = "Braga";
    edadInt = 45;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email, pwd);
    
    email = "int4@sis.com";
    pwd = "passt4";
    nombreInt = "Alfonso";
    apellidoInt = "Mier";
    edadInt = 30;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email, pwd);
    
    email = "int5@sis.com";
    pwd = "passt5";
    nombreInt = "Juan";
    apellidoInt = "Alpi";
    edadInt = 60;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email, pwd);
    
}

void cargarEdificios(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itE = f->getContProp();
    string nombreEdificio;
    int cantPisos;
    float gastosComunes;
    
    nombreEdificio = "Apache Valiente";
    cantPisos = 4;
    gastosComunes = 1234;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
    nombreEdificio = "Mebeo";
    cantPisos = 20;
    gastosComunes = 3452;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
    nombreEdificio = "Socrates";
    cantPisos = 34;
    gastosComunes = 456;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
    nombreEdificio = "El Burdel";
    cantPisos = 12;
    gastosComunes = 800;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
    nombreEdificio = "Milajo";
    cantPisos = 5;
    gastosComunes = 900;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
}

void cargarPropAptos(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itPA = f->getContProp();
    dtPropiedadApto* PropApto;
    int cantAmbiente, cantDormitorios, cantBanios;
    bool garage, ventAlq;
    dtDireccion* direccionProp;
    float mCuadradosEdificado, mCuadradosTotales, valor;
    string nombreEdificio, codigoProp, ciudad, calle, numero, nombreInmo, nombreZona;
    
    //////////           Apartamento 1
    
    codigoProp = "1111";
    cantAmbiente = 2;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Montevideo";
    calle = "Iturria";
    numero = "1115";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 34;
    mCuadradosTotales = 34;
    nombreEdificio = "Apache Valiente";
    nombreInmo = "Selmo";
    ventAlq = true;
    valor = 34567;
    nombreZona = "Zona1";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    //////////////       Apartamento 2
    
    codigoProp = "1112";
    cantAmbiente = 3;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Montevideo";
    calle = "Iturria";
    numero = "1115";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 35;
    mCuadradosTotales = 35;
    nombreEdificio = "Apache Valiente";
    nombreInmo = "Selmo";
    ventAlq = true;
    valor = 65789;
    nombreZona = "Zona1";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    ////////////         Apartamento 3
    
    codigoProp = "1113";
    cantAmbiente = 2;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = true;
    ciudad = "Rivera";
    calle = "CALLEJON";
    numero = "456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 45;
    mCuadradosTotales = 45;
    nombreEdificio = "Mebeo";
    nombreInmo = "Garcia";
    ventAlq = false;
    valor = 7689;
    nombreZona = "Zona2";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    ////////////////     Apartamento 4
    
    codigoProp = "1113";
    cantAmbiente = 7;
    cantDormitorios = 3;
    cantBanios = 2;
    garage = true;
    ciudad = "Rivera";
    calle = "CORCEGA ";
    numero = "3456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 34;
    mCuadradosTotales = 34;
    nombreEdificio = "Socrates";
    nombreInmo = "Garcia";
    ventAlq = false;
    valor = 6789;
    nombreZona = "Zona3";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    /////////////         Apartamento 5
    
    codigoProp = "1115";
    cantAmbiente = 4;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Artigas";
    calle = "LUCRECIA";
    numero = "456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 25;
    mCuadradosTotales = 25;
    nombreEdificio = "El Burdel";
    nombreInmo = "Invernissi";
    ventAlq = false;
    valor = 7890;
    nombreZona = "Zona4";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    //////////////////      Apartamento 6
    
    codigoProp = "1116";
    cantAmbiente = 2;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Artigas";
    calle = "LUCRECIA";
    numero = "456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 17;
    mCuadradosTotales = 17;
    nombreEdificio = "El Burdel";
    nombreInmo = "Solei";
    ventAlq = false;
    valor = 768;
    nombreZona = "Zona4";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
}

void cargarPropCasa(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itPC = f->getContProp();
    dtPropiedadCasa* PropCasa;
    string ciudad, calle, numero, nombreZona, nombreInmo, codigoProp;
    int cantAmbiente, cantDormitorios, cantBanios;
    bool garage, ventaAlq;
    dtDireccion* direccionProp;
    float mCuadradosEdificado, valor, metrosVerdes, mCuadradosTotales;
    
    ///////////     Casa 1
    
    codigoProp = "2111";
    cantAmbiente = 12;
    cantDormitorios = 5;
    cantBanios = 1;
    garage = true;
    ciudad = "Mdeo";
    calle = "Chana";
    numero = "2345";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 34;
    mCuadradosTotales = 44;
    metrosVerdes = 10;
    nombreInmo = "Selmo";
    ventaAlq = true;
    valor = 45000;
    nombreZona = "Zona5";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
    ///////////     Casa 2
    
    codigoProp = "2112";
    cantAmbiente = 2;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Paysandu";
    calle = "Gloria";
    numero = "345";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 35;
    mCuadradosTotales = 55;
    metrosVerdes = 20;
    nombreInmo = "Selmo";
    ventaAlq = true;
    valor = 34560;
    nombreZona = "Zona1";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
    ///////////     Casa 3
    
    codigoProp = "2113";
    cantAmbiente = 3;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Salto";
    calle = "CHAPAZ";
    numero = "345";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 12;
    mCuadradosTotales = 22;
    metrosVerdes = 10;
    nombreInmo = "Garcia";
    ventaAlq = true;
    valor = 13000;
    nombreZona = "Zona1";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
    ///////////     Casa 4
    
    codigoProp = "2114";
    cantAmbiente = 6;
    cantDormitorios = 3;
    cantBanios = 2;
    garage = true;
    ciudad = "Canelones";
    calle = "JUANICO";
    numero = "456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 34;
    mCuadradosTotales = 34;
    metrosVerdes = 0;
    nombreInmo = "Invernissi";
    ventaAlq = false;
    valor = 20000;
    nombreZona = "Zona2";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
    ///////////     Casa 5
    
    codigoProp = "2115";
    cantAmbiente = 3;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Fray Bentos";
    calle = "VENECIA";
    numero = "3456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 25;
    mCuadradosTotales = 25;
    metrosVerdes = 0;
    nombreInmo = "Solei";
    ventaAlq = false;
    valor = 56789;
    nombreZona = "Zona1";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
}

void cargarZonas(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itZ = f->getContProp();
    string nombreZ,codigoZ,Departamento;
    
    nombreZ="Zona1";
    codigoZ="101";
    Departamento="A";
    itZ->altaZona(nombreZ,codigoZ,Departamento);
    nombreZ="Zona2";
    codigoZ="101";
    Departamento="A";
    itZ->altaZona(nombreZ,codigoZ,Departamento);
    nombreZ="Zona3";
    codigoZ="101";
    Departamento="B";
   itZ->altaZona(nombreZ,codigoZ,Departamento);
    nombreZ="Zona4";
    codigoZ="101";
    Departamento="D";
    itZ->altaZona(nombreZ,codigoZ,Departamento);
    nombreZ="Zona5";
    codigoZ="101";
    Departamento="V";
    itZ->altaZona(nombreZ,codigoZ,Departamento);
     
}

void cargarDeptos(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itD = f->getContProp();
    string letraDepto, nombreDepto;
    dtDepartamento* depto;
   
    letraDepto = "A";
    nombreDepto = "Canelones";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
//    letraDepto = "A";
//    nombreDepto = "Canelones";
//    depto = new dtDepartamento(letraDepto, nombreDepto);
//    itD->altaDepto(depto);
   
    letraDepto = "B";
    nombreDepto = "Maldonado";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
    letraDepto = "C";
    nombreDepto = "Rocha";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
    letraDepto = "D";
    nombreDepto = "Salto";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
    letraDepto = "E";
    nombreDepto = "Montevideo";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
}

void cargarMensajes(){
    Fabrica * f = Fabrica::getInstance();
    IContUsuario* m = f->getContUsuario();
    string usuario, mensaje, inmobiliaria,propiedad;
    usuario="T1";
    mensaje="Estoy Interesado";
    inmobiliaria="I1";
    propiedad="C1";
    dtFecha *fecha =new dtFecha(25,5,2016);
    dtHora *hora=new dtHora(13,02);
    m->altamensaje(usuario, mensaje, fecha, hora, inmobiliaria, propiedad);
    usuario="T2";

    mensaje="Cuanto cuesta?";
    inmobiliaria="I3";
    propiedad="C4";
    dtFecha *fecha0 =new dtFecha();
    dtHora *hora0=new dtHora(12,30);
    m->altamensaje(usuario, mensaje, fecha0, hora0, inmobiliaria, propiedad);
    
    usuario="T3";
    mensaje="PERDON ME EQUIVOQUE";
    inmobiliaria="I1";
    propiedad="C1";
    
    dtFecha *fecha1 =new dtFecha(23,5,2016);
    dtHora *hora1=new dtHora(12,35);
    m->altamensaje(usuario, mensaje, fecha1, hora1, inmobiliaria, propiedad);
    
    usuario="T4";
    mensaje="Quiero hacer una oferta ya!";
    inmobiliaria="I2";
    propiedad="AP1";
    dtFecha *fecha2 =new dtFecha(1,6,2016);
    dtHora *hora2=new dtHora(0,30);
    m->altamensaje(usuario, mensaje, fecha2, hora2, inmobiliaria, propiedad);
    
    usuario="T1";
    mensaje="Tiene humedad?";
    inmobiliaria="I4";
    propiedad="AP2";
    dtFecha *fecha3 =new dtFecha(2,6,2016);
    dtHora *hora3=new dtHora(12,45);
    m->altamensaje(usuario, mensaje, fecha3, hora3, inmobiliaria, propiedad);
    
    usuario="T5";
    mensaje="Cual es el precio?";
    inmobiliaria="I1";
    propiedad="AP3";
    dtFecha *fecha4 =new dtFecha(3,6,2016);
    dtHora *hora4=new dtHora(2,5);
    m->altamensaje(usuario, mensaje, fecha4, hora4, inmobiliaria, propiedad);
    
    
}

void cargaDatosPrueba(){
    cout << "CUCargarDatos()" << endl;
//    Fabrica * f = Fabrica::getInstance();
//    IContProp * itp = f->getContProp();	
    // Par\E1metros 
	
    //cargarUsuAdmin();
    cargarUsuInmo();
    cargarUsuInteresado();
    cargarEdificios();   
    cargarDeptos();   
    cargarZonas();
    
    cargarPropAptos();
    cargarPropCasa();
    cargarMensajes();
}

