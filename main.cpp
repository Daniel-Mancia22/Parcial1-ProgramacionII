#include <iostream>
#define DIM 5
#include <stdlib.h>
#include "Cliente.h"
#include "Prestamo.h"
#include "Pago.h"
#include "Fecha.h"
#include <conio.h>

using namespace std;

Cliente *agregarCliente(){

    //Variables temporales
    int id;
    string n, a;

    // Se declara un puntero. Aún no apunta a nada concreto.
    Cliente *cli;

    cout << "----------------------------------\n";
    cout << "Ingrese el id del cliente: ";
    cin >> id;
    cout << "Ingrese el Nombre del cliente: ";
    cin >> n;
    cout << "Ingrese el Apellido del cliente: ";
    cin >> a;
    cout << "----------------------------------\n";
    cout << endl;

    // 'new' reserva espacio en el HEAP.
    // 'cli' ahora guarda la dirección de ese espacio.
    cli = new Cliente(id, n, a);

    // Retornamos la dirección para que el programa principal
    // sepa dónde encontrar a este nuevo cliente.
    return cli;
}

void mostrarClientes(Cliente *lst[], int cont){
    if(cont==0){
            cout << "----------------------------------\n";
            cout << "La lista esta vacia\n";
            cout << "----------------------------------\n";
    }
    else{
        cout << "**********************************\n";
        cout << "ID\tNOMBRE\tAPELLIDO\n";
        cout << "**********************************\n";

        for(int i=0; i<cont;i++){
            cout << lst[i]->getIdCliente() << "\t";
            cout << lst[i]->getNombre() << "\t";
            cout << lst[i]->getApellido() << "\n";
            cout << "----------------------------------\n";
        }
    }
}

Prestamo *agregarPrestamo(Cliente *cli){
    int id, d, m, a;
    Fecha *fp;
    float ma;

    Prestamo *ptmo;

    cout << "----------------------------------\n";
    cout << "Ingrese el id del prestamo: ";
    cin >> id;
    cout << "Ingrese la fecha de aprobacion (dd,mm,aa): \n";
    cin >> d;
    cin >> m;
    cin >> a;
    cout << "Ingrese el monto aprobado: ";
    cin >> ma;
    cout << "----------------------------------\n";
    cout << endl;

    fp = new Fecha(d, m, a);
    ptmo = new Prestamo(id);

    ptmo->setCliente(cli);
    ptmo->setFecha(fp);
    ptmo->setMontoAprobado(ma);

    return ptmo;
}

void mostrarPrestamos(Prestamo *lst[], int cont){
    if(cont==0){
            cout << "----------------------------------\n";
            cout << "La lista esta vacia\n";
            cout << "----------------------------------\n";
    }
    else{
        cout << "****************************************\n";
        cout << "ID\tCLIENTE\t\tMONTO\tFECHA\n";
        cout << "****************************************\n";

        for(int i = 0; i<cont; i++){
            cout << lst[i]->getIdPrestamo() << "\t";
            cout << lst[i]->getCliente() ->getNombre() << " " << lst[i]->getCliente()->getApellido() << "\t";
            cout << lst[i]->getMontoAprobado() << "\t";
            lst[i]->getFecha()->mostrarFecha(); cout <<endl;
            cout << "-----------------------------------------\n";
            cout << endl;
        }
    }
}

Cliente *buscarCliente(Cliente *lst[], int cont, int id){
    Cliente *cli = NULL;
    int c = 0;
    bool encontrado = false;

    while (c < cont && !encontrado){
        if(lst[c]->getIdCliente()== id){
            encontrado = true;
            cli = lst[c];
        }
        else{
            c++;
        }
    }
    return cli;
}

Prestamo *buscarPrestamo(Prestamo *lst[], int cont, int id){
    Prestamo *ptmo = NULL;
    int c = 0;
    bool encontrado = false;

    while (c < cont && !encontrado){
        if(lst[c]->getIdPrestamo()== id){
            encontrado = true;
            ptmo = lst[c];
        }
        else{
            c++;
        }
    }
    return ptmo;
}

void MostrarDetallePrestamo(Prestamo *ptmo){
    cout << "----------------------------------\n";
    cout << "Id Prestamo: " << ptmo->getIdPrestamo() << endl;
    cout << "Cliente: " << ptmo->getCliente()->getNombre() << " " << ptmo->getCliente()->getApellido() << endl;
    cout << "Fecha aprobacion: ";
    ptmo->getFecha()->mostrarFecha();
    cout << endl;

    cout << "Monto aprobado: " << ptmo->getMontoAprobado() << endl;
    cout << "Saldo pendiente: " << ptmo->getSaldoPendiente() << endl;
    cout << "----------------------------------\n";
    cout << endl;

    if (ptmo->getContadorPagos() == 0){
        cout << "----------------------------------\n";
        cout << "No hay pagos registrados\n";
        cout << "----------------------------------\n";
    }
    else{
        Pago **lista = ptmo->getListaPagos();
        cout << "**********************************\n";
        cout << "No\tFECHA\t\tMONTO\n";
        cout << "**********************************\n";
        for (int i=0; i<ptmo->getContadorPagos();i++){
            cout << (i+1) << "\t";
            lista[i]->getFechaPago()->mostrarFecha();
            cout << "\t\t";
            cout << lista[i]->getMonto()<<endl;
            cout << "----------------------------------\n";
        }
    }
}

