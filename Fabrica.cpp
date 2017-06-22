    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.cpp
 * Author: ernesto
 * 
 * Created on 13 de junio de 2017, 07:49 AM
 */

#include "Fabrica.h"

Fabrica* Fabrica::fabrica = NULL;

Fabrica::Fabrica() {}


Fabrica::~Fabrica(){
	//delete this->cliit;
	//delete this->espvue;
	//delete this->vuelop;
}

Fabrica* Fabrica::getInstance(){
    if (fabrica==NULL){
            fabrica = new Fabrica();
    }
    return fabrica;
}

IContUsuario* Fabrica::getContUsuario(){
    if (this->cUsu == NULL)
            this->cUsu = new ContUsuario();
    return this->cUsu;
}	

IContProp* Fabrica::getContProp(){
    if (this->cProp==NULL)
            this->cProp = new ContProp();
    return this->cProp;
}
