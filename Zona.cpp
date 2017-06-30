/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zona.cpp
 * Author: lucia
 * 
 * Created on 9 de junio de 2017, 06:45 PM
 */

#include <stdexcept>

#include "Zona.h"


Zona::Zona() {
    this->IPropiedad = new ListDicc();
}

void Zona::setNombreZona(string nombreZona) {
    this->nombreZona = nombreZona;
    this->IPropiedad = new ListDicc();

}

string Zona::getNombreZona() const {
    return nombreZona;
}

void Zona::setCodigoZona(string codigoZona) {
    this->codigoZona = codigoZona;
}

string Zona::getCodigoZona() const {
    return codigoZona;
}

Zona::Zona(const Zona& orig) {}

Zona::~Zona() {}

dtZonas* Zona::getZonas(){
    return new dtZonas(codigoZona, nombreZona);
}
Zona::Zona(string nombreZ,string codigoZ){
    this->nombreZona=nombreZ;
    this->codigoZona=codigoZ;
    this->IPropiedad = new ListDicc();
}



Lista* Zona::listaPropiedades(string usuario){
    int cantidad= 0;
    IIterator *it =IPropiedad->getIteratorObj();
    Lista *resul=new Lista();
    while (it->hasNext()) {
        Propiedad* p= dynamic_cast <Propiedad*> (it->getCurrent());
        //cantidad = usuario->cantMensajesPropiedad(p->getCodigoProp());
        resul->add(p->getPropiedad(cantidad));
        it->next();
    }
    delete it;
    return resul;
}

Lista* Zona::ultimosCincoMensajes(string codProp){
   Lista *resul=new Lista();
    StringKey *sk= new StringKey(codProp);
    Propiedad *p=dynamic_cast<Propiedad*>(IPropiedad->find(sk));
    if(p!=NULL)
        p->getUltimosCinco();
    else 
        throw invalid_argument("No existe esa Propiedad");
    
return resul;
}
Lista * Zona::listaPropDisponible(Usuarios *usu){
    IIterator *it=IPropiedad->getIteratorObj();
    Lista *resul=new Lista();
    while (it->hasNext()) {
        dtPropiedadDisponible* p= dynamic_cast<dtPropiedadDisponible*>(it->getCurrent());
        resul->add(p->getPropiedadDisponible(usu));
    }
    delete it;
    return resul;
}

dtPropiedadInmobiliaria * Zona::seleccionaPropDisponible(string codprop){
     IIterator *it=IPropiedad->getIteratorObj();
    StringKey *sk=new StringKey(codprop);
    Propiedad *p=dynamic_cast<Propiedad*>(IPropiedad->find(sk));
    if(p!=NULL){
        return p->getPropiedadDisponible();
    }
    else
    throw invalid_argument("No existe esa Propiedad");
  
}
dtPropZonas getPropZonaDpto(Usuarios){}

Propiedad getPropiedad(){}

void Zona::altaPropiedad(Propiedad * p, StringKey* sk){
     
    if(IPropiedad->member(sk)!=true)
    IPropiedad->add(p,sk);
    else throw new invalid_argument("Propiedad ya existente");    

}
