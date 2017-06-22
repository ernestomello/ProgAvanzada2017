/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContProp.h
 * Author: juan
 *
 * Created on 9 de junio de 2017, 08:17 PM
 */

#include"IContPorp.h"
<<<<<<< HEAD
#include"IDictionary.h"
=======
#include "IDictionary.h"
#include "ColGenerica.h"
#include "IKey.h"
#include "IIterator.h"
#include "ListaIterator.h"
>>>>>>> 3470b3c80ced2f2b69a59537769188547f36e8dc
#include <iostream>

#ifndef CONTPROP_H
#define CONTPROP_H

using namespace std;

 class ContProp : public IContProp {
    private: 
<<<<<<< HEAD
        IDictionary * Departamento;
        IDictionary * Edificio;
        IDictionary * PropInmo;
        IDictionary * ContUsuario;
    
=======
        IDictionary *diccionario;
        IKey *key;
        IIterator *iterator;
        ListDicc *listdiscc;
        ListDiccIterator *listdicciterator;
        ListDiccIteratorKey *listDiccIteratorKey;
        ListDiccIteratorObj *listDiccIteratorObj;
        ListaIterator *listaIterator;
        
>>>>>>> 3470b3c80ced2f2b69a59537769188547f36e8dc
     
    public:
        ContProp();
        ContProp(const ContProp& orig);
        virtual ~ContProp();
        dtDepartamento ** listaDepartamentos();
        void seleccionarDepartamentos(string);
        dtZonas ** listaZonasDepartamentos(string);
        void seleccionaZona(string);
        dtPropiedadMensaje ** listaPropiedades(string);
        dtPropiedadMensaje ** seleccionaPropiedad(string,int);
        void enviarMensaje(string);
        string ingesrarCodProp(string);
        void modifPropCasa(dtPropiedadCasa);
        void modifPropApto(dtPropiedadApto);
        dtConversaInmobiliaria ** listaConversacionesInmobiliarias();
        void seleccionaConversacion(string);
        dtMensajes ** listaUltimosCincoMensajes();
        void seleccionaMensaje(string);
        void agregaMensaje(string,string);
        dtPropiedadDisponible ** listaPropiedadesDisponibles();
        dtPropiedadInmobiliaria ** seleccionaPropiedadDisponible(string);
        void altaInteresado (string,string,int,string);
        void altaEdificio(string,int,int);
        dtReporteInmobiliaria** iniciarReporte(Inmobiliaria);
        void altaPropiedadCasa(dtPropiedadCasa);
        void altaPropiedadApto(dtPropiedadApto);
    };

#endif /* CONTPROP_H */

