#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de cidade
typedef struct {
    char codigo[4];        // Código da carta (ex: A01, B02)
    char estado[20];       // Nome do estado
    char cidade[20];       // Nome da cidade
    int populacao;         // População da cidade
    float area;            // Área em km²
    float pib;             // PIB em bilhões
    int pontos_turisticos; // Número de pontos turísticos
} Carta;

// Função para exibir o cabeçalho do programa
void exibirCabecalho() {
    printf("\n=== SUPER TRUNFO - CADASTRO DE CARTAS ===\n");
    printf("Tema: Cidades Brasileiras\n");
    printf("Nível: Novato\n");
    printf("========================================\n\n");
}

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, char letra_estado, int numero_cidade) {
    // Definir estados brasileiros (A-H)
    char estados[8][20] = {
        "Acre",      // A
        "Bahia",     // B
        "Ceará",     // C
        "Goiás",     // D
        "Espírito",  // E (Espírito Santo)
        "Minas",     // F (Minas Gerais)
        "Paraná",    // G
        "Roraima"    // H
    };
    
    // Definir cidades para cada estado (4 cidades por estado)
    char cidades[8][4][20] = {
        // Acre (A)
        {"Cruzeiro", "Feijó", "Sena", "Tarauacá"},
        // Bahia (B)
        {"Salvador", "Feira", "Vitória", "Camaçari"},
        // Ceará (C)
        {"Fortaleza", "Sobral", "Crato", "Maracanaú"},
        // Goiás (D)
        {"Goiânia", "Aparecida", "Anápolis", "Luziânia"},
        // Espírito Santo (E)
        {"Vitória", "Serra", "Cariacica", "Linhares"},
        // Minas Gerais (F)
        {"Contagem", "Uberlândia", "Juiz", "Betim"},
        // Paraná (G)
        {"Curitiba", "Londrina", "Maringá", "Ponta"},
        // Roraima (H)
        {"Boa", "Rorainópolis", "Caracaraí", "Alto"}
    };
    
    // Gerar código da carta
    sprintf(carta->codigo, "%c%02d", letra_estado, numero_cidade);
    
    // Definir estado e cidade automaticamente
    int indice_estado = letra_estado - 'A';
    strcpy(carta->estado, estados[indice_estado]);
    strcpy(carta->cidade, cidades[indice_estado][numero_cidade - 1]);
    
    // Solicitar dados do usuário
    printf("=== CADASTRO DA CARTA %s ===\n", carta->codigo);
    printf("Estado: %s\n", carta->estado);
    printf("Cidade: %s\n\n", carta->cidade);
    
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    printf("\nCarta %s cadastrada com sucesso!\n\n", carta->codigo);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("=== CARTA %s ===\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("========================\n\n");
}

// Função principal
int main() {
    // Array para armazenar as duas cartas
    Carta cartas[2];
    char letra_estado;
    int numero_cidade;
    
    exibirCabecalho();
    
    // Cadastrar as duas cartas
    for(int i = 0; i < 2; i++) {
        printf("=== CADASTRO DA %dª CARTA ===\n", i + 1);
        
        printf("Digite a letra do estado (A-H): ");
        scanf(" %c", &letra_estado);
        
        // Converter para maiúscula se necessário
        if(letra_estado >= 'a' && letra_estado <= 'h') {
            letra_estado = letra_estado - 'a' + 'A';
        }
        
        // Verificar se a letra é válida
        if(letra_estado >= 'A' && letra_estado <= 'H') {
            printf("Digite o número da cidade (1-4): ");
            scanf("%d", &numero_cidade);
            
            if(numero_cidade >= 1 && numero_cidade <= 4) {
                cadastrarCarta(&cartas[i], letra_estado, numero_cidade);
            } else {
                printf("Número de cidade inválido! Use números de 1 a 4.\n");
                i--; // Repetir esta iteração
            }
        } else {
            printf("Estado inválido! Use letras de A a H.\n");
            i--; // Repetir esta iteração
        }
    }
    
    // Exibir as cartas cadastradas
    printf("\n=== CARTAS CADASTRADAS ===\n\n");
    for(int i = 0; i < 2; i++) {
        exibirCarta(cartas[i]);
    }
    
    printf("Programa finalizado com sucesso!\n");
    
    return 0;
}
