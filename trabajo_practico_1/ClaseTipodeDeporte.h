#ifndef CLASETIPODEDEPORTE_H_INCLUDED
#define CLASETIPODEDEPORTE_H_INCLUDED

class TipodeDeporte:public Equipo{
private:

public:
    TipodeDeporte(){
        _estado=true;
        _id=0;
        _nivel=0;
    }

    //Sets
    void setId(const int id){if(id >= 1 && id <=21) _id=id;}
    void setNivel(const int nivel){if(nivel >=1 && nivel <=8) _nivel=nivel;}
    void setEstado(bool estado){_estado=estado;}



    //metodos declaracion
    void Cargar(int &idTipodeDeporte);
    void Mostrar();
};

//metodos implementacion TipodeDeporte

void TipodeDeporte::Cargar(int &idTipodeDeporte){
    int nivel;

    setId(idTipodeDeporte);
    cout<<"Id del Tipo de deporte: "<<_id<<endl<<endl<<endl<<endl;
    system("pause");

    system("cls");
    cout<<"Nombre del Tipo de deporte: ";
    cargarCadena(_nombre,30);

    system("cls");
    cout<<"Nivel de dificultad (Entre 1 y 8): ";
    cin>>nivel;
    setNivel(nivel);
    while(_nivel==0){
        system("cls");
        cout<<"Nivel de dificultad invalido. Debe de ser un numero entre 1 y 8."<<endl;
        cout<<"Nivel de dificultad: ";
        cin>>nivel;
        setNivel(nivel);
    }
}

void TipodeDeporte::Mostrar(){
    cout<<"ID del Tipo de deporte: "<<_id<<endl;
    cout<<"Nombre del Tipo de deporte: "<<_nombre<<endl;
    cout<<"Nivel de dificultad: "<<_nivel<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
}

class ArchivoTipodeDeporte{
private:
    char _nombreArchivo[30];
public:
    ArchivoTipodeDeporte(){
        strcpy(_nombreArchivo, "tipoDeDeporte.dat");
    }

    //metodos

    int agregarTipo(int &idTipodeDeporte);
    int cantidadRegistros();
    int buscarID(const int id);
    TipodeDeporte leerRegistro(const int pos);
    bool listarPorID();
    void listarTodos();
    int grabarArchivo(TipodeDeporte reg, const int pos);
    int modificarNivel();
    int eliminarRegistro();

};

// metodos ArchivoTipodeDeporte

int ArchivoTipodeDeporte::agregarTipo(int &idTipodeDeporte){
    FILE* pArchivoTipodeDeporte=fopen(_nombreArchivo,"ab");
    TipodeDeporte reg;

    if(pArchivoTipodeDeporte==nullptr){
        return -2;
    }
    int pos=buscarID(idTipodeDeporte);
    while(pos >= 0){                        //incrementar id hasta encontrar uno disponible
        idTipodeDeporte++;
        pos=buscarID(idTipodeDeporte);
    }


    if(idTipodeDeporte > 21){                       // Se verifica si se alcanzo el maximo de IDs disponibles
        fclose(pArchivoTipodeDeporte);
        return -1;
    }

    reg.Cargar(idTipodeDeporte);
    int escribio=fwrite(&reg,sizeof(TipodeDeporte),1,pArchivoTipodeDeporte);
    fclose(pArchivoTipodeDeporte);

    return escribio;
}


int ArchivoTipodeDeporte::cantidadRegistros(){
    FILE* pArchivoTipodeDeporte=fopen(_nombreArchivo,"rb");
    if(pArchivoTipodeDeporte==nullptr){
        return -2;
    }

    fseek(pArchivoTipodeDeporte, 0, 2);
    int tam=ftell(pArchivoTipodeDeporte)/sizeof(TipodeDeporte);
    fclose(pArchivoTipodeDeporte);

    return tam;
}


int ArchivoTipodeDeporte::buscarID(const int id){
    FILE* pArchivoTipodeDeporte=fopen(_nombreArchivo,"rb");
    TipodeDeporte reg;
    int tam=cantidadRegistros();

    if(pArchivoTipodeDeporte==nullptr){
        return -2;
    }

    for(int i=0; i<tam; i++){
        fread(&reg,sizeof(TipodeDeporte),1,pArchivoTipodeDeporte);
        if(reg.getId()==id && reg.getEstado()==true){
            fclose(pArchivoTipodeDeporte);
            return i;
        }
    }

    fclose(pArchivoTipodeDeporte);
    return -1;
}


