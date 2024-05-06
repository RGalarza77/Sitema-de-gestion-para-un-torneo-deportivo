#ifndef MENUTIPODEDEPORTE_H_INCLUDED
#define MENUTIPODEDEPORTE_H_INCLUDED

void menuTipodeDeporte()
{
    int opt;
    int retorno;
    ArchivoTipodeDeporte arcTipodeDeporte;

    while(true){
         int idTipodeDeporte=1;  //Acumulador de IDs de tipo de deporte

        cout<<"\t     MENU TIPOS DE DEPORTE "<<endl;
        cout<<"\t-----------------------------------"<<endl<<endl;
        cout<<"\t 1) AGREGAR TIPO"<<endl;
        cout<<endl;
        cout<<"\t 2) LISTAR TIPO POR ID "<<endl;
        cout<<endl;
        cout<<"\t 3) LISTAR TODO"<<endl;
        cout<<endl;
        cout<<"\t 4) MODIFICAR NIVEL DE DIFICULTAD"<<endl;
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
            cout<<"\t AGREGAR TIPO"<<endl<<endl;
            retorno=arcTipodeDeporte.agregarTipo(idTipodeDeporte);

            system("cls");
            if(retorno== -2){
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
            }else if(retorno == 0){
                cout<<"No se pudo agregar el tipo de deporte. ERROR 0"<<endl;
            }else if(retorno == -1){
                cout<<"Se ha alcanzado el maximo de ID disponibles (de 21 IDs).\nPor favor elimine algun registro para seguir cargando."<<endl<<endl<<endl;
            }else{
                cout<<"Registro agregado con exito!!!."<<endl;
            }
            break;

        case 2:
            cout<<"\t LISTAR TIPO POR ID"<<endl<<endl;
            if(!arcTipodeDeporte.listarPorID()){
                cout<<"No existe un tipo de deporte con tal ID dentro del archivo."<<endl;
            }
            break;

        case 3:
            cout<<"\t LISTAR TODO"<<endl<<endl;
            arcTipodeDeporte.listarTodos();
            break;

        case 4:
            cout<<"MODIFICAR NIVEL DE DIFICULTAD"<<endl<<endl;
            retorno=arcTipodeDeporte.modificarNivel();

             system("cls");
             switch (retorno){
                case -4:
                    cout<<"Nivel de dificualtad invalido.\nDebe ser un numero entre el 1 y el 8 . ERROR -4"<<endl<<endl;
                    break;
                case -3:
                    cout<<"Registro no encontrado o eliminado. ERROR -3"<<endl;
                    break;
                case -2:
                    cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
                    break;
                case -1:
                    cout<<"No existe un equipo con tal ID dentro del archivo.ERROR -1"<<endl;
                    break;
                case 0:
                    cout<<"No se pudo modificar el registro. ERROR 0"<<endl;
                    break;
                default:
                    cout<<"Nivel de dificultad del tipo de deporte modificado con exito!!!."<<endl;
                    break;
            }
            break;
        case 5:
            cout<<" ELIMINAR REGISTRO"<<endl<<endl;

            retorno=arcTipodeDeporte.eliminarRegistro();

            system("cls");
            switch (retorno){
            case -3:
                cout<<"Registro no encontrado. ERROR -3"<<endl;
                break;
            case -2:
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
                break;
            case -1:
                cout<<"No existe un tipo de deporte con tal ID dentro del archivo.ERROR -1"<<endl;
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

#endif // MENUTIPODEDEPORTE_H_INCLUDED
