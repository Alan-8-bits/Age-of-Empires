#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <iostream>
#include <list>
#include "aldeano.h"
using namespace std;

class Civilizacion
{
private:
    list <Aldeano> aldeanos;
    string nombre;
    int ubicacion_x;
    int ubicacion_y;
public:
    void agregarInicio(const Aldeano &a);
    void agregarFinal(const Aldeano &a);
    void eliminarNombre(const string &nombre);
    void eliminarSalud(size_t s);
    void eliminarEdad();
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();
    size_t numeroAldeanos();
    void mostrar();

    Civilizacion();
    string getNombre() const;
    void setNombre(const string &value);
    int getUbicacion_x() const;
    void setUbicacion_x(int value);
    int getUbicacion_y() const;
    void setUbicacion_y(int value);

    bool operator < (Civilizacion &a)
    {
        return ubicacion_x<a.getUbicacion_x();
    }

    Aldeano* operator[](unsigned int pos)
    {
        auto it=aldeanos.begin();
        for (int i = 0; i < pos; i++) {
            it++;
        }
        return &*it;
    }
};

#endif // CIVILIZACION_H
