#ifndef SUBMENUEQUIPOS_H_INCLUDED
#define SUBMENUEQUIPOS_H_INCLUDED

bool agregarRegistroEquipo();
bool listarEquipoSegunID();
void listarEquipos();
bool modificarEquipoNombre();
bool eliminarEquipo();

void subMenuEquipos() {
    int opc;
    while(true){
        system("cls");
        cout<<"MENU EQUIPOS"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR EQUIPO"<<endl;
        cout<<"2) LISTAR EQUIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NOMBRE"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(agregarRegistroEquipo()){
            cout<<"REGISTRO AGREGADO"<<endl;
            } else {cout<<"NO SE HA PODIDO AGREGAR EL REGISTRO"<<endl;
            };
                break;
            case 2: if(!listarEquipoSegunID()){cout<<"NO HAY REGISTRO CON ESE ID"<<endl;}
                break;
            case 3: listarEquipos();
                break;
            case 4: if(modificarEquipoNombre()){cout<<"SE HA MODIFICADO EL NOMBRE"<<endl;}else{cout<<"NO SE HA PODIDO MODIFICAR"<<endl;};
                break;
            case 5: eliminarEquipo();
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
