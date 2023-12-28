///Alumno: Alonso Villa Joaquin Manuel.

# include<iostream>
# include<cstdlib>
# include<cstring>
# include<ctime>

using namespace std;

# include "rlutil.h"
# include "clasePunto.h"
# include "FuncionesGlobales.h"
# include "clsFecha.h"
# include "clsDeporte.h"
# include "clsJugador.h"
# include "clsEquipo.h"
# include "clsTipodeDeporte.h"
# include "subMenuJugadores.h"
# include "subMenuDeportes.h"
# include "subMenuConfiguracion.h"
# include "subMenuEquipos.h"
# include "subMenuTiposdeDeporte.h"
# include "reportes.h"

int main() {

    int y=0;
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::cls();
    while(true){
        int i;
        Punto obj(26,8, cMAGENTA_CLARO);
        for(i=26;i<55;i++){
            obj.Mostrar();
            obj.setX(i);
            }
        for(i=8;i<18;i++){
            obj.Mostrar();
            obj.setY(i);
        }
        for(i=54;i>25;i--){
            obj.setX(i);
            obj.Mostrar();
        }
        for(i=17;i>7;i--){
            obj.Mostrar();
            obj.setY(i);
        }

        rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
        showItem("  --MENU PRINCIPAL-- ", 30, 9, false);
        showItem("    MENU JUGADORES   ", 30, 10, y==0);
        showItem("    MENU DEPORTES    ", 30, 11, y==1);
        showItem("    MENU EQUIPOS     ", 30, 12, y==2);
        showItem("MENU TIPOS DE DEPORTE", 30, 13, y==3);
        showItem("      REPORTES       ", 30, 14, y==4);
        showItem("    CONFIGURACION    ", 30, 15, y==5);
        showItem("  SALIR DEL PROGRAMA ", 30, 16, y==6);


        switch(rlutil::getkey()){
            case 14: //UP
                rlutil::locate(28,10+y);
                cout<<" "<<endl;
                y--;
                if(y<0){
                    y=6;
                }
                break;
            case 15: //DOWN
                rlutil::locate(28,10+y);
                cout<<" "<<endl;
                y++;
                if(y>6){
                    y=0;
                }
                break;
            case 1: //ENTER
                switch(y){
                case 0: subMenuJugadores();
                    break;
                case 1: subMenuDeportes();
                    break;
                case 2: subMenuEquipos();
                    break;
                case 3: subMenuTiposdeDeporte();
                    break;
                case 4: reportes();
                    break;
                case 5: subMenuConfiguracion();
                    break;
                case 6: return 0;
                    break;
                }
                break;
            default:
                break;
            }
    }
}

