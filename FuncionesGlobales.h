#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
# include "clsFecha.h"
void cargarCadena();
bool fechaEsPasada();///Devuelve si la fecha es antigua o igual a la fecha actual

void cargarCadena(char *palabra, int tamano){

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

bool fechaEsPasada(Fecha f){
 Fecha actual;
 if(f.getAnio()>actual.getAnio()){
        return false;
 } else if(f.getAnio()==actual.getAnio()&&f.getMes()>actual.getMes()){
    return false;
 } else if(f.getAnio()==actual.getAnio()&&f.getMes()==actual.getMes()&&f.getDia()>actual.getDia()){
    return false;
 } else {
 return true;
 }
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
