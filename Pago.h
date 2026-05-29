#ifndef PAGO_H_INCLUDED
#define PAGO_H_INCLUDED
#include "Fecha.h"

using namespace std;

class Pago{
    private:
        Fecha *fechaPago;
        float monto;

    public:
        Pago(Fecha *fp, float mp){
            this->fechaPago = fp;
            this->monto = mp ;
        }

        Fecha *getFechaPago(){
            return this->fechaPago;
        }

        float getMonto(){
            return this->monto;
        }
};

#endif // PAGO_H_INCLUDED
