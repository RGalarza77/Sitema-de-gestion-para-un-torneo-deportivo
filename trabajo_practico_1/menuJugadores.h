#ifndef MENUJUGADORES_H_INCLUDED
#define MENUJUGADORES_H_INCLUDED


void menuJugadores()
{
    int opt;
    int retorno;
    ArchivoJugador arcJugador;

    while(true){

        cout<<"\t     MENU JUGADORES"<<endl;
        cout<<"\t-----------------------------------"<<endl<<endl;
        cout<<"\t 1) AGREGAR JUGADOR"<<endl;
        cout<<endl;
        cout<<"\t 2) LISTAR JUGADOR POR DNI "<<endl;
        cout<<endl;
        cout<<"\t 3) LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<endl;
        cout<<"\t 4) MODIFICAR  FECHA DE INSCRIPCION"<<endl;
        cout<<endl;
        cout<<"\t 5) ELIMINAR REGISTRO DE JUGADOR"<<endl;
        cout<<"\t-----------------------------------"<<endl;
        cout<<"\t 0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"Opcion: ";
        cin>>opt;

        system("cls");
        switch(opt){
        case 1:
            cout<<"\t AGREGAR JUGADOR"<<endl<<endl;
            retorno=arcJugador.agregarRegistro();

            system("cls");
            if(retorno== -2){
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
            }else if(retorno == 0){
                cout<<"No se pudo agregar registro. ERROR 0"<<endl;
            }else{
                cout<<"Registro agregado con exito!!!."<<endl;
            }
            break;
        case 2:
            cout<<"\t LISTA JUGADOR POR DNI"<<endl<<endl;
            retorno=arcJugador.listarPorDni();

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
            cout<<"\t LISTA DE TODOS LOS JUGADORES"<<endl<<endl;

            if(!arcJugador.listarArchivo()){
                cout<<"No se pudo leer el archivo. ERROR -2"<<endl;
            }
            break;
        case 4:
            cout<<"MODIFICAR  FECHA DE INSCRIPCION"<<endl<<endl;
            retorno=arcJugador.modificarFecha();

            system("cls");
            switch (retorno){
            case -4:
                cout<<"Error al modificar fecha.Fecha invalida. ERROR -4"<<endl;
                break;
            case -3:
                cout<<"Registro no encontrado. ERROR -3"<<endl;
                break;
            case -2:
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
                break;
            case -1:
                cout<<"No existe el jugador con tal DNI dentro del archivo.ERROR -1"<<endl;
                break;
            case 0:
                cout<<"No se pudo modificar el registro. ERROR 0"<<endl;
                break;
            default:
                cout<<"Fecha de ingreso modificada con exito!!!."<<endl;
                break;
            }
            break;
        case 5:
            cout<<"ELIMINAR REGISTRO DE JUGADOR"<<endl<<endl;

            retorno=arcJugador.eliminarRegistro();

            system("cls");
            switch (retorno){
            case -3:
                cout<<"Registro no encontrado. ERROR -3"<<endl;
                break;
            case -2:
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
                break;
            case -1:
                cout<<"No existe el jugador con tal DNI dentro del archivo.ERROR -1"<<endl;
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




#endif // MENUJUGADORES_H_INCLUDED
