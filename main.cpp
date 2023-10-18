#include "probla.h"

/*
A agência bancária deverá possuir 3 caixas, sendo uma fila (dinâmica) específica para cada caixa. A cada
unidade de tempo (iteração do loop), o programa simulará a entrada de novos clientes nas filas e o
atendimento de um cliente por caixa. O atendimento consiste em desenfileirar um cliente de cada uma das 3
filas, atribuí-lo ao respectivo caixa e contabilizar o valor da operação do cliente. Ao final do tempo de
funcionamento da agência, será interrompida a entrada de mais clientes, porém, os caixas deverão trabalhar
até que todas as 3 filas estejam vazias (todos os clientes atendidos). Antes do encerramento do programa,
exiba um relatório sobre o trabalho executado pelos 3 caixas. Sugestão: defina constantes para valores como:
tempo de funcionamento, valores das operações dos clientes e número randômico de clientes a serem
atendidos por iteração e operações (0- Saque; 1- Depósito; 2- Pagamento).
*/

int main() {
    int tempoFuncionamento = 10; // Defina o tempo de funcionamento da agência aqui
    int numCaixas = 3;           // Defina o número de caixas aqui

    TipoFila filas[numCaixas];
    TipoCaixa caixas[numCaixas];
    InicializaCaixas(caixas, numCaixas);

    int i;
    for (i = 0; i < numCaixas; i++) {
        FFVazia(&filas[i]);
    }

    SimularAtendimento(tempoFuncionamento, filas, caixas, numCaixas);
    ExibirRelatorio(caixas, numCaixas);

    return 0;
}