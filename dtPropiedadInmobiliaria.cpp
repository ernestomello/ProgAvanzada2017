/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadInmobiliaria.cpp
 * Author: Boris
 * 
 * Created on 9 de junio de 2017, 08:23 PM
 */

#include "dtPropiedadInmobiliaria.h"

dtPropiedadInmobiliaria::dtPropiedadInmobiliaria(int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, float mCuadradosTotales, string nombreInm){
    this->cantAmbiente = cantAmbiente;
    this->cantBanios = cantBanios;
    this->cantDormitorios = cantDormitorios;
    this->direccionProp = direccionProp;
    this->garage = garage;
    this->mCuadradosEdificado = mCuadradosEdificado;
    this->mCuadradosTotales = mCuadradosTotales;
    this->nombreInm = nombreInm;
}

dtPropiedadInmobiliaria::dtPropiedadInmobiliaria() {
}

dtPropiedadInmobiliaria::dtPropiedadInmobiliaria(const dtPropiedadInmobiliaria& orig) {
}

dtPropiedadInmobiliaria::~dtPropiedadInmobiliaria() {
}

int dtPropiedadInmobiliaria::getcantAmbiente() const{
    return this->cantAmbiente;
}

int dtPropiedadInmobiliaria::getcantBanios() const{
    return this->cantBanios;
}

int dtPropiedadInmobiliaria::getcantDormitorios() const{
    return this->cantDormitorios;
}

dtDireccion* dtPropiedadInmobiliaria::getdireccionProp() const{
    return this->direccionProp;
}

bool dtPropiedadInmobiliaria::getgarage() const{
    return this->garage;
}

float dtPropiedadInmobiliaria::getmCuadradosEdificado() const{
    return this->mCuadradosEdificado;
}

float dtPropiedadInmobiliaria::getmCuadradosTotales() const{
    return this->mCuadradosTotales;
}

string dtPropiedadInmobiliaria::getnombreInm() const{
    return this->nombreInm;
}

void dtPropiedadInmobiliaria::setNombreInm(string nombreInm) {
    this->nombreInm = nombreInm;
}

string dtPropiedadInmobiliaria::getNombreInm() const {
    return nombreInm;
}

void dtPropiedadInmobiliaria::setMCuadradosTotales(float mCuadradosTotales) {
    this->mCuadradosTotales = mCuadradosTotales;
}

float dtPropiedadInmobiliaria::getMCuadradosTotales() const {
    return mCuadradosTotales;
}

void dtPropiedadInmobiliaria::setMCuadradosEdificado(float mCuadradosEdificado) {
    this->mCuadradosEdificado = mCuadradosEdificado;
}

float dtPropiedadInmobiliaria::getMCuadradosEdificado() const {
    return mCuadradosEdificado;
}

void dtPropiedadInmobiliaria::setDireccionProp(dtDireccion* direccionProp) {
    this->direccionProp = direccionProp;
}

dtDireccion* dtPropiedadInmobiliaria::getDireccionProp() const {
    return direccionProp;
}

void dtPropiedadInmobiliaria::setGarage(bool garage) {
    this->garage = garage;
}

bool dtPropiedadInmobiliaria::isGarage() const {
    return garage;
}

void dtPropiedadInmobiliaria::setCantDormitorios(int cantDormitorios) {
    this->cantDormitorios = cantDormitorios;
}

int dtPropiedadInmobiliaria::getCantDormitorios() const {
    return cantDormitorios;
}

void dtPropiedadInmobiliaria::setCantBanios(int cantBanios) {
    this->cantBanios = cantBanios;
}

int dtPropiedadInmobiliaria::getCantBanios() const {
    return cantBanios;
}

void dtPropiedadInmobiliaria::setCantAmbiente(int cantAmbiente) {
    this->cantAmbiente = cantAmbiente;
}

int dtPropiedadInmobiliaria::getCantAmbiente() const {
    return cantAmbiente;
}
