#ifndef TROCO_H
#define TROCO_H

#include <vector>

std::vector<int> calcularTroco(int valor, const std::vector<int>& moedas) {
    std::vector<int> resultado;

    for (int moeda : moedas) {
        while (valor >= moeda) {
            valor -= moeda;
            resultado.push_back(moeda);
        }
    }

    return resultado;
}

#endif // TROCO_H
