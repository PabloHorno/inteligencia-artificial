#ifndef MOCHILA_H_INCLUDED
#define MOCHILA_H_INCLUDED
#include "problema_bb.h"
#include <vector>
#include <string>
#include <fstream>

namespace mochila
{
    class Mochila:public bb::Problema_bb<unsigned>
    {
    public:
        Mochila(const std::string nombre_fichero):nombre_fichero(nombre_fichero)
        {
            std::ifstream fichero(nombre_fichero);
            if(fichero)
            {
                fichero>>num_variables;
            }
        }
        void imprime_solucion();
    private:
        //VIRTUALES
        void inicializa();
        void ordenacion_estatica_variables_ad_hoc();
        void restaura_estado(const std::pair<unsigned,unsigned> &asignacion);
        void actualiza_estado(const std::pair<unsigned,unsigned> &asignacion);
        bool consistente(const unsigned variable,const unsigned valor);
        void actualiza_solucion(std::vector<std::pair<unsigned,unsigned>>&sol);

        //ESPECIFICAS
        double cota_superior_mochila_fraccional();
        std::string nombre_fichero;
        double capacidad_maxima;
        double peso_actual;
        double valor_actual;
        double valor_optimo;
        std::vector<double> pesos;
        std::vector<double> valores;

    };

}
#endif // MOCHILA_H_INCLUDED
