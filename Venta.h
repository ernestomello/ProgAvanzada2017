/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   venta.h
 * Author: esteban
 *
 * Created on 9 de junio de 2017, 08:26 PM
 */

#include"Aviso.h"

#ifndef VENTA_H
#define VENTA_H

using namespace std;

class Venta : public Aviso {
private:
	int precioTotalVenta;
public:
   
    Venta();
    Venta(const Venta & orig);
    virtual ~Venta();
    
    void altaVenta(float);
    bool esVenta();
    bool esAlquiler();
    
    float getPrecioVenta();
    void setPrecioVenta(int);

};

#endif /* VENTA_H */



	
