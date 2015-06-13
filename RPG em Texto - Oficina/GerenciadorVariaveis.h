#ifndef GERENCIADORVARIAVEIS_H
#define GERENCIADORVARIAVEIS_H

#using<system.dll>
using namespace System;

#include "ConsoleHelper.h"
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef enum ESTADO_JOGO
{
	MENU,
	GAMEPLAY,
	GAMEOVER,
	SAIR
};
typedef enum MENU
{
	INICIAR,
	INFO,
	REGRAS
};
enum TIPO_INSTRUCAO{
	ESPECIAL,
	NORMAL
};

struct Jogo
{
	int estadoJogo;
	int estadoMenu;
	int auxMenu;
	int instrucaoAtual;
}; 
struct Instrucoes
{
	int quantOpcoes;
	int linhaApos;
	int opcoesNumericas[10];
};



#endif 