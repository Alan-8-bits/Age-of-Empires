#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>
#include <iostream>
using namespace std;

class VideoGame
{
private:
    string nombre_usuario;
    vector<Civilizacion> civilizaciones;
public:
    VideoGame();
    void agregar_civilizacion(Civilizacion a, size_t pos);
    void crear_civilizaciones(size_t n,const Civilizacion &a);
    Civilizacion primera_civilizacion();
    Civilizacion ultimo_civilizacion();
    void ordenar();
    void eliminar_civilizacion(string nombre);
    int total();

    bool existe_civ(string nombre);
    Civilizacion *buscar_civilizaciones(string nombre);
    size_t numero_civ(string nombre);

    string getNombre_usuario() const;
    void setNombre_usuario(const string &value);

    Civilizacion &operator[](unsigned int pos)
{
    return civilizaciones[pos];
}
};

#endif // VIDEOGAME_H
