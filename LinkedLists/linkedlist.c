#include "linkedlist.h"


/**
* @brief Fun��o que aloca um espa�o do tamanho de uma Celula na mem�ria
* @param info -> N�mero inteiro a ser guardado nessa Celula
* @return novaCelula, a nova c�lula som os apontamentos de mem�ria para o pr�ximo ou anterior
*/
Celula llCriaCelula(int info) {

	//Aloca um espa�o na mem�ria do tamanho de uma Celula.
	Celula novaCelula = (Celula) malloc(sizeof(No));

	//Setta os valores dessa c�lula para "vazio".
	novaCelula->info = info;
	novaCelula->prox = NULL;
	novaCelula->prev = NULL;

	//Retorna a nova Celula.
	return novaCelula;
}

/**
* @brief 
* @param 
* @return 
*/
Lista* llCriarLista() {

	//Aloca um espa�o na mem�ria do tamando de uma Lista.
	Lista* novaLista = (Lista*) malloc(sizeof(struct lista));

	//Setta o in�cio e fim da lista para "vazio".
	novaLista->inicio = NULL;
	novaLista->fim = NULL;

	//Retorna a nova Lista.
	return novaLista;
}

/**
* @brief
* @param
* @return
*/
void llInsereNoFim(Lista* lista, int info) {

	//Cria a nova Celula a qual vai ser adicionada na Lista.
	Celula novaCelula = llCriaCelula(info);

	//Caso 1: 
	//Se a Lista estiver vazia [...]
	if (lista->inicio == NULL)
	{
		// [...] A nova Celula � inserida e passa a ser o come�o e o fim da Lista.
		lista->inicio = novaCelula;
		lista->fim = novaCelula;

		//Sai da fun��o.
		return;
	}

	//Caso 2:
	//Caso a Lista n�o esteja vazia [...]

	// [...] A pr�xima Celula do fim atual passa a ser a nova Celula.
	lista->fim->prox = novaCelula;

	// [...] A Celula anterior da nova Celula passa a ser o fim atual da Lista.
	novaCelula->prev = lista->fim;

	// [...] Atualiza-se o fim da lista para a nova Celula.
	lista->fim = novaCelula;
}

/**
* @brief
* @param
* @return
*/
void llInsereNoInicio(Lista* lista, int info) {

	//Cria a nova Celula a qual vai ser adicionada na Lista.
	Celula novaCelula = llCriaCelula(info);

	//Caso 1: 
	//Se a Lista estiver vazia [...]
	if (lista->inicio == NULL)
	{
		// [...] A nova Celula � inserida e passa a ser o come�o e o fim da Lista.
		lista->inicio = novaCelula;
		lista->fim = novaCelula;

		//Sai da fun��o.
		return;
	}

	//Caso 2:
	//Caso a Lista n�o esteja vazia [...]

	// [...] A pr�xima Celula da nova Celula passa a ser o in�cio atual da Lista.
	novaCelula->prox = lista->inicio;

	// [...] A Celula anterior do inicio atual passa a ser a nova Celula.
	lista->inicio->prev = novaCelula;

	// [...] Atualiza-se o in�cio da lista para a nova Celula.
	lista->inicio = novaCelula;
}

/**
* @brief
* @param
* @return
*/
void llInsereAntesDe(Lista* lista, int info, int alvo) {

	//Cria a nova Celula a qual vai ser adicionada na Lista.
	Celula novaCelula = llCriaCelula(info);

	//Busca a Celula que a nova Celula ser� inserida antes.
	Celula buscada = llBusca(lista, alvo);

	//Caso 1:
	//Se a Celula existir na Lista [...]
	if (buscada != NULL)
	{

		// [...] A Celula anterior da nova Celula passa a ser o anterior da buscada.
		novaCelula->prev = buscada->prev;

		//Caso 1.1:
		//Caso exista uma Celula antes da Celula buscada [...]
		if (buscada->prev != NULL)
		{
			// [...] essa Celula anterior passa a apontar para a nova Celula.
			buscada->prev->prox = novaCelula;
		}

		//A Celula anterior da Celula buscada passa a ser a nova Celula.
		buscada->prev = novaCelula;

		//A pr�xima Celula da nova Celula passa a ser a Celula buscada.
		novaCelula->prox = buscada;
	}

	//Caso 2:
	//A Celula buscada n�o existe na Lista [...]
	else
	{
		// [...] Ent�o ser� inserida no in�cio da Lista.
		llInsereNoInicio(lista, info);
		free(novaCelula);
	}
}

