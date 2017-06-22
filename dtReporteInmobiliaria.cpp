/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "dtReporteInmobiliaria.h"

dtReporteInmobiliaria::dtReporteInmobiliaria (string nombreInm, dtDireccion* ubicacionInm, string email, string nombreDepto, string nombreZona, int CantCasa, int CantDeptos){
    this->nombreInm = nombreInm;
    this->ubicacionInm = ubicacionInm;
    this->email = email;
    this->nombreDepto = nombreDepto;
    this->nombreZona = nombreZona;
    this->CantCasa = CantCasa;
    this->CantDeptos = CantDeptos;
    
}

dtReporteInmobiliaria::dtReporteInmobiliaria(){
}

dtReporteInmobiliaria::dtReporteInmobiliaria(const dtReporteInmobiliaria& orig){
}

dtReporteInmobiliaria::~dtReporteInmobiliaria(){
}

string dtReporteInmobiliaria::getnombreInm() const{
    return this->nombreInm;
}

dtDireccion* dtReporteInmobiliaria::getubicacionInm() const{
    return this->ubicacionInm;
}

string dtReporteInmobiliaria::getemail() const{
    return this->email;
}

string dtReporteInmobiliaria::getnombreDepto() const{
    return this->nombreDepto;
}

string dtReporteInmobiliaria::getnombreZona() const{
    return this->nombreZona;
}

int dtReporteInmobiliaria::getCantCasa() const{
    return this->CantCasa;
}

int dtReporteInmobiliaria::getCantDeptos() const{
    return this->CantDeptos;
}

void dtReporteInmobiliaria::setCantDeptos(int CantDeptos) {
    this->CantDeptos = CantDeptos;
}

void dtReporteInmobiliaria::setCantCasa(int CantCasa) {
    this->CantCasa = CantCasa;
}

void dtReporteInmobiliaria::setNombreZona(string nombreZona) {
    this->nombreZona = nombreZona;
}

string dtReporteInmobiliaria::getNombreZona() const {
    return nombreZona;
}

void dtReporteInmobiliaria::setNombreDepto(string nombreDepto) {
    this->nombreDepto = nombreDepto;
}

string dtReporteInmobiliaria::getNombreDepto() const {
    return nombreDepto;
}

void dtReporteInmobiliaria::setEmail(string email) {
    this->email = email;
}

string dtReporteInmobiliaria::getEmail() const {
    return email;
}

void dtReporteInmobiliaria::setUbicacionInm(dtDireccion* ubicacionInm) {
    this->ubicacionInm = ubicacionInm;
}

dtDireccion* dtReporteInmobiliaria::getUbicacionInm() const {
    return ubicacionInm;
}

void dtReporteInmobiliaria::setNombreInm(string nombreInm) {
    this->nombreInm = nombreInm;
}

string dtReporteInmobiliaria::getNombreInm() const {
    return nombreInm;
}
