/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IContUsuario.h
 * Author: esteban
 *
 * Created on 12 de junio de 2017, 08:16 PM
 */

#ifndef ICONTUSUARIO_H
#define ICONTUSUARIO_H
#include"dtDireccion.h"
#include"dtReporteInmobiliaria.h"
#include"Usuarios.h"

using namespace std;

class IContUsuario {
public:

    virtual ~IContUsuario();
    
    virtual void altaInmobiliaria(string, dtDireccion *, string)= 0;
    virtual void altaInteresado(string,string,int,string)= 0;
    virtual Usuarios ** usuarioLogueado()= 0;
    virtual void iniciarSesion(string, string)= 0;
    virtual bool verificarContrasena(string, string)= 0;
    virtual void activarUsuario(string, string)= 0;
    virtual void validarPwd(string)= 0;
    virtual void altaSesion()= 0;
    virtual void cancelarAccion()= 0;
    virtual dtReporteInmobiliaria ** obtenerReporteInmobiliarias ()= 0;
    virtual void CerrarSesion(int)= 0;
    
    private:
};

#endif /* ICONTUSUARIO_H */

