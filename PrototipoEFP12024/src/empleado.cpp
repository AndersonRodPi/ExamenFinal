//Programa que permite insertar, desplegar, modificar y borrar empleados
#include "empleado.h" // Incluye el archivo de cabecera Sedes.h que contiene la declaración de la clase Sedes
#include "usuarios.h"
#include<iostream> // Incluye la biblioteca estándar para entrada y salida
#include<fstream> // Incluye la biblioteca para manejo de archivos
#include<stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad
#include<cstdlib> // Incluye la biblioteca estándar para funciones de utilidad
#include<iomanip> // Incluye la biblioteca para manipulación de la salida
#include <sstream> // Incluye la biblioteca para operaciones de flujo de cadena
#include <cstring> // Incluye la biblioteca para operaciones de cadena
#include"Bitacora.h"

using namespace std; // Usa el espacio de nombres estándar

// Definición de la estructura Sede que contiene los datos de una sede
struct Empleado {
    char codigo_empleado[5];
    char nombre_empleado[60];
    char codigo_puesto[5];
    char codigo_departamento[5];
    char sueldo_empleado[20];
    char status_empleado[1];
};


// Definición de las funciones miembro de la clase Sedes
void empleado::menu()
{
    //implementacion de variables para bitacora
    string codigoPrograma = "100";
    Bitacora Auditoria;
    string user = "admin";
    int choice; // Variable para almacenar la opción seleccionada por el usuario
    char x; // Variable para almacenar la respuesta de agregar otra sede

    // Ciclo para mostrar el menú y procesar las opciones del usuario
    do
    {
        system("cls"); // Limpia la pantalla

        // Imprime el encabezado del menú
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\t| SISTEMA DE GESTION EMPLEADOS -  100  |"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\t 1. Ingreso empleados"<<endl;
        cout<<"\t\t\t 2. Despliegue empleados"<<endl;
        cout<<"\t\t\t 3. Modifica empleados"<<endl;
        cout<<"\t\t\t 4. Borra empleados"<<endl;
        cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\tIngresa tu Opcion: ";
        cin>>choice; // Lee la opción del usuario

        switch(choice) // Evalúa la opción seleccionada por el usuario
        {
        case 1:
            // Agregar sede
            do
            {
                insertar(); // Llama a la función para agregar una sede
                //registro de bitacora ingreso
                Auditoria.ingresoBitacora(user,codigoPrograma,"INS");//ingreso matricula
                cout<<"\n\t\t\t Agrega otra Sede(Y,N): ";
                cin>>x; // Pregunta al usuario si quiere agregar otra sede
            } while(x=='y'||x=='Y'); // Repite el proceso si el usuario responde 'y' o 'Y'
            break;
        case 2:
            desplegar(); // Llama a la función para mostrar las sedes
            //registro de bitacora
            Auditoria.ingresoBitacora(user,codigoPrograma,"CON");//ingreso matricula
            break;
        case 3:
            modificar(); // Llama a la función para modificar una sede
            //registro de bitacora
            Auditoria.ingresoBitacora(user,codigoPrograma,"MOD");//ingreso matricula
            break;
        case 4:
            borrar(); // Llama a la función para borrar una sede
            //registro de bitacora ingreso
            Auditoria.ingresoBitacora(user,codigoPrograma,"DEL");//ingreso matricula
            break;
        case 5:
            break; // Salir del menú
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get(); // Espera a que el usuario presione Enter
        }
    } while(choice!= 5); // Repite el menú hasta que el usuario seleccione la opción 5
}

