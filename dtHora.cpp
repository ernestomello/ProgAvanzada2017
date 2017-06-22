/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtHora.cpp
 * Author: Boris
 * 
 * Created on 10 de junio de 2017, 12:16 AM
 */

#include "dtHora.h"

dtHora::dtHora(int ss, int mm, int hh) {
    this->ss = ss;
    this->mm = mm;
    this->hh = hh;
}

dtHora::dtHora() {
}

dtHora::dtHora(const dtHora& orig) {
}

dtHora::~dtHora() {
}

int dtHora::getsegundos() const{
    return this->ss;
}

int dtHora::getminutos() const{
    return this->mm;
}

int dtHora::gethoras() const{
    return this->hh;
}