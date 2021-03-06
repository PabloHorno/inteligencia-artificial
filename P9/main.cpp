#include "sudoku.h"
#include "cronometro.h"
int main()
{
    sudoku::Sudoku sud1("sudoku2.txt");

    Cronometro<std::milli> crono;

    crono.inicio();
    if(sud1.resolver(csp::Seleccion_variable::mrv,csp::Algoritmo::fc_ac1))
    {
        std::cout<<"SOLUCION"<<std::endl;
        sudoku::imprime_solucion(sud1.get_solucion());
        std::cout<<"\nNODOS VISITADOS= "<<sud1.get_nodos_expandidos()<<std::endl;
    }
    crono.fin();
    std::cout<<"Tiempo empleado: "<<crono<<" ms."<<std::endl;
    std::cout<<std::endl;

    return 0;
}
