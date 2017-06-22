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
void sistema::seleccionaZona(string codigoZona){
}
void sistema::altaPropiedadCasa (dtPropiedadCasa){

}
dtEdificio** sistema::listarEdificioZona(string codigoZona){
    dtEdificio ** dtE = new dtEdificio*[2](); 
    dtEdificio * edificio1 = new dtEdificio("Edificio1", 1, 1500);
    dtEdificio * edificio2 = new dtEdificio("Edificio2", 1, 1500 );
            dtE[0] = edificio1;
            dtE[1] = edificio2;
            return dtE;
}
void sistema::altaEdificio(dtEdificio edificio){
}
string sistema::seleccionarEdificio(){
    return "se selecciono el Edificio";
}    
void sistema::altaPropiedadApto(dtPropiedadApto){

}
    