TipodeDeporte ArchivoTipodeDeporte::leerRegistro(const int pos){
    FILE* pArchivoTipodeDeporte=fopen(_nombreArchivo,"rb");
    TipodeDeporte reg;
    reg.setEstado(false);

    if(pArchivoTipodeDeporte==nullptr){
        return reg;
    }

    fseek(pArchivoTipodeDeporte,sizeof(TipodeDeporte)*pos,0);
    if(fread(&reg,sizeof(TipodeDeporte),1,pArchivoTipodeDeporte)==1){
        fclose(pArchivoTipodeDeporte);
        return reg;
    }
    fclose(pArchivoTipodeDeporte);

    reg.setEstado(false);
    return reg;
}


bool ArchivoTipodeDeporte::listarPorID(){
    TipodeDeporte reg;
    int pos,id;

    cout<<"Ingrese ID del tipo de deporte a buscar: ";
    cin>>id;
    system("cls");

    pos=buscarID(id);

    if(pos < 0){
        return false;
    }

    reg=leerRegistro(pos);
    if(!reg.getEstado()){
        return false;
    }
    reg.Mostrar();
    return true;
}


void ArchivoTipodeDeporte::listarTodos(){
    TipodeDeporte reg;
    int tam=cantidadRegistros();

    if(tam==0){
        cout<<"El archivo no contiene ningun registro."<<endl;
    }

    cout<<setw(3)<<"ID";
    cout<<setw(32)<<"Nombre";
    cout<<setw(18)<<"Nivel dificultad"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;

    for(int i=0;i<tam;i++){
        reg=leerRegistro(i);
        if(reg.getEstado()==true){          //si esta activo el registro, mostrarlo
            cout<<left;
            cout<<setw(3)<<reg.getId();
            cout<<right;
            cout<<setw(32)<<reg.getNombre();
            cout<<setw(7)<<reg.getNivel()<<endl;
        }
    }
    cout<<"-----------------------------------------------------------"<<endl;
 }


int ArchivoTipodeDeporte::grabarArchivo(TipodeDeporte reg, const int pos){
    FILE* pArchivoTipodeDeporte=fopen(_nombreArchivo,"rb+");

    if(pArchivoTipodeDeporte==nullptr){
        return -2;
    }

    fseek(pArchivoTipodeDeporte, sizeof(TipodeDeporte)*pos,0);
    int modifico=fwrite(&reg,sizeof(TipodeDeporte),1,pArchivoTipodeDeporte);
    fclose(pArchivoTipodeDeporte);

    return modifico;

}


int ArchivoTipodeDeporte::modificarNivel(){
    TipodeDeporte reg;
    int pos,id,nivel;

    cout<<"Ingrese el ID del tipo de deporte a modificar el nivel de dificultad: ";
    cin>>id;
    system("cls");

    //buscar registro
    pos=buscarID(id);
    if(pos < 0){
        return -1;
    }

    //leer registro
   reg = leerRegistro(pos);
   if(!reg.getEstado()){
        return -3;
   }

   //modificar registro
   cout<<"Ingrese el nivel de difcultad: ";
   cin>>nivel;
   system("cls");

    if(nivel >=1 && nivel <=8){
        reg.setNivel(nivel);
    }else{
        return -4;
    }

    //grabar en el archivo
    int grabo=grabarArchivo(reg,pos);

    return grabo;
}


int ArchivoTipodeDeporte::eliminarRegistro(){
    int pos,id;
    TipodeDeporte reg;

    cout<<"Ingrese ID del tipo de deporte a eliminar: ";
    cin>>id;
    system("cls");

    pos=buscarID(id);
    if(pos < 0){
        return -1;
    }

    reg=leerRegistro(pos);
    if(!reg.getEstado()){
        return -3;
    }

    reg.setEstado(false);

    int grabo=grabarArchivo(reg,pos);

    return grabo;
}




#endif // CLASETIPODEDEPORTE_H_INCLUDED
