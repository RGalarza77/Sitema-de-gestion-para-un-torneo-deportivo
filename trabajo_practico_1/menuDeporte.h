#ifndef MENUDEPORTE_H_INCLUDED
#define MENUDEPORTE_H_INCLUDED



void menuDeportes()
{

    int opt;
    int retorno;
    ArchivoDeporte arcDeporte;

    while(true){
         int ID=1;  //Acumulador de IDs de deportes

        cout<<"\t     MENU DEPORTES "<<endl;
        cout<<"\t-----------------------------------"<<endl<<endl;
        cout<<"\t 1) AGREGAR DEPORTE"<<endl;
        cout<<endl;
        cout<<"\t 2) LISTAR DEPORTE POR ID "<<endl;
        cout<<endl;
        cout<<"\t 3) LISTAR TODO"<<endl;
        cout<<endl;
        cout<<"\t 4) MODIFICAR  ANIO DE ORIGEN"<<endl;
        cout<<endl;
        cout<<"\t 5) ELIMINAR REGISTRO "<<endl;
        cout<<"\t-----------------------------------"<<endl;
        cout<<"\t 0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"Opcion: ";
        cin>>opt;

        system("cls");
        switch(opt){
        case 1:
            cout<<"\t AGREGAR DEPORTE"<<endl<<endl;
            retorno=arcDeporte.agregarDeporte(ID);

            system("cls");
            if(retorno== -2){
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
            }else if(retorno == 0){
                cout<<"No se pudo agregar deporte. ERROR 0"<<endl;
            }else{
                cout<<"Registro agregado con exito!!!."<<endl;
            }
            break;
        case 2:
            cout<<"\t LISTAR DEPORTE POR ID"<<endl<<endl;
            retorno=arcDeporte.listarPorID();

            switch (retorno){
            case -2:
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
                break;
            case -1:
                cout<<"No existe el jugador con tal DNI dentro del archivo."<<endl;
                break;
            case 0:
                cout<<"No se pudo leer el registro. ERROR 0"<<endl;
                break;
            }
            break;
        case 3:
            cout<<"\t LISTAR TODO"<<endl<<endl;

            if(!arcDeporte.listarTodos()){
                cout<<"No se pudo leer el archivo."<<endl;
            }
            break;
        case 4:
            cout<<"MODIFICAR ANIO DE ORIGEN"<<endl<<endl;
            retorno=arcDeporte.modificarAnioOrigen();

            system("cls");
            switch (retorno){
            case -4:
                cout<<"Error al modificar el anio de origen.Anio invalido. ERROR -4"<<endl;
                break;
            case -3:
                cout<<"Registro no encontrado. ERROR -3"<<endl;
                break;
            case -2:
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
                break;
            case -1:
                cout<<"No existe deporte con tal ID dentro del archivo.ERROR -1"<<endl;
                break;
            case 0:
                cout<<"No se pudo modificar el registro. ERROR 0"<<endl;
                break;
            default:
                cout<<"Anio de origen modificado con exito!!!."<<endl;
                break;
            }
            break;
        case 5:
            cout<<" ELIMINAR REGISTRO"<<endl<<endl;

            retorno=arcDeporte.eliminarRegistro();

            system("cls");
            switch (retorno){
            case -3:
                cout<<"Registro no encontrado. ERROR -3"<<endl;
                break;
            case -2:
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
                break;
            case -1:
                cout<<"No existe deporte con tal ID dentro del archivo.ERROR -1"<<endl;
                break;
            case 0:
                cout<<"No se pudo eliminar el registro. ERROR 0"<<endl;
                break;
            default:
                cout<<"Registro eliminado con exito!!!."<<endl;
                break;
            }
            break;
        case 0:
            return ;
            break;
        default:
            cout<<"Opcion incorrecta. Intente de nuevo"<<endl;
            system("pause");
            break;
        }
        system("pause");
        system("cls");


    }

}




#endif // MENUDEPORTE_H_INCLUDED
