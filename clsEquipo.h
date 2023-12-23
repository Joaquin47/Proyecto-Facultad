#ifndef CLSEQUIPO_H_INCLUDED
#define CLSEQUIPO_H_INCLUDED

class Equipo{
private:
    int ID;
    char nombre[30];
    int nivel;
    bool estado;
public:
   ///SETS
   void setID(int id){ID=id;}
   void setNombre(const char *n){strcpy(nombre,n);}
   void setNivel(int niv){if(niv>=1&&niv<=3){nivel=niv;}}
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

void Equipo::Cargar(int id){
    ID=id;
   cout<<"INGRESE EL NOMBRE: "<<endl;
   cargarCadena(nombre,30);
   cout<<"INGRESE EL NIVEL: (1-3)"<<endl;
   cin>>nivel;
   estado=true;
}
void Equipo::Mostrar(){
    if(estado){
        cout<<"ID: ";
        cout<<ID<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"NIVEL: ";
        cout<<nivel<<endl;
    }
}

class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(const char *n){
    strcpy(nombre,n);
    }
    int contarRegistros();
    bool agregarEquipo(Equipo reg);
    void listarEquipos();
    int buscarID(int id);
    Equipo leerRegistroPos(int pos);
    bool modificarRegistro(int pos, Equipo reg);
    bool estaDisponibleIDEquipo(int id);
};

int ArchivoEquipos::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return -2;
    }
    fseek(p,0,2);
    int tam=ftell(p);
    return tam/sizeof (Equipo);
}

bool ArchivoEquipos::agregarEquipo(Equipo reg){
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

void ArchivoEquipos::listarEquipos(){
    Equipo reg;
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

int ArchivoEquipos::buscarID(int id){
    Equipo reg;
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

Equipo ArchivoEquipos::leerRegistroPos(int pos){
    Equipo reg;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof (Equipo)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool ArchivoEquipos::modificarRegistro(int pos, Equipo reg){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR CON EL ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(Equipo)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

bool ArchivoEquipos::estaDisponibleIDEquipo(int id){
    Equipo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Equipo),1,p)==1){
        if(id==reg.getID()&&reg.getEstado()==true){
            return true;
        }
    }
    fclose(p);
    return false;
}
#endif // CLSEQUIPO_H_INCLUDED
