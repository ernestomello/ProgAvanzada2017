/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtFecha.cpp
 * Author: Boris
 * 
 * Created on 10 de junio de 2017, 12:22 AM
 */

#include "dtFecha.h"

dtFecha::dtFecha(int dd, int mm, int aa) {
    this->mm = mm;
    this->dd = dd;
    this->aa = aa;
}

dtFecha::dtFecha() {
}

dtFecha::dtFecha(const dtFecha& orig) {
}

dtFecha::~dtFecha() {
}

int dtFecha::getMeses() const{
    return this->mm;
}

int dtFecha::getDias() const{
    return this->dd;
}

int dtFecha::getAnios() const{
    return this->aa;
}