/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtEdificio.cpp
 * Author: lucia
 * 
 * Created on 6 de mayo de 2017, 06:40 PM
 */



#include "dtEdificio.h"
using namespace std;

dtEdificio::dtEdificio() {
}

dtEdificio::dtEdificio(const dtEdificio & orig) {
}
dtEdificio::dtEdificio (string nombreEdificio, int picantPisosEdificiosos, float gastosComunesEdificio){
    this->nombreEdificio = nombreEdificio;
    this->cantPisosEdificio = picantPisosEdificiosos;
    this->gastosComunesEdificio = gastosComunesEdificio;
}
dtEdificio::~dtEdificio() {
}

string dtEdificio::getnombreEdificio() const {
    return this->nombreEdificio;
}

void dtEdificio::setGastosComunesEdificio(float gastosComunesEdificio) {
}

void dtEdificio::setCantPisosEdificio(int cantPisosEdificio) {
    this->cantPisosEdificio = cantPisosEdificio;
}

int dtEdificio::getCantPisosEdificio() const {
    return cantPisosEdificio;
}

void dtEdificio::setNombreEdificio(string nombreEdificio) {
    this->nombreEdificio = nombreEdificio;
}

string dtEdificio::getNombreEdificio() const {
    return nombreEdificio;
}