// Función para agregar una sede
void empleado::insertar() {
    system("cls"); // Limpia la pantalla
    Empleado empleado; // Crea una instancia de la estructura Empleado para almacenar los datos del empleado
    ofstream file("empleados.dat", ios::binary | ios::app);

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    // Solicita al usuario ingresar los datos de la sede
    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------Agregar Sede-------------------------------------------------------" << endl;
    cout << "\t\t\tIngrese codigo del empleado   : ";
    cin.ignore();//limpia el buffer de entrada del flujo de entrada estándar
    cin.getline(empleado.codigo_empleado, sizeof(empleado.codigo_empleado));//guarda el id en la instancia que se creo de la estructura empleado
    cout << "\t\t\tIngrese nombre del empleado   : ";
    cin.getline(empleado.nombre_empleado, sizeof(empleado.nombre_empleado));
    cout << "\t\t\tIngrese codigo de puesto      : ";
    cin.getline(empleado.codigo_puesto, sizeof(empleado.codigo_puesto));
    cout << "\t\t\tIngrese codigo de departamento: ";
    cin.getline(empleado.codigo_departamento, sizeof(empleado.codigo_departamento));
    cout << "\t\t\tIngrese el sueldo del empleado: ";
    cin.getline(empleado.sueldo_empleado, sizeof(empleado.sueldo_empleado));
    cout << "\t\t\tIngrese status del empleado (solvente=1 | pendiente=0): ";
    cin.getline(empleado.status_empleado, sizeof(empleado.status_empleado));
    // Escribe los datos del empleado en el archivo
    file.write(reinterpret_cast<const char*>(&empleado), sizeof(Empleado));
    file.close(); // Cierra el archivo
}

// Función para mostrar todas las sedes
void empleado::desplegar(){
    system("cls"); // Limpia la pantalla
    ifstream file("empleados.dat", ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    int total = 0; // Contador para el total de sedes

    // Muestra la tabla de detalles de sedes
    cout << "\n-----------------------------------------Tabla Detalles de empleados ----------------------------------------------" << endl;
    Empleado empleado; // Crea una instancia de la estructura empleado para almacenar los datos de cada empleado
    while (file.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado))) { // Lee los datos de los empleados del archivo
        cout << "\t\t\t Codigo de empleado     : " << empleado.codigo_empleado<< endl;
        cout << "\t\t\t Nombre de empleado     : " << empleado.nombre_empleado << endl;
        cout << "\t\t\t Codigo de puesto       : " << empleado.codigo_puesto << endl;
        cout << "\t\t\t Codigo de departamento : " << empleado.codigo_departamento << endl;
        cout << "\t\t\t Sueldo del empleado    : " << empleado.sueldo_empleado << endl;
        cout << "\t\t\t Status del empleado    : " << empleado.status_empleado << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        total++; // Incrementa el contador de sedes
    }

    if (total == 0) { // Verifica si no hay sedes en el archivo
        cout << "\n\t\t\tNo hay informacion..." << endl; // Muestra un mensaje indicando que no hay información
    }

    file.close(); // Cierra el archivo
    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver la información
}

