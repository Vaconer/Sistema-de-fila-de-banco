#include "dinamic.h"

// Inicializa os caixas
void InicializaCaixas(TipoCaixa *caixas, int numCaixas) {
    int i;
    for (i = 0; i < numCaixas; i++) {
        caixas[i].clientesAtendidos = 0;
        caixas[i].valorSaque = 0.0;
        caixas[i].valorDeposito = 0.0;
        caixas[i].valorPagamento = 0.0;
    }
}

// Simula o atendimento dos clientes
void SimularAtendimento(int tempoFuncionamento, TipoFila *filas, TipoCaixa *caixas, int numCaixas) {
    int tempo;
    TipoItem cliente;
    srand(time(NULL));

    for (tempo = 0; tempo < tempoFuncionamento; tempo++) {
        int i;
        for (i = 0; i < numCaixas; i++) {
            if (!Vazia(filas[i])) {
                Desenfileira(&filas[i], &cliente);
                caixas[i].clientesAtendidos++;

                switch (cliente.op) {
                    case 0:
                        caixas[i].valorSaque += cliente.valor;
                        break;
                    case 1:
                        caixas[i].valorDeposito += cliente.valor;
                        break;
                    case 2:
                        caixas[i].valorPagamento += cliente.valor;
                        break;
                }
            }
        }

        // Geração aleatória de novos clientes
        int numClientes = rand() % 4; // Gera de 0 a 3 clientes por iteração
        for (i = 0; i < numClientes; i++) {
            TipoItem novoCliente;
            novoCliente.cod = rand() % 1000;
            novoCliente.valor = (float)(rand() % 10001); // Gera valores de 1 a 10000
            novoCliente.op = rand() % 3;                 // Gera operações de 0 a 2

            int menorFila = 0;
            int menorTamanho = filas[0].tamanho;
            int j;
            for (j = 1; j < numCaixas; j++) {
                if (filas[j].tamanho < menorTamanho) {
                    menorFila = j;
                    menorTamanho = filas[j].tamanho;
                }
            }

            Enfileira(novoCliente, &filas[menorFila]);
        }
    }
}

// Exibe o relatório do trabalho executado pelos caixas
void ExibirRelatorio(TipoCaixa *caixas, int numCaixas) {
    int i;
    for (i = 0; i < numCaixas; i++) {
        cout << "Caixa: " << i+1 <<endl;
        cout << "Clientes atendidos: " << caixas[i].clientesAtendidos<<endl;
        cout << "Valor saque: " << caixas[i].valorSaque<<endl;
        cout << "Valor deposito: " << caixas[i].valorDeposito<<endl;
        cout << "Valor pagamento: " << caixas[i].valorPagamento<<endl;
        cout << "\n";
    }
}