#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

void copiaSeguridadJugadores();
void copiaSeguridadDeportes();
void copiaSeguridadEquipos();
void copiaSeguridadTiposdeDeporte();
void restaurarDeportes();
void restaurarJugadores();
void restaurarEquipos();
void restaurarTiposdeDeporte();
void establecerDatosInicio();

void subMenuConfiguracion(){
      int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO JUGADORES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DEPORTES"<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO EQUIPOS"<<endl;
        cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO TIPOS DE DEPORTE"<<endl;
        cout<<"5) RESTAURAR JUGADORES"<<endl;
        cout<<"6) RESTAURAR DEPORTES"<<endl;
        cout<<"7) RESTAURAR EQUIPOS"<<endl;
        cout<<"8) RESTAURAR TIPOS DE DEPORTE"<<endl;
        cout<<"9) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: copiaSeguridadJugadores();
                break;
            case 2: copiaSeguridadDeportes();
                break;
            case 3: copiaSeguridadEquipos();
                break;
            case 4: copiaSeguridadTiposdeDeporte();
                break;
            case 5: restaurarJugadores();
                break;
            case 6: restaurarDeportes();
                break;
            case 7: restaurarEquipos();
                break;
            case 8: restaurarTiposdeDeporte();
                break;
            case 9: establecerDatosInicio();
                break;
            case 0: return ;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        system("pause");
    }
}
void copiaSeguridadJugadores(){
    FILE *p=fopen("Jugadores.bkp","wb");
    fclose(p);
    system("copy Jugadores.dat Jugadores.bkp");
}

void copiaSeguridadDeportes(){
    FILE *p=fopen("Deportes.bkp","wb");
    fclose(p);
    system("copy Deportes.dat Deportes.bkp");
}

void copiaSeguridadEquipos(){
    FILE *p=fopen("Equipos.bkp","wb");
    fclose(p);
    system("copy Equipos.dat Equipos.bkp");
}

void copiaSeguridadTiposdeDeporte(){
    FILE *p=fopen("TipodeDeporte.bkp","wb");
    fclose(p);
    system("copy TipodeDeporte.dat TipodeDeporte.bkp");
}

void restaurarJugadores(){
    FILE *j=fopen("Jugadores.dat","wb");
    FILE *jb=fopen("Jugadores.bkp","rb");
    Jugador reg;
    while(fread(&reg,sizeof(Jugador),1,jb)==1){
        if(reg.getEstado()==true){
            fwrite(&reg,sizeof(Jugador),1,j);
        }
    }
}

void restaurarDeportes(){
    FILE *d=fopen("Deportes.dat","wb");
    FILE *db=fopen("Deportes.bkp","rb");
    Deporte reg;
    while(fread(&reg,sizeof(Deporte),1,db)==1){
        if(reg.getEstado()==true){
            fwrite(&reg,sizeof(Deporte),1,d);
        }
    }
}

void restaurarEquipos(){
    FILE *j=fopen("Equipos.dat","wb");
    FILE *jb=fopen("Equipos.bkp","rb");
    Equipo reg;
    while(fread(&reg,sizeof(Equipo),1,jb)==1){
        if(reg.getEstado()==true){
            fwrite(&reg,sizeof(Equipo),1,j);
        }
    }
}

void restaurarTiposdeDeporte(){
    FILE *j=fopen("TipodeDeporte.dat","wb");
    FILE *jb=fopen("TipodeDeporte.bkp","rb");
    TipodeDeporte reg;
    while(fread(&reg,sizeof(TipodeDeporte),1,jb)==1){
        if(reg.getEstado()==true){
            fwrite(&reg,sizeof(TipodeDeporte),1,j);
        }
    }
}

void establecerDatosInicio(){
    FILE *ji;
    FILE *j;
    ji=fopen("Jugadoresinicio.dat","rb");
    if(ji==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    j=fopen("Jugadores.dat","wb");
    if(j==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    Jugador jug;
    while(fread(&jug,sizeof(Jugador),1,ji)==1){
        if(jug.getEstado()){
            fwrite(&jug,sizeof(Jugador),1,j);
        }
    }
    fclose(ji);
    fclose(j);

    FILE *d;
    FILE *di;
    di=fopen("Deportesinicio.dat","rb");
    if(di==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    d=fopen("Deportes.dat","wb");
    if(d==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    Deporte dep;
    while(fread(&dep,sizeof(Deporte),1,di)==1){
        if(dep.getEstado()){
            fwrite(&dep,sizeof(Deporte),1,d);
        }
    }
    fclose(di);
    fclose(d);

    FILE *e;
    FILE *ei;
    ei=fopen("Equiposinicio.dat","rb");
    if(ei==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    e=fopen("Equipos.dat","wb");
    if(e==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    Equipo equi;
    while(fread(&equi,sizeof(Equipo),1,ei)==1){
        if(equi.getEstado()){
            fwrite(&equi,sizeof(Equipo),1,e);
        }
    }
    fclose(ei);
    fclose(e);

    FILE *td;
    FILE *tdi;
    tdi=fopen("TipodeDeporteinicio.dat","rb");
    if(tdi==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    td=fopen("TipodeDeporte.dat","wb");
    if(td==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }
    TipodeDeporte tipo;
    while(fread(&tipo,sizeof(TipodeDeporte),1,tdi)==1){
        if(tipo.getEstado()){
            fwrite(&tipo,sizeof(TipodeDeporte),1,td);
        }
    }
    fclose(tdi);
    fclose(td);

    cout<<"DATOS DE INICIO ESTABLECIDOS CORRECTAMENTE"<<endl;
}
#endif // SUBMENUCONFIGURACION_H_INCLUDED
