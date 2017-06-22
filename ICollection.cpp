/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ICollection.h"

#include "StringKey.h"
#include "ListaDicc.h"
#include "Propiedad.h"
#include "ListDiccIteratorObj.h"
#include "ListDiccIteratorKey.h"
#include "IDictionary.h"



//destructor		
ICollection::~ ICollection(){
}

ICollection::ICollection(){
    this->= new ListDicc();
}

ICollection::ICollection(IDictionary* dicc){
	this->dicc=dicc;
        
}

//operaciones
void ICollection::add(ICollection* tray, StringKey* key){
	this->dicc->add(tray,key);
}

bool ICollection::member(StringKey* key){
	return(this->dicc->member(key));
}

ICollection* ICollection::removeKey(StringKey* key){
	return((ICollection*)this->dicc->removeKey(key));
}

ICollection* ICollection::removeObj(ICollection* obj){
 	return((ICollection*)this->dicc->removeObj(obj));
}

ICollection* ICollection::find(StringKey* key){
	ICollection* t=(ICollection*)this->dicc->find(key);
	if(t==NULL){
		//delete(key);
		throw(invalid_argument("Error: el Trayecto buscado no existe en el sistema \n"));
	}else
 		return(t);
}

ListDiccIteratorObj* ICollection::getIteratorObj(){
	return((ListDiccIteratorObj*)this->dicc->getIteratorObj());
}

ListDiccIteratorKey* ICollection::getIteratorKey(){
	return((ListDiccIteratorKey*)this->dicc->getIteratorKey());
}

unsigned int ICollection::size(){
	return(this->dicc->size());
}

//destructor		
ICollection::~ ICollection(){
	delete(this->dicc);
}

