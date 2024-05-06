#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

//                JUGADOR

class Jugador{
private:
    int _dni;
    char _nombre[30];
    char _apellido[30];
    char _email[30];
    char _tel[30];
    int _claustro;
    int _deporte;
    int _nroEquipo;
    Fecha _fechaInscripcion;
    float _matricula;
    bool _estado;

public:
    //Constructor
    Jugador(){
        _claustro=0;
        _deporte=0;
        _matricula=-1;
        _estado=true;
    }

    //Sets
    void setDni(const int dni){_dni=dni;}
    void setClaustro(const int claustro){if(claustro>=1 && claustro<=4) _claustro=claustro;}
    void setDeporte(const int deporte){if(deporte>=0 && deporte<=10) _deporte=deporte;}
    void setFechaInscripcion(Fecha fechaInscripcion){
        Fecha fActual;
        fActual.fechaActual();
        if(fechaInscripcion <= fActual){
            _fechaInscripcion=fechaInscripcion;
        }
    }
    void setMatricula(const float matricula){if(matricula >= 0) _matricula=matricula;}
    void setEstado(bool estado){_estado=estado;}

    //Gets
    const int getDni(){return _dni;}
    bool getEstado(){return _estado;}
    const int getDiaFechaInscripcion(){return _fechaInscripcion.getDia();}
    const int getMesFechaInscripcion(){return _fechaInscripcion.getMes();}
    const int getAnioFechaInscripcion(){return _fechaInscripcion.getAnio();}
    const int getDeporte(){return _deporte;}
    const int getClaustro(){return _claustro;}
    const int getEquipo(){return _nroEquipo;}
    const char* getNombre(){return _nombre;}
    const char* getApellido(){return _apellido;}
    Fecha getFechaInscripcion(){return _fechaInscripcion;}


    //Metodos declaracion
    void Cargar( int dni);
    void Mostrar();
};

//Metodos implementacion
    void Jugador::Cargar(int dni=-1){
        int claustro,deporte;
        Fecha fechaInscripcion;
        float matricula;
        ArchivoDeporte arcDeporte;
        ArchivoEquipo arcEquipo;


        if(dni==-1){
            system("cls");
            cout<<"DNI: ";
            cin>>_dni;
        }else{
            _dni=dni;
        }

        system("cls");
        cout<<"Nombre: ";
        cargarCadena(_nombre,30);
        system("cls");
        cout<<"Apellido: ";
        cargarCadena(_apellido,30);
        system("cls");
        cout<<"Email: ";
        cargarCadena(_email,30);
        system("cls");
        cout<<"Telefono: ";
        cargarCadena(_tel,30);

        system("cls");
        cout<<"Claustro(1: docente;2: alumno;3: no docente; 4: graduado): ";
        cin>>claustro;
        setClaustro(claustro);
        while (_claustro==0){
            system("cls");
            cout<<"Claustro incorrecto. Debe ingresar algunas de las siguientes opciones."<<endl;
            cout<<"Claustro(1: docente;2: alumno;3: no docente; 4: graduado): ";
            cin>>claustro;
            setClaustro(claustro);
        }

        system("cls");

        cout<<"Deporte(Entre 1 y 10): ";
        cin>>deporte;
        setDeporte(deporte);
        while(_deporte == 0){
            system("cls");
            cout<<"Deporte incorrecto. Debe ingresar algun deporte del 1 al 10."<<endl;
            cout<<"Deporte(Entre 1 y 10): ";
            cin>>deporte;
            setDeporte(deporte);
        }

        int posDeporte=arcDeporte.buscarID(_deporte);           //Comprobar si el ID de deporte esta cargado en el archivoDeportes
        while(posDeporte <=-1){
            system("cls");
            cout<<"El ID de deporte ingresado no se encuetra cargado en el archivo de deportes."<<endl;
            cout<<"Deporte(Entre 1 y 10): ";
            cin>>deporte;
            setDeporte(deporte);
            posDeporte=arcDeporte.buscarID(_deporte);
        }

        system("cls");
        cout<<"Nro de equipo: ";
        cin>>_nroEquipo;

        int posEquipo= arcEquipo.buscarID(_nroEquipo);

        while(posEquipo <= -1){                                               //Comprobar si el nro de equipo esta cargado en el archivoEquipo
            system("cls");
            cout<<"El Numero de quipo ingresado no se encuentra cargado en el archivo de equipos."<<endl;
            cout<<"Nro de equipo: ";
            cin>>_nroEquipo;
            posEquipo=arcEquipo.buscarID(_nroEquipo);
        }


        system("cls");
        cout<<"Fecha de inscripcion: ";
        fechaInscripcion.Cargar();
        setFechaInscripcion(fechaInscripcion);
        while(this->getDiaFechaInscripcion()==0 || this->getMesFechaInscripcion()==0 ||this->getAnioFechaInscripcion()==0){
            system("cls");
            cout<<" Fecha invalida.\n La fecha debe ser anterior o igual a la actual"<<endl<<endl;
            cout<<"Fecha de inscripcion: ";
            fechaInscripcion.Cargar();
            setFechaInscripcion(fechaInscripcion);
        }

        system("cls");
        cout<<"Matricula: ";
        cin>>matricula;
        setMatricula(matricula);
        while(_matricula == -1){
            system("cls");
            cout<<"Matricula: ";
            cin>>matricula;
            setMatricula(matricula);
        }
    }

    void Jugador::Mostrar(){

        ArchivoDeporte arcDeporte;  //Buscar el regristro del deporte en el archivo deporte
        Deporte regDeporte;
        int posDeporte= arcDeporte.buscarID(_deporte);
        regDeporte=arcDeporte.leerRegistro(posDeporte);

        if(_estado==true){
            cout<<"DNI: "<<_dni<<endl;
            cout<<"Nombre: "<<_nombre<<endl;
            cout<<"Apellido: "<<_apellido<<endl;
            cout<<"Email: "<<_email<<endl;
            cout<<"Telefono: "<<_tel<<endl;
            cout<<"Claustro(1: docente;2: alumno;3: no docente; 4: graduado): "<<_claustro<<endl;

            if(posDeporte >= 0){         //si el deporte existe mostrar el nombre, si no mostrar como eliminado
                cout<<"ID Deporte: "<<_deporte<<" - "<<regDeporte.getNombre()<<endl;
            }else{
                cout<<"ID Deporte: Deporte Eliminado"<<endl;
            }

            cout<<"Nro de equipo: "<<_nroEquipo<<endl;
            cout<<"Fecha de inscripcion: ";
            _fechaInscripcion.Mostrar();
            cout<<"Matricula: "<<_matricula<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
        }
    }



