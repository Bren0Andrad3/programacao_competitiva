#include <iostream>
#include "mochila.h"
#include "troco.h"
#include "escalonamento.h"

int main() {
    // Mochila Fracionária
    std::vector<Item> itens = {{60, 10}, {100, 20}, {120, 30}};
    double capacidade = 50;
    std::cout << "Valor máximo na mochila: " << mochilaFracionaria(itens, capacidade) << "\n\n";

    // Problema do Troco
    std::vector<int> moedas = {25, 10, 5, 1}; // em centavos
    int troco = 63;
    std::vector<int> resultadoTroco = calcularTroco(troco, moedas);
    std::cout << "Moedas usadas para troco de " << troco << " centavos: ";
    for (int m : resultadoTroco) std::cout << m << " ";
    std::cout << "\n\n";

    // Escalonamento de Tarefas
    std::vector<Evento> eventos = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
    std::vector<Evento> selecionados = selecionarEventosMaximos(eventos);
    std::cout << "Eventos selecionados:\n";
    for (const Evento& e : selecionados) {
        std::cout << "Início: " << e.inicio << ", Fim: " << e.fim << "\n";
    }

    return 0;
}
