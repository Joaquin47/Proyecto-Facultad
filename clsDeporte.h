#ifndef CLSDEPORTE_H_INCLUDED
#define CLSDEPORTE_H_INCLUDED

class Deporte{
private:
    int id;
    char nombre[30];
    int tipo;
    int anio;
    bool estado;
public:
    void Cargar(int id, int);
    void Mostrar();
    void setID(int i){id=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTipo(int t){if(t>=1&&t<=21){tipo=t;}}
    void setAnio(int a){Fecha actual;
    if(a>=1800&&a<actual.getAnio()){anio=a;}}
    void setEstado(bool e){estado=e;}
    int getID(){return id;}
    const char *getNombre(){return nombre;}
    int getTipo(){return tipo;}
    int getAnio(){return anio;}
    bool getEstado(){return estado;}
};

void Deporte::Cargar(int id, int tipo=-1){
    setID(id);
    int t, a;
    cout<<"INGRESE EL NOMBRE: ";
    cargarCadena(nombre,30);
    if(tipo==-1){
    cout<<"INGRESE EL TIPO DE DEPORTE: ";
    cin>> t;
    setTipo(t);
    }
    cout<<"INGRESE EL ANIO DE ORIGEN: ";
    cin>>a;
    setAnio(a);
    estado=true;
}

void Deporte::Mostrar(){
    if(estado==true){
        cout<<"ID: ";
        cout<<id<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"TIPO DE DEPORTE: ";
        cout<<tipo<<endl;
        cout<<"ANIO DE ORGIEN: ";
        cout<<anio<<endl;
    }
}

class ArchivoDeportes{
private:
    char nombre[30];
public:
    ArchivoDeportes(const char *nAr){
    strcpy(nombre,nAr);
    }
    int contarRegistros();
    bool agregarRegistroDeporte();
    int buscarID(int id);
    bool agregarDeporte(Deporte reg);
    void listarDeportes();
    Deporte leerRegistroPos(int pos);
    bool modificarRegistro(int pos, Deporte reg);
    bool estaDisponibleID(int id);
};

int ArchivoDeportes::contarRegistros(){

    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return -2;
    }
    fseek(p,0,2);
    int cant=ftell(p);
    return cant/sizeof(Deporte);
}
int ArchivoDeportes::buscarID(int id){
    Deporte reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return -2;
    }
    int cont=0;
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getID()==id){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

bool ArchivoDeportes::agregarDeporte(Deporte reg){
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

void ArchivoDeportes::listarDeportes(){
    Deporte reg;
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


Deporte ArchivoDeportes::leerRegistroPos(int pos){
    Deporte reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof (Deporte)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool ArchivoDeportes::modificarRegistro(int pos, Deporte reg){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(Deporte)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

bool ArchivoDeportes::estaDisponibleID(int id){
    Deporte reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Deporte),1,p)==1){
        if(id==reg.getID()&&reg.getEstado()==true){
            return true;
        }
    }
    fclose(p);
    return false;
}
#endif // CLSDEPORTE_H_INCLUDED
