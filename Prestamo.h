#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "Fecha.h"
#include "Pago.h"
#include "Cliente.h"
#define TAM 5

using namespace std;

class Prestamo{
    private:
        int idPrestamo;
        Cliente *cliente;
        Fecha *fecha;
        float montoAprobado;
        Pago *listaPagos[TAM];
        float saldoPendiente;
        int contadorPagos;

    public:
        Prestamo(int id){
            this->idPrestamo = id;
            this->montoAprobado = 0;
            this->saldoPendiente = 0;
            this->contadorPagos = 0;
        }

        int getIdPrestamo(){
            return this->idPrestamo;
        }

        void setCliente(Cliente *cli){
            this->cliente = cli;
        }

        Cliente *getCliente(){
            return this->cliente;
        }

        void setFecha(Fecha *f){
            this->fecha = f;
        }

        Fecha *getFecha(){
            return this->fecha;
        }

        void setMontoAprobado(float ma){
            this->montoAprobado = ma;
            this->saldoPendiente = ma;
        }

        float getMontoAprobado(){
            return this->montoAprobado;
        }

        void registrarPagos(Pago *pg){
            if(this->contadorPagos < TAM){
               this->listaPagos[this->contadorPagos] = pg;
               this->contadorPagos++;
               this->saldoPendiente -= pg->getMonto();
            }
            else{
                cout << "La lista de pagos esta llena\n";
            }
        }

        Pago **getListaPagos(){
            return this->listaPagos;
        }

        float getSaldoPendiente(){
            return this->saldoPendiente;
        }

        int getContadorPagos(){
            return this->contadorPagos;
        }
};

#endif // PRESTAMO_H_INCLUDED
