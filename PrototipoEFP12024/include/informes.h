#ifndef INFORMES_H
#define INFORMES_H

#include <iostream>

using namespace std;

class informes
{
    private:
        string imp_codigo, imp_nombre, imp_puesto, imp_departamento, imp_sueldo, imp_status;

    public:
        void imprimirArchivo();

        struct Empleado {
            char codigo_empleado[5];
            char nombre_empleado[60];
            char codigo_puesto[5];
            char codigo_departamento[5];
            char sueldo_empleado[20];
            char status_empleado[5];
            };
};

#endif // INFORMES_H
