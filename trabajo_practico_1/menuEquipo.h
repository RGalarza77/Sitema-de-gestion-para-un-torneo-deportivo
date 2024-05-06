#ifndef MENUEQUIPO_H_INCLUDED
#define MENUEQUIPO_H_INCLUDED

void menuEquipos()
{
    int opt;
    int retorno;
    ArchivoEquipo arcEquipo;

    while(true){
         int idEquipo=1;  //Acumulador de IDs de Equipos

        cout<<"\t     MENU EQUIPOS "<<endl;
        cout<<"\t-----------------------------------"<<endl<<endl;
        cout<<"\t 1) AGREGAR EQUIPO"<<endl;
        cout<<endl;
        cout<<"\t 2) LISTAR EQUIPO POR ID "<<endl;
        cout<<endl;
        cout<<"\t 3) LISTAR TODO"<<endl;
        cout<<endl;
        cout<<"\t 4) MODIFICAR NOMBRE"<<endl;
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
            cout<<"\t AGREGAR EQUIPO"<<endl<<endl;
            retorno=arcEquipo.agregarEquipo(idEquipo);

            system("cls");
            if(retorno== -2){
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
            }else if(retorno == 0){
                cout<<"No se pudo agregar equipo. ERROR 0"<<endl;
            }else{
                cout<<"Registro agregado con exito!!!."<<endl;
            }
            break;
        case 2:
            cout<<"\t LISTAR EQUIPO POR ID"<<endl<<endl;
            if(!arcEquipo.listarPorID()){
                cout<<"No existe un equipo con tal ID dentro del archivo."<<endl;
            }
            break;
        case 3:
            cout<<"\t LISTAR TODO"<<endl<<endl;
            arcEquipo.listarTodos();
            break;
        case 4:
            cout<<"MODIFICAR NOMBRE"<<endl<<endl;
            retorno=arcEquipo.modificarNombre();

             system("cls");
             switch (retorno){
                case -3:
                    cout<<"Registro no encontrado. ERROR -3"<<endl;
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
                    cout<<"Nombre del equipo modificado con exito!!!."<<endl;
                    break;
            }
            break;
        case 5:
            cout<<" ELIMINAR REGISTRO"<<endl<<endl;

            retorno=arcEquipo.eliminarRegistro();

            system("cls");
            switch (retorno){
            case -3:
                cout<<"Registro no encontrado. ERROR -3"<<endl;
                break;
            case -2:
                cout<<"No se pudo abrir el archivo. ERROR -2"<<endl;
                break;
            case -1:
                cout<<"No existe un equipo con tal ID dentro del archivo.ERROR -1"<<endl;
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

#endif // MENUEQUIPO_H_INCLUDED