/**
* @brief
* @param
* @return
*/
void llInsereDepoisDe(Lista* lista, int info, int alvo) {

	//Cria a nova Celula a qual vai ser adicionada na Lista.
	Celula novaCelula = llCriaCelula(info);

	//Busca a Celula que a nova Celula ser� inserida depois.
	Celula buscada = llBusca(lista, alvo);

	//Caso 1:
	//Se a Celula existir na Lista [...]
	if (buscada != NULL)
	{

		// [...] A Celula seguinte da nova Celula passa a ser o seguinte da buscada.
		novaCelula->prox = buscada->prox;

		//Caso 1.1:
		//Caso exista uma Celula seguinte da Celula buscada [...]
		if (buscada->prox != NULL)
		{
			// [...] essa Celula seguinte passa a apontar para a nova Celula como anterior.
			buscada->prox->prev = novaCelula;
		}

		//A Celula seguinte da Celula buscada passa a ser a nova Celula.
		buscada->prox = novaCelula;

		//A anterior Celula da nova Celula passa a ser a Celula buscada.
		novaCelula->prev = buscada;
	}

	//Caso 2:
	//A Celula buscada n�o existe na Lista [...]
	else
	{
		// [...] Ent�o ser� inserida no fim da Lista.
		llInsereNoFim(lista, info);
		free(novaCelula);
	}
}

/**
* @brief
* @param
* @return
*/
void llInsereOrdenado(Lista* lista, int info) {

	//Caso 1:
	//A Lista est� vazia ou o n�mero a ser inserido � menor que o n�mero atualmente no in�cio:
	if (lista->inicio == NULL || info < lista->inicio->info)
	{
		//O n�mero � inserido no in�cio.
		llInsereNoInicio(lista, info);
	}

	//Caso 2:
	//O n�mero a ser inserido � maior que o n�mero que est� atualmente no fim:
	else if (info > lista->fim->info)
	{
		//O n�mero � inserido no fim.
		llInsereNoFim(lista, info);
	}

	//Caso 3:
	//O n�mero deve ser inserido no meio da Lista:
	else
	{

		//Cria a nova Celula a qual vai ser adicionada na Lista.
		Celula novaCelula = llCriaCelula(info);

		//Criada uma Celula auxiliar, que ser� usada para percorrer a Lista.
		Celula aux = lista->inicio;

		//Percorrendo a Lista at� que seja encontrado o maior n�mero que seja menor que o n�mero que vai ser inserido na Lista.
		while (aux->prox->info <= info)
		{
			aux = aux->prox;
		}

		//A Celula seguinte da nova Celula aponta para a Celula seguinte da Celula auxiliar.
		novaCelula->prox = aux->prox;

		//A Celula seguinte da Celula auxiliar passa a ser a nova Celula.
		aux->prox = novaCelula;

		//A Celula anterior da nova Celula passa a ser a Celula auxiliar
		novaCelula->prev = aux;
	}
}

/**
* @brief
* @param
* @return
*/
void llRemoveFim(Lista* lista) {

	//Caso 1:
	//Se a lista n�o estiver vazia:
	if (lista->inicio != NULL)
	{
		//Salva o antigo fim da Lista.
		Celula fimRemovido = lista->fim;

		//O pen�ltimo elemento passa a ser o fim da lista.
		lista->fim = lista->fim->prev;

		//O pen�ltimo elemento deixa de apontar para um elemento seguinte.
		lista->fim->prox = NULL;

		//Desaloca o espa�o da Celula que era o fim.
		free(fimRemovido);
	}
}

/**
* @brief
* @param
* @return
*/
void llRemoveInicio(Lista* lista) {

	//Caso 1:
	//Se a lista n�o estiver vazia:
	if (lista->inicio != NULL)
	{
		//Salva o antigo in�cio da Lista.
		Celula inicioRemovido = lista->inicio;

		//O segundo elemento passa a ser o in�cio da lista.
		lista->inicio = lista->inicio->prox;

		//O in�cio da Lista deixa de apontar para um elemento anterior.
		lista->inicio->prev = NULL;

		//Desaloca o espa�o da Celula que era o in�cio.
		free(inicioRemovido);
	}
}

