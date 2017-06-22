/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inmobiliaria.h
 * Author: ernesto
 *
 * Created on 9 de junio de 2017, 06:00 PM
 */
#include"Usuarios.h"
#include"dtDireccion.h"

#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

class Inmobiliaria : public Usuarios{
    private:
        string nombreInm;
        dtDireccion* direccion;
    public:
        Inmobiliaria();
        virtual ~Inmobiliaria();
        
};

#endif /* INMOBILIARIA_H */
