#pragma once

#include "sorts.h"

//============== Auxiliares ==============//
int* gera_vetor(long int tam);
void print_vetor(int* vet, long int tam);
void print_dados_sort(DadosSort dados);

//============== Estat�sticas ==============//
DadosSort calcula_estatisticas(DadosAmostra* dados, int tamAmostra);