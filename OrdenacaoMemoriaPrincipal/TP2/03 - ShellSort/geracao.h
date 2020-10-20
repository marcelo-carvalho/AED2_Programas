#ifndef GERACAO_H
#define GERACAO_H
//=============================================================================
#include <stdbool.h>
static long long int trocas;
static long long int comparacao;
//=============================================================================
void swap(int *i, int *j);
//=============================================================================
void crescente(int *array, int n);
//=============================================================================
void decrescente(int *array, int n);
//=============================================================================
void aleatorio(int *array, int n);
//=============================================================================
void mostrar(int *array, int n);
//=============================================================================
bool isOrdenado(int *array, int n);
//=============================================================================
#endif

