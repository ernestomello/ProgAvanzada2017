/* 
 * File:   dtPropiedadCasa.cpp
 * Author: Esteban
 *
 * Created on 9 de junio de 2017, 05:06 PM
 */
#include "dtPropiedadCasa.h"

dtPropiedadCasa::dtPropiedadCasa(int cantAmbiente, int cantBanios, int cantDormitorios,
        bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, float metrosVerdes,
        float valor, bool ventAlq){
    this->cantAmbiente = cantAmbiente;
    this->cantBanios = cantBanios;
    this->cantDormitorios = cantDormitorios;
    this->direccionProp = direccionProp;
    this->garage = garage;
    this->mCuadradosEdificado = mCuadradosEdificado;
    this->metrosVerdes = metrosVerdes;
    this->valor = valor;
    this->ventAlq = ventAlq;
}

dtPropiedadCasa::dtPropiedadCasa(){
}

dtPropiedadCasa::dtPropiedadCasa(const dtPropiedadCasa& orig){
}

dtPropiedadCasa::~dtPropiedadCasa(){
}

int dtPropiedadCasa::getcantAmbiente() const{
    return this->cantAmbiente;
}

int dtPropiedadCasa::getcantBanios() const{
    return this->cantBanios;
}

int dtPropiedadCasa::getcantDormitorios() const{
    return this->cantDormitorios;
}

dtDireccion* dtPropiedadCasa::getdireccionProp() const{
    return this->direccionProp;
}

bool dtPropiedadCasa::getgarage() const{
    return this->garage;
}

float dtPropiedadCasa::getmCuadradosEdificado() const{
    return this->mCuadradosEdificado;
}

float dtPropiedadCasa::getmetrosVerdes() const{
    return this->metrosVerdes;
}

float dtPropiedadCasa::getValor() const{
    return this->valor;
}

bool dtPropiedadCasa::getVentaAlq() const{
    return this->ventAlq;
}
