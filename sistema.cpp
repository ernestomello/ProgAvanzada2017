/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sistema.cpp
 * Author: lucia
 * 
 * Created on 6 de mayo de 2017, 05:32 PM
 */
#include "sistema.h"
#include "dtPropiedad.h"
#include "dtPropiedadApto.h"
#include "dtPropiedadCasa.h"
#include "ListaDicc.h"

sistema::sistema() {
}

sistema::sistema(const sistema& orig) {
}

sistema::~sistema() {
}

void sistema::altaInmobiliaria(string nombreInm, dtDireccion* ubicacionInm){
}
    
dtDepartamento** sistema::listaDepartamentos(){
     dtDepartamento ** dtD = new dtDepartamento*[2](); 
    dtDepartamento* dep1 = new dtDepartamento("1","Departamento 1");
    dtDepartamento* dep2 = new dtDepartamento("2","Departamento 2");
            dtD[0] = dep1;
            dtD[1] = dep2;
            return dtD;
}
void sistema::seleccionaDepartamento(string letraDepartamento){
}

dtZonas** sistema::listaZonaDepartamento(string letraDepartamento){
    dtZonas ** dtZ = new dtZonas*[2](); 
    dtZonas* zona1 = new dtZonas("1","zona 1");
    dtZonas* zona2 = new dtZonas("2","zona 2");
            dtZ[0] = zona1;
            dtZ[1] = zona2;
            return dtZ;
}
dtPropiedad ** sistema::listarPropXZona(string codZona){
    dtPropiedad ** dtprop=new dtPropiedad*[2]();
    ListDicc *s=new ListDicc;
    

}
void sistema::seleccionaZona(string codigoZona){
}
void sistema::altaPropiedadCasa (int cantAmbiente, int cantBanios, int cantDormitorios,
        bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, 
        float metrosVerdes, float valor, string alquierOVenta){

}
dtEdificio** sistema::listarEdificioZona(string codigoZona){
    dtEdificio ** dtE = new dtEdificio*[2](); 
    dtEdificio * edificio1 = new dtEdificio("Edificio 1");
    dtEdificio * edificio2 = new dtEdificio("Edificio 2" );
            dtE[0] = edificio1;
            dtE[1] = edificio2;
            return dtE;
}
void sistema::altaEdificio(dtEdificio edificio){
}
string sistema::seleccionarEdificio(){
    return "se selecciono el Edificio";
}    
void sistema::altaPropiedadApto(int cantAmbiente, int cantBanios,int cantDormitorios, 
        bool garage, dtDireccion* direccionProp, float mCuadradosEdificado,
        string nombreEdificio, float valor, string alquierOVenta){

}
    