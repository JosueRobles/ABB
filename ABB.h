#ifndef ABB_H
#define ABB_H
#include <iostream>
struct Nodo
{
    int dato;
    Nodo *der;
    Nodo *izq;
};
void menu();
Nodo *crearNodo(int);
Nodo *arbol = NULL;
void insert(Nodo *&, int);
void print(Nodo *, int);

void menu()
{
    int dato, op, contador=0;
    do
    {
        std::cout << "Seleccione una opcion: " << "\n";
        std::cout << "1) Insertar un nuevo nodo" << "\n";
        std:: cout << "2) Mostrar nodos" << "\n";
        std::cout << "Opcion: ";
        std::cin >> op;
        switch(op)
        {
            case 1:
                std::cout << "Digite un numero: ";
                std::cin >> dato;
                insert(arbol,dato);
                std::cout << "\n";
                break;
            case 2:
                print(arbol,contador);
                std::cout << "\n";
                system("pause");
                break;
        }
        system("cls");
    }while(op!=5);
}
Nodo *crearNodo(int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}
void insert(Nodo *&arbol, int n)
{
    if(arbol == NULL)
    {
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else
    {
        int valorRaiz = arbol->dato;
        if(n < valorRaiz)
        {
            insert(arbol->izq,n);
        }
        else
        {
            insert(arbol->der,n);
        }
    }
}
void print(Nodo *arbol, int cont)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        print(arbol->der,cont+1);
        for(int i=0;i<cont;i++)
        {
            std::cout << "   ";
        }
        std::cout << arbol->dato << "\n";
        print(arbol->izq,cont+1);
    }
}
#endif
