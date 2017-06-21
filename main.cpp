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
#include<fstream>
#include"dtEdificio.h"
#include"dtDepartamento.h"
#include"dtDireccion.h"
#include"dtReporteInmobiliaria.h"
#include"Propiedad.h"
#include"dtPropiedad.h"
//#include"Fabrica.h"
#include"sistema.h"
#include"PropInmo.h"
#include "dtPropiedadApto.h"
#include "dtPropiedadCasa.h"
#include "ICollection.h"
#include "Inmobiliaria.h"
#include "Interesado.h"
#include "ListaDicc.h"
<<<<<<< HEAD

#include"Usuarios.h"
#include "ColGenerica.h"
#include "ListaIterator.h"
#include "Lista.h"
=======
<<<<<<< HEAD
#include "Fabrica.h"
=======
<<<<<<< HEAD
#include"Usuarios.h"
#include "ColGenerica.h"
#include "ListaIterator.h"
=======
>>>>>>> origin/master
>>>>>>> 729c524443422a5bcea25244112d98b827f9c0bc



using namespace std;
//void menu();
void opcionesGenerales(); // MENU GENERAL DE OPCIONES ADMIN/INTER/INMO/CARGAR PRUEBA
void cargaDatosPrueba();
void administradorOpciones();
void inmobiliariaOpciones();
void interesadoOpciones();
void iniciarSesion();

void adminOpciones(int opAdmin);
void inmoOpciones(int opInmo);
void interOpciones(int opInter);

void altaInteresado();
dtReporteInmobiliaria obtenerReporteInmo();
void cerrarSesion(int idSesion);
void modificarPropiedad();
void eliminarPropiedad();

dtPropiedad consultarPropiedad();
void altaEdificio();
void enviarMsjInmobiliaria(string msjInmo);
void enviarMsjInteresado(string msjInter);


//Usuarios
Usuarios * recorrerUsuarios(string, string);

/////////////////////////////////////////
void altaInmobiliaria();
void altaPropiedad();


int idSesion=0;
string us, pwd; // LOS DEFINO COMO VARIABLES GLOBALES PARA MOSTRAR EL USUARIO EN CADA CU

