/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edificio.cpp
 * Author: ernesto
 * 
 * Created on 9 de junio de 2017, 07:14 PM
 */

#include "Edificio.h"

    Edificio::Edificio (){}
    Edificio::Edificio(const Edificio& orig){}

Edificio::Edificio(string nombre, int pisos, float gastosComunes) {
    this->nombreEdificio=nombre;
    this->cantpisosEdificio=pisos;
    this->gastosComunes=gastosComunes;
    
}

    Edificio::~Edificio(){}