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
#include"sistema.h"
#include"PropInmo.h"
#include "dtPropiedadApto.h"
#include "dtPropiedadCasa.h"

using namespace std;

void menu();
void altaInmobiliaria();
void altaPropiedad();

//PropInmo
int getCantidadMensajes(Usuarios);
void enviarMensaje(Propiedad, Usuarios, string);
void altaPropEnInmob(Propiedad,Usuarios);
void eliminarLinks();
void getAvisos();

void altaPropiedadC(dtPropiedadCasa);




int main(int argc, char** argv) {

    int option = -1;
    
    while(option != 0){
        menu();
        cin>>option;
        switch(option){
            case 1:
                altaInmobiliaria();
                break;
            case 2:
                altaPropiedad();
                
                break;
        }
    }
    
    return 0;
}


void altaPropiedad(){
    sistema* s= new sistema();
    dtDepartamento** listaDep;
    
    dtZonas** listaZona;
    dtEdificio edif;
    string letraDep, codigoZona,ciudad, calle, numero,nEdif;
    int cAmb,cBanios,cDorm;
    float mEdif,mVerdes,valor;
    char opt,garage;
    dtPropiedadCasa * dtPropC;
    dtPropiedadApto * dtPropA;
    dtDireccion* dir;
    bool lgarage,ventAlq;
    
    
    listaDep = s->listaDepartamentos();
    s->seleccionaDepartamento(letraDep);
    listaZona = s->listaZonaDepartamento(letraDep);
    s->seleccionaZona(codigoZona);
    cout<<"Ingresa Una Casa o Un Apto? C / A \n";
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
    cout<<"Indique si  Venta o Alquiler : A/V \n";
    cin>>ventAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
    dtPropC = new dtPropiedadCasa(cAmb,cBanios,cDorm,lgarage,dir,mEdif,mVerdes,valor,ventAlq);
    s->altaPropiedadCasa(*dtPropC);
   
    }else{
        s->listarEdificioZona(codigoZona);
        cout<<"Ingrese Un Edificio: S/N \n";
        cin>>opt;
        if (opt =='S'){
            s->altaEdificio(edif);
            s->listarEdificioZona(codigoZona);
        }
        nEdif = s->seleccionarEdificio();
     
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
    dir = new dtDireccion(ciudad,numero,calle);
    cout<<"Ingrese Metros Cuadrados Edif: \n";
    cin>>mEdif;
    cout<<"Indique si  Venta o Alquiler : A/V \n";
    cin>>ventAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
    dtPropA = new dtPropiedadApto(cAmb,cBanios,cDorm,lgarage,dir,mEdif,nEdif,valor,ventAlq);
    s->altaPropiedadApto(*dtPropA);
    }
}

void altaInmobiliaria(){
    string nombre, ciudad, calle, numero;
    sistema* s= new sistema();
    dtDireccion* dir;
    
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria\n";
    cout<<"Ingrese Nombre: ";
    cin>>nombre;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);
    s->altaInmobiliaria(nombre,dir);
    cout<<"Inmobiliaria dada de Alta ";
    
    
    
}
   
void menu(){
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria"<<endl;
    cout<<"2 - Alta propiedad"<<endl; 
    cout<<"0 - Salir"<<endl;
}