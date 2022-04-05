#pragma once

#include <stdio.h>
#include <stdlib.h>


//Declarando o que � um No: uma estrutura com uma informa��o (int) e dois apontamentos para outros No
//		um anterior e um seguinte
typedef struct no
{
	int info;
	struct no* prox;
	struct no* prev;
} No;

//Declarando o que � uma Celula: um apontamento para um No
typedef No* Celula;

//Declarado o que � uma Lista: uma estrutua com duas Celulas: inicio e fim
typedef struct lista
{
	Celula inicio;
	Celula fim;
} Lista;

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma Celula na mem�ria
* @param info -> N�mero inteiro a ser guardado nessa Celula
* @return novaCelula, a nova c�lula com os apontamentos de mem�ria para o pr�ximo ou anterior apontando para NULL
*/
Celula llCriaCelula(int info);

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma Lista na mem�ria
* @param
* @return novaLista, a nova Lista com os apontamentos de mem�ria para o in�cio e fim apontando para NULL
*/
Lista* llCriarLista();

/**
* @brief Fun��o que cria uma Celula e a insere no fim da Lista
* @param lista -> Lista na qual a nova Celula vai ser inserida
* @param info -> N�mero inteiro a ser guardado nessa nova Celula
*/
void llInsereNoFim(Lista* lista, int info);

/**
* @brief Fun��o que cria uma Celula e a insere no in�cio da Lista
* @param lista -> Lista na qual a nova Celula vai ser inserida
* @param info -> N�mero inteiro a ser guardado nessa nova Celula
*/
void llInsereNoInicio(Lista* lista, int info);

/**
* @brief Fun��o que cria uma Celula e a insere antes de um elemento da lista,
	caso esse elemento n�o exista � inserida no in�cio
* @param lista -> Lista na qual a nova Celula vai ser inserida
* @param info -> N�mero inteiro a ser guardado nessa nova Celula
* @param alvo -> N�mero o qual a nova Celula vai ser inserida antes
*/
void llInsereAntesDe(Lista* lista, int info, int alvo);

/**
* @brief Fun��o que cria uma Celula e a insere depois de um elemento da lista,
	caso esse elemento n�o exista � inserida no fim
* @param lista -> Lista na qual a nova Celula vai ser inserida
* @param info -> N�mero inteiro a ser guardado nessa nova Celula
* @param alvo -> N�mero o qual a nova Celula vai ser inserida depois
*/
void llInsereDepoisDe(Lista* lista, int info, int alvo);

/**
* @brief Fun��o que cria uma Celula e a insere de forma ordenada na lista
* @param lista -> Lista na qual a nova Celula vai ser inserida
* @param info -> N�mero inteiro a ser guardado nessa nova Celula
*/
void llInsereOrdenado(Lista* lista, int info);

/**
* @brief Fun��o que remove o �ltimo elemento da lista
* @param lista -> Lista a qual vai ter o fim removido
*/
void llRemoveFim(Lista* lista);

/**
* @brief Fun��o que remove o primeiro elemento da lista
* @param lista -> Lista a qual vai ter o in�cio removido
*/
void llRemoveInicio(Lista* lista);

/**
* @brief Fun��o que busca um elemento na lista e se o encontrar, o remove
* @param lista -> Lista a qual vai ter o elemento removido
* @param alvo -> N�mero o qual vai ser buscado na lista para ser removido caso exista
* @return buscada -> A Celula removida
* @return NULL -> Caso o alvo n�o exista na lista
*/
Celula llRemoveNo(Lista* lista, int info);

/**
* @brief Fun��o que verifica se um elemento existe na lista, e caso exista, o retorna
* @param lista -> Lista na qual vai acontecer a busca
* @param info -> N�mero a ser buscado na Lista
* @return aux -> O Celula do numero buscado
* @return NULL -> Caso o n�mero n�o exista na lista
*/
Celula llBusca(Lista* lista, int info);

/**
* @brief Fun��o que passa pelos elementos da lista e os imprime
* @param lista -> lista a qual vai ter os elementos impressos
*/
void llImprimeLista(Lista* lista);

/**
* @brief Fun��o que passa pelos elementos da lista e imprime os apontamentos de mem�ria de cada elemento
* @param lista -> lista a qual vai ter os apontamentos impressos
*/
void llImprimePonteiros(Lista* lista);

/**
* @brief Fun��o que verifica se a lista tem um ciclo em algum ponto
* @param lista -> a lista que vai ser verificada
* @return 1 -> caso exista um ciclo
* @return 0 -> caso n�o exista um ciclo
*/
int llTemCiclo(Lista* lista);

/**
* @brief
* @param
* @return
*/
Celula bubbleList(Celula inicio);