#ifndef SUBMENUJUGADORES_H_INCLUDED
#define SUBMENUJUGADORES_H_INCLUDED

bool agregarRegistroJugador();
bool listarJugadoresSegunDNI();
void listarJugadores();
bool modificarFecha();
bool bajaLogicaJugador();


void subMenuJugadores() {
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::cls();
        int y=0;
     while(true){
        int i;
        Punto obj(26,8, cMAGENTA_CLARO);
        for(i=26;i<64;i++){
            obj.Mostrar();
            obj.setX(i);
            }
        for(i=8;i<17;i++){
            obj.Mostrar();
            obj.setY(i);
        }
        for(i=63;i>25;i--){
            obj.setX(i);
            obj.Mostrar();
        }
        for(i=16;i>7;i--){
            obj.Mostrar();
            obj.setY(i);
        }

        rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
        showItem("      --MENU JUGADORES--      ", 30, 9, false);
        showItem("       AGREGAR JUGADOR        ", 30, 10, y==0);
        showItem("    LISTAR JUGADOR POR DNI    ", 30, 11, y==1);
        showItem("  LISTAR TODOS LOS JUGADORES  ", 30, 12, y==2);
        showItem("MODIFICAR FECHA DE INSCRIPCION", 30, 13, y==3);
        showItem("  ELIMINAR REGISTRO DE JUGADOR", 30, 14, y==4);
        showItem("   VOLVER AL MENU PRINCIPAL   ", 30, 15, y==5);


        switch(rlutil::getkey()){
            case 14: //UP
                rlutil::locate(28,10+y);
                cout<<" "<<endl;
                y--;
                if(y<0){
                    y=5;
                }
                break;
            case 15: //DOWN
                rlutil::locate(28,10+y);
                cout<<" "<<endl;
                y++;
                if(y>5){
                    y=0;
                }
                break;
            case 1: //ENTER
                switch(y){
                case 0: system("cls");
                        if(agregarRegistroJugador()){
                    cout<<"REGISTRO AGREGADO"<<endl;
                    } else {cout<<"NO SE HA PODIDO AGREGAR EL REGISTRO"<<endl;
                    } pauseCls();
                    break;
                case 1: system("cls");
                        if(!listarJugadoresSegunDNI()){cout<<"NO HAY REGISTRO CON ESE DNI"<<endl;}
                        pauseCls();
                    break;
                case 2: system("cls");
                        listarJugadores();
                        pauseCls();
                    break;
                case 3: system("cls");
                    if(modificarFecha()){
                cout<<"ARCHIVO MODIFICADO"<<endl;
                } else {cout<<"NO SE HA PODIDO MODIFICAR EL REGISTRO"<<endl;
                }  pauseCls();
                    break;
                case 4: system("cls");
                        if(bajaLogicaJugador()){cout<<"SE HA DADO DE BAJA AL JUGADOR"<<endl;
                    } else {cout<<"NO SE HA DADO DE BAJA AL JUGADOR"<<endl;
                    } pauseCls();
                    break;
                case 5: system("cls");
                        return ;
                    break;
                }
                break;
            default:
                break;
            }
    }
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
