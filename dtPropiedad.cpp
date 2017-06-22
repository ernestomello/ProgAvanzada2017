/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedad.cpp
 * Author: esteban
 * 
 * Created on 11 de junio de 2017, 07:59 PM
 */

#include "dtPropiedad.h"

dtPropiedad::dtPropiedad(string codigoProp, int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, float mCuadradosTotales) {
    this->codigoProp = codigoProp;
    this->cantAmbiente = cantAmbiente;
    this->cantBanios = cantBanios;
    this->cantDormitorios = cantDormitorios;
    this->garage = garage;
    this->direccionProp = direccionProp;
    this->mCuadradosEdificado = mCuadradosEdificado;
    this->mCuadradosTotales = mCuadradosTotales;
}

dtPropiedad::dtPropiedad() {
}

dtPropiedad::dtPropiedad(const dtPropiedad& orig) {
}

dtPropiedad::~dtPropiedad() {
}

string dtPropiedad::getcodigoProp() const{
    return this->codigoProp;
}

int dtPropiedad::getcantAmbiente() const{
    return this->cantAmbiente;
}

int dtPropiedad::getcantBanios() const{
    return this->cantBanios;
}

int dtPropiedad::getcantDormitorios() const{
    return this->cantDormitorios;
}

dtDireccion* dtPropiedad::getdireccionProp() const{
    return this->direccionProp;
}

float dtPropiedad::getmCuadradosEdificado() const{
    return this->mCuadradosEdificado;
}

float dtPropiedad::getmCuadradoTotales() const{
    return this->mCuadradosTotales;
}