#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

struct Endereco {
  char rua[50];
  int numero;
  char bairro[50];
  char cidade[50];
  char estado[3];
};

struct Aluno {
  char nome[50];
  char ra[10];
  char dataNascimento[11]; // formato: dd/mm/aaaa
  struct Endereco endereco1;
  struct Endereco endereco2;
  float notas[5];
};

int podeAdicionarAluno(int totalAlunos) { return totalAlunos < 20; }

int raExiste(struct Aluno alunos[], int totalAlunos, const char raBuscado[]) {
  for (int i = 0; i < totalAlunos; i++) {
    if (strcmp(alunos[i].ra, raBuscado) == 0) {
      return 1;
    }
  }
  return 0;
}

void adicionarAluno(struct Aluno alunos[], int *totalAlunos) {
  if (!podeAdicionarAluno(*totalAlunos)) {
    printf("\e[2J");
    system("cls");
    printf("\e[1;31m");
    printf("Não é possível adicionar mais alunos. Limite atingido.\n");
    return;
  }

  struct Aluno novoAluno;

  printf("\e[1;32mInforme o nome do novo aluno: \e[0m");
  getchar();
  scanf(" %[^\n]", novoAluno.nome);
  printf("\n\e[1;32mInforme o RA do novo aluno: \e[0m");
  scanf("%s", novoAluno.ra);
  printf("\n\e[1;32mInforme a data de nascimento do novo aluno (dd/mm/aaaa): \e[0m");
  scanf("%s", novoAluno.dataNascimento);
  printf("\n\e[1;34mInforme o primeiro endereço do novo aluno:\n\e[0m");
  printf("\n\e[1;32mRua: \e[0m");
  getchar();
  scanf(" %[^\n]", novoAluno.endereco1.rua);
  printf("\n\e[1;32mNumero: \e[0m");
  scanf("%d", &novoAluno.endereco1.numero);
  printf("\n\e[1;32mBairro: \e[0m");
  getchar();
  scanf(" %[^\n]", novoAluno.endereco1.bairro);
  printf("\n\e[1;32mCidade: \e[0m");
  getchar();
  scanf("%[^\n]", novoAluno.endereco1.cidade);
  printf("\n\e[1;32mEstado (UF): \e[0m");
  getchar();
  scanf("%[^\n]", novoAluno.endereco1.estado);

  printf("\n\e[1;34mInforme o segundo endereço do novo aluno:\n\e[0m");
  printf("\n\e[1;32mRua: \e[0m");
  getchar();
  scanf(" %[^\n]", novoAluno.endereco2.rua);
  printf("\n\e[1;32mNumero: \e[0m");
  scanf("%d", &novoAluno.endereco2.numero);
  printf("\n\e[1;32mBairro: \e[0m");
  getchar();
  scanf(" %[^\n]", novoAluno.endereco2.bairro);
  printf("\n\e[1;32mCidade: \e[0m");
  getchar();
  scanf("%[^\n]", novoAluno.endereco2.cidade);
  printf("\n\e[1;32mEstado (UF): \e[0m");
  getchar();
  scanf("%[^\n]", novoAluno.endereco2.estado);

  printf("\n\e[1;34mInforme as notas das 5 disciplinas do novo aluno:\n\e[0m");
  for (int i = 0; i < 5; i++) {
    printf("\n\e[1;32mNota da disciplina %d: \e[0m", i + 1);
    scanf("%f", &novoAluno.notas[i]);
  }

   if (raExiste(alunos, *totalAlunos, novoAluno.ra)) {
        printf("\n\e[1;31mO RA informado ja esta cadastrado. Não e possível adicionar o aluno.\e[0m\n");
        return;
   }

  alunos[*totalAlunos] = novoAluno;
  (*totalAlunos)++;
    printf("\e[2J");
    system("cls");
  printf("\e[1;31m\nNovo aluno adicionado com sucesso!\n");

}

void excluirAluno(struct Aluno alunos[], int *totalAlunos, int indice) {
  if (indice < 0 || indice >= *totalAlunos) {
   printf("\e[2J");
    system("cls");
    printf("\e[1;31m");
    printf("\nindice de aluno invalido.\n");
    return;
  }

  for (int i = indice; i < *totalAlunos - 1; i++) {
    alunos[i] = alunos[i + 1];
  }

  (*totalAlunos)--;
   printf("\e[2J");
    system("cls");
  printf("\e[1;31m");
  printf("\nAluno no indice %d excluido com sucesso!\n", indice);
  return;
}

