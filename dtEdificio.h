/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtEdificio.h
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 06:40 PM
 */
#include <string.h>
#include <iostream>
using namespace std;

#ifndef DTEDIFICIO_H
#define DTEDIFICIO_H

using namespace std;

class dtEdificio {
public:
    dtEdificio();
    dtEdificio(const dtEdificio& orig);
    virtual ~dtEdificio();
    dtEdificio (string nombreEdificio, int picantPisosEdificiosos, float gastosComunesEdificio);
    
    dtEdificio seleccionarEdificio(string nombreEdificio);
    dtEdificio** listarEdificioZona();
    void altaEdificio(string nombreEdificio);
    
    string getnombreEdificio() const;
    void setGastosComunesEdificio(float gastosComunesEdificio);
    void getGastosComunesEdificio(float) const;
    void setCantPisosEdificio(int cantPisosEdificio);
    int getCantPisosEdificio() const;
    void setNombreEdificio(string nombreEdificio);
    string getNombreEdificio() const;    
    
    
    
private:
    string nombreEdificio;
    int cantPisosEdificio;
    float gastosComunesEdificio;
    

};

#endif /* DTEDIFICIO_H */

