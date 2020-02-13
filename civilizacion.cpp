#include "civilizacion.h"
#include <iomanip>

string Civilizacion::getNombre() const
{
    return nombre;
}

void Civilizacion::setNombre(const string &value)
{
    nombre = value;
}

int Civilizacion::getUbicacion_x() const
{
    return ubicacion_x;
}

void Civilizacion::setUbicacion_x(int value)
{
    ubicacion_x = value;
}

int Civilizacion::getUbicacion_y() const
{
    return ubicacion_y;
}

void Civilizacion::setUbicacion_y(int value)
{
    ubicacion_y = value;
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for(auto it = aldeanos.begin();it!= aldeanos.end();++it)
    {
        Aldeano &a =*it;
        if(nombre == a.getNombre()){
           aldeanos.erase(it);
           break;
        }
    }
}

void Civilizacion::eliminarSalud(size_t s)
{
    aldeanos.remove_if([s](const Aldeano &a){return a.getSalud()<s;});
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if([](const Aldeano &a){return a.getEdad()>=60;});
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort();
}

bool comparador(const Aldeano &a,const Aldeano &b)
{
    return a.getEdad()>b.getEdad();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort(comparador);
}

bool comparadorSalud(const Aldeano &a,const Aldeano &b)
{
    return a.getSalud()>b.getSalud();
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort(comparadorSalud);
}

size_t Civilizacion::numeroAldeanos()
{
    return aldeanos.size();
}

void Civilizacion::mostrar()
{
    cout<<left;
    cout<<setw(10)<<"Nombre"
        <<setw(10)<<"Edad"
        <<setw(10)<<"Genero"
        <<setw(10)<<"Salud"
        <<endl;
    for(auto it=aldeanos.begin();it!= aldeanos.end();it++){
        Aldeano &j = *it;
        cout<<setw(10)<<j.getNombre()
        <<setw(10)<<j.getEdad()
        <<setw(10)<<j.getGenero()
        <<setw(10)<<j.getSalud()
        <<endl;
    }

}

Civilizacion::Civilizacion()
{

}
