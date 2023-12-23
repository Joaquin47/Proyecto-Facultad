#ifndef CLSJUGADOR_H_INCLUDED
#define CLSJUGADOR_H_INCLUDED

class Jugador{
private:
    int DNI;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro;
    int deporte;
    int numEquipo;
    Fecha fechaInscripcion;
    float matricula;
    bool estado;
public:
    ///SETS
    void setDNI(int dni){DNI=dni;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido,a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setClaustro(int c){if(c>=1&&c<=4){claustro=c;}else{cout<<"CLAUSTRO INCORRECTO (1-4)"<<endl;}}
    void setDeporte(int d){if(d>=1&&d<=10){deporte=d;}}
    void setNumEquipo(int ne){numEquipo=ne;}
    void setFechaInscripcion(Fecha f){if(fechaEsPasada(f)){fechaInscripcion=f;}else {cout<<"LA FECHA INGRESADA ES INCORRECTA"<<endl;}}
    void setMatricula(float m){if(m>=0){matricula=m;}}
    void setEstado(bool e){estado=e;}
    ///GETS
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    const char *getTelefono(){return telefono;}
    int getClaustro(){return claustro;}
    int getDeporte(){return deporte;}
    int getNumEquipo(){return numEquipo;}
    Fecha getFechaInscripcion(){return fechaInscripcion;}
    float getMatricula(){return matricula;}
    bool getEstado(){return estado;}
    ///
    void Cargar(int ,int , int);
    void Mostrar();
};

void Jugador::Cargar(int dni=0, int iddeporte=-1, int idequipo=-1){
    int c;
    if(dni==0){
    cout<<"INGRESE EL DNI: "<<endl;
    cin>>DNI;
    } else {
        DNI=dni;
    }
    cout<<"INGRESE EL NOMBRE: "<<endl;
    cargarCadena(nombre,30);
    cout<<"INGRESE EL APELLIDO: "<<endl;
    cargarCadena(apellido,30);
    cout<<"INGRESE EL EMAIL: "<<endl;
    cargarCadena(email,30);
    cout<<"INGRESE EL TELEFONO: "<<endl;
    cargarCadena(telefono,30);
    cout<<"INGRESE EL CLAUSTRO: "<<endl;
    cin>>c;
    setClaustro(c);
    if(iddeporte==-1){
    cout<<"INGRESE EL ID DEL DEPORTE: "<<endl;
    cin>>deporte;
    } else {
        deporte=iddeporte;
    }
    if(idequipo==-1){
    cout<<"INGRESE EL NUMERO DEL EQUIPO: "<<endl;
    cin>>numEquipo;
    } else {
    numEquipo=idequipo;
    }
    do{
    cout<<"INGRESE LA FECHA: "<<endl;
    fechaInscripcion.Cargar();
    if(!fechaEsPasada(fechaInscripcion)){cout<<"LA FECHA INTRODUCIDA ES INCORRECTA"<<endl;}
    } while(!fechaEsPasada(fechaInscripcion));
    cout<<"INGRESE LA MATRICULA: "<<endl;
    cin>>matricula;
    estado=true;

}
void Jugador::Mostrar(){
    if(estado==true){
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;
    cout<<"CLAUSTRO: ";
    cout<<claustro<<endl;
    cout<<"DEPORTE: ";
    cout<<deporte<<endl;
    cout<<"NUMERO DE EQUIPO: ";
    cout<<numEquipo<<endl;
    cout<<"FECHA: ";
    fechaInscripcion.Mostrar();
    cout<<"MATRICULA: ";
    cout<<matricula<<endl;
}
}

class ArchivoJugadores{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char *nAr){
    strcpy(nombre, nAr);
    }
    int buscarDNI(int dni);
    bool agregarJugador(Jugador reg);
    void listarJugadores();
    Jugador leerRegistroPos(int pos);
    bool modificarRegistro(int pos, Jugador reg);
    int contarRegistros();
    int contarRegistrosDocentesconMatricula();
    int contarRegistroInscrito2022();
    int contarRegistrosDocentesYNo();
    };


int ArchivoJugadores::buscarDNI(int dni){
    Jugador reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return -2;
    }
    int cont=0;
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getDNI()==dni){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

bool ArchivoJugadores::agregarJugador(Jugador reg){
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

void ArchivoJugadores::listarJugadores(){
    Jugador reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
}

Jugador ArchivoJugadores::leerRegistroPos(int pos){
    Jugador reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof (Jugador)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool ArchivoJugadores::modificarRegistro(int pos, Jugador reg){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(Jugador)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int ArchivoJugadores::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return -2;
    }
    fseek(p,0,2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Jugador);
}
int ArchivoJugadores::contarRegistrosDocentesconMatricula(){
    FILE *p=fopen(nombre,"rb");
    Jugador reg;
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return -2;
    }
    int cant=0;
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getClaustro()==1&&reg.getMatricula()>0&&reg.getEstado()){
            cant++;
        }
    }
    fclose(p);
    return cant;
}

int ArchivoJugadores::contarRegistroInscrito2022(){
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return -2;
    }
    Jugador reg;
    int cant=0;
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getFechaInscripcion().getAnio()==2022&&reg.getEstado()){
            cant++;
        }
    }
    fclose(p);
    return cant;
}

int ArchivoJugadores::contarRegistrosDocentesYNo(){
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return -2;
    }
    Jugador reg;
    int cant=0;
    while(fread(&reg,sizeof reg,1,p)==1){
        if((reg.getClaustro()==1||reg.getClaustro()==3)&&reg.getEstado()){
            cant++;
        }
    }
    fclose(p);
    return cant;
}
#endif // CLSJUGADOR_H_INCLUDED
