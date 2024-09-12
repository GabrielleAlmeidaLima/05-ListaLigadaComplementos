#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo; // se for o primeiro
	}
	else if (novo->valor < primeiro->valor) // se for menor que o primeiro
	{
		novo->prox = primeiro; //próximo do novo elemento aponta para o primeiro 
		primeiro = novo; // primeiro agora é o novo elemento menor
	}
	else //se for maior que o primeiro 
	{
		NO* aux = primeiro;
		NO* anterior = NULL;
		
		while (aux != NULL && novo->valor > aux->valor) {
			anterior = aux;
			aux = aux->prox; // faz com que o anterior esteja sempre um ponteiro antes da auxiliar
		}

		if (aux != NULL && aux->valor == novo->valor)
		{
			cout << "Valor ja existe na lista. \n"; //verifica se já existe algum valor igual no ponto de inserção 
			return;
		}

		anterior->prox = novo; // liga os pedaços da lista 
		novo->prox = aux;
	}
}

void excluirElemento()
{
	int elementoApagado;

	cout << "Digite o elemento a ser deletado: ";
	cin >> elementoApagado;

	NO* aux = primeiro;
	NO* anterior = NULL;

	if (primeiro == NULL) { // se a lista estiver vazia
		cout << "Lista vazia \n";
		return;
	}
	else if (primeiro->valor == elementoApagado) { // se for o primeiro elemento 
		aux = primeiro;
		primeiro = primeiro->prox;
		free(aux);
		cout << "Elemento excluido. \n";
	}
	else {
		while (aux != NULL && elementoApagado > aux->valor) { //procura em ordem
			anterior = aux;
			aux = aux->prox;
		}

		if (aux == NULL) {
			cout << "Elemento nao encontrado \n";
		}

		anterior->prox = aux->prox;
		free(aux);
		cout << "Elemento excluido. \n" << endl;
	}
}

void buscarElemento()
{
	int elementoBuscado;

	cout << "Digite um elemento para ser buscado: ";
	cin >> elementoBuscado;

	NO* aux = primeiro;
	NO* anterior = NULL;

	if (primeiro == NULL) { // se a lista estiver vazia
		cout << "Lista vazia \n";
		return;
	}
	else if (primeiro->valor == elementoBuscado) { // se for o primeiro elemento 
		cout << "Elemento " << primeiro->valor << " encontrado. \n";
	}
	else {
		while (aux != NULL && elementoBuscado != aux->valor) { //procura em ordem
			aux = aux->prox;
		}

		if (aux == NULL) {
			cout << "Elemento nao encontrado \n";
		}
		else {
			cout << "Elemento " << aux->valor << " encontrado. \n";
		}
	}
}
