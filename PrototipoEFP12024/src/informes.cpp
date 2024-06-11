//Programa que permite imprimir en un archivo txt los datos de los empleados
#include<iostream> // Incluye la biblioteca estándar para entrada y salida
#include<fstream> // Incluye la biblioteca para manejo de archivos
#include<stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad
#include<cstdlib> // Incluye la biblioteca estándar para funciones de utilidad
#include<iomanip> // Incluye la biblioteca para manipulación de la salida
#include <sstream> // Incluye la biblioteca para operaciones de flujo de cadena
#include <cstring> // Incluye la biblioteca para operaciones de cadena

#include "informes.h"
#include "empleado.h"
#include"Bitacora.h"

using namespace std;

struct Informes{
    string imp_codigo;
    string imp_nombre;
    string imp_puesto;
    string imp_departamento;
    string imp_sueldo;
    string imp_status;
};


void informes::imprimirArchivo() {
    //implementacion de variables para bitacora
    string codigoPrograma = "1200";
    Bitacora Auditoria;
    //abrira el archivo de User y contraseñas--------------------------
    ifstream fileU;
    fileU.open("usuarios.txt",ios::in);


    //verificar si se abrio el archivo---------------------------
    if (!fileU)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU.close();
    }
    //busca el usuario en el archivo---------------------------------
    string user,pass;
    while (fileU>>user>>pass)
    {
        //obtener el nombre de usuario
    }
    fileU.close();

    system("cls");
    Informes informes;
    ofstream file("impresion.txt", ios::out); // Abre el archivo txt

    if (!file) {
        cerr << "No se pudo abrir el archivo 'impresion.txt'." << endl;
        return;
    } else {
        Empleado empleado;

        ifstream fileEmp("empleados.dat", ios::binary);
        if (!fileEmp.is_open()) {
            cerr << "Error: No se pudo abrir el archivo 'empleados.dat'." << endl;
            return;
        }
        else
        {
            cout << "\n\t\t\tLa informacion del empleado se ha impreso exitosamente." << endl;
            system("pause");
            Auditoria.ingresoBitacora(user,codigoPrograma,"IMP");//inpresion de archivo

            file <<"-----------------------------------------Tabla Detalles de empleados ----------------------------------------------" << endl;
            while (fileEmp.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado))){
                file << "\t\t\t Codigo de empleado     : " << empleado.codigo_empleado << endl;
                file << "\t\t\t Nombre de empleado     : " << empleado.nombre_empleado << endl;
                file << "\t\t\t Codigo de puesto       : " << empleado.codigo_puesto << endl;
                file << "\t\t\t Codigo de departamento : " << empleado.codigo_departamento << endl;
                file << "\t\t\t Sueldo del empleado    : Q" << empleado.sueldo_empleado << endl;
                file << "\t\t\t Status del empleado    : " << empleado.status_empleado << endl;
                file << "-----------------------------------------------------------------------------------------------------------------" << endl;
                }
        fileEmp.close();
        file.close();
        }
    }
}
