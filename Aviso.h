/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aviso.h
 * Author: esteban
 *
 * Created on 11 de junio de 2017, 06:42 PM
 */

#include"Propiedad.h"


#ifndef AVISO_H
#define AVISO_H


using namespace std;

class Aviso {
       
public:
    Aviso();
    Aviso(const Aviso& orig);
    virtual ~Aviso();
       
    virtual Aviso getAviso();
    
    virtual void crearAvisoProp(Propiedad);
    virtual void altaAlquiler(float);
    virtual void altaVenta(float);

private:    
    /*Alquiler *propEnAlq;
    Venta * propEnVenta;*/
  

};

#endif /* AVISO_H */