///Alumno: Alonso Villa Joaquin Manuel.

# include<iostream>
# include<cstdlib>
# include<cstring>
# include<ctime>

using namespace std;


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
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) MENU JUGADORES"<<endl;
        cout<<"2) MENU DEPORTES"<<endl;
        cout<<"3) MENU EQUIPOS"<<endl;
        cout<<"4) MENU TIPOS DE DEPORTE"<<endl;
        cout<<"5) REPORTES"<<endl;
        cout<<"6) CONFIGURACION"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: subMenuJugadores();
                break;
            case 2: subMenuDeportes();
                break;
            case 5: reportes();
                break;
            case 6: subMenuConfiguracion();
                break;
            case 3: subMenuEquipos();
                break;
            case 4: subMenuTiposdeDeporte();
                break;
            case 0: return 0;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        system("pause");
    }
    cout<<endl;
    system("pause");
    return 0;
}
