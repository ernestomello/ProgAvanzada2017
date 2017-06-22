/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.h
 * Author: ernesto
 *
 * Created on 13 de junio de 2017, 07:49 AM
 */

#include"ContUsuario.h"
#include"ContProp.h"

#ifndef FABRICA_H
#define FABRICA_H

class Fabrica {
    //Fabrica es singleton
private:
    ContUsuario * cUsu;
    ContProp * cProp;
    Fabrica();
    static Fabrica* fabrica;
public:
    
    static Fabrica* getInstance();
    IContUsuario* getContUsuario();
    IContProp* getContProp();

    //destructor
    virtual ~Fabrica();
private:

};

#endif /* FABRICA_H */

