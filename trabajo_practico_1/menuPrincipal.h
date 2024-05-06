#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

int menuPrincipal(){
    int opt;

    while(true){


        cout<<"\t     MENU PRINCIPAL "<<endl;
        cout<<"\t-----------------------------------"<<endl<<endl;
        cout<<"\t 1) MENU JUGADORES"<<endl;
        cout<<endl;
        cout<<"\t 2) MENU DEPORTES "<<endl;
        cout<<endl;
        cout<<"\t 3) MENU EQUIPOS "<<endl;
        cout<<endl;
        cout<<"\t 4) MENU TIPOS DE DEPORTE "<<endl;
        cout<<endl;
        cout<<"\t 5) REPORTES "<<endl;
        cout<<endl;
        cout<<"\t 6) CONFIGURACION"<<endl;
        cout<<"\t-----------------------------------"<<endl;
        cout<<"\t 0) FIN DEL PROGRAMA"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"SELECIONE UNA DE LAS OPCIONES: ";
        cin>>opt;

        system("cls");
        switch(opt){
        case 1:
            menuJugadores();
            break;
        case 2:
            menuDeportes();
            break;
        case 3:
            menuEquipos();
            break;
        case 4:
            menuTipodeDeporte();
            break;
        case 5:
            menuReportes();
            break;
        case 6:
            menuConfiguracion();
            break;
        case 0:
            cout<<"Hasta luego!!!"<<endl;
            return 0;
            break;
        default:
            cout<<"Opcion incorrecta. Intente de nuevo"<<endl;
            system("pause");
            break;
        }
        system("cls");

    }
}




#endif // MENUPRINCIPAL_H_INCLUDED
