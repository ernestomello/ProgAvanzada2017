/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtHora.h
 * Author: Boris
 *
 * Created on 10 de junio de 2017, 12:16 AM
 */

#ifndef DTHORA_H
#define DTHORA_H

class dtHora {
public:
    dtHora();
    dtHora(const dtHora& orig);
    virtual ~dtHora();
    dtHora(int ss, int mm, int hh);
    
    int getsegundos() const;
    int getminutos() const;
    int gethoras() const;
    
private:
    int ss;
    int mm;
    int hh;

};

#endif /* DTHORA_H */

