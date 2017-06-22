/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interesado.h
 * Author: ernesto
 *
 * Created on 9 de junio de 2017, 06:07 PM
 */
#include"Usuarios.h"

#ifndef INTERESADO_H
#define INTERESADO_H

class Interesado :public Usuarios{
    private: 
        int edad;
        string nombreInt;
        string apellidoInt;
        public:
            int getEdad();
            void setEdad();
            Interesado();
            virtual ~Interesado();
};
#endif /* INTERESADO_H */
