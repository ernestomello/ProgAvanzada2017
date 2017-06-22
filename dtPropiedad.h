/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedad.h
 * Author: esteban
 *
 * Created on 11 de junio de 2017, 07:59 PM
 */

#ifndef DTPROPIEDAD_H
#define DTPROPIEDAD_H
#include<string.h>
#include <stdio.h>
#include <iostream>
#include"dtDireccion.h"

using namespace std;
class dtPropiedad {
    private:
    string codigoProp;
    int cantAmbiente;
    int cantBanios;
    int cantDormitorios;
    bool garage;
    dtDireccion* direccionProp;
    float mCuadradosEdificado;
    float mCuadradosTotales;
public:
    dtPropiedad();
    dtPropiedad(const dtPropiedad& orig);
   
    dtPropiedad(string codigoProp, int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, float mCuadradosTotales);
    virtual ~dtPropiedad();
    
    string getcodigoProp() const;
    int getcantAmbiente() const;
    int getcantBanios() const;
    int getcantDormitorios() const;
    bool getgarage() const;
    dtDireccion* getdireccionProp() const;
    float getmCuadradosEdificado() const;
    float getmCuadradoTotales() const;
    

};

#endif /* DTPROPIEDAD_H */

