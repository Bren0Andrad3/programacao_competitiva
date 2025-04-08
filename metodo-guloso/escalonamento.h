#ifndef ESCALONAMENTO_H
#define ESCALONAMENTO_H

#include <vector>
#include <algorithm>

struct Evento {
    int inicio;
    int fim;

    bool operator<(const Evento& outro) const {
        return fim < outro.fim; // Ordena por tempo de término
    }
};

std::vector<Evento> selecionarEventosMaximos(std::vector<Evento> eventos) {
    std::sort(eventos.begin(), eventos.end());
    std::vector<Evento> resultado;

    int fimAnterior = 0;

    for (const Evento& e : eventos) {
        if (e.inicio >= fimAnterior) {
            resultado.push_back(e);
            fimAnterior = e.fim;
        }
    }

    return resultado;
}

#endif // ESCALONAMENTO_H
