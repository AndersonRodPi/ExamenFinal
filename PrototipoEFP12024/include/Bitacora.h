#ifndef BITACORA_H
#define BITACORA_H
#include <iostream>


using namespace std;
class Bitacora
{
    public:
        void ingresoBitacora(string nombre, string numAccion, string accion);
        void visualizarBitacora();

    private:
        string nombre, accion, numAccion;
		char* date_time;
};

#endif // BITACORA_H