int main(int argc, char** argv) {
    
	int opcion=1;

	while (opcion !=  0){
		opcionesGenerales();
		cin >> opcion;
		switch (opcion){
			case 1 : iniciarSesion();break;
                        case 2 : iniciarSesion();break;
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

void administradorOpciones(){
    int opAdmin=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "\nMENU - USUARIO ADMINISTRADOR" << endl;
    cout << "1 - Alta inmobiliaria" << endl;
    cout << "2 - Alta interesado" << endl;
    cout << "3 - Obtener reporte inmobiliaria" << endl;
    cout << "4 - Cerrar sesion" << endl; 
    cin>>opAdmin;
    adminOpciones(opAdmin);
}

void inmobiliariaOpciones(){
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

void interesadoOpciones(){
    int opInter=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INTERESADO" << endl;
    cout << "1 - Consultar propiedad" << endl;
    cout << "2 - Enviar mensaje interesado" << endl; 
    cout << "3 - Cerrar sesion" << endl; 
    cin>>opInter;
    interOpciones(opInter);
    
}

void iniciarSesion(){
    Usuarios * usu;
    
    string datos = "n";
    cout<<"Desea precargar datos? ";
    cin>>datos;
       
    if (datos=="s"){
        cout<<"precargarDatos();";
    }
    
    cout<<"\nIngrese email: ";
    cin>>us;
    
    cout<<"\nIngrese contrasenia: ";
    cin>>pwd;
    
    // usu = recorrerUsuarios(us, pwd); Recorrer colección de usuarios
    // ESTO ES SOLO PARA PROBAR EL MENU
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\nSeleccione tipo de usuario: ";
    cout<<"\n1 - Administrador"<<endl;
    cout<<"2 - Inmobiliaria"<<endl;
    cout<<"3 - Interesado"<<endl;
        
    int opUsr=1;
        
    while (opUsr !=  0){
                cin >> opUsr;
        switch (opUsr){
                case 1 : administradorOpciones(); break;
                case 2 : inmobiliariaOpciones(); break;
                case 3 : interesadoOpciones(); break;
           }
        }
    
}

void adminOpciones(int opAdmin){
     //int opAdmin=1;    
    while (opAdmin !=  0){
                //cin >> opAdmin;
        switch (opAdmin){
                case 1 : altaInmobiliaria(); break;
                case 2 : altaInteresado(); break;
                case 3 : obtenerReporteInmo(); break;
                case 4 : cerrarSesion(idSesion); break;
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
                case 6 : enviarMsjInmobiliaria(msjInmo); break;
                case 7 : cerrarSesion(idSesion); break;
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
                case 2 : enviarMsjInteresado(msjInter); break;
                case 3 : cerrarSesion(idSesion); break;
           }
        }
}

void cargaDatosPrueba(){
    
}
Usuarios buscarUsr(string email){
    
}

void altaInteresado(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n2 - Alta interesado\n";
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * i = f->getContUsuario();  //EJEMPLO
    // buscarUsr(email);
    string nombre, apellido, email;
    int edad;
    string seguir="s";
    
    //if(buscarUsr(email)!= NULL){
    while(!seguir){
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
        }catch(invalid_argument & e){
            cout<<e.what();
        }
        }
    //}
    cout<<"\nDesea ingresar otro? ";
    cin>>seguir;
        
    
}

dtReporteInmobiliaria obtenerReporteInmo(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n - Obtener Reporte Inmobiliaria";
    
    
   
    
    
}

void cerrarSesion(){
    string opCerrar="n";
    cout<<"Cerrar Sesion";
    
    cout<<"\nDesea cerrar sesion?";
    cin>>opCerrar;
    if (!opCerrar){
        //recorrerSesiones(idSesion); // idSesion es una variable global
        // Destruir todo
    }
}

void modificarPropiedad(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n Modificar Propiedad";
    string codigoProp;
    
    cout<<"\nIngrese codigo propiedad: ";
    cin>>codigoProp;
    // recorrerPropiedades(codigoProp);
    //     
}

void eliminarPropiedad(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Eliminar Propiedad";
}


dtPropiedad consultarPropiedad(){
<<<<<<< HEAD
    sistema *s=new sistema;
    string letra;
    dtDepartamento *depto=new dtDepartamento;
    if( s ==dynamic_cast <s*> Inmobiliaria){
        depto=s->listaDepartamentos();
        cout<<"Seleccione un Departamento: "<<endl;
        cout<<"Clave: "<<" "<<"Nombre Departamento: ";<<endl;
        while (depto) {
            cout<<depto->getletraDepartamento()<<" "<<depto->getnombreDepartamento()<<endl;
            
        }
        cin>>letra;
        dtZonas *zonadepto = new dtZonas;
        zonadepto=s->listaZonaDepartamento(letra);
        system("cls");
        cout<<"Seleccione la Zona: "<<endl;
        cout<<"Clave: "<<" Nombre Zona: "<<endl;
        while(zonadepto){cout<<zonadepto->getCodigoZona()<<" "<<zonadepto->getNombreZona();}
        string codzona;
        cin>>codzona;
        //falta listar prop
    }

    else{if(sistema * s2 ==dynamic_cast <s2*> Interesado){}}
=======
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n - Consultar propiedad";
    
    dtPropiedad *dtprop = new dtPropiedad;
    ColGenerica *col =new ColGenerica;
    if(sistema * s =dynamic_cast <s*> Inmobiliaria){
        col->find()
        
        }}
    else{if(sistema * s2 =dynamic_cast <s2*> Interesado){}}
>>>>>>> 729c524443422a5bcea25244112d98b827f9c0bc
    

    
 
    
}

void altaEdificio(){
 string nombre;
 int pisos;
 float gastosComunes;
 
    
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n - Alta edificio";    
    string nombre;
    int pisos, gastosComunes;
    try {
         if (sistema * s = dynamic_cast <s*> Inmobiliaria){
         cout<<"Ingrese nombre del edificio: "<<endl;
         cin>>nombre;
         ICollection * coso= new ICollection;
         if(coso->member(nombre)!=false){
         cout<<"Ingrese la cantidad de pisos: "<<endl;
         cin<<pisos;
         cout<<"Ingrese el valor de los gastos comunes: "<<endl;}
         else invalid_argument("Nombre repetido");
         cin<<gastosComunes;
         dtEdificio dtedi = new dtEdificio(nombre,pisos,gastosComunes);
         coso->add(dtedi);
    }
    else {invalid_argument("Solo puede el user Inmobiliaria");}
      
    }
    catch(invalid_argument& excepcion){
				cout<<excepcion.what();
			}
}
    
    
