#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 10
#define MAX_PALAVRA_LEN 20

// Função para escolher uma palavra aleatória
char* escolherPalavraAleatoria(char palavras[][MAX_PALAVRA_LEN], int numPalavras) {
    srand(time(NULL));
    int indice = rand() % numPalavras;
    return palavras[indice];
}

// Função para exibir o estado atual da palavra com letras adivinhadas
void exibirPalavraParcial(char palavra[], char letrasAdivinhadas[]) {
    for (int i = 0; i < strlen(palavra); i++) {
        if (letrasAdivinhadas[i] != '\0') {
            printf("%c ", letrasAdivinhadas[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// Função principal do jogo da forca
void jogarForca() {
    char palavras[MAX_PALAVRAS][MAX_PALAVRA_LEN] = {
        "computador",
        "programacao",
        "algoritmo",
        "linguagem",
        "desenvolvimento",
        "software",
        "hardware",
        "interface",
        "internet",
        "teclado"
    };

    char* palavra = escolherPalavraAleatoria(palavras, MAX_PALAVRAS);
    int numTentativas = 0;
    int letrasErradas = 0;
    char letrasAdivinhadas[MAX_PALAVRA_LEN];
    char letra;

    // Inicializa o vetor de letras adivinhadas
    memset(letrasAdivinhadas, '\0', sizeof(letrasAdivinhadas));

    printf("Bem-vindo ao jogo da forca!\n");
    printf("Tente adivinhar a palavra desconhecida.\n");

    while (1) {
        printf("\nPalavra: ");
        exibirPalavraParcial(palavra, letrasAdivinhadas);
        printf("Letras erradas: %d\n", letrasErradas);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra); // Converte para minúscula

        int encontrou = 0;
        for (int i = 0; i < strlen(palavra); i++) {
            if (letrasAdivinhadas[i] == letra) {
                printf("Você já adivinhou essa letra.\n");
                encontrou = 1;
                break;
            } else if (palavra[i] == letra) {
                letrasAdivinhadas[i] = letra;
                encontrou = 1;
            }
        }

        if (!encontrou) {
            printf("A letra não está na palavra.\n");
            letrasErradas++;
        }

        // Verifica se o jogador acertou todas as letras da palavra
        int acertouTodas = 1;
        for (int i = 0; i < strlen(palavra); i++) {
            if (letrasAdivinhadas[i] == '\0') {
                acertouTodas = 0;
                break;
            }
        }

        if (acertouTodas) {
            printf("\nParabéns, você acertou a palavra!\n");
            printf("A palavra era: %s\n", palavra);
            break;
        }

        if (letrasErradas >= MAX_TENTATIVAS) {
            printf("\nVocê excedeu o número de tentativas.\n");
            printf("A palavra era: %s\n", palavra);
            break;
        }
    }
}

int main() {
    jogarForca();
    return 0;
}
