#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "usuarios.h"
#include "Login.h"
#include "Bitacora.h"

#include "alumnos.h"
#include "maestros.h"
#include "Carrera.h"
#include "Facultad.h"
#include "Cursoss.h"
#include "jornada.h"
#include "aulas.h"
#include "secciones.h"
#include "Sedes.h"
#include "Horarios.h"

#include "matricula.h"
#include "Inscripcion.h"
#include "colegiatura.h"
#include "sueldos.h"

using namespace std;

void menuGeneral();
void informes();
void procesos();
void seguridad();
string codigoPrograma="1";
Bitacora Auditoria;
string user, contrasena;

int main()
{
        // Llamamos al objeto e ingresamos los parametros
    Login ingreso(user, contrasena);

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
    int choice;


    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG     |" << endl;
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
            informes();
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
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - CATALOGOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Alumnos" << endl;
        cout << "\t\t\t 2. Maestros" << endl;
        cout << "\t\t\t 3. Usuarios del sistema" << endl;
        cout << "\t\t\t 4. Carreras" << endl;
        cout << "\t\t\t 5. Facultades" << endl;
        cout << "\t\t\t 6. Cursos" << endl;
        cout << "\t\t\t 7. Jornadas" << endl;
        cout << "\t\t\t 8. Aulas" << endl;
        cout << "\t\t\t 9. Secciones" << endl;
        cout << "\t\t\t 10. Sedes" << endl;
        cout << "\t\t\t 11. Horarios" << endl;
        cout << "\t\t\t 12. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1-12]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            alumnos alumno;
            alumno.menu();
        }
            break;
        case 2:
        {
            maestros maestro;
            maestro.menu();
        }
            break;
        case 3:
        {
            usuarios usuario;
            usuario.menuUsuarios();
            break;
        }
        case 4:
        {
            CarrerasCRUD carrera;
            carrera.Crudcarrera();
        }
            break;
        case 5:
        {
            FacultadCRUD facultad;
            facultad.Crudfacultad();
        }
            break;
        case 6:
        {
            CursosCRUD cursos;
            cursos.CrudCursos();
        }
            break;
        case 7:
        {
            JornadaCRUD jornada;
            jornada.CrudJornada();
        }
            break;
        case 8:
        {
            AulasCRUD aulas;
            aulas.CrudAula();
        }
            break;
        case 9:
        {
            SeccionesCrud secciones;
            secciones.CrudSeccion();
        }
            break;
        case 10:
        {
            Sedes sede;
            sede.menu();
        }
            break;
        case 11:
        {
            Horarios horarios;
            horarios.menu();
        }
            break;
        case 12:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 12);
}

void informes()
{
    // Implementación de procesos
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - PROCESOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Matricula" << endl;
        cout << "\t\t\t 2. Inscripcion" << endl;
        cout << "\t\t\t 3. Colegiatura" << endl;
        cout << "\t\t\t 4. Sueldos" << endl;
        cout << "\t\t\t 5. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1-5]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            matricula matricula;
            matricula.menu();
        }
            break;
        case 2:
        {
            Inscripcion inscripcion;
            inscripcion.leerDatos();
        }
            break;
        case 3:
        {
            colegiatura colegiatura;
            colegiatura.leerDatos();
        }
            break;
        case 4:
        {
            sueldos sueldos;
            sueldos.menu();
        }
            break;
        case 5:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 5);
}

void reportes()
{
    // Implementación de reportes
}

void ayuda()
{
    // Implementación de ayuda
}

void seguridad()
{
    // Implementación de seguridad
    Bitacora Auditoria;
    Auditoria.visualizarBitacora();
}
