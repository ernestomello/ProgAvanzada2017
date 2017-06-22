/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edificio.h
 * Author: ernesto
 *
 * Created on 9 de junio de 2017, 07:14 PM
 */

#include"ICollectible.h"
#include<string.h>
#include<stdio.h>
#include<iostream>

#ifndef EDIFICIO_H
#define EDIFICIO_H

using namespace std;

class Edificio :public ICollectible {
    private:
        string nombreEdificio;
        int cantpisosEdificio;
        float gastosComunes;
        
};
#endif /* EDIFICIO_H */