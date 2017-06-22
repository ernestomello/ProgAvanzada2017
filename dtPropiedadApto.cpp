/* 
 * File:   dtPropiedadApto.cpp
 * Author: Esteban
 *
 * Created on 9 de junio de 2017, 05:06 PM
 */

#include "dtPropiedadApto.h"

dtPropiedadApto::dtPropiedadApto(int cantAmbiente, int cantBanios, int cantDormitorios,
    bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, string nombreEdificio,
    float valor, bool ventAlq){
    // artibutos
    this->cantAmbiente = cantAmbiente;
    this->cantBanios = cantBanios;
    this->cantDormitorios = cantDormitorios;
    this->direccionProp = direccionProp;
    this->garage = garage;
    this->mCuadradosEdificado = mCuadradosEdificado;
    this->nombreEdificio = nombreEdificio;
    this->valor = valor;
    this->ventAlq = ventAlq;
    
}

dtPropiedadApto::dtPropiedadApto(const dtPropiedadApto& orig){
}

dtPropiedadApto::dtPropiedadApto(){
}

dtPropiedadApto::~dtPropiedadApto(){
}

int dtPropiedadApto::getcantAmbiente() const{
    return this->cantAmbiente;
}

int dtPropiedadApto::getcantBanios() const{
    return this->cantBanios;
}

int dtPropiedadApto::getcantDormitorios() const{
    return this->cantDormitorios;
}

dtDireccion* dtPropiedadApto::getdireccionProp() const{
    return this->direccionProp;
}

bool dtPropiedadApto::getgarage() const{
    return this->garage;
}

float dtPropiedadApto::getmCuadradosEdificado() const{
    return this->mCuadradosEdificado;
}

string dtPropiedadApto::getnombreEdificio() const{
    return this->nombreEdificio;
}
float dtPropiedadApto::getValor() const{
    return this->valor;
}

bool dtPropiedadApto::getVentaAlq() const{
    return this->ventAlq;
}
