#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

void menuConfiguracion()
{
    int opt;

    while(true){

        cout<<"\t     MENU CONFIGURACION "<<endl;
        cout<<"\t-----------------------------------"<<endl<<endl;
        cout<<"\t 1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<<endl;
        cout<<"\t 2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<<endl;
        cout<<"\t 3) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<<endl;
        cout<<"\t 4) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<<endl;
        cout<<"\t 5) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<endl;
        cout<<"\t 6) COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS"<<endl;
        cout<<endl;
        cout<<"\t 7) COPIA DE SEGURIDAD DEL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<<endl;
        cout<<"\t 8) RESTAURAR EL ARCHIVO DE EQUIPOS"<<endl;
        cout<<endl;
        cout<<"\t 9) RESTAURAR EL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<<endl;
        cout<<"\t-----------------------------------"<<endl;
        cout<<"\t 0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"SELECIONE UNA DE LAS OPCIONES: ";
        cin>>opt;

        system("cls");
        switch(opt){
        case 1:
            cout<<"\t  COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl<<endl;
            backUpJugadores();
            break;
        case 2:
           cout<<"\t  COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl<<endl;
           backUpDeportes();
            break;
        case 3:
            cout<<"\t  RESTAURAR EL ARCHIVO DE JUGADORES"<<endl<<endl;
            restaurarBackUpJugadores();
            break;
        case 4:
            cout<<"\t  RESTAURAR EL ARCHIVO DE DEPORTES"<<endl<<endl;
            restaurarBackUpDeportes();
            break;
        case 5:
            cout<<"\t  ESTABLECER DATOS DE INICIO"<<endl<<endl;
            establecerDatosInicio();
            break;
        case 6:
           cout<<"\t  COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS"<<endl<<endl;
            backUpEquipos();
            break;
        case 7:
            cout<<"\t  COPIA DE SEGURIDAD DEL ARCHIVO DE TIPO DE DEPORTES"<<endl<<endl;
            backUpTipodeDeportes();
            break;
        case 8:
            cout<<"\t  RESTAURAR EL ARCHIVO DE EQUIPOS"<<endl<<endl;
            restaurarBackUpEquipos();
            break;
        case 9:
            cout<<"\t  RESTAURAR EL ARCHIVO DE TIPO DE DEPORTES"<<endl<<endl;
            restaurarBackUpTipodeDeportes();
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



#endif // MENUCONFIGURACION_H_INCLUDED
