#ifndef MOCHILA_H
#define MOCHILA_H

#include <vector>
#include <algorithm>

struct Item {
    double valor;
    double peso;

    bool operator<(const Item& outro) const {
        return (valor / peso) > (outro.valor / outro.peso);
    }
};

double mochilaFracionaria(std::vector<Item> itens, double capacidade) {
    std::sort(itens.begin(), itens.end());
    double valorTotal = 0.0;

    for (const Item& item : itens) {
        if (capacidade >= item.peso) {
            capacidade -= item.peso;
            valorTotal += item.valor;
        } else {
            valorTotal += item.valor * (capacidade / item.peso);
            break;
        }
    }

    return valorTotal;
}

#endif // MOCHILA_H
