#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
# include "clsFecha.h"

void cargarCadena();
bool fechaEsPasada();///Devuelve si la fecha es antigua o igual a la fecha actual
void showItem();///Opción de un Menú
void pauseCls();///Pausa primero y limpia el programa despues


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

void showItem(const char* text, int posx, int posy, bool selected){
    if(selected){
    rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
    rlutil::locate(posx-2,posy);
    cout<<(char)62<<" "<<text<<" "<<(char)60<<endl;
    } else {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::locate(posx-2,posy);
    cout<<"  "<<text<<"  "<<endl;
    }
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void pauseCls(){
    system("pause");
    system("cls");
}
#endif // FUNCIONESGLOBALES_H_INCLUDED
