#ifndef USUMAESTROS_H
#define USUMAESTROS_H
#include <iostream>

using namespace std;

class usumaestros
{
    public:
        void menu();
        void pideDatos();
        void muestraDatos();
        void editaDatos();
        void borraDatos();

    private:
        string nombre, contra;
};

#endif // USUMAESTROS_H
