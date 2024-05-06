#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED


class Fecha{
    private:
        int _dia, _mes, _anio;

    public:

        //Constructores

        Fecha(int dia=0, int mes=0, int anio=0)
        :_dia(0), _mes(0), _anio(0)
        {
            setDia(dia);
            setMes(mes);
            setAnio(anio);
        }

        //Sets
        void setDia(int d){if(d>=0 && d<32) _dia=d;}
        void setMes(int m){if(m>=0 && m<13)_mes=m;}
        void setAnio(int a){if(a>=0) _anio=a;}

        //Gets
        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}

        //Metodos
        void Cargar();
        void Mostrar();
        string toString(string formatoFecha);
        void fechaActual();
        bool fechaAnteriorIgualAlaActual();

        //sobrecarga de operadores
        bool operator <=(Fecha aux);

};

bool Fecha::operator<=(Fecha aux){
        if(_anio > aux.getAnio()){return false;}
        if(_anio ==aux.getAnio() && _mes > aux.getMes()){return false;}
        if(_anio ==aux.getAnio() && _mes == aux.getMes() && _dia > aux.getDia()){return false;}
        return true;
}

 void Fecha::Cargar(){
    int dia,mes,anio;
    cout<<"DIA: ";
    cin>>dia;
    setDia(dia);
    cout<<"MES: ";
    cin>>mes;
    setMes(mes);
    cout<<"ANIO: ";
    cin>>anio;
    setAnio(anio);
}

void Fecha::Mostrar(){
    cout<<this->toString("dd/mm/aaaa")<<endl;
}

string Fecha::toString(string formatoFecha){
    string fechaFormateada = "";

    string DD = to_string(_dia);
    string MM = to_string(_mes);
    string YYYY = to_string(_anio);
//     DD/MM/YYYY
    if (_dia < 10)
    {
        DD = "0" + to_string(_dia);
    }
    if (_mes < 10)
    {
        MM = "0" + to_string(_mes);
    }

    if (formatoFecha == "DD/MM/YYYY")
    {
        fechaFormateada = DD + "/" + MM + "/" + YYYY;
    }
    else if (formatoFecha == "YYYY/MM/DD")
    {
        fechaFormateada = YYYY + "/" + MM + "/" + DD;
    }
    else
    {
        fechaFormateada = DD + "/" + MM + "/" + YYYY;
    }

    return fechaFormateada;
}


void Fecha::fechaActual(){
    time_t tiempo=time(nullptr); //tiempo actual en milisegundos desde 1900
    tm* fechaActual= localtime(&tiempo);

    setDia(fechaActual->tm_mday);       //tm_mday ---> Dias del mes (1 - 31) tm_wday ---> dias de la semana (0-6), tm_yday ---> dias del anio(0, 365)
    setMes(fechaActual->tm_mon+1);
    setAnio(fechaActual->tm_year+1900);
}



#endif // CLASEFECHA_H_INCLUDED
