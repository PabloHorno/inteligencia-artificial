#include "reinas.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
namespace reinas
{
    void Reinas::inicializa_dominio()
    {
        dominio = std::vector<std::vector<unsigned>>(num_variables,std::vector<unsigned>(num_variables,0));
        for(unsigned i=0; i!=num_variables; ++i)
        {
            for(unsigned j=0; j!=num_variables; ++j)
            {
                dominio[i].at(j)=j;
            }
        }
        columna.clear();
        diag_45.clear();
        diag_135.clear();
    }

    void Reinas::actualiza_estado(const std::pair<unsigned,unsigned> &asignacion)
    {
        auto variable=asignacion.first;
        auto valor=asignacion.second;
        columna.insert(valor);
        diag_45.insert(variable+valor);
        diag_135.insert(num_variables+variable-valor);
    }

    void Reinas::restaura_estado(const std::pair<unsigned,unsigned> &asignacion)
    {
        auto variable=asignacion.first;
        auto valor=asignacion.second;
        columna.erase(valor);
        diag_45.erase(variable+valor);
        diag_135.erase(num_variables+variable-valor);
    }

    void imprime_solucion(std::vector<std::pair<unsigned,unsigned>>& solucion)
    {
        std::sort(solucion.begin(),solucion.end());
        for(auto v:solucion)
        {
            std::cout<<"("<<v.first<<","<<v.second<<")"<<std::endl;
        }
    }
}
