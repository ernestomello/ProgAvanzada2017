/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtMensajes.cpp
 * Author: Boris
 * 
 * Created on 10 de junio de 2017, 12:04 AM
 */

#include "dtMensajes.h"

dtMensajes::dtMensajes(string idMensaje, string textoMsj, dtFecha fechaMsj, dtHora horaMsj) {
    this->idMensaje = idMensaje;
    this->textoMsj = textoMsj;
    this->fechaMsj = fechaMsj;
    this->horaMsj = horaMsj;
}

dtMensajes::dtMensajes() {
}

dtMensajes::dtMensajes(const dtMensajes& orig) {
}

dtMensajes::~dtMensajes() {
}

string dtMensajes::getidMensaje() const{
    return this->idMensaje;
}

string dtMensajes::gettextoMsj() const{
    return this->textoMsj;
}

dtFecha dtMensajes::getfechaMsj() const{
    return this->fechaMsj;
}

dtHora dtMensajes::gethoraMsj() const{
    return this->horaMsj;
}