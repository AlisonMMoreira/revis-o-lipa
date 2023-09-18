#include <stdio.h>
#include <stdlib.h>


//Define um struct que será usado para armazenar as informações que o usuário inserir
struct Estudante{
	char nome[50];
	int idade;
	int matricula;
};


//Cria as definições da pilha
struct Pilha{
	struct Estudante* estudantes;
	int tamanho;
	int capacidade;
};

//Criando uma pilha Vazia
struct Pilha* criarPilha(int capacidade){
	struct Pilha* pilha = (struct Pilha*)malloc(sizeof(struct Pilha));
	pilha->capacidade = capacidade;
	pilha->tamanho = 0;
	pilha->estudantes = (struct Estudante*)malloc(capacidade * sizeof(struct Estudante));
	return pilha;
}


//Verifica se a pilha está vazia
int estaVazia(struct Pilha* pilha){
	return pilha -> tamanho==0;
}

//Verifica se a pilha está completa, sempre que precisar usar alguma informação preciso chamar esse ponteiro
int estaCheia(struct Pilha* pilha){
	return pilha->tamanho == pilha->capacidade;
}

//Empilha a pilha
void push(struct Pilha* pilha, struct Estudante estudante){
	if(estaCheia(pilha)){
		printf("A pilha está cheia!");
		return;
	}
	pilha->estudantes[pilha->tamanho++] = estudante;
	printf("Estudante empilhado!\n");
}

//Desempilhar a pilha
struct Estudante pop(struct Pilha* pilha){
	struct Estudante estudanteV;
	if(estaVazia(pilha)){
		return estudanteV;
	}
	return pilha->estudantes[--pilha->tamanho];
}


int main(void){
	struct Pilha* pilha = criarPilha(5)	;
	
	struct Estudante estudantes1 = { "Augusto",18, 20231 };
	struct Estudante estudantes2 = { "Bruno",19, 20232 };
	struct Estudante estudantes3 = { "Marco",21, 20231 };
	
	push(pilha, estudantes1);
	push(pilha, estudantes2);
	push(pilha, estudantes3);
	
	Voltar:;
	
	struct Estudante estudanteDesempilhado = pop(pilha);
	printf("Desempilhado - Nome: %s, Idade: %d, Matricula: %d",estudanteDesempilhado.nome, estudanteDesempilhado.idade, estudanteDesempilhado.matricula);
	
	
	
	return 0;
}
