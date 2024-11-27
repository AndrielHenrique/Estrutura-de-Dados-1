#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    int horas;
    int minutos;
} Tempo;
typedef struct
{
    char placa[8];
    Tempo entrada;
    Tempo saida;

} Veiculos;

Veiculos lerVeiculo()
{
    Veiculos veiculo;
    printf("\nInforme a placa do veiculo: ");
    fgets(veiculo.placa, 8, stdin);
    getchar();
    printf("\nInforme o tempo da entrada, Hora e Minutos: ");
    scanf("%d %d", &veiculo.entrada.horas, &veiculo.entrada.minutos);
    return veiculo;
}

int verificarPlaca(Veiculos veiculo[], int qtdEstacionamento, char placa[])
{
    int i;
    for (i = 0; i < qtdEstacionamento; i++)
    {
        if (strcmp(veiculo[i].placa, placa) == 0)
            return i;
    }
    return -1;
}
void retirarVeiculo(Veiculos veiculo[], int qtdEstacionamento, int pos)
{
    int i;
    for (i = pos; i < qtdEstacionamento; i++)
        veiculo[i] = veiculo[i + 1];
}

void calcularEstadia(Veiculos veiculo[], int pos)
{
    float tarifa = 0.10, total;
    int horas, minutos;

    printf("Informe o horario da saida: Horas: ");
    getchar();
    scanf("%d", &veiculo[pos].saida.horas);
    printf("Informe o horario da saida: Minutos: ");
    scanf("%d", &veiculo[pos].saida.minutos);
    horas = veiculo[pos].saida.horas - veiculo[pos].entrada.horas;
    minutos = veiculo[pos].saida.minutos - veiculo[pos].entrada.minutos;

    if (minutos < 0)
    {
        minutos += 60;
        horas--;
    }
    printf("O tempo no estacionamento foi de %d horas e %d minutos", horas, minutos);
    total = (horas * 60 + minutos) * tarifa;
    printf("\nTotal a ser pago %.2f", total);
}

int menu()
{
    int op;

    printf("\t\t===== Menu =====");
    printf("\n1 - Cadastrar a entrada de um veiculo. Placa e tempo da entrada");
    printf("\n2 - Lancar a retirada do veiculo");
    printf("\n3 - Sair");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int main()
{
    int op, qtdEstacionamento = 0;
    char placa[8];

    Veiculos veiculo[MAX];
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            if (qtdEstacionamento <= MAX)
            {
                veiculo[qtdEstacionamento] = lerVeiculo();
                qtdEstacionamento++;
                printf("\nVeiculo cadastrado!");
            }
            else
                printf("\nEstacionamento cheio!!");
            break;
        case 2:
            printf("\nInforme a placa do veiculo para sair do estacionamento: ");
            fgets(placa, 8, stdin);
            int pos = (verificarPlaca(veiculo, qtdEstacionamento, placa));
            if (pos >= 0)
            {
                calcularEstadia(veiculo, pos);
                retirarVeiculo(veiculo, qtdEstacionamento--, pos);
            }
            else
                printf("\nVeiculo nao localizado!");
            break;
        case 3:
            printf("\nSaindo...");
            break;
        default:
            printf("\nOpcao invalida!");
        }
    } while (op != 3);
}