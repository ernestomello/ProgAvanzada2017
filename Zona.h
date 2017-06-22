/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zona.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 06:45 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include"ICollectible.h"
#include"Propiedad.h"
#include"Usuarios.h"
#include"dtZonas.h"
#include"dtPropiedadApto.h"
#include"dtPropZonas.h"

#ifndef ZONA_H
#define ZONA_H

using namespace std;

class Zona: public ICollectible {
public:
    Zona();
    Zona(const Zona& orig);
    virtual ~Zona();
    
    dtZonas** getZona();
    dtPropZonas** getPropZonaDpto(Usuarios inmobiliaria);
    Propiedad getPropiedad();
private:
    string codigoZona;
    string nombreZona;
    Propiedad* propiedad;
};

#endif /* ZONA_H */

