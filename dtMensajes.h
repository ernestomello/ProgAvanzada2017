/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtMensajes.h
 * Author: Boris
 *
 * Created on 10 de junio de 2017, 12:04 AM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "dtFecha.h"
#include "dtHora.h"

#ifndef DTMENSAJES_H
#define DTMENSAJES_H

class dtMensajes {
public:
    dtMensajes();
    dtMensajes(const dtMensajes& orig);
    virtual ~dtMensajes();
    dtMensajes(string idMensaje, string textoMsj, dtFecha fechaMsj, dtHora horaMsj);
    
    string getidMensaje() const;
    string gettextoMsj() const;
    dtFecha getfechaMsj() const;
    dtHora gethoraMsj() const;
    
private:
    string idMensaje;
    string textoMsj;
    dtFecha fechaMsj;
    dtHora horaMsj;

};

#endif /* DTMENSAJES_H */