void buscarAlunoPorRA(struct Aluno alunos[], int totalAlunos,
                      const char raBuscado[]) {
  int encontrado = 0;

  for (int i = 0; i < totalAlunos; i++) {
    if (strcmp(alunos[i].ra, raBuscado) == 0) {
      encontrado = 1;
      printf("\e[1;34mALUNO ENCONTRADO:\n\e[0m");
      printf("\e[1;32m\nNome: \e[0m%s\n", alunos[i].nome);
      printf("\e[1;32mRA: \e[0m%s\n", alunos[i].ra);
      printf("\e[1;32mData de Nascimento: \e[0m%s\n", alunos[i].dataNascimento);
      printf("\e[1;34m\nENDERECO 1:\n");
      printf("\e[1;32mRua: \e[0m%s\n", alunos[i].endereco1.rua);
      printf("\e[1;32mNumero: \e[0m%d\n", alunos[i].endereco1.numero);
      printf("\e[1;32mBairro: \e[0m%s\n", alunos[i].endereco1.bairro);
      printf("\e[1;32mCidade: \e[0m%s\n", alunos[i].endereco1.cidade);
      printf("\e[1;32mEstado: \e[0m%s\n", alunos[i].endereco1.estado);
      printf("\e[1;34m\nENDERECO 2:\n");
      printf("\e[1;32mRua: \e[0m%s\n", alunos[i].endereco2.rua);
      printf("\e[1;32mNumero: \e[0m%d\n", alunos[i].endereco2.numero);
      printf("\e[1;32mBairro: \e[0m%s\n", alunos[i].endereco2.bairro);
      printf("\e[1;32mCidade: \e[0m%s\n", alunos[i].endereco2.cidade);
      printf("\e[1;32mEstado: \e[0m%s\n", alunos[i].endereco2.estado);
      printf("\e[1;34m\nNOTAS DAS DISCIPLINAS:\n");
      for (int j = 0; j < 5; j++) {
        printf("\e[1;34mDisciplina \e[0m%d: %.2f\n", j + 1, alunos[i].notas[j]);
      }
      break;
    }
  }

  if (!encontrado) {
    printf("\e[2J");
    system("cls");
    printf("\e[1;31m");
    printf("\e[1;31m\nAluno com RA %s nao encontrado.\n", raBuscado);
  }
}
void exibirTodosOsAlunos(struct Aluno alunos[], int totalAlunos) {
    if (totalAlunos == 0) {
        printf("\e[2J");
        system("cls");
        printf("\e[1;31m");
        printf("Nao ha alunos cadastrados.\n");
        return;
    }

    printf("\e[1;34mInformacoes de todos os alunos:\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("\e[1;34m\nAluno %d:\n", i + 1);
        printf("\e[1;32mNome: \e[0m%s\n", alunos[i].nome);
        printf("\e[1;32mRA: \e[0m%s\n", alunos[i].ra);
        printf("\e[1;32mData de Nascimento: \e[0m%s\n", alunos[i].dataNascimento);
        printf("\e[1;34m\nEndereco 1:\n");
        printf("\e[1;32mRua: \e[0m%s\n", alunos[i].endereco1.rua);
        printf("\e[1;32mNumero: \e[0m%d\n", alunos[i].endereco1.numero);
        printf("\e[1;32mBairro: \e[0m%s\n", alunos[i].endereco1.bairro);
        printf("\e[1;32mCidade: \e[0m%s\n", alunos[i].endereco1.cidade);
        printf("\e[1;32mEstado: \e[0m%s\n", alunos[i].endereco1.estado);
        printf("\e[1;34m\nEndereco 2:\n");
        printf("\e[1;32mRua: \e[0m%s\n", alunos[i].endereco2.rua);
        printf("\e[1;32mNumero: \e[0m%d\n", alunos[i].endereco2.numero);
        printf("\e[1;32mBairro: \e[0m%s\n", alunos[i].endereco2.bairro);
        printf("\e[1;32mCidade: \e[0m%s\n", alunos[i].endereco2.cidade);
        printf("\e[1;32mEstado: \e[0m%s\n", alunos[i].endereco2.estado);
        printf("\e[1;34m\nNotas das disciplinas:\n");
        for (int j = 0; j < 5; j++) {
            printf("\e[1;32mDisciplina %d: \e[0m%.2f\n", j + 1, alunos[i].notas[j]);
        }
        printf("\n");
        printf("------------------------------\n");

    }
}
//CORPO PRINCIPAL DO CODIGO
int main() {

  struct Aluno alunos[20];
  int totalAlunos = 0;
  int opcao;

  do {
    printf("\e[1;34m\n|---------------------------|\n");
    printf("|         OPERACOES:        |\n");
    printf("|---------------------------|\n");
    printf("|     \e[1;32m1) Adicionar Aluno\e[1;34m    |\n");
    printf("|     \e[1;32m2) Excluir Aluno\e[1;34m      |\n");
    printf("|  \e[1;32m3) Buscar Aluno por RA\e[1;34m   |\n");
    printf("| \e[1;32m4) Exibir Todos os Alunos\e[1;34m |\n");
    printf("|          \e[1;32m5) \e[1;31mSair\e[1;34m          |\n");
    printf("|---------------------------|\n");
    printf("\e[1m    ESCOLHA UMA OPERACAO:\e[0m");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      if (podeAdicionarAluno(totalAlunos)) {
        adicionarAluno(alunos, &totalAlunos);
      } else {
        printf("\e[2J");
        system("cls");
        printf("\e[1;31m");
        printf("\nNao e possivel adicionar mais alunos. Limite atingido.\n");
      }
      break;
    case 2:
      if (totalAlunos > 0) {
        int indiceParaExcluir;
        printf("\e[1;32m");
        printf("Informe o indice do aluno a ser excluido: ");
        scanf("%d", &indiceParaExcluir);
        excluirAluno(alunos, &totalAlunos, indiceParaExcluir);
      } else {
        printf("\e[2J");
        system("cls");
        printf("\e[1;31m");
        printf("\nNao ha alunos para excluir.\n");
      }
      break;
    case 3:
      if (totalAlunos > 0) {
        char raBuscado[10];
        printf("\e[1;32m");
        printf("Informe o RA do aluno a ser buscado: ");
        scanf("%s", raBuscado);
        buscarAlunoPorRA(alunos, totalAlunos, raBuscado);
      } else {
        printf("\e[2J");
        system("cls");
        printf("\e[1;31m");
        printf("\nNao ha alunos para buscar.\n");
      }
          break;
        case 4:
          printf("\e[2J");
          system("cls");
          exibirTodosOsAlunos(alunos, totalAlunos);
          break;
        case 5:
          printf("\e[2J");
          system("cls");
          printf("\e[1;31mSaindo do programa.\n");
          system("exit");
          return 0;
        default:
          printf("\e[2J");
          system("cls");
          printf("\e[1;31mOpcao invalida. Tente novamente.\n");
          break;
        }
      } while (opcao != 5);

      return 0;
    }
