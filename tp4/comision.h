#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char item;

// char *listaApellidos[] = {"Perz", "Maerínez", "Días", "Robles", "Gonzales", "Areas"};
const item indefinido = '_';

//REPRESENTACIÓN DEL TDA
struct Alumno 
{
    item apellido;
    struct Alumno *siguiente;
} ;

typedef struct Alumno* Comision;

//PROTOTIPO DE OPERACIONES Y FUNCIONES
Comision comisionVacia();//
bool estaVacia(Comision M);//
Comision altaAlumno(Comision M, item a);//
int cantidad(Comision M);//
item ultimoInscripto(Comision M);//
bool esta(Comision M, item a);//
Comision bajaUltimo(Comision M);//
Comision bajaAlumno(Comision M, item a);

bool hayComunes(Comision M, Comision N);


//IMPLEMENTACION DE OPERACIONES
Comision comisionVacia()
{
    return NULL;
}

bool estaVacia(Comision M)
{
    return M == NULL;   
}

Comision altaAlumno(Comision M, item a)
{ //control si está en la comision
    struct Alumno *nuevo; //struct Alumno* nuevo;
    nuevo = (struct Alumno*)malloc(sizeof(struct Alumno));
    nuevo->apellido = a;
    nuevo->siguiente = M;
    M = nuevo;
    return M;
} 

int cantidad(Comision M)
{
    int cont = 0;
    while(!estaVacia(M)) {
        cont++;
        M = M->siguiente;
    }
    return cont;
}

item ultimoInscripto(Comision M)
{
    if(estaVacia)
        return indefinido;
    else 
        return M->apellido;
}

bool esta(Comision M, item a)
{
    while(!estaVacia(M) && a!=M->apellido) {
        M = M->siguiente;
    }
    return !estaVacia(M);
}

Comision bajaUltimo(Comision M)
{
    struct Alumno* aux;
    if (!estaVacia(M)) {
        aux = M;
        M = M->siguiente;
        free(aux);
    }
    return M;
}

Comision bajaAlumno(Comision M, item a)
{
    struct Alumno* temporal;
    struct Alumno* anterior;

    if(M == NULL)
        return NULL;

    if(M->siguiente != NULL) {
    
        anterior = M;
        temporal = M->siguiente;

        while (temporal != NULL) {
            
            if(temporal->apellido == a) {
                anterior->siguiente = temporal->siguiente;
                free(temporal);
                temporal = anterior->siguiente;

                return M;

            } else {
                anterior = anterior->siguiente;
                temporal = temporal->siguiente;
            }
        }
    } else {
        if(M->apellido == a) {
            free(M);
            return NULL;
        }    
    }
    return M;
}

// bool hayComunes(Comision M, Comision N)
// {
//     if(M == NULL)
//         return false;
//     if(N == NULL)
//         return false;
//     if(M->apellido == N->apellido)
//         return true;
//     else {
//         if(hayComunes(M, N->siguiente))
//             return true;
//         else
//             return hayComunes(M->siguiente, N);
//     }
// }

