/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Propiedad.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 06:46 PM
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include"ICollectible.h"
#include "dtDireccion.h"
#include"Usuarios.h"
#include"dtPropiedadMensaje.h"
#include"dtMensajes.h"
//#include"dtPropiedad.h"

#ifndef PROPIEDAD_H
#define PROPIEDAD_H

using namespace std;

class Propiedad :public ICollectible {
public:
    Propiedad();
    Propiedad(const Propiedad& orig);
    virtual ~Propiedad();
    
  void esCasaP();
  void esAptoP();
  bool perteneceInmobiliaria(Usuarios inmobiliaria);
  dtPropiedadMensaje** getPropiedad(Usuarios usu );
  dtMensajes** getUltimosCinco(Usuarios usu);
  void eliminarLinksPropInmo();
  //dtPropiedad** getPropiedad();
    
private:
    string codigoProp;
    int cantAmbientes;
    int cantBanios;
    int cantDormitorios;
    bool garage;
    dtDireccion direccionProp;
    float mCuadradosEdificado;
    float mCuadradosTotales;

};

#endif /* PROPIEDAD_H */

