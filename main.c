#include <stdio.h>
#include <stdlib.h>

int verificaInt()
{
    int num;
    int verificador = scanf("%d", &num);
    while (verificador != 1 || getchar() != '\n')
    {
        printf("Valor invalido! Digite um numero inteiro: ");
        while (getchar() != '\n');
        verificador = scanf("%d", &num);
    }
    return num;
}
void continuar()
{
    int continuar;
    printf("Deseja continuar? 1 para sim, qualquer outro para nao.\n\n");
    scanf("%d", &continuar);
    if (continuar == 1)
    {
        system("cls"); system("clear");
    } else {
        exit(0);
    }
}

void vetores(int n, int m, int a[], int b[])
{
    printf("Digite os valores do vetor A: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    fflush(stdin);
    printf("Digite os valores do vetor B: \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    fflush(stdin);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e1
void intersecaoDosVetores(int n, int m, int a[], int b[])
{
    printf("Intersecao dos dois vetores: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                printf("%d ", a[i]);
                break; // Interseção contém elementos únicos, então podemos sair do loop interno quando encontramos uma correspondência.
            }
        }
    }
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e2
void uniaoDosVetores(int n, int m, int a[], int b[])
{
    printf("Uniao dos dois vetores: ");

    // Imprime os elementos do vetor A
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // Imprime os elementos únicos do vetor B
    for (int i = 0; i < m; i++)
    {
        int estaNaUniao = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i] == a[j])
            {
                estaNaUniao = 1;
                break;
            }
        }
        if (!estaNaUniao)
        {
            printf("%d ", b[i]);
        }
    }
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e3
void concatenarVetores(int n, int m, int a[], int b[])
{
    printf("Concatenacao dos dois vetores: ");

    // Imprime os elementos do vetor A
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // Imprime os elementos do vetor B
    for (int i = 0; i < m; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e4
void subtracaoDosVetores(int n, int m, int a[], int b[])
{
    printf("Subtracao do vetor B do vetor A: ");

    for (int i = 0; i < n; i++)
    {
        int estaNaSubtracao = 1; // Assumimos que está na subtração até encontrar uma correspondência em B.

        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                estaNaSubtracao = 0; // Encontramos uma correspondência, então não está na subtração.
                break;
            }
        }

        if (estaNaSubtracao)
        {
            printf("%d ", a[i]);
        }
    }

    printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e5
void procuraValor(int n, int m, int a[], int b[])
{
    int valor;
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valor);

    // Verifica se o valor contém vírgula ou caracteres
    if (valor < 0 || getchar() != '\n')
    {
        printf("Valor inválido!\n");
        return;
    }

    int encontrado = 0; // Flag para indicar se o valor foi encontrado

    // Procura no vetor A
    for (int i = 0; i < n; i++)
    {
        if (a[i] == valor)
        {
            printf("Valor %d encontrado no vetor A na posicao %d.\n", valor, i);
            encontrado = 1;
            break;
        }
    }

    // Procura no vetor B apenas se não foi encontrado no vetor A
    if (!encontrado)
    {
        for (int i = 0; i < m; i++)
        {
            if (b[i] == valor)
            {
                printf("Valor %d encontrado no vetor B na posicao %d.\n", valor, i);
                encontrado = 1;
                break;
            }
        }
    }

    // Se não foi encontrado em nenhum vetor
    if (!encontrado)
    {
        printf("Valor %d nao encontrado nos vetores A e B.\n", valor);
        printf("Valor base retornado = -1\n");
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e6
void multiplicarPorEscalar(int m, int b[], int escalar)
{
    for (int i = 0; i < m; i++)
    {
        b[i] *= escalar;
        printf("%d ", b[i]);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e7
void produtoEscalar(int n, int a[], int b[])
{
    int resultado = 0;

    for (int i = 0; i < n; i++)
    {
        resultado += a[i] * b[i];
    }

    printf("Produto escalar dos vetores A e B: %d\n", resultado);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e8
// Função de comparação para o qsort
int compararV(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Função para classificar o vetor A em ordem crescente
void ordenarVetorA(int n, int a[])
{
    qsort(a, n, sizeof(int), compararV);
    printf("Vetor A ordenado em ordem crescente: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Verificar se os valores estão realmente ordenados
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            printf("Erro: Vetor A nao esta ordenado corretamente.\n");
            break;
        }
    }
    printf("Vetor A verificado.\n");
    fflush(stdin);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e9

// Função para classificar o vetor em ordem crescente
void ordenarVetorB(int m, int b[])
{

    qsort(b, m, sizeof(int), compararV);
    printf("Vetor B ordenado em ordem crescente: ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    // Verificar se os valores estão realmente ordenados
    for (int i = 1; i < m; i++)
    {
        if (b[i - 1] > b[i]) {
            printf("Erro: Vetor A nao esta ordenado corretamente.\n");
            break;
        }
    }
    printf("Vetor B verificado.\n");
    fflush(stdin);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e10
// Função para intercalar dois vetores mantendo a ordenação
void intercalarOrdenado(int n, int m, int a[], int b[])
{
    // Ordena os vetores antes de intercalar
    qsort(a, n, sizeof(int), compararV);
    qsort(b, m, sizeof(int), compararV);

    printf("Intercalacao ordenada dos dois vetores: ");

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] < b[j])
        {
            printf("%d ", a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            printf("%d ", b[j]);
            j++;
        }
        else
        {
            // Ambos são iguais, imprime apenas uma vez
            printf("%d ", a[i]);
            i++;
            j++;
        }
    }

    // Imprime os elementos restantes de a (se houver)
    while (i < n)
    {
        printf("%d ", a[i]);
        i++;
    }

    // Imprime os elementos restantes de b (se houver)
    while (j < m)
    {
        printf("%d ", b[j]);
        j++;
    }

    printf("\n");
    fflush(stdin);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////e11
void armazenarBVetorA(int n, int m, int a[], int b[])
{
    // Verifica se há espaço suficiente em A para armazenar os elementos de B
    if (n + m > 30)
    {
        printf("Nao ha espaco suficiente em A para armazenar B. Reduza o tamanho de B ou remova elementos de A.\n");
        return;
    }

    // Copia os elementos de B para A
    for (int i = 0; i < m; i++)
    {
        a[n + i] = b[i];
    }

    printf("Vetor B armazenado em A:\n");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    fflush(stdin);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Main

int main()
{
    int n, m;

    printf("Digite o tamanho do vetor A (n <= 30): ");
    scanf("%d", &n);
    while (n > 30)
    {
        printf("Nao pode ter mais de 30 valores! \n");
        printf("Digite o numero de casas de N: ");
        scanf("%d", &n);
    }

    printf("Digite o tamanho do vetor B (m <= 30): ");
    scanf("%d", &m);
    while (m > 30)
     {
        printf("Nao pode ter mais de 30 valores! \n");
        printf("Digite o numero de casas de M: ");
        scanf("%d", &m);
    }

    int a[n], b[m];
    vetores(n, m, a, b);

    int opcao = 0;

    while (opcao != 12)
    {

        printf("   ┌───────────────────────────────────────────────────────────┐\n");
        printf("   │                    Selecione uma opção                    │\n");
        printf("   ├───────────────────────────────────────────────────────────┤\n");
        printf("   │  1. Intersecao dos 2 vetores                              │\n");
        printf("   │  2. Uniao dos 2 vetores                                   │\n");
        printf("   │  3. Cocatenacao dos 2 vetores                             │\n");
        printf("   │  4. Subtracao dos vetores                                 │\n");
        printf("   │  5. Procura de valor em um vetor                          │\n");
        printf("   │  6. Multiplicar um vetor por um escalar                   │\n");
        printf("   │  7. Calcular o produto escalar dos dois vetores           │\n");
        printf("   │  8. Classificar o vetor A em forma crescente              │\n");
        printf("   │  9. Classificar o vetor B em forma crescente              │\n");
        printf("   │  10. Intercalar ambos vetores de maneira ordenada         │\n");
        printf("   │  11. Armazenar o vetor B no vetor A                       │\n");
        printf("   │  12. Finalizar                                            │\n");
        printf("   └───────────────────────────────────────────────────────────┘\n");

        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
            case 1:
            {
                printf("\n");
                intersecaoDosVetores(n, m, a, b);
                continuar();
                break;
            }
            case 2:
            {
                printf("\n");
                uniaoDosVetores(n, m, a, b);
                continuar();
                break;
            }
            case 3:
            {
                printf("\n");
                concatenarVetores(n, m, a, b);
                continuar();
                break;
            }
            case 4:
            {
                printf("\n");
                subtracaoDosVetores(n, m, a, b);
                continuar();
                break;
            }
            case 5:
            {
                printf("\n");
                procuraValor(n, m, a, b);
                continuar();
                break;
            }
            case 6:
            {
                printf("\n");
                // Adiciona a chamada da função multiplicarPorEscalar
                printf("Digite o escalar para multiplicar o vetor B: ");
                int escalar = verificaInt();
                multiplicarPorEscalar(m, b, escalar);
                continuar();
                break;
            }
            case 7:
            {
                printf("\n");
                produtoEscalar(n, a, b); //nao sei se esta concatenando ou somando os valores u.u
                continuar();
                break;
            }
            case 8:
            {
                printf("\n");
                 ordenarVetorA(n, a);
                continuar();
                break;
            }
            case 9:
            {
                printf("\n");
                 ordenarVetorB(m, b);
                continuar();
                break;
            }
            case 10:
            {
                printf("\n");
                intercalarOrdenado(n, m, a, b);
                continuar();
                break;
            }
            case 11:
            {
                printf("\n");
                 armazenarBVetorA(n, m, a, b);
                continuar();
                break;
            }
            case 12:
            {
                printf("Saindo do programa...\n");
                break;
            }
            default:
            {
                system("cls"); system("clear");
                printf("Opcao invalida!\n");
            }
        }
    }
    return 0;
}