#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

//clase nueva
class DeporteDificultad7{
private:
    int _idDeporte, _tipoDeporte;
    char _nombre[30];

public:
    void setIdDeporte(const int id){_idDeporte=id;}
    void setTipoDeDeporte(const int tipodeDeporte){_tipoDeporte=tipodeDeporte;}
    void setNombre(const char* nombre){strcpy(_nombre,nombre);}

    void Mostrar(){
        cout<<"Id deporte: "<<_idDeporte<<endl;
        cout<<"Tipo de deporte: "<<_tipoDeporte<<endl;
        cout<<"Nombre del deporte: "<<_nombre<<endl;
        cout<<"----------------------------------------------"<<endl;
    }

};

class ArchivoDeporteDificultad7{
private:
    char _nombre [30];

public:
    ArchivoDeporteDificultad7(const char* nombre){
        strcpy(_nombre,nombre);
    }

    bool grabarRegistro(DeporteDificultad7 reg){
        FILE* p= fopen(_nombre,"ab");
        if(p==nullptr){
            return false;
        }
        int grabo=fwrite(&reg,sizeof(DeporteDificultad7),1,p);
        fclose(p);
        return grabo;
    }


    int contarRegistros(){
        FILE* p=fopen(_nombre,"rb");
        if(p==nullptr){
        return 0;
        }
        fseek(p,0, SEEK_END);
        int tam=(ftell(p))/ sizeof(DeporteDificultad7);
        fclose(p);

        return tam;
    }


    DeporteDificultad7 leerRegistro(const int pos){
    FILE* p=fopen(_nombre,"rb");
    DeporteDificultad7 reg;
    reg.setIdDeporte(-1);

     if(p==NULL){
        return reg;
    }

    fseek(p,sizeof(DeporteDificultad7)*pos,0);
    fread(&reg,sizeof(DeporteDificultad7),1,p);

    fclose(p);

    return reg;
}


};



//Declaracion de Metodos
void menuReportes();
int contarJugadores(const int idDeporte);
int buscarDificultad(const int idTipoDeporte);

//puntos
void punto1();
void punto2();
void punto3();



void menuReportes(){
    int opt;

    while(true){

        cout<<"\t     MENU REPORTES "<<endl;
        cout<<"\t-----------------------------------"<<endl<<endl;
        cout<<"\t 1) PUNTO 1"<<endl;
        cout<<endl;
        cout<<"\t 2) PUNTO 2"<<endl;
        cout<<endl;
        cout<<"\t 3) PUNTO 3"<<endl;
        cout<<"\t-----------------------------------"<<endl;
        cout<<"\t 0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"SELECIONE UNA DE LAS OPCIONES: ";
        cin>>opt;

        system("cls");
        switch(opt){
        case 1:
            cout<<"\t PUNTO 1"<<endl<<endl;
            punto1();
            break;
        case 2:
           cout<<"\t  PUNTO 2"<<endl<<endl;
           punto2();
            break;
        case 3:
            cout<<"\t  PUNTO 3"<<endl<<endl;
           punto3();
           break;
        case 0:
            return ;
            break;
        default:
            cout<<"Opcion incorrecta. Intente de nuevo"<<endl;
            system("pause");
            break;
        }
        system("cls");

    }
}


//Metodos
int buscarDificultad(const int idTipoDeporte){
        ArchivoTipodeDeporte arc;
        TipodeDeporte reg;


        for(int i=0; i<arc.cantidadRegistros(); i++){
            reg=arc.leerRegistro(i);
            if(reg.getId()==idTipoDeporte){
                return reg.getNivel();
            }
        }
        return 0;
    }


int contarJugadores(const int idDeporte){
    ArchivoJugador arcJug;
    Jugador regJug;

    int i, cont=0;
    for(i=0; i< arcJug.cantidadRegistros(); i++){
        regJug=arcJug.leerRegistro(i);
        if(regJug.getDeporte() == idDeporte){
            cont++;
        }
    }
    return cont;
}



//puntos
void punto1(){
    ArchivoDeporte arcDeporte;
    Deporte regDeporte;
    int cantRegDeporte=arcDeporte.cantidadRegistros();

    ArchivoDeporteDificultad7 arcDeporteDif7("deportesDificultad7.dat");
    DeporteDificultad7 regDeporteDif7;

    int i;
    for(i=0; i<cantRegDeporte;i++){
        regDeporte=arcDeporte.leerRegistro(i);

        if(buscarDificultad(regDeporte.getTipo()) == 7 && regDeporte.getEstado()){
            regDeporteDif7.setTipoDeDeporte(regDeporte.getTipo());
            regDeporteDif7.setIdDeporte(regDeporte.getId());
            regDeporteDif7.setNombre(regDeporte.getNombre());

            if(arcDeporteDif7.grabarRegistro(regDeporteDif7)){
                cout<<"Registro Agregado"<<endl;
            }else{
                 cout<<"Problemas al agregar Registro"<<endl;
            }
        }
    }
    system("pause");

}

void punto2(){
    ArchivoDeporte arcDep;
    Deporte regDep;

    for(int i=0;i<arcDep.cantidadRegistros();i++){
        regDep=arcDep.leerRegistro(i);

        if(contarJugadores(regDep.getId()) < 15){
            regDep.Mostrar();
            cout<<"cant jugadores: "<<contarJugadores(regDep.getId()) <<endl<<endl;
        }
    }
    system("pause");

}


void punto3(){
    ArchivoDeporteDificultad7 arc("deportesDificultad7.dat");
    DeporteDificultad7 reg;
    int cantReg=arc.contarRegistros();

    DeporteDificultad7* vDinamico;
    vDinamico=new DeporteDificultad7[cantReg];
    if(vDinamico==nullptr){
        cout<<"no se pudo asignar memoria al vector del punto3"<<endl;
        system("pause");
        return;
    }
    int i;
    for(i=0; i<cantReg; i++){
        reg= arc.leerRegistro(i);
        vDinamico[i]=reg;
    }

    for(i=0; i<cantReg;i++){
        vDinamico[i].Mostrar();
    }
    if(cantReg ==0){
        cout<<"No hay registros"<<endl;
    }

    system("pause");

    delete [] vDinamico ;

}



#endif // REPORTES_H_INCLUDED
