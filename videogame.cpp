#include "videogame.h"
#include <algorithm>

string VideoGame::getNombre_usuario() const
{
    return nombre_usuario;
}

void VideoGame::setNombre_usuario(const string &value)
{
    nombre_usuario = value;
}

VideoGame::VideoGame()
{

}

void VideoGame::agregar_civilizacion(Civilizacion a, size_t pos)
{
    if(pos>civilizaciones.size()){
        cout<<"Posicion no valida"<<endl;
    }
    else{
        vector<Civilizacion>::iterator it= civilizaciones.begin();
        civilizaciones.insert(it+pos, a);
    }
}

void VideoGame::crear_civilizaciones(size_t n, const Civilizacion &a)
{
    civilizaciones= vector<Civilizacion>(n,a);
}

Civilizacion VideoGame::primera_civilizacion()
{
        return civilizaciones[0];
}

Civilizacion VideoGame::ultimo_civilizacion()
{
        return civilizaciones[civilizaciones.size()-1];
}

void VideoGame::ordenar()
{
    sort(civilizaciones.begin(),civilizaciones.end());
}

void VideoGame::eliminar_civilizacion(string nombre)
{
    if(civilizaciones.empty()){
        cout<<"No se ha creado ninguna civilizacion"<<endl;
    }
    else{
        for (size_t i = 0; i < civilizaciones.size(); i++) {
            if(nombre == civilizaciones[i].getNombre()){
                auto it=civilizaciones.begin();
                civilizaciones.erase(it+i);
            }
        }
    }
}

int VideoGame::total()
{
    return civilizaciones.size();
}

bool VideoGame::existe_civ(string nombre)
{
    for (size_t i = 0; i < civilizaciones.size(); i++) {
            if(nombre == civilizaciones[i].getNombre()){
                return true;
            }
        }
    return false;
}

Civilizacion* VideoGame::buscar_civilizaciones(string nombre)
{
    for (size_t i = 0; i < civilizaciones.size(); i++) {
            if(nombre == civilizaciones[i].getNombre()){
                return &civilizaciones[i];
            }
    }
}

size_t VideoGame::numero_civ(string nombre)
{
    for (size_t i = 0; i < civilizaciones.size(); i++) {
            if(nombre == civilizaciones[i].getNombre()){
                return i;
            }
    }
}