//                ARCHIVO JUGADOR

class ArchivoJugador{
private:
    char _nombreArchivo[30];

public:
        ArchivoJugador(){
            strcpy(_nombreArchivo,"jugadores.dat");
        }

        //Metodos declaracion ArchivoJugador
        int buscarJugador(const int dni);
        int agregarRegistro();
        int listarPorDni();
        int cantidadRegistros();
        bool listarArchivo();
        Jugador leerRegistro(const int pos);
        int modificarFecha();
        int eliminarRegistro();

} ;


//Metodos implementacion ArchivoJugador
int ArchivoJugador::buscarJugador(const int dni){
    Jugador regCargado;
    int pos=0;

    FILE* pArchivoJugador;
    pArchivoJugador=fopen(_nombreArchivo, "rb");
    if(pArchivoJugador==NULL)
    {
        fclose(pArchivoJugador);
        return -2;
    }

    while(fread(&regCargado,sizeof(Jugador),1,pArchivoJugador )==1){
            if(regCargado.getDni()==dni && regCargado.getEstado()==true){
                fclose(pArchivoJugador);
                return pos;
            }
            pos++;
        }
    fclose(pArchivoJugador);
    return -1;              //si no encontro -1
}


int ArchivoJugador::agregarRegistro(){
    FILE* pArchivoJugador;
    pArchivoJugador=fopen(_nombreArchivo,"ab");
    int escribio;
    Jugador reg;

    if(pArchivoJugador==NULL){
        fclose(pArchivoJugador);
        return -2;
    }
    int dni;
    cout<<"DNI: ";
    cin>>dni;
    while(buscarJugador(dni) !=-1){
        system("cls");
        cout<<"DNI ya existente. Verifique el numero"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        cout<<"DNI: ";
        cin>>dni;
    }
    reg.Cargar(dni);
    escribio=fwrite(&reg, sizeof(Jugador),1,pArchivoJugador);
    fclose(pArchivoJugador);
    return escribio;
}


