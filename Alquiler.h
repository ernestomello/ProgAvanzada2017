// -*- C++ -*-
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alquiler.h
 * Author: ernesto
 *
 * Created on 12 de junio de 2017, 12:48 PM
 */
#include"Aviso.h"

#ifndef ALQUILER_H
#define ALQUILER_H

class Alquiler : public Aviso {
private:
	 int precioALquiler;
public:
    
    Alquiler();
    Alquiler(const Alquiler & orig);
    virtual ~Alquiler();
    
    void altaAlquiler(float); 
    bool esVenta();
    bool esAlquiler();
    
    float getPrecioAlquiler();
    void setPrecioAlquiler(float);

    
};


#endif /* ALQUILER_H */

