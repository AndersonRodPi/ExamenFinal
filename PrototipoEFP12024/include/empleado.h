#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>

using namespace std;

class empleado
{
    private:
        char codigo_empleado[5];
        char nombre_empleado[60];
        char codigo_puesto[5];
        char codigo_departamento[5];
        char sueldo_empleado[20];
        char status_empleado[5];
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void borrar();
};


#endif // EMPLEADO_H