int ArchivoJugador::listarPorDni(){
    Jugador reg;
    FILE* pArchivoJugador= fopen(_nombreArchivo,"rb");
    int pos, dni;
    if(pArchivoJugador==NULL){
        fclose(pArchivoJugador);
        return -2;
    }

    cout<<"Ingrese el DNI del registro a visualizar: ";
    cin>>dni;
    system("cls");

    pos=buscarJugador(dni);

    if(pos==-1){
        fclose(pArchivoJugador);
        return -1;
    }
    fseek(pArchivoJugador, sizeof(Jugador)*pos, 0);
    int leyo=fread(&reg,sizeof(Jugador),1,pArchivoJugador);
    fclose(pArchivoJugador);


    reg.Mostrar();
    return leyo;
}


int ArchivoJugador::cantidadRegistros(){
    FILE* pArchivoJugador=fopen(_nombreArchivo,"rb");
    if(pArchivoJugador==NULL){
        return -2;
    }
    fseek(pArchivoJugador,0, SEEK_END);

    int tam=(ftell(pArchivoJugador))/ sizeof(Jugador);
    fclose(pArchivoJugador);

    return tam;
}


bool ArchivoJugador::listarArchivo(){
    Jugador reg;
    FILE* pArchivoJugador= fopen(_nombreArchivo,"rb");

    if(pArchivoJugador==NULL){
        fclose(pArchivoJugador);
        return false;
    }

    while(fread(&reg,sizeof(Jugador),1,pArchivoJugador)==1){
        reg.Mostrar();
    }
    fclose(pArchivoJugador);

    return true;

}


Jugador ArchivoJugador::leerRegistro(const int pos){
    FILE* pArchivoJugador=fopen(_nombreArchivo,"rb+");
    Jugador reg;
    reg.setEstado(false);

     if(pArchivoJugador==NULL){
        return reg;
    }

    fseek(pArchivoJugador,sizeof(Jugador)*pos,0);
    fread(&reg,sizeof(Jugador),1,pArchivoJugador);
    fclose(pArchivoJugador);

    return reg;
}


int ArchivoJugador::modificarFecha(){
    int dni,pos, escribio;
    Fecha fechaInscripcion;
    FILE* pArchivoJugador=fopen(_nombreArchivo,"rb+");
    Jugador reg;

    if(pArchivoJugador==NULL){
        return -2;
    }

    cout<<"Ingrese el DNI del jugador al cual desea modificar la fecha de inscripcion: ";
    cin>>dni;

     //BUSCAR EL REGISTRO
    pos=buscarJugador(dni);

    if(pos <= -1){
        fclose(pArchivoJugador);
        return -1;
    }

    //LEER EL REGISTRO ENCONTRADO
    reg=leerRegistro(pos);

    if(reg.getEstado()==false){
         fclose(pArchivoJugador);
        return -3;
    }

    system("cls");

    //MODIFICAR REGISTRO
    cout<<"Ingrese la fecha de inscripcion a modificar: ";
    fechaInscripcion.Cargar();
    reg.setFechaInscripcion(fechaInscripcion);

    if(reg.getDiaFechaInscripcion()==0 || reg.getMesFechaInscripcion()==0 ||reg.getAnioFechaInscripcion()==0)
    {
        fclose(pArchivoJugador);
        return -4;
    }

    //ESCRIBIR EN ARCHIVO
    fseek(pArchivoJugador,sizeof(Jugador)*pos,0);
    escribio=fwrite(&reg,sizeof(Jugador),1,pArchivoJugador);

    fclose(pArchivoJugador);
    return escribio;
}


int ArchivoJugador::eliminarRegistro(){
    FILE* pArchivoJugadores=fopen(_nombreArchivo,"rb+");
    Jugador reg;
    int dni,pos,escribio;
    if(pArchivoJugadores==NULL){
        fclose(pArchivoJugadores);
        return -2;
    }

    cout<<"DNI del jugador a eliminar: ";
    cin>>dni;

    pos=buscarJugador(dni);
    if(pos <= -1){
        fclose(pArchivoJugadores);
        return -1;
    }

    reg=leerRegistro(pos);
    if(reg.getEstado()==false){
        fclose(pArchivoJugadores);
        return -3;
    }
    reg.setEstado(false);

    fseek(pArchivoJugadores,sizeof(Jugador)*pos,0);

    escribio=fwrite(&reg, sizeof(Jugador),1,pArchivoJugadores);
    fclose(pArchivoJugadores);

    return escribio;

}


#endif // CLASES_H_INCLUDED
