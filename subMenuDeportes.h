#ifndef SUBMENUDEPORTES_H_INCLUDED
#define SUBMENUDEPORTES_H_INCLUDED

bool agregarRegistroDeporte();
bool listarDeporteSegunID();
void listarDeportes();
bool modificarAnio();
bool bajaLogicaDeporte();

void subMenuDeportes(){
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::cls();
        int y=0;
     while(true){
        int i;
        Punto obj(26,8, cMAGENTA_CLARO);
        for(i=26;i<62;i++){
            obj.Mostrar();
            obj.setX(i);
            }
        for(i=8;i<17;i++){
            obj.Mostrar();
            obj.setY(i);
        }
        for(i=61;i>25;i--){
            obj.setX(i);
            obj.Mostrar();
        }
        for(i=16;i>7;i--){
            obj.Mostrar();
            obj.setY(i);
        }

        rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
        showItem("      --MENU DEPORTES--     ", 30, 9, false);
        showItem("       AGREGAR DEPORTE      ", 30, 10, y==0);
        showItem("    LISTAR DEPORTE POR ID   ", 30, 11, y==1);
        showItem("  LISTAR TODOS LOS DEPORTES ", 30, 12, y==2);
        showItem("  MODIFICAR ANIO DE ORIGEN  ", 30, 13, y==3);
        showItem("ELIMINAR REGISTRO DE DEPORTE", 30, 14, y==4);
        showItem("  VOLVER AL MENU PRINCIPAL  ", 30, 15, y==5);


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
                            if(agregarRegistroDeporte()){
                    cout<<"REGISTRO AGREGADO"<<endl;
                    } else {cout<<"NO SE HA PODIDO AGREGAR EL REGISTRO"<<endl;
                    } pauseCls();
                    break;
                case 1: system("cls");
                        if(!listarDeporteSegunID()){cout<<"NO HAY REGISTRO CON ESE ID"<<endl;}
                        pauseCls();
                    break;
                case 2: system("cls");
                        listarDeportes();
                        pauseCls();
                    break;
                case 3: system("cls");
                        if(modificarAnio()){
                    cout<<"ARCHIVO MODIFICADO"<<endl;
                    } else {cout<<"NO SE HA PODIDO MODIFICAR EL REGISTRO"<<endl;
                    } pauseCls();
                    break;
                case 4: system("cls");
                        if(bajaLogicaDeporte()){cout<<"SE HA DADO DE BAJA AL DEPORTE"<<endl;
                    } else {cout<<"NO SE HA DADO DE BAJA AL DEPORTE"<<endl;
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

bool agregarRegistroDeporte(){
    Deporte reg;
    ArchivoDeportes arch("Deportes.dat");
    ArchivoTiposdeDeporte archTD("TipodeDeporte.dat");
    int tipo;
    cout<<"INGRESE EL TIPO DE DEPORTE: "<<endl;
    cin>>tipo;
    if(!archTD.estaDisponibleTipo(tipo)){
        cout<<"EL TIPO NO CORRESPONDE A UN TIPO DE DEPORTE O EL TIPO DE DEPORTE SE ENCUENTRA DESHABILITADO"<<endl;
        return false;
    }
    int id=arch.contarRegistros();
    id++;
    reg.Cargar(id,tipo);
    bool agrego=arch.agregarDeporte(reg);
    return agrego;
}

bool listarDeporteSegunID(){
    int id;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    Deporte reg;
    ArchivoDeportes arch("Deportes.dat");
    FILE *p;
    p=fopen("Deportes.dat","rb");
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

void listarDeportes(){
    ArchivoDeportes arch("Deportes.dat");
    arch.listarDeportes();
}

bool modificarAnio(){
    ArchivoDeportes arch("Deportes.dat");
    int anioaux;
    Deporte reg;
    int id;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    cout<<"INGRESE EL ANIO: "<<endl;
    cin>>anioaux;
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
    reg.setAnio(anioaux);
    bool modifico=arch.modificarRegistro(pos,reg);
    return modifico;
}

bool bajaLogicaDeporte(){
    ArchivoDeportes arch("Deportes.dat");
    Deporte reg;
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

#endif // SUBMENUDEPORTES_H_INCLUDED
