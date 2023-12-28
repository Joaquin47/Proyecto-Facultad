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
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::cls();
        int y=0;
     while(true){
        int i;
        Punto obj(26,8, cMAGENTA_CLARO);
        for(i=26;i<77;i++){
            obj.Mostrar();
            obj.setX(i);
            }
        for(i=8;i<21;i++){
            obj.Mostrar();
            obj.setY(i);
        }
        for(i=76;i>25;i--){
            obj.setX(i);
            obj.Mostrar();
        }
        for(i=20;i>7;i--){
            obj.Mostrar();
            obj.setY(i);
        }

        rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
        showItem("          --MENU CONFIGURACION--           ", 30, 9, false);
        showItem("    COPIA DE SEGURIDAD ARCHIVO JUGADORES   ", 30, 10, y==0);
        showItem("    COPIA DE SEGURIDAD ARCHIVO DEPORTES    ", 30, 11, y==1);
        showItem("    COPIA DE SEGURIDAD ARCHIVO EQUIPOS     ", 30, 12, y==2);
        showItem("COPIA DE SEGURIDAD ARCHIVO TIPOS DE DEPORTE", 30, 13, y==3);
        showItem("            RESTAURAR JUGADORES            ", 30, 14, y==4);
        showItem("            RESTAURAR DEPORTES             ", 30, 15, y==5);
        showItem("            RESTAURAR EQUIPOS              ", 30, 16, y==6);
        showItem("         RESTAURAR TIPOS DE DEPORTE        ", 30, 17, y==7);
        showItem("         ESTABLECER DATOS DE INICIO        ", 30, 18, y==8);
        showItem("          VOLVER AL MENU PRINCIPAL         ", 30, 19, y==9);


        switch(rlutil::getkey()){
            case 14: //UP
                rlutil::locate(28,10+y);
                cout<<" "<<endl;
                y--;
                if(y<0){
                    y=0;
                }
                break;
            case 15: //DOWN
                rlutil::locate(28,10+y);
                cout<<" "<<endl;
                y++;
                if(y>9){
                    y=9;
                }
                break;
            case 1: //ENTER
                switch(y){
                case 0: system("cls");
                    copiaSeguridadJugadores();
                    pauseCls();
                    break;
                case 1: system("cls");
                    copiaSeguridadDeportes();
                    pauseCls();
                    break;
                case 2: system("cls");
                    copiaSeguridadEquipos();
                    pauseCls();
                    break;
                case 3: copiaSeguridadTiposdeDeporte();
                    break;
                case 4: restaurarJugadores();
                    break;
                case 5: restaurarDeportes();
                    break;
                case 6: restaurarEquipos();
                    break;
                case 7: system("cls");
                    restaurarTiposdeDeporte();
                    pauseCls();
                    break;
                case 8: system("cls");
                    establecerDatosInicio();
                    pauseCls();
                    break;
                case 9: system("cls");
                        return ;
                    break;
                default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
                }
        }
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