int menu (){
    int op;

    cout << "Menu de opciones\n";
    cout << "**********************************\n";
    cout << "1. Agregar clientes a la lista\n";
    cout << "2. Agregar prestamo a la lista\n";
    cout << "3. Hacer pagos de prestamos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de prestamos\n";
    cout << "6. Mostar detalles del prestamo\n";
    cout << "7. Salir\n";
    cout << "**********************************\n";
    cout << "Digite la opcion: "; cin >> op;
    cout << endl;

    return op;
}


int main (){
    Cliente *lstCliente[DIM];
    int contCliente = 0;
    Prestamo *lstPrestamo[DIM];
    int contPrestamo = 0;
    int opc, id, d, m, a;
    float mp;

    do{
            system("cls");
            opc = menu();
            switch (opc){
                case 1:
                    ///Agregar cliente.
                    if(contCliente < DIM){
                        lstCliente[contCliente] = agregarCliente();
                        contCliente++;
                        cout << "----------------------------------\n";
                        cout << "El cliente se agrego con exito.\n";
                        cout << "----------------------------------\n";
                    }
                    else{
                        cout << "-----------------------------------\n";
                        cout << "La lista de clientes esta llena\n";
                        cout << "-----------------------------------\n";
                    }
                    break;

                case 2:
                    ///Agregar prestamo.
                    if(contPrestamo < DIM){
                        cout << "----------------------------------\n";
                        cout << "Digite el id del cliente: "; cin >> id;

                        Cliente *cli = buscarCliente(lstCliente, contCliente, id);

                        if(cli != NULL){
                            ///Se encontro.
                            lstPrestamo[contPrestamo] = agregarPrestamo(cli);
                            contPrestamo++;

                            cout << "----------------------------------\n";
                            cout << "El prestamo se registro con exito\n";
                            cout << "----------------------------------\n";
                        }
                        else{
                            cout << "----------------------------------\n";
                            cout << "El cliente no esta en la lista\n";
                            cout << "----------------------------------\n";
                        }
                    }
                    else{
                        cout << "----------------------------------\n";
                        cout << "La lista de prestamos esta llena\n";
                        cout << "----------------------------------\n";
                    }
                    break;

                case 3:
                    ///Hacer pagos.
                    {
                        cout << "----------------------------------\n";
                        cout << "Digite el id del prestamo: "; cin >> id;

                        Prestamo *ptmo = buscarPrestamo(lstPrestamo, contPrestamo, id);

                        if(ptmo!=NULL){
                            ///se encontro.
                            cout << "----------------------------------\n";
                            cout << "Digite la fecha de pago (dd,mm,aa): \n";
                            cin >> d;
                            cin >> m;
                            cin >> a;
                            Fecha *fp = new Fecha(d, m, a);

                            cout << "Digite el monto: "; cin>> mp;
                            cout << "----------------------------------\n";
                            cout << endl;

                            Pago *pg = new Pago(fp, mp);
                            ptmo->registrarPagos(pg);

                            cout << "----------------------------------\n";
                            cout << "El pago se registro con exito\n";
                            cout << "----------------------------------\n";
                        }
                        else{
                            cout << "----------------------------------\n";
                            cout << "No se encontro el prestamo\n";
                            cout << "----------------------------------\n";
                        }
                    }
                    break;

                case 4:
                    ///Mostrar lst cliente.
                    mostrarClientes(lstCliente, contCliente);
                    break;

                case 5:
                    ///Mostrar lst prestamo.
                    mostrarPrestamos(lstPrestamo, contPrestamo);
                    break;

                case 6:
                    ///Ver detalles de prestamo.
                    {
                        cout << "----------------------------------\n";
                        cout << "Digite el id del prestamo: "; cin >> id;

                        Prestamo *ptmo = buscarPrestamo(lstPrestamo, contPrestamo, id);

                        if (ptmo != NULL){
                            ///se encontro.
                            MostrarDetallePrestamo(ptmo);
                        }
                        else{
                            cout << "----------------------------------\n";
                            cout << "El prestamo no esta en la lista\n";
                            cout << "----------------------------------\n";
                        }
                    }
                    break;

                case 7:
                    cout << "----------------------------------\n";
                    cout << "Abandonando el programa\n";
                    cout << "----------------------------------\n";
                    break;

                default:
                    cout << "----------------------------------\n";
                    cout << "Error, la opcion no esta definida\n";
                    cout << "----------------------------------\n";
            }
            system("pause");
        }while(opc !=7);

        return 0;
    }
