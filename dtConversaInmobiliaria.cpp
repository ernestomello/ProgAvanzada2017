/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtConversaInmobiliaria.cpp
 * Author: Boris
 * 
 * Created on 10 de junio de 2017, 12:36 AM
 */

#include "dtConversaInmobiliaria.h"

dtConversaInmobiliaria::dtConversaInmobiliaria(string IdConversacion, dtFecha fechaUltimoMensaje) {
    this->IdConversacion = IdConversacion;
    this->fechaUltimoMensaje = fechaUltimoMensaje;
}

dtConversaInmobiliaria::dtConversaInmobiliaria() {
}

dtConversaInmobiliaria::dtConversaInmobiliaria(const dtConversaInmobiliaria& orig) {
}

dtConversaInmobiliaria::~dtConversaInmobiliaria() {
}

string dtConversaInmobiliaria::getIdConversacion() const{
    return this->IdConversacion;
}

dtFecha dtConversaInmobiliaria::getFechaUltimoMensaje() const{
    return this->fechaUltimoMensaje;
}