/**
* @brief
* @param
* @return
*/
Celula llRemoveNo(Lista* lista, int info) {

	//Busca a Celula que ser� removida.
	Celula buscada = llBusca(lista, info);

	//Caso 1:
	//Caso essa Celula exista:
	if (buscada != NULL)
	{
		//Caso 1.1:
		//A Celula buscada � o in�cio da Lista:
		if (buscada == lista->inicio)
		{
			//O in�cio � removido.
			llRemoveInicio(lista);
		}

		//Caso 1.2:
		//A Celula buscada � o fim da Lista:
		else if (buscada == lista->fim)
		{
			//O fim � removido.
			llRemoveFim(lista);
		}

		//Caso 1.3:
		//A Celula est� no meio da Lista
		else
		{
			//A Celula seguinte da Celula anterior da Celula buscada passa a apontar para a Celula anterior da Celula buscada.
			buscada->prox->prev = buscada->prev;

			//A Celula anterior da Celula Seguinte da Celula buscada passa a apontar para a Celula seguinte da Celula buscada.
			buscada->prev->prox = buscada->prox;

			//Retorna a Celula removida.
			return buscada;
		}
	}

	//Caso 2:
	//A Celula n�o existe.
	return NULL;
}

/**
* @brief
* @param
* @return
*/
Celula llBusca(Lista* lista, int info) {
	
	//Percorre a Lista inteira.
	for (Celula aux = lista->inicio; aux != NULL; aux = aux->prox)
	{
		//Caso o n�mero desejado exista na Lista [...]
		if (aux->info == info)
		{
			// [...] ele � retornado.
			return aux;
		}
	}

	//O n�mero n�o existe na Lista.
	return NULL;
}

/**
* @brief
* @param
* @return
*/
void llImprimeLista(Lista* lista) {

	//Percorre a Lisa inteira [...]
	for (Celula aux = lista->inicio; aux != NULL; aux = aux->prox)
	{
		// [...] imprimindo o n�mero dentro da Celula atual.
		printf("%d ", aux->info);
	}
	printf("\n");
}

void llImprimePonteiros(Lista* lista) {

	//Percorre a Lisa inteira [...]
	for (Celula aux = lista->inicio; aux != NULL; aux = aux->prox)
	{
		// [...] imprimindo os ponteiros da Celula anterior, Celula atual e Celula seguinte.
		printf("%p <- %p -> %p\n", aux->prev, aux, aux->prox);
	}
	printf("\n");
}

/**
* @brief
* @param
* @return
*/
int llTemCiclo(Lista* lista) {

	//Criadas duas Celulas e apontando-as ao in�cio da Lista.
	Celula rapida = lista->inicio;
	Celula devagar = lista->inicio;

	//Enquanto as Celulas n�o forem nulas e a primeira tiver Celulas seguintes [...]
	while (rapida != NULL && devagar != NULL && rapida->prox != NULL)
	{

		// [...] A primeira anda duas posi��es [...]
		rapida = rapida->prox->prox;

		// [...] A segunda anda uma posi��o [...]
		devagar = devagar->prox;

		// [...] Se elas se encontrarem existe um ciclo.
		if (rapida == devagar)
		{
			return 1;
		}
	}

	//N�o existe um ciclo.
	return 0;
}

/**
* @brief
* @param
* @return
*/
Celula swapCelulas(Celula a, Celula b) {
	Celula temp = b;
	a->prox = b->prox;
	a->prev = b;
	b->prox->prev = a;
	b->prev = temp->prev;
	b->prox = a;
	return b;
}

/**
* @brief
* @param
* @return
*/
Celula bubbleList(Celula inicio) {
	if (inicio == NULL || inicio->prox == NULL)
	{
		return;
	}

	Celula atual, prev, head;
	int swapped;

	head = llCriaCelula(-999);
	head->prox = inicio;
	do
	{
		swapped = 0;
		prev = head;
		atual = head->prox;
		while (atual->prox != NULL)
		{
			if (atual->info > atual->prox->info) 
			{
				prev->prox = swapCelulas(atual, atual->prox);
				swapped = 1;
			}

			prev = atual;
			if (atual->prox != NULL)
			{
				atual = atual->prox;
			}
		}

	} while (swapped);

	atual = head->prox;
	free(head);
	return atual;
}