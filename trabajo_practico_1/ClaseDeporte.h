#ifndef CLASEDEPORTE_H_INCLUDED
#define CLASEDEPORTE_H_INCLUDED


class Deporte{
private:
    int _id;
    char _nombre[30];
    int _tipo;
    int _anioOrigen;
    bool _estado;

public:
    //Constructores
    Deporte()
    {
        _tipo=0;
        _anioOrigen=0;
        _estado=true;
    }
    //Sets
    void setId(int id){if(id >=0 )_id=id;}
    void setTipo(const int tipo){if(tipo >=1 && tipo <= 21 ) _tipo=tipo;}
    void setAnioOrigen(const int anioOrigen){if(anioOrigen >=1800 && anioOrigen <=2023) _anioOrigen=anioOrigen;}
    void setEstado(bool estado){_estado=estado;}

    //Gets
    const int getId(){return _id;}
    bool getEstado(){return _estado;}
    const int getAnioOrigen(){return _anioOrigen;}
    const char* getNombre(){return _nombre;}
    const int getTipo(){return _tipo;}

    //Metodos declaracion
    void Cargar(int& ID);
    void Mostrar();
};


//Metodos Implementacion

    void Deporte::Cargar(int &ID){
        int tipo,anioOrigen;
        ArchivoTipodeDeporte arcTipodeDeporte;

        setId(ID);
        cout<<"ID de deporte: "<<_id<<endl<<endl<<endl;
        system("pause");

        system("cls");
        cout<<"Nombre: ";
        cargarCadena(_nombre,30);

        system("cls");
        cout<<"Tipo de deporte (entre 1 y 21): ";
        cin>>tipo;
        setTipo(tipo);


         while(_tipo == 0){
            system("cls");
            cout<<"Tipo de deporte erroneo"<<endl<<endl;
            cout<<"Tipo de deporte (entre 1 y 21): ";
            cin>>tipo;
            setTipo(tipo);
        }

        while(arcTipodeDeporte.buscarID(_tipo) < 0){                    // Si el tipo de deporte ingresado no se encuentra en el archivo de tipo de deporte
            system("cls");
            cout<<"El ID del tipo de deporte ingresado no existe en el archivo de 'tipo de deportes'."<<endl;
            cout<<"Ingrese otro ID del tipo de deporte:";
            cin>>tipo;
            setTipo(tipo);
        }

        system("cls");
        cout<<"Anio de origen (entre 1800 y 2023): ";
        cin>>anioOrigen;
        setAnioOrigen(anioOrigen);
        while(_anioOrigen == 0){
            system("cls");
            cout<<"Anio de origen erroneo"<<endl<<endl;
            cout<<"Anio de origen (entre 1800 y 2023): ";
            cin>>anioOrigen;
            setAnioOrigen(anioOrigen);
        }
        cout<<"-----------------------------------------------------------"<<endl;

    }

    void Deporte::Mostrar(){
        if(_estado==true){
            cout<<"ID: "<<_id<<endl;
            cout<<"Nombre: "<<_nombre<<endl;
            cout<<"Tipo de deporte (entre 1 y 21): "<<_tipo<<endl;
            cout<<"Anio de origen (entre 1800 y 2023): "<<_anioOrigen<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
        }
    }

//          ARCHIVO DEPORTE

class ArchivoDeporte{
private:
    char _nombreArchivo[30];

public:

    ArchivoDeporte(){
        strcpy(_nombreArchivo,"deportes.dat");
    }

    //Metodos declaracion
    int agregarDeporte(int& ID);
    int buscarID(const int id);
    int listarPorID();

    bool listarTodos();
    Deporte leerRegistro(const int pos);
    int modificarArchivo(Deporte reg, int pos);
    int modificarAnioOrigen();
    int eliminarRegistro();
    int cantidadRegistros();

};

//Metodos Implementacion

int ArchivoDeporte::buscarID(const int id){
    FILE* pArchivoDeporte=fopen(_nombreArchivo,"rb");
    Deporte reg;
    int pos=0;

    if(pArchivoDeporte==NULL){
        fclose(pArchivoDeporte);
        return -2;
    }

    while(fread(&reg, sizeof(Deporte),1,pArchivoDeporte)==1){
        if(id == reg.getId() && reg.getEstado() == true ){
            fclose(pArchivoDeporte);
            return pos;
        }
        pos++;
    }
    fclose(pArchivoDeporte);
    return -1;
}

