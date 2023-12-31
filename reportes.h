#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void Ejercicio1();
void Ejercicio2();
void Ejercicio3();

void reportes() {
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::cls();
        int y=0;
     while(true){
        int i;
        Punto obj(26,8, cMAGENTA_CLARO);
        for(i=26;i<84;i++){
            obj.Mostrar();
            obj.setX(i);
            }
        for(i=8;i<15;i++){
            obj.Mostrar();
            obj.setY(i);
        }
        for(i=83;i>25;i--){
            obj.setX(i);
            obj.Mostrar();
        }
        for(i=14;i>7;i--){
            obj.Mostrar();
            obj.setY(i);
        }

        rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
        showItem("                 --MENU REPORTES-                 ", 30, 9, false);
        showItem("    EQUIPOS CON TODOS SUS INTEGRANTES DOCENTES    ", 30, 10, y==0);
        showItem("INFORMAR EL/LOS CLAUSTRO/S CON MAS DE 15 JUGADORES", 30, 11, y==1);
        showItem("             PUNTO 2 CON VECTOR DINAMICO          ", 30, 12, y==2);
        showItem("              VOLVER AL MENU PRINCIPAL            ", 30, 13, y==3);

        switch(rlutil::getkey()){
            case 14: //UP
                rlutil::locate(28,10+y);
                cout<<" "<<endl;
                y--;
                if(y<0){
                    y=3;
                }
                break;
            case 15: //DOWN
                rlutil::locate(28,10+y);
                cout<<" "<<endl;
                y++;
                if(y>3){
                    y=0;
                }
                break;
            case 1: //ENTER
                switch(y){
                case 0: system("cls");
                        Ejercicio1();
                        pauseCls();
                    break;
                case 1: system("cls");
                        Ejercicio2();
                        pauseCls();
                    break;
                case 2: system("cls");
                        Ejercicio3();
                        pauseCls();
                    break;
                case 3: system("cls");
                        return ;
                    break;
                }
                break;
            default:
                break;
        }
}
}

class Punto1{
 private:
    int ID;
    char nombreEquipo[30];
    int cantIntegrantes;
    bool estado;
 public:
    int getID(){return ID;}
    void setID(int id){ID=id;}
    void setNombreEquipo(const char *n){strcpy(nombreEquipo,n);}
    void setCantIntegrantes(int cant){cantIntegrantes=cant;}
    void setEstado(bool b){estado=b;}
    void Mostrar(){
    cout<<"ID: ";
    cout<<ID<<endl;
    cout<<"NOMBRE DEL EQUIPO: ";
    cout<<nombreEquipo<<endl;
    cout<<"CANTIDAD DE INTEGRANTES: ";
    cout<<cantIntegrantes<<endl;
    }
};

class ArchivoPunto1{
private:
    char nombre[30];
public:
    ArchivoPunto1(const char *n){
    strcpy(nombre,n);
    }
    Punto1 leerRegistro(int pos){
        Punto1 reg;
        reg.setEstado(0);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }
    bool grabarRegistro(Punto1 reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

};

bool estaEnArchivoPunto1(Punto1 a1){
    FILE *p=fopen("Ejercicio1.dat","rb");
    if(p==NULL){

    }
    Punto1 reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        if(a1.getID()==reg.getID()){
            fclose(p);
            return true;
        }
    }
    fclose(p);
return false;
}

