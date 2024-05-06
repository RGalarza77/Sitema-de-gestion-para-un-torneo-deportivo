#ifndef CLASEEQUIPO_H_INCLUDED
#define CLASEEQUIPO_H_INCLUDED

class Equipo{

protected:
        int _id, _nivel;
        char _nombre[30];
        bool _estado;

public:
    Equipo(){
        _estado=true;
        _nivel=0;
    }
    //Gets
    const int getId(){return _id;}
    const int getNivel(){return _nivel;}
    const char* getNombre(){return _nombre;}
    bool getEstado(){return _estado;}

    //Sets
    void setId(const int id){if(id >= 0) _id=id;}
    void setNivel(const int nivel){if(nivel >= 1 && nivel <=3) _nivel=nivel;}
    void setNombre(const char* nombre){strcpy(_nombre,nombre);}
    void setEstado(bool estado){_estado=estado;}

    //Declaracion de metodos
    void Cargar(int &idEquipo);
    void Mostrar();

};

//Implementacion de Metodos

void Equipo::Cargar(int &idEquipo){
    int nivel;

    setId(idEquipo);
    cout<<"Id del equipo: "<<_id<<endl<<endl<<endl<<endl;
    system("pause");

    system("cls");
    cout<<"Nombre de equipo: ";
    cargarCadena(_nombre,30);
    system("cls");

    cout<<"Nivel (Entre 1 y 3): ";
    cin>>nivel;
    setNivel(nivel);
    while(_nivel ==0){
        system("cls");
        cout<<"Nivel incorrecto. El nivel debe de ser un numero entero entre 1 y 3."<<endl;
        cout<<"Nivel (Entre 1 y 3): ";
        cin>>nivel;
        setNivel(nivel);
    }

}

void Equipo::Mostrar(){
    cout<<"Id del equipo: "<<_id<<endl;
    cout<<"Nombre del equipo: "<<_nombre<<endl;
    cout<<"Nivel: "<<_nivel<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
}


// Archivo Equipo
class ArchivoEquipo{
private:
    char _nombreArchivo[30];

public:
    ArchivoEquipo(){
        strcpy(_nombreArchivo,"equipos.dat");
    }

    //Metodos
    int agregarEquipo(int &idEquipos);
    Equipo leerRegistro(const int pos);
    int cantidadRegistros();
    int buscarID(const int id);
    bool listarPorID();
    void listarTodos();
    int grabarArchivo(Equipo reg, const int pos);
    int modificarNombre();
    int eliminarRegistro();

};

//Metodos

int ArchivoEquipo::agregarEquipo(int &idEquipos){
    FILE* pArchivoEquipo=fopen(_nombreArchivo,"ab+");
    Equipo reg;
    int pos;
    if(pArchivoEquipo==NULL){
        return -2;
    }

    pos=buscarID(idEquipos);
    while(pos != -1){       // mientras id no este disponible buscar otra
        idEquipos++;
        pos=buscarID(idEquipos);
    }

    reg.Cargar(idEquipos);
    int escribio=fwrite(&reg, sizeof(Equipo),1,pArchivoEquipo);

    fclose(pArchivoEquipo);
    return escribio;
}


Equipo ArchivoEquipo::leerRegistro(const int pos){
    FILE* pArchivoEquipo=fopen(_nombreArchivo,"rb+");
    Equipo reg;
    reg.setEstado(false);

    if(pArchivoEquipo == nullptr){
        return reg;
    }

    fseek(pArchivoEquipo,sizeof(Equipo)*pos,0);
    if(fread(&reg, sizeof(Equipo),1,pArchivoEquipo)==1){
        fclose(pArchivoEquipo);
        return reg;
    }
    fclose(pArchivoEquipo);
    reg.setEstado(false);
    return reg;
}


int ArchivoEquipo::cantidadRegistros(){
    FILE* pArchivoEquipo= fopen(_nombreArchivo,"rb");
    if(pArchivoEquipo==NULL){
        return -2;
    }
    fseek(pArchivoEquipo,0,2);
    int tam=(ftell(pArchivoEquipo) )/ sizeof(Equipo);
    fclose(pArchivoEquipo);

    return tam;
}


int ArchivoEquipo::buscarID(const int id){
    FILE* pArchivoEquipo= fopen(_nombreArchivo,"rb");
    Equipo reg;
    int pos=0;

    if(pArchivoEquipo==NULL){
        return -2;
    }

    while(fread(&reg, sizeof(Equipo),1,pArchivoEquipo)==1){
        if(reg.getId() == id && reg.getEstado()==true){
            fclose(pArchivoEquipo);
            return pos;
        }
        pos++;
    }

    fclose(pArchivoEquipo);
    return -1;
}

bool ArchivoEquipo::listarPorID(){
    Equipo reg;
    int id, pos;

    cout<<"Ingrese el ID del equipo a buscar: ";
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


void ArchivoEquipo::listarTodos(){
    int cantReg=cantidadRegistros();
    Equipo reg;

    if(cantReg ==0){
        cout<<"El archivo no contiene nungun registro"<<endl;
    }

    cout<<setw(3)<<"ID";
    cout<<setw(31)<<"Nombre";
    cout<<setw(6)<<"Nivel"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;

    for(int i=0; i<cantReg; i++){
        reg=leerRegistro(i);
        if(reg.getEstado()){
            cout<<left;
            cout<<setw(3)<<reg.getId();
            cout<<right;
            cout<<setw(31)<<reg.getNombre();
            cout<<setw(4)<<reg.getNivel()<<endl;
        }
    }
    cout<<"-----------------------------------------------------------"<<endl;
}


int ArchivoEquipo::grabarArchivo(Equipo reg, const int pos){
     FILE* pArchivoEquipo=fopen(_nombreArchivo,"rb+");
    if(pArchivoEquipo==NULL){
        return -2;
    }

    fseek(pArchivoEquipo, sizeof(Equipo)*pos,0);
    int escribio=fwrite(&reg, sizeof(Equipo),1,pArchivoEquipo);
    fclose(pArchivoEquipo);

    return escribio;
}


int ArchivoEquipo::modificarNombre(){
    int pos,id;
    Equipo reg;
    char nombre[30];

    cout<<"Ingrese el ID del equipo a modificar: ";
    cin>>id;
    system("cls");

    //buscar registro
    pos=buscarID(id);
    if(pos < 0){      //no se encontro el id
        return -1;
    }

    //Leer registro
   reg=leerRegistro(pos);
   if(!reg.getEstado()){
        return -3;
   }

    //modificar registro
    cout<<"Ingrese el nombre: ";
    cargarCadena(nombre,30);
    system("cls");
    reg.setNombre(nombre);

    //grabar en archivo
    int escribio=grabarArchivo(reg,pos);

    return escribio;
}

int ArchivoEquipo::eliminarRegistro(){
    int id,pos;
    Equipo reg;

    cout<<"Ingrese el ID del equipo a dar de baja: ";
    cin>>id;
    system("cls");

    //bsucar registro
    pos=buscarID(id);
    if(pos < 0){
        return -1;
    }

    //leer registro
    reg=leerRegistro(pos);
    if(!reg.getEstado()){
        return -3;
    }

    //modificar registro
    reg.setEstado(false);

    //grabar registro en archivo
    int escribio=grabarArchivo(reg,pos);

    return escribio;
}

#endif // CLASEEQUIPO_H_INCLUDED
