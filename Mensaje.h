/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.h
 * Author: esteban
 *
 * Created on 11 de junio de 2017, 06:46 PM
 */

#ifndef MENSAJE_H
#define MENSAJE_H

#include<string.h>
#include <stdio.h>
#include <iostream>
#include "dtFecha.h"
#include "dtHora.h"
#include "Chat.h"


using namespace std;

class Mensaje {
private:
	string textMsj;
	dtFecha * fechaMsj;
	dtHora * horaMsj;
	

public:
	Mensaje();
	~Mensaje();
        string getTextoMsj();
        dtFecha getFechaMsj();
        dtHora getHoraMsj();
        void setTextoMsj(string);
        dtMensajes** getMensaje();
        
};

#endif