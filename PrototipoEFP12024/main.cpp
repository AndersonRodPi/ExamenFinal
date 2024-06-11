#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Login.h"
#include "Bitacora.h"

#include "empleado.h"
#include "informes.h"

using namespace std;

void menuGeneral();
void catalogos();
void Informes();
void seguridad();
string codigoPrograma="1";
Bitacora Auditoria;
string usuario, contrasena;

int main()
{
        // Llamamos al objeto e ingresamos los parametros
    Login ingreso(usuario, contrasena);

    // Creamos un bool que verifique y despliegue el metodo VerificarUsuario
    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    // Luego de ingresar con usuario y contraseña se nos despliega otro menu
    if (UsuarioCorrecto)
    {
        menuGeneral();
    }

    return 0;
}

void menuGeneral()
{
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
    int choice;


    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t| SISTEMA DE GESTION EMPLEADOS |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Informes" << endl;
        cout << "\t\t\t 3. Seguridad" << endl;
        cout << "\t\t\t 4. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;
        case 2:
            Informes();
            break;
        case 3:
            seguridad();
            break;
        case 4:
                    Auditoria.ingresoBitacora(user,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
            exit(0);
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 4);
}

void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t| SISTEMA DE GESTION EMPLEADOS - CATALOGOS |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Empleados" << endl;
        cout << "\t\t\t 2. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            //implementacion de empleados
            empleado empleados;
            empleados.menu();
        }
            break;
        case 2:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 2);
}

void Informes()
{
    // Implementación de informes
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t| SISTEMA DE IMPRESION DE EMPLEADOS - 1200 |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Implesion de archivo txt" << endl;
        cout << "\t\t\t 2. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            //Implementación de inpresion
            informes informe;
            informe.imprimirArchivo();
        }
            break;
        case 2:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 2);
}

void seguridad()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - PROCESOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Consultar bitacora" << endl;
        cout << "\t\t\t 2. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Bitacora Auditoria;
            Auditoria.visualizarBitacora();
        }
            break;
        case 2:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 2);
}
