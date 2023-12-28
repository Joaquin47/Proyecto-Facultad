#ifndef CLASEPUNTO_H_INCLUDED
#define CLASEPUNTO_H_INCLUDED

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
#include <windows.h>
#include <ctime>

using namespace std;

///DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el número 15

void ocultarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void mostrarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x, short y){ ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
///ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto=15, int colorFondo=0){
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

///**FIN FUNCIONES


///CLASE PUNTO
class Punto {
    private:
        int x;
        int y;
        int color;
    public:
        Punto(int a=0, int b=0, int nuevoColor=cNEGRO){
            x=a;
            y=b;
            color=nuevoColor;
        }
        void Mostrar(){
            textcolor(color, 15);
            gotoxy(x,y);
            cout<<(char)219;
        }
        void MostrarValores();
        void Ocultar(){
            gotoxy(x,y);
            cout<<" ";
        }
        void setX(int valor){
            if(valor>=0 && valor<=166)  x=valor;
        }
        void setY(int valor){
            if(valor>=0)  y=valor;
        }

        void setColor(int nuevo){
            if(nuevo>0 && nuevo<=15){
                color=nuevo;
            }else{
                color=nuevo%16;
            }
        }
        int getX(){return x;}
        int getY(){return y;}
        int getColor(){return color;}
        ~Punto(){///DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su alcance.
            textcolor(cBLANCO,cNEGRO);

        }
};

void Punto::MostrarValores(){
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<color<<endl;
    }



#endif // CLASEPUNTO_H_INCLUDED
