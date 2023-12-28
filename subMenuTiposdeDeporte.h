#ifndef SUBMENUTIPOSDEDEPORTE_H_INCLUDED
#define SUBMENUTIPOSDEDEPORTE_H_INCLUDED

bool agregarRegistroTipodeDeporte();
bool listarTipodeDeporteSegunID();
void listarTiposdeDeporte();
bool modificarTipodeDeporteNivel();
bool eliminarTipodeDeporte();

void subMenuTiposdeDeporte() {
   /* int opc;
    while(true){
        system("cls");
        cout<<"MENU EQUIPOS"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR TIPO DE DEPORTE"<<endl;
        cout<<"2) LISTAR TIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NIVEL DE DIFICULTAD"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(agregarRegistroTipodeDeporte()){
            cout<<"REGISTRO AGREGADO"<<endl;
            } else {cout<<"NO SE HA PODIDO AGREGAR EL REGISTRO"<<endl;
            };
                break;
            case 2: if(!listarTipodeDeporteSegunID()){cout<<"NO HAY REGISTRO CON ESE ID"<<endl;}
                break;
            case 3: listarTiposdeDeporte();
                break;
            case 4: if(modificarTipodeDeporteNivel()){cout<<"SE HA MODIFICADO EL NIVEL"<<endl;}else{cout<<"NO SE HA PODIDO MODIFICAR"<<endl;};
                break;
            case 5: eliminarTipodeDeporte();
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
}*/

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
                    if(agregarRegistroTipodeDeporte()){
                cout<<"REGISTRO AGREGADO"<<endl;
                } else {cout<<"NO SE HA PODIDO AGREGAR EL REGISTRO"<<endl;
                } pauseCls();
                break;
            case 1: system("cls");
                    if(!listarTipodeDeporteSegunID()){cout<<"NO HAY REGISTRO CON ESE ID"<<endl;}
                    pauseCls();
                break;
            case 2: system("cls");
                    listarTiposdeDeporte();
                    pauseCls();
                break;
            case 3: system("cls");
                    if(modificarTipodeDeporteNivel()){cout<<"SE HA MODIFICADO EL NIVEL"<<endl;}else{cout<<"NO SE HA PODIDO MODIFICAR"<<endl;}
                    pauseCls();
                break;
            case 4: system("cls");
                    eliminarTipodeDeporte();
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

bool agregarRegistroTipodeDeporte(){
    TipodeDeporte reg;
    ArchivoTiposdeDeporte arch("TipodeDeporte.dat");
    int id=arch.contarRegistros();
    id++;
    reg.Cargar(id);
    bool agrego=arch.agregarTipodeDeporte(reg);
    return agrego;
}

bool listarTipodeDeporteSegunID(){
    int id;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    TipodeDeporte reg;
    ArchivoTiposdeDeporte arch("TipodeDeporte.dat");
    FILE *p;
    p=fopen("TipodeDeporte.dat","rb");
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

void listarTiposdeDeporte(){
    ArchivoTiposdeDeporte arch("TipodeDeporte.dat");
    arch.listarTiposdeDeporte();
}


bool modificarTipodeDeporteNivel(){
    ArchivoTiposdeDeporte arch("TipodeDeporte.dat");
    int nivel;
    TipodeDeporte reg;
    int id;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    cout<<"INGRESE EL NUEVO NIVEL: "<<endl;
    cin>>nivel;
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
    reg.setNivel(nivel);
    bool modifico=arch.modificarRegistro(pos,reg);
    return modifico;
}



bool eliminarTipodeDeporte(){
    ArchivoTiposdeDeporte arch("TipodeDeporte.dat");
    TipodeDeporte reg;
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


#endif // SUBMENUTIPOSDEDEPORTE_H_INCLUDED
