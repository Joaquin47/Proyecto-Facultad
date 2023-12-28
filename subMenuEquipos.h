#ifndef SUBMENUEQUIPOS_H_INCLUDED
#define SUBMENUEQUIPOS_H_INCLUDED

bool agregarRegistroEquipo();
bool listarEquipoSegunID();
void listarEquipos();
bool modificarEquipoNombre();
bool eliminarEquipo();

void subMenuEquipos() {
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::cls();
        int y=0;
     while(true){
        int i;
        Punto obj(26,8, cMAGENTA_CLARO);
        for(i=26;i<61;i++){
            obj.Mostrar();
            obj.setX(i);
            }
        for(i=8;i<17;i++){
            obj.Mostrar();
            obj.setY(i);
        }
        for(i=60;i>25;i--){
            obj.setX(i);
            obj.Mostrar();
        }
        for(i=16;i>7;i--){
            obj.Mostrar();
            obj.setY(i);
        }

        rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
        showItem("      --MENU EQUIPOS--     ", 30, 9, false);
        showItem("       AGREGAR EQUIPO      ", 30, 10, y==0);
        showItem("    LISTAR EQUIPO POR ID   ", 30, 11, y==1);
        showItem("  LISTAR TODOS LOS EQUIPOS ", 30, 12, y==2);
        showItem("     MODIFICAR NOMBRE      ", 30, 13, y==3);
        showItem("     ELIMINAR REGISTRO     ", 30, 14, y==4);
        showItem("  VOLVER AL MENU PRINCIPAL ", 30, 15, y==5);


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
                        if(agregarRegistroEquipo()){
                    cout<<"REGISTRO AGREGADO"<<endl;
                    } else {cout<<"NO SE HA PODIDO AGREGAR EL REGISTRO"<<endl;
                    } pauseCls();
                    break;
                case 1: system("cls");
                        if(!listarEquipoSegunID()){cout<<"NO HAY REGISTRO CON ESE ID"<<endl;}
                        pauseCls();
                    break;
                case 2: system("cls");
                        listarEquipos();
                        pauseCls();
                    break;
                case 3: system("cls");
                        if(modificarEquipoNombre()){cout<<"SE HA MODIFICADO EL NOMBRE"<<endl;}
                        else{
                        cout<<"NO SE HA PODIDO MODIFICAR"<<endl;
                        } pauseCls();
                    break;
                case 4: system("cls");
                        eliminarEquipo();
                        pauseCls();
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

bool agregarRegistroEquipo(){
    Equipo reg;
    ArchivoEquipos arch("Equipos.dat");
    int id=arch.contarRegistros();
    id++;
    reg.Cargar(id);
    bool agrego=arch.agregarEquipo(reg);
    return agrego;
}

bool listarEquipoSegunID(){
    int id;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    Equipo reg;
    ArchivoEquipos arch("Equipos.dat");
    FILE *p;
    p=fopen("Equipos.dat","rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(id==reg.getID()){
            reg.Mostrar();
            return true;
        }
    }
    fclose(p);
    return false;
}

void listarEquipos(){
    ArchivoEquipos arch("Equipos.dat");
    arch.listarEquipos();
}


bool modificarEquipoNombre(){
    ArchivoEquipos arch("Equipos.dat");
    char nombreaux[30];
    Equipo reg;
    int id;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    cout<<"INGRESE EL NUEVO NOMBRE: "<<endl;
    cargarCadena(nombreaux,30);
    int pos;
    pos=arch.buscarID(id);
    if(pos==-2){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    } else if(pos==-1){
        cout<<"NO HAY REGISTRO CON ESE ID"<<endl;
        return false;
    } else {cout<<"REGISTRO ENCONTRADO"<<endl;}
    reg=arch.leerRegistroPos(pos);
    reg.setNombre(nombreaux);
    bool modifico=arch.modificarRegistro(pos,reg);
    return modifico;
}



bool eliminarEquipo(){
    ArchivoEquipos arch("Equipos.dat");
    Equipo reg;
    int id;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    int pos;
    pos=arch.buscarID(id);
    if(pos==-2){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    } else if(pos==-1){
        cout<<"NO HAY REGISTRO CON ESE ID"<<endl;
        return false;
    } else {cout<<"REGISTRO ENCONTRADO"<<endl;}
    reg=arch.leerRegistroPos(pos);
    reg.setEstado(false);
    bool modifico=arch.modificarRegistro(pos, reg);
    return modifico;
}


#endif // SUBMENUEQUIPOS_H_INCLUDED
