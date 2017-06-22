/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.h
 * Author: esteban
 *
 * Created on 12 de junio de 2017, 07:50 PM
 */

#ifndef CONTUSUARIO_H
#define CONTUSUARIO_H

#include"IContUsuario.h"

using namespace std;

class ContUsuario : public IContUsuario {
public:
    ContUsuario();
    ContUsuario(const ContUsuario& orig);
    
    virtual ~ContUsuario();
    
    void altaInmobiliaria(string, dtDireccion*, string);
    void altaInteresado(string,string,int,string);
    Usuarios ** usuarioLogueado();
    void iniciarSesion(string, string);
    bool verificarContrasena(string, string);
    void activarUsuario(string, string);
    void validarPwd(string);
    void altaSesion();
    void cancelarAccion();
    dtReporteInmobiliaria ** obtenerReporteInmobiliarias ();
    void CerrarSesion(int);
    private:

};

#endif /* CONTUSUARIO_H */

