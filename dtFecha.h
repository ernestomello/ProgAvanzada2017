/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtFecha.h
 * Author: ernesto
 *
 * Created on 12 de junio de 2017, 09:20 AM
 */

#ifndef DTFECHA_H
#define DTFECHA_H
using namespace std;

class dtFecha {
private:
    int dd;
    int mm;
    int aa;
public:
    dtFecha(int dd, int mm, int aa);
    dtFecha() ;
    dtFecha(const dtFecha& orig) ;
    ~dtFecha() ;
    int getMeses() const;
    int getDias() const;
    int getAnios() const;
};


#endif /* DTFECHA_H */

