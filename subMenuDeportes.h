#ifndef SUBMENUDEPORTES_H_INCLUDED
#define SUBMENUDEPORTES_H_INCLUDED

bool agregarRegistroDeporte();
bool listarDeporteSegunID();
void listarDeportes();
bool modificarAnio();
bool bajaLogicaDeporte();

void subMenuDeportes(){
   while(true){
        int opc;
        system("cls");
        cout<<"MENU DEPORTES"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR DEPORTE"<<endl;
        cout<<"2) LISTAR DEPORTE POR ID"<<endl;
        cout<<"3) LISTAR TODOS LOS DEPORTES"<<endl;
        cout<<"4) MODIFICAR ANIO DE ORIGEN"<<endl;
        cout<<"5) ELIMINAR REGISTRO DE DEPORTE"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(agregarRegistroDeporte()){
            cout<<"REGISTRO AGREGADO"<<endl;
            } else {cout<<"NO SE HA PODIDO AGREGAR EL REGISTRO"<<endl;
            };
                break;
            case 2: if(!listarDeporteSegunID()){cout<<"NO HAY REGISTRO CON ESE ID"<<endl;}
                break;
            case 3: listarDeportes();
                break;
            case 4: if(modificarAnio()){
            cout<<"ARCHIVO MODIFICADO"<<endl;
            } else {cout<<"NO SE HA PODIDO MODIFICAR EL REGISTRO"<<endl;
            }
                break;
            case 5: if(bajaLogicaDeporte()){cout<<"SE HA DADO DE BAJA AL DEPORTE"<<endl;
            } else {cout<<"NO SE HA DADO DE BAJA AL DEPORTE"<<endl;
            }
                break;
            case 0: return ;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        system("pause");
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
