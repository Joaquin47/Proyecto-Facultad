#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
private:
    int _day;
    int _month;
    int _year;
public:
    Fecha(){
    time_t tiempo = time(nullptr);
    tm* fecha = localtime(&tiempo);

    setDia(fecha->tm_mday);
    setMes(fecha->tm_mon + 1);
    setAnio(fecha->tm_year + 1900);
    }
    Fecha(int day, int month, int year){
    setDia(day);
    setMes(month);
    setAnio(year);
    }
    bool setDia(int d){if(d>=1&&d<=31){
        _day=d;
        return true;
    } else {
        return false;
    }}
    bool setMes(int mo){if(mo>=1&&mo<=12){
        _month=mo;
        return true;
    } else {
        return false;
    }}
    bool setAnio(int y){if(y>=1){
        _year=y;
        return true;
    } else {
        return false;
    }}
    int getAnio(){return _year;}
    int getMes(){return _month;}
    int getDia(){return _day;}
    void Cargar();
    void Mostrar();
};

void Fecha::Cargar(){
    int d, m, y;
    do{
    cout<<"INGRESE EL DIA: "<<endl;
    cin>>d;
    bool valord=setDia(d);
    if(!valord){cout<<"DIA INCORRECTO"<<endl;}
    } while(!setDia(d));
    do{
    cout<<"INGRESE EL MES: "<<endl;
    cin>>m;
    bool valorm=setMes(m);
    if(!valorm){cout<<"MES INCORRECTO"<<endl;}
    } while(!setMes(m));
    do{
    cout<<"INGRESE EL ANIO: "<<endl;
    cin>>y;
    bool valory=setAnio(y);
    if(!valory){cout<<"ANIO INCORRECTO"<<endl;}
    } while(!setAnio(y));
}
void Fecha::Mostrar(){
    cout<<_day<<"/"<<_month<<"/"<<_year<<endl;
}

#endif // CLSFECHA_H_INCLUDED
