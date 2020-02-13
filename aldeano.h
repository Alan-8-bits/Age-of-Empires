#ifndef ALDEANO_H
#define ALDEANO_H

#include "iostream"
using namespace std;

class Aldeano
{
private:
    string nombre;
    size_t edad;
    string genero;
    size_t salud;
public:
    Aldeano();
    string getNombre() const;
    void setNombre(const string &value);
    size_t getEdad() const;
    void setEdad(const size_t &value);
    string getGenero() const;
    void setGenero(const string &value);
    size_t getSalud() const;
    void setSalud(const size_t &value);

    bool operator <(const Aldeano &a){
        return nombre<a.getNombre();
    }
};

#endif // ALDEANO_H
