#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "auxiliar.h"

DadosSort calcula_estatisticas(DadosAmostra* dados, int tamAmostra)
{
	DadosSort estats;

	estats.tempo_de_execucao.media = 0;
	estats.tempo_de_execucao.desvio_padrao = 0;
	estats.tempo_de_execucao.variancia = 0;
	estats.num_trocas.media = 0;
	estats.num_trocas.desvio_padrao = 0;
	estats.num_trocas.variancia = 0;
	estats.num_comparacoes.media = 0;
	estats.num_comparacoes.desvio_padrao = 0;
	estats.num_comparacoes.variancia = 0;

	// Calculos das m�dias
	for (int i = 0; i < tamAmostra; i++) {
		estats.tempo_de_execucao.media += dados[i].tempo_de_execucao;
		estats.num_trocas.media += dados[i].num_trocas;
		estats.num_comparacoes.media += dados[i].num_comparacoes;
	}

	estats.tempo_de_execucao.media /= tamAmostra;
	estats.num_trocas.media /= tamAmostra;
	estats.num_comparacoes.media /= tamAmostra;

	// Calculos das vari�ncias e desvios padr�o 
	for (int i = 0; i < tamAmostra; i++) {
		estats.tempo_de_execucao.variancia += pow((dados[i].tempo_de_execucao - estats.tempo_de_execucao.media), 2);
		estats.num_trocas.variancia += pow((dados[i].num_trocas - estats.num_trocas.media), 2);
		estats.num_comparacoes.variancia += pow((dados[i].num_comparacoes - estats.num_comparacoes.media), 2);
	}

	estats.tempo_de_execucao.variancia /= (tamAmostra - 1);
	estats.tempo_de_execucao.desvio_padrao = sqrt(estats.tempo_de_execucao.variancia);

	estats.num_trocas.variancia /= (tamAmostra - 1);
	estats.num_trocas.desvio_padrao = sqrt(estats.num_trocas.variancia);

	estats.num_comparacoes.variancia /= (tamAmostra - 1);
	estats.num_comparacoes.desvio_padrao = sqrt(estats.num_comparacoes.variancia);

	return estats;
}

int* gera_vetor(long int tam)
{
	int i;
	int* vet = (int*)malloc(sizeof(int) * tam);

	for (i = 0; i < tam; i++)
		vet[i] = rand() % 100;

	return vet;
}

void print_vetor(int* vet, long int tam)
{
	int i;
	for (i = 0; i < tam; i++)
		printf("%d ", vet[i]);
}

void print_dados_sort(DadosSort dados)
{
	printf("[Tempo de execucao]\n");
	printf("Media: %f\n", dados.tempo_de_execucao.media);
	printf("Variancia: %f\n", dados.tempo_de_execucao.variancia);
	printf("DP: %f\n", dados.tempo_de_execucao.desvio_padrao);

	printf("\n[Numero de Trocas]\n");
	printf("Media: %f\n", dados.num_trocas.media);
	printf("Variancia: %f\n", dados.num_trocas.variancia);
	printf("DP: %f\n", dados.num_trocas.desvio_padrao);

	printf("\n[Numero Comparacoes]\n");
	printf("Media: %f\n", dados.num_comparacoes.media);
	printf("Variancia: %f\n", dados.num_comparacoes.variancia);
	printf("DP: %f\n", dados.num_comparacoes.desvio_padrao);

}