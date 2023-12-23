#ifndef SUBMENUTIPOSDEDEPORTE_H_INCLUDED
#define SUBMENUTIPOSDEDEPORTE_H_INCLUDED

bool agregarRegistroTipodeDeporte();
bool listarTipodeDeporteSegunID();
void listarTiposdeDeporte();
bool modificarTipodeDeporteNivel();
bool eliminarTipodeDeporte();

void subMenuTiposdeDeporte() {
    int opc;
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
