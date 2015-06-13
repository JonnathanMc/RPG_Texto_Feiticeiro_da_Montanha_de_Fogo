#include "MenuNavegavel.h"
#include "Tela.h"
#include "GerenciadorVariaveis.h"
#include<stdlib.h>

using namespace System;

int opcao;
extern Jogo controleDeEstado;
extern Instrucoes controleDeInstrucoes;

int MenuOpcoesSelecao(int tipoDeInstrucao,int quantOpcoes, System::ConsoleKeyInfo tecla, array<System::String^>^ Instrucoes)
{
	if (controleDeEstado.estadoJogo == ESTADO_JOGO::MENU){
		controleDeInstrucoes.linhaApos = Console::WindowHeight * 0.5f ;
	}
	
	ImprimirGerenciadorOpcoes(controleDeInstrucoes.quantOpcoes, opcao, Instrucoes, controleDeInstrucoes.linhaApos);
	if (tecla.Key == ConsoleKey::S || tecla.Key == ConsoleKey::DownArrow)
	{
		opcao++;
		if (opcao == 2)
			opcao = 0;
	}
	if (tecla.Key == ConsoleKey::W || tecla.Key == ConsoleKey::UpArrow)
	{
		if (opcao == 0)
			opcao = controleDeInstrucoes.quantOpcoes-1;
		else
			opcao--;
	}
	if (tipoDeInstrucao == 0){
		if (opcao == MENU::INICIAR && tecla.Key == ConsoleKey::Enter)
		{
			controleDeEstado.estadoMenu = MENU::INICIAR;
			controleDeEstado.auxMenu = 1;
		}
		if (opcao == MENU::INFO && tecla.Key == ConsoleKey::Enter)
		{
			controleDeEstado.estadoMenu = MENU::INFO;
			controleDeEstado.auxMenu = 1;
		}
		if (opcao == MENU::REGRAS && tecla.Key == ConsoleKey::Enter)
		{
			controleDeEstado.estadoMenu = MENU::REGRAS;
			controleDeEstado.auxMenu = 1;
		}
		if (opcao == ESTADO_JOGO::SAIR && tecla.Key == ConsoleKey::Enter)
		{
			exit(0);
		}
	}
	if (tipoDeInstrucao == 1){
		for (int a = 0; a < quantOpcoes; a++){
			if (opcao == a && tecla.Key == ConsoleKey::Enter){
				controleDeEstado.instrucaoAtual = controleDeInstrucoes.opcoesNumericas[a];
			}
		}
		//scanf_s("%d", &controleDeEstado.instrucaoAtual);
	}
	

	return opcao;
}