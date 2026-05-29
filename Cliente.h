#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>

using namespace std;

class Cliente{

    //Atributos
    private:
        int idCliente;
        string Nombre;
        string Apellido;

    public:
        //Constructor
        Cliente(int id, string n, string a){
            this->idCliente = id;
            this->Nombre = n;
            this->Apellido = a;
        }

        //Getters
        int getIdCliente(){
            return this->idCliente;
        }

        string getNombre(){
            return this->Nombre;
        }

        string getApellido(){
            return this->Apellido;
        }

};

#endif // CLIENTE_H_INCLUDED
