#ifndef SUBMENUJUGADORES_H_INCLUDED
#define SUBMENUJUGADORES_H_INCLUDED

bool agregarRegistroJugador();
bool listarJugadoresSegunDNI();
void listarJugadores();
bool modificarFecha();
bool bajaLogicaJugador();


void subMenuJugadores() {
    int opc;
    while(true){
        system("cls");
        cout<<"MENU JUGADORES"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR JUGADOR"<<endl;
        cout<<"2) LISTAR JUGADOR POR DNI"<<endl;
        cout<<"3) LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
        cout<<"5) ELIMINAR REGISTRO DE JUGADORES"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(agregarRegistroJugador()){
            cout<<"REGISTRO AGREGADO"<<endl;
            } else {cout<<"NO SE HA PODIDO AGREGAR EL REGISTRO"<<endl;
            };
                break;
            case 2: if(!listarJugadoresSegunDNI()){cout<<"NO HAY REGISTRO CON ESE DNI"<<endl;}
                break;
            case 3: listarJugadores();
                break;
            case 4: if(modificarFecha()){
            cout<<"ARCHIVO MODIFICADO"<<endl;
            } else {cout<<"NO SE HA PODIDO MODIFICAR EL REGISTRO"<<endl;
            }
                break;
            case 5: if(bajaLogicaJugador()){cout<<"SE HA DADO DE BAJA AL JUGADOR"<<endl;
            } else {cout<<"NO SE HA DADO DE BAJA AL JUGADOR"<<endl;
            }
                break;
            case 0: return ;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        system("pause");
    }
    cout<<endl;
    system("pause");
    return ;
}

bool agregarRegistroJugador(){
    Jugador reg;
    ArchivoJugadores arch("Jugadores.dat");
    ArchivoDeportes archD("Deportes.dat");
    ArchivoEquipos archE("Equipos.dat");
    int dni, pos;
    cout<<"INGRESE DNI: ";
    cin>>dni;
    pos=arch.buscarDNI(dni);
    if(pos==-2){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    } else if(pos!=-1){
        cout<<"YA HAY UN JUGADOR CON ESE DNI EN EL ARCHIVO"<<endl;
        return false;
    }
    int iddeporte;
    cout<<"INGRESE EL ID DEL DEPORTE: "<<endl;
    cin>>iddeporte;
    if(!archD.estaDisponibleID(iddeporte)){
        cout<<"EL ID NO CORRESPONDE A UN DEPORTE O EL DEPORTE SE ENCUENTRA DESHABILITADO"<<endl;

        return false;
    }
    int idequipo;
    cout<<"INGRESE EL EQUIPO: "<<endl;
    cin>>idequipo;
    if(!archE.estaDisponibleIDEquipo(idequipo)){
        cout<<"EL ID NO CORRESPONDE A UN EQUIPO O EL EQUIPO SE ENCUENTRA DESHABILITADO"<<endl;

        return false;
    }
    reg.Cargar(dni,iddeporte,idequipo);
    bool agrego=arch.agregarJugador(reg);
    return agrego;
}

bool listarJugadoresSegunDNI(){
    int dni;
    cout<<"INGRESE EL DNI: "<<endl;
    cin>>dni;
    Jugador reg;
    ArchivoJugadores arch("Jugadores.dat");
    FILE *p;
    p=fopen("Jugadores.dat","rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(dni==reg.getDNI()&&reg.getEstado()){
            reg.Mostrar();
            return true;
        }
    }
    fclose(p);
    return false;
}

void listarJugadores(){
    ArchivoJugadores arch("Jugadores.dat");
    arch.listarJugadores();
}

bool modificarFecha(){
    ArchivoJugadores arch("Jugadores.dat");
    Fecha fechaux;
    Jugador reg;
    int dni;
    cout<<"INGRESE EL DNI: "<<endl;
    cin>>dni;
    cout<<"INGRESE LA FECHA: "<<endl;
    fechaux.Cargar();
    int pos;
    pos=arch.buscarDNI(dni);
    if(pos==-2){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    } else if(pos==-1){
        cout<<"NO HAY REGISTRO CON ESE DNI"<<endl;
        return false;
    } else {cout<<"REGISTRO ENCONTRADO"<<endl;}
    reg=arch.leerRegistroPos(pos);
    reg.setFechaInscripcion(fechaux);
    bool modifico=arch.modificarRegistro(pos,reg);
    return modifico;
}

bool bajaLogicaJugador(){
    ArchivoJugadores arch("Jugadores.dat");
    Jugador reg;
    int dni;
    cout<<"INGRESE EL DNI: "<<endl;
    cin>>dni;
    int pos;
    pos=arch.buscarDNI(dni);
    if(pos==-2){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    } else if(pos==-1){
        cout<<"NO HAY REGISTRO CON ESE DNI"<<endl;
        return false;
    } else {cout<<"REGISTRO ENCONTRADO"<<endl;}
    reg=arch.leerRegistroPos(pos);
    reg.setEstado(false);
    bool modifico=arch.modificarRegistro(pos, reg);
    return modifico;
}

#endif // SUBMENUJUGADORES_H_INCLUDED