// Función para modificar los detalles de una sede
void empleado::modificar() {
    system("cls"); // Limpia la pantalla
    fstream file("empleados.dat", ios::in | ios::out | ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura/escritura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cout << "\n\t\t\tNo hay información..."; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    string id_modificar; // Variable para almacenar el ID del emplead que se desea modificar
    int found = 0; // Variable para indicar si se encontró la sede a modificar

    cout << "\n-------------------------------------Modificar Detalles de empleado----------------------------------------------" << endl;
    cout << "\t\t\tIngrese codigo del empleado que desea modificar: ";
    cin >> id_modificar; // Lee el ID del empleado que se desea modificar

    Empleado empleado; // Crea una instancia de la estructura Empleado para almacenar los datos del empleado
    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo de escritura binaria

    // Verifica si el archivo temporal se abrió correctamente
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal..."; // Muestra un mensaje de error si no se puede abrir el archivo temporal
        return; // Retorna
    }

    // Lee los empleado del archivo y modifica los detalles de la sede con el ID proporcionado
    while (file.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado))) {
        if (strcmp(empleado.codigo_empleado, id_modificar.c_str()) == 0) { // Compara el ID de la sede actual con el ID proporcionado
            cout << "\t\t\tIngrese nuevo codigo del empleado: ";
            cin >> empleado.codigo_empleado; // Solicita al usuario ingresar el nuevo ID de la sede
            cout << "\t\t\tIngrese nuevo nombre del empleado: ";
            cin.ignore();
            cin.getline(empleado.nombre_empleado, sizeof(empleado.nombre_empleado)); // Solicita al usuario ingresar el nuevo nombre de la sede
            cout << "\t\t\tIngrese nuevo codigo de puesto: ";
            cin.getline(empleado.codigo_puesto, sizeof(empleado.codigo_puesto)); // Solicita al usuario ingresar el nuevo teléfono de la sede
            cout << "\t\t\tIngrese nuevo codigo de departamento: ";
            cin.getline(empleado.codigo_departamento, sizeof(empleado.codigo_departamento));
            cout << "\t\t\tIngrese el nuevo sueldo del empleado: ";
            cin.getline(empleado.sueldo_empleado, sizeof(empleado.sueldo_empleado));
            cout << "\t\t\tIngrese el nuevo status del empleado (solvente=1 | pendiente=0): ";
            cin.getline(empleado.status_empleado, sizeof(empleado.status_empleado));

            file1.write(reinterpret_cast<const char*>(&empleado), sizeof(Empleado)); // Escribe los datos de la sede modificada en el archivo temporal

            cout << "\n\t\t\tEmpleado modificado correctamente!!!" << endl; // Muestra un mensaje indicando que la sede se modificó correctamente
            found++; // Incrementa el contador de sedes encontradas
        } else {
            file1.write(reinterpret_cast<const char*>(&empleado), sizeof(Empleado)); // Escribe los datos de la sede sin modificar en el archivo temporal
        }
    }

    if (!found) { // Verifica si no se encontró la sede con el ID proporcionado
        cout << "\n\t\t\tNo se encontro el empleado con el codigo proporcionado." << endl; // Muestra un mensaje indicando que no se encontró la sede
    }

    file.close(); // Cierra el archivo original
    file1.close(); // Cierra el archivo temporal
    remove("empleados.dat"); // Elimina el archivo original
    rename("temporal.dat", "empleados.dat"); // Renombra el archivo temporal como "Sedes.dat"
    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver el mensaje
}

// Función para borrar una sede
void empleado::borrar() {
    system("cls"); // Limpia la pantalla
    string id_borrar; // Variable para almacenar el ID de la sede que se desea borrar
    int found = 0; // Variable para indicar si se encontró la sede a borrar

    cout << "\n------------------------------------------Detalles del empleado a Borrar-----------------------------------------------" << endl;

    ifstream file("empleados.dat", ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cout << "\n\t\t\tNo hay informacion..."; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo de escritura binaria

    // Verifica si el archivo temporal se abrió correctamente
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal..."; // Muestra un mensaje de error si no se puede abrir el archivo temporal
        return; // Retorna
    }

    cout << "\n-----------------------------------------Sistema Busqueda de empleados---------------------------------------------" << endl;
    cout << "\n\t\t Ingrese el codigo del empleado que quiere Borrar: ";
    cin >> id_borrar; // Lee el ID de la sede que se desea borrar

    Empleado empleado; // Crea una instancia de la estructura Sede para almacenar los datos de la sede
    while (file.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado))) { // Lee las sedes del archivo
        if (strcmp(empleado.codigo_empleado, id_borrar.c_str()) == 0) { // Compara el ID de la sede actual con el ID proporcionado
            cout << "\n\t\t\tBorrado de informacion exitoso!!!!" << "\n" << endl; // Muestra un mensaje indicando que la sede se borró exitosamente
            found++; // Incrementa el contador de sedes encontradas
        } else {
            file1.write(reinterpret_cast<const char*>(&empleado), sizeof(Empleado)); // Escribe los datos de la sede sin borrar en el archivo temporal
        }
    }

    if (found == 0) { // Verifica si no se encontró la sede con el ID proporcionado
        cout << "\n\t\t\t Codigo del empleado no encontrado...." << "\n" << endl; // Muestra un mensaje indicando que no se encontró la sede
    }

    file1.close(); // Cierra el archivo temporal
    file.close(); // Cierra el archivo original

    remove("empleados.dat"); // Elimina el archivo original
    rename("temporal.dat", "empleados.dat"); // Renombra el archivo temporal como "Sedes.dat"

    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver el mensaje
}
