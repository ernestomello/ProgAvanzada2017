/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sistema.h
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 05:32 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include"dtDireccion.h"
#include"dtDepartamento.h"
#include"dtZonas.h"
#include"dtEdificio.h"
#include "dtPropiedad.h"



#ifndef SISTEMA_H
#define SISTEMA_H

using namespace std;

class sistema {
public:
    sistema();
    sistema(const sistema& orig);
    virtual ~sistema();
    
    void altaInmobiliaria(string nombreInm, dtDireccion* ubicacionInm);
    dtPropiedad *listarPropXZona(string codZona);
    dtDepartamento** listaDepartamentos();
    void seleccionaDepartamento(string letraDepartamento);
    
    dtZonas** listaZonaDepartamento(string letraDepartamento);
    void seleccionaZona(string codigoZona);
    void altaPropiedadCasa (int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, float metrosVerdes, float valor, string alquierOVenta);
    dtEdificio** listarEdificioZona(string codigoZona);
    void altaEdificio(dtEdificio edificio);
    string seleccionarEdificio();    
    void altaPropiedadApto(int cantAmbiente, int cantBanios,int cantDormitorios, bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, string nombreEdificio, float valor, string alquierOVenta);
       
    
private:

};

#endif /* SISTEMA_H */

