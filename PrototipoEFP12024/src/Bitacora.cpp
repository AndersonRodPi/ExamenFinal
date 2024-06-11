#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

#include "Bitacora.h"

void Bitacora::ingresoBitacora(string nombre, string numAccion, string accion)
{
    system("cls");
	fstream file;
	file.open("Bitacora.dat", ios::binary | ios::app | ios::out );
    time_t now = time(0);
    date_time = ctime(&now);
    file<<std::left<<std::setw(20)<<nombre<<std::left<<std::setw(15)<<numAccion<<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
    file.close();
}
void Bitacora::visualizarBitacora()
{
    system("cls");
	fstream file;
	string texto;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Bitacora----------------------------"<<endl;
	file.open("Bitacora.dat",ios::binary | ios::in);
	cout<<"\nNombre" <<setw(22)<< "Aplicacion" <<setw(12)<< "Accion" <<setw(20)<< "Fecha\n\n";

    while(!file.eof())
    {
        total++;
        getline(file,texto);
        cout<<texto<<endl;
    }
    if(total==0)
    {
        cout<<"\n\t\t\tNo hay informacion...";
    }

    file.close();
    getch();
    system("pause");
}
