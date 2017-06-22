/* 
 * File:   dtPropiedadCasa.h
 * Author: Esteban
 *
 * Created on 9 de junio de 2017, 05:06 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "dtDireccion.h"


#ifndef DTPROPIEDADCASA_H
#define DTPROPIEDADCASA_H

using namespace std;

class dtPropiedadCasa{
    public:
        dtPropiedadCasa();
        dtPropiedadCasa(const dtPropiedadCasa& orig);
        virtual ~dtPropiedadCasa();
        dtPropiedadCasa(int cantAmbiente, int cantBanios, int cantDormitorios,
        bool garage, dtDireccion* direccionProp, float mCuadradosEdificado,
        float metrosVerdes,float valor, bool ventaAlq);
        
        int getcantAmbiente() const;
        int getcantBanios() const;
        int getcantDormitorios() const;
        bool getgarage() const;
        dtDireccion* getdireccionProp() const;
        float getmCuadradosEdificado() const;
        float getmetrosVerdes() const;
        float getValor() const;
        bool getVentaAlq() const;
        
    private:
        int cantAmbiente;
        int cantBanios;
        int cantDormitorios;
        bool garage;
        dtDireccion* direccionProp;
        float mCuadradosEdificado;
        float metrosVerdes;
        float valor;
        bool ventAlq;
};


#endif /* DTPROPIEDADCASA_H */
