#include "aldeano.h"

string Aldeano::getNombre() const
{
    return nombre;
}

void Aldeano::setNombre(const string &value)
{
    nombre = value;
}

size_t Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setEdad(const size_t &value)
{
    edad = value;
}

string Aldeano::getGenero() const
{
    return genero;
}

void Aldeano::setGenero(const string &value)
{
    genero = value;
}

size_t Aldeano::getSalud() const
{
    return salud;
}

void Aldeano::setSalud(const size_t &value)
{
    salud = value;
}

Aldeano::Aldeano()
{

}
