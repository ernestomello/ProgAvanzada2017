/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtReporteInmobiliaria.h
 * Author: Boris
 *
 * Created on 9 de junio de 2017, 02:58 PM
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "dtDireccion.h"

#ifndef DTREPORTEINMOBILIARIA_H
#define DTREPORTEINMOBILIARIA_H

using namespace std;

class dtReporteInmobiliaria{
    public:
        dtReporteInmobiliaria();
        dtReporteInmobiliaria(const dtReporteInmobiliaria& orig);
        virtual ~dtReporteInmobiliaria();
        dtReporteInmobiliaria(string nombreInm, dtDireccion* ubicacionInm, string email, string nombreDepto, string nombreZona, int CantCasa, int CantDeptos);
        
        string getnombreInm() const;
        dtDireccion* getubicacionInm() const;
        string getemail() const;
        string getnombreDepto() const;
        string getnombreZona() const;
        int getCantCasa() const;
        int getCantDeptos() const;
        void setCantDeptos(int CantDeptos);
        void setCantCasa(int CantCasa);
        void setNombreZona(string nombreZona);
        string getNombreZona() const;
        void setNombreDepto(string nombreDepto);
        string getNombreDepto() const;
        void setEmail(string email);
        string getEmail() const;
        void setUbicacionInm(dtDireccion* ubicacionInm);
        dtDireccion* getUbicacionInm() const;
        void setNombreInm(string nombreInm);
        string getNombreInm() const;
        
    private:
        string nombreInm;
        dtDireccion* ubicacionInm;
        string email;
        string nombreDepto;
        string nombreZona;
        int CantCasa;
        int CantDeptos;
        
};

#endif /* DTREPORTEINMOBILIARIA_H */