void Ejercicio1(){
    ArchivoJugadores arcJug("Jugadores.dat");
    int tamJugadores=arcJug.contarRegistros();
    Jugador jug;
    ArchivoEquipos arcEquip("Equipos.dat");
    int tamEquipos=arcEquip.contarRegistros();
    Equipo equip;
    int *vIntegrantes;
    vIntegrantes=new int[tamEquipos];
    if(vIntegrantes==NULL){
        cout<<"ERROR EN LA ASIGNACION DE MEMORIA"<<endl;
    }
    int i, j;
    for(i=0;i<tamEquipos;i++){
        vIntegrantes[i]=0;
    }
    for(i=0;i<tamJugadores;i++){
        jug=arcJug.leerRegistroPos(i);
        if(jug.getEstado()){
            vIntegrantes[jug.getNumEquipo()-1]++;
        }
    }
    bool *vDocentes;
    vDocentes=new bool[tamEquipos];
    if(vDocentes==NULL){
        cout<<"ERROR EN LA ASIGNACION DE MEMORIA"<<endl;
    }
    for(i=0;i<tamEquipos;i++){
        vDocentes[i]=true;
    }
    for(i=0;i<tamEquipos;i++){
        equip=arcEquip.leerRegistroPos(i);
        for(j=0;j<tamJugadores;j++){
            jug=arcJug.leerRegistroPos(j);
                if(equip.getID()==jug.getNumEquipo()&&jug.getClaustro()!=1&&jug.getEstado()&&equip.getEstado()){
                vDocentes[equip.getID()-1]=false;
        }
    }
}
    ArchivoPunto1 arcPunto1("Ejercicio1.dat");
    Punto1 punto1;
    for(i=0;i<tamEquipos;i++){
        equip=arcEquip.leerRegistroPos(i);
        if(vDocentes[equip.getID()-1]&&vIntegrantes[equip.getID()-1]!=0){
            punto1.setID(equip.getID());
            punto1.setNombreEquipo(equip.getNombre());
            punto1.setCantIntegrantes(vIntegrantes[equip.getID()-1]);
            punto1.setEstado(true);
            if(!estaEnArchivoPunto1(punto1)){
            arcPunto1.grabarRegistro(punto1);
        }
    }
}
    int tamPunto1=arcPunto1.contarRegistros();
    for(i=0;i<tamPunto1;i++){
        punto1=arcPunto1.leerRegistro(i);
        punto1.Mostrar();
        cout<<endl;
    }

delete []vDocentes;
delete []vIntegrantes;
}

void Ejercicio2(){
    ArchivoJugadores arcJug("Jugadores.dat");
    int tamJugadores=arcJug.contarRegistros();
    int i;
    Jugador jug;
    int vClaustros[4]={0};
    for(i=0;i<tamJugadores;i++){
        jug=arcJug.leerRegistroPos(i);
        if(jug.getEstado()){
            vClaustros[jug.getClaustro()-1]++;
        }
    }
    cout<<"EL/LOS CLAUSTRO/S CON MAS DE 15 JUGADORES"<<endl;
    for(i=0;i<4;i++){
    if(vClaustros[i]>15){
        cout<<endl;
        cout<<"CLAUSTRO: "<<i+1<<endl;
    }
    }
}

void Ejercicio3(){
    ArchivoJugadores arcJug("Jugadores.dat");
    int tamJugadores=arcJug.contarRegistros();
    int i;
    Jugador jug;
    int claustroMax;
    for(i=0;i<tamJugadores;i++){
        jug=arcJug.leerRegistroPos(i);
        if(jug.getEstado()&&claustroMax<jug.getClaustro()){
            claustroMax=jug.getClaustro();
        }
    }
    int *vClaustros;
    vClaustros=new int[claustroMax];
    if(vClaustros==NULL){
        cout<<"ERROR EN LA ASIGNACION DE MEMORIA"<<endl;
    }
    for(i=0;i<claustroMax;i++){
        vClaustros[i]=0;
    }
    for(i=0;i<tamJugadores;i++){
        jug=arcJug.leerRegistroPos(i);
        if(jug.getEstado()){
            vClaustros[jug.getClaustro()-1]++;
        }
    }
    cout<<"EL/LOS CLAUSTRO/S CON MAS DE 15 JUGADORES"<<endl;
    for(i=0;i<4;i++){
    if(vClaustros[i]>15){
        cout<<endl;
        cout<<"CLAUSTRO: "<<i+1<<endl;
    }
    }
    delete []vClaustros;
}


#endif // REPORTES_H_INCLUDED
