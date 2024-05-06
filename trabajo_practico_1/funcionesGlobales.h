#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED


//Funcion Cargar cadena
void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}


//Funciones Backups

void backUpJugadores(){
        system("echo. > jugadores.bkp");                    //creo el archivo jugadores.bkp
        system("copy jugadores.dat jugadores.bkp");  //copio Jugadores.dat  a  jugadores.bkp
        cout<<endl<<endl;
        cout<<"Backup de jugadores creado "<<endl<<endl<<endl;
        system("pause");
}

void backUpDeportes(){
        system("echo. > deportes.bkp");                    //creo el archivo deportes.bkp
        system("copy deportes.dat deportes.bkp");  //copio deportes.dat  a  deportes.bkp
        cout<<endl<<endl;
        cout<<"Backup de Deportes creado "<<endl<<endl<<endl;
        system("pause");
}

void backUpEquipos(){
        system("echo. > equipos.bkp");                    //creo el archivo equipos.bkp
        system("copy equipos.dat equipos.bkp");  //copio equipos.dat  a  equipos.bkp
        cout<<endl<<endl;
        cout<<"Backup de equipos creado "<<endl<<endl<<endl;
        system("pause");
}

void backUpTipodeDeportes(){
        system("echo. > tipoDeDeporte.bkp");                    //creo el archivo TipodeDeporte.bkp
        system("copy tipoDeDeporte.dat tipoDeDeporte.bkp");  //copio TipodeDeporte.dat  a  TipodeDeporte.bkp
        cout<<endl<<endl;
        cout<<"Backup de tipo de deportes creado "<<endl<<endl<<endl;
        system("pause");
}



// Restaurar Bkps
void restaurarBackUpJugadores(){
    system("copy jugadores.bkp jugadores.dat");
    cout<<endl<<endl;
    cout<<"Datos de jugadores re establecidos "<<endl<<endl<<endl;
    system("pause");
}

void restaurarBackUpDeportes(){
    system("copy deportes.bkp deportes.dat");
    cout<<endl<<endl;
    cout<<"Datos de Deportes re establecidos "<<endl<<endl<<endl;
    system("pause");
}

void restaurarBackUpEquipos(){
    system("copy equipos.bkp equipos.dat");
    cout<<endl<<endl;
    cout<<"Datos de Equipos re establecidos "<<endl<<endl<<endl;
    system("pause");
}

void restaurarBackUpTipodeDeportes(){
    system("copy tipoDeDeporte.bkp tipoDeDeporte.dat");
    cout<<endl<<endl;
    cout<<"Datos de Tipo de Deporte re establecidos "<<endl<<endl<<endl;
    system("pause");
}



void establecerDatosInicio(){
    system("copy datosInicioJugadores.dat jugadores.dat");
    cout<<endl<<endl;
    cout<<"Datos de inicio de Jugadores establecidos "<<endl<<endl<<endl;
    system("pause");
    system("cls");
    system("copy datosInicioDeportes.dat deportes.dat");
    cout<<endl<<endl;
    cout<<"Datos de inicio de Deportes establecidos "<<endl<<endl<<endl;
    system("pause");

}



#endif // FUNCIONESGLOBALES_H_INCLUDED
