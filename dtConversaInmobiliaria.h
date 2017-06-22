/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtConversaInmobiliaria.h
 * Author: Boris
 *
 * Created on 10 de junio de 2017, 12:36 AM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include"dtFecha.h"

#ifndef DTCONVERSAINMOBILIARIA_H
#define DTCONVERSAINMOBILIARIA_H

class dtConversaInmobiliaria {
public:
    dtConversaInmobiliaria();
    dtConversaInmobiliaria(const dtConversaInmobiliaria& orig);
    
    dtConversaInmobiliaria(string IdConversacion, dtFecha fechaUltimoMensaje);
    virtual ~dtConversaInmobiliaria();
    
    string getIdConversacion() const;
    dtFecha getFechaUltimoMensaje() const;
    
private:
    string IdConversacion;
    dtFecha fechaUltimoMensaje;

};

#endif /* DTCONVERSAINMOBILIARIA_H */

