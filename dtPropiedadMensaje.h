/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadMensaje.h
 * Author: ernesto
 *
 * Created on 12 de junio de 2017, 09:19 AM
 */

#ifndef DTPROPIEDADMENSAJE_H
#define DTPROPIEDADMENSAJE_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include"dtDireccion.h"

using namespace std;

class dtPropiedadMensaje {
void setCantMensajesEnviados(int cantMensajesEnviados);
void setDireccionProp(dtDireccion* direccionProp);
dtDireccion* getDireccionProp() const;
void setCodigoProp(string codigoProp);
string getCodigoProp() const;
private:
    string codigoProp;
    dtDireccion* direccionProp;
    int cantMensajesEnviados;
private:    
dtPropiedadMensaje(string codigoProp, dtDireccion* direccionProp, int cantMensajesEnviados);
dtPropiedadMensaje();
dtPropiedadMensaje(const dtPropiedadMensaje& orig);
~dtPropiedadMensaje();
string getcodigoProp() const;
dtDireccion* getdireccionProp() const;
int getCantMensajesEnviados() const;

};
#endif /* DTPROPIEDADMENSAJE_H */

