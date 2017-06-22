/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   venta.cpp
 * Author: esteban
 * 
 * Created on 9 de junio de 2017, 08:26 PM
 */

#include<string.h>
#include <stdio.h>
#include <iostream>

#include "Venta.h"

Venta::Venta() {
}

Venta::Venta(const Venta& orig) {
}

Venta::~Venta() {
}


float Venta::getPrecioVenta(){
    return this->precioTotalVenta ;
	
}

void Venta::altaVenta(float precio){   
    this->precioTotalVenta = precio;
}
bool Venta::esVenta(){
    return true;
	
}
bool Venta::esAlquiler(){
}