#ifndef CLSTIPODEDEPORTE_H_INCLUDED
#define CLSTIPODEDEPORTE_H_INCLUDED

class TipodeDeporte{
private:
    int ID;
    char nombre[30];
    int nivel;
    bool estado;
public:
   ///SETS
   void setID(int id){ID=id;}
   void setNombre(const char *n){strcpy(nombre,n);}
   void setNivel(int niv){if(niv>=1&&niv<=8){nivel=niv;}}
   void setEstado(bool t){estado=t;}
   ///GETS
   int getID(){return ID;}
   const char *getNombre(){return nombre;}
   int getNivel(){return nivel;}
   bool getEstado(){return estado;}
   ///METODOS
   void Cargar(int id);
   void Mostrar();
};

void TipodeDeporte::Cargar(int id){
    ID=id;
   cout<<"INGRESE EL NOMBRE: "<<endl;
   cargarCadena(nombre,30);
   cout<<"INGRESE EL NIVEL: (1-8)"<<endl;
   cin>>nivel;
   estado=true;
}
void TipodeDeporte::Mostrar(){
    if(estado){
        cout<<"ID: ";
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"NIVEL DE DIFICULTAD: ";
        cout<<nivel<<endl;
    }
}

class ArchivoTiposdeDeporte{
private:
    char nombre[30];
public:
    ArchivoTiposdeDeporte(const char *n){
    strcpy(nombre,n);
    }
    int contarRegistros();
    bool agregarTipodeDeporte(TipodeDeporte reg);
    void listarTiposdeDeporte();
    int buscarID(int id);
    TipodeDeporte leerRegistroPos(int pos);
    bool modificarRegistro(int pos, TipodeDeporte reg);
    bool estaDisponibleTipo(int id);
};

int ArchivoTiposdeDeporte::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return -2;
    }
    fseek(p,0,2);
    int tam=ftell(p);
    return tam/sizeof (TipodeDeporte);
}

bool ArchivoTiposdeDeporte::agregarTipodeDeporte(TipodeDeporte reg){
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

void ArchivoTiposdeDeporte::listarTiposdeDeporte(){
    TipodeDeporte reg;
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

int ArchivoTiposdeDeporte::buscarID(int id){
    TipodeDeporte reg;
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

TipodeDeporte ArchivoTiposdeDeporte::leerRegistroPos(int pos){
    TipodeDeporte reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof (TipodeDeporte)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool ArchivoTiposdeDeporte::modificarRegistro(int pos, TipodeDeporte reg){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(TipodeDeporte)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

bool ArchivoTiposdeDeporte::estaDisponibleTipo(int tipo){
    TipodeDeporte reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg,sizeof(TipodeDeporte),1,p)==1){
        if(tipo==reg.getID()&&reg.getEstado()==true){
            return true;
        }
    }
    fclose(p);
    return false;
}

#endif // CLSTIPODEDEPORTE_H_INCLUDED
