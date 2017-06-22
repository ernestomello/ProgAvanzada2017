/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadInmobiliaria.h
 * Author: Boris
 *
 * Created on 9 de junio de 2017, 08:23 PM
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "dtDireccion.h"

#ifndef DTPROPIEDADINMOBILIARIA_H
#define DTPROPIEDADINMOBILIARIA_H

using namespace std;

class dtPropiedadInmobiliaria {
public:
    dtPropiedadInmobiliaria();
    dtPropiedadInmobiliaria(const dtPropiedadInmobiliaria& orig);
    virtual ~dtPropiedadInmobiliaria();
    dtPropiedadInmobiliaria(int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, float mCuadradosTotales, string nombreInm);
    
    int getcantAmbiente() const;
    int getcantBanios() const;
    int getcantDormitorios() const;
    bool getgarage() const;
    dtDireccion* getdireccionProp() const;
    float getmCuadradosEdificado() const;
    float getmCuadradosTotales() const;
    string getnombreInm() const;
    void setNombreInm(string nombreInm);
    string getNombreInm() const;
    void setMCuadradosTotales(float mCuadradosTotales);
    float getMCuadradosTotales() const;
    void setMCuadradosEdificado(float mCuadradosEdificado);
    float getMCuadradosEdificado() const;
    void setDireccionProp(dtDireccion* direccionProp);
    dtDireccion* getDireccionProp() const;
    void setGarage(bool garage);
    bool isGarage() const;
    void setCantDormitorios(int cantDormitorios);
    int getCantDormitorios() const;
    void setCantBanios(int cantBanios);
    int getCantBanios() const;
    void setCantAmbiente(int cantAmbiente);
    int getCantAmbiente() const;
    
private:
    int cantAmbiente;
        int cantBanios;
        int cantDormitorios;
        bool garage;
        dtDireccion* direccionProp;
        float mCuadradosEdificado;
        float mCuadradosTotales;
        string nombreInm;

};

#endif /* DTPROPIEDADINMOBILIARIA_H */