int ArchivoDeporte::agregarDeporte(int& ID){
    FILE* pArchivoDeporte=fopen(_nombreArchivo,"ab+");
    Deporte reg;
    int escribio,pos;

    if(pArchivoDeporte==NULL){
        fclose(pArchivoDeporte);
        return -2;
    }

    pos= buscarID(ID);

    while(pos != -1){
        ID++;               //Incremento del ID
        pos= buscarID(ID);
    }
    reg.Cargar(ID);
    escribio=fwrite(&reg,sizeof(Deporte),1,pArchivoDeporte);

    fclose(pArchivoDeporte);
    return escribio;
}

int ArchivoDeporte::listarPorID(){
    FILE* pArchivoDeporte=fopen(_nombreArchivo,"rb");
    Deporte reg;
    int leyo,pos,id;

    if(pArchivoDeporte==NULL){
        fclose(pArchivoDeporte);
        return -2;
    }
    cout<<"ID del deporte a solicitar: ";
    cin>>id;
    system("cls");

    pos=buscarID(id);
    if(pos <= -1){
        fclose(pArchivoDeporte);
        return -1;
    }

    fseek(pArchivoDeporte,sizeof(Deporte)*pos,0);
    leyo=fread(&reg,sizeof(Deporte),1,pArchivoDeporte);

    reg.Mostrar();

    fclose(pArchivoDeporte);
    return leyo;

}

bool ArchivoDeporte::listarTodos(){
    Deporte reg;
    FILE* pArchivoDeporte= fopen(_nombreArchivo,"rb");

    if(pArchivoDeporte==NULL){
        fclose(pArchivoDeporte);
        return false;
    }

    while(fread(&reg,sizeof(Deporte),1,pArchivoDeporte)==1){
        reg.Mostrar();
    }
    fclose(pArchivoDeporte);

    return true;
}

Deporte ArchivoDeporte::leerRegistro(const int pos){
    FILE* pArchivoDeporte=fopen(_nombreArchivo,"rb");
    Deporte reg;
    reg.setEstado(false);

     if(pArchivoDeporte==NULL){
        return reg;
    }

    fseek(pArchivoDeporte,sizeof(Deporte)*pos,0);
    fread(&reg,sizeof(Deporte),1,pArchivoDeporte);

    fclose(pArchivoDeporte);

    return reg;
}

int ArchivoDeporte::modificarArchivo(Deporte reg, int pos){
    int escribio;
    FILE* pArchivoDeporte=fopen(_nombreArchivo,"rb+");

    if(pArchivoDeporte==NULL){
        pclose(pArchivoDeporte);
        return -2;
    }

    fseek(pArchivoDeporte,sizeof(Deporte)*pos,0);
    escribio=fwrite(&reg,sizeof(Deporte),1,pArchivoDeporte);

    fclose(pArchivoDeporte);

    return escribio;
}

int ArchivoDeporte::modificarAnioOrigen(){
    int id,pos, escribio,anio;
    Deporte reg;

    cout<<"Ingrese el ID del deporte al cual desea modificar el anio de origen: ";
    cin>>id;

     //BUSCAR EL REGISTRO
    pos=buscarID(id);

    if(pos <= -1){
        return -1;
    }

    //LEER EL REGISTRO ENCONTRADO
    reg=leerRegistro(pos);

    if(reg.getEstado()==false){
        return -3;
    }

    system("cls");

    //MODIFICAR REGISTRO
    cout<<"Ingrese el anio de origen a modificar: ";
    cin>>anio;
    if(anio < 1800 || anio > 2023){
        return -4;
    }
    reg.setAnioOrigen(anio);

    //ESCRIBIR EN ARCHIVO
    escribio=modificarArchivo(reg, pos);

    return escribio;
}


int ArchivoDeporte::eliminarRegistro(){
    int id,pos,escribio;
    Deporte reg;

    cout<<"Ingrese el ID del deporte a eliminar: ";
    cin>>id;

     //BUSCAR EL REGISTRO
    pos=buscarID(id);

    if(pos <= -1){
        return -1;
    }

    //LEER EL REGISTRO ENCONTRADO
    reg=leerRegistro(pos);

    if(reg.getEstado()==false){
        return -3;
    }

    system("cls");

    //MODIFICAR REGISTRO

    reg.setEstado(false);

    //ESCRIBIR EN ARCHIVO
    escribio=modificarArchivo(reg, pos);

    return escribio;
}


int ArchivoDeporte::cantidadRegistros(){
    FILE* pArchivoDeporte=fopen(_nombreArchivo,"rb");
    if(pArchivoDeporte==NULL){
        return -2;
    }
    fseek(pArchivoDeporte,0, SEEK_END);
    int tam=(ftell(pArchivoDeporte))/ sizeof(Deporte);
    fclose(pArchivoDeporte);

    return tam;
}





#endif // CLASEDEPORTE_H_INCLUDED
