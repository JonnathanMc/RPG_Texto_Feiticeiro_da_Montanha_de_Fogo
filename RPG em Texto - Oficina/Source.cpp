#using<system.dll>
#include "ConsoleHelper.h"
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#include "LeitorDeArquivos.h"
#include "Tela.h"
#include "GerenciadorVariaveis.h"
#include "MenuNavegavel.h"

#define SELECTED_FONTE_COLOR ConsoleColor::Green
#define SELECTED_BACKGROUND_COLOR ConsoleColor::Blue

extern Jogo controleDeEstado;
extern Instrucoes controleDeInstrucoes;

using namespace System;



int main()
{
	array<String^>^ Instrucoes = gcnew array<String^>(1000);

	array<String^>^ Opcoes = gcnew array<String^>(60);
	Opcoes[0] = "INICIAR";
	Opcoes[1] = "INFO";
	Opcoes[2] = "REGRAS";
	Opcoes[3] = "SAIR";

	setlocale(LC_ALL, "Portuguese");

	controleDeEstado.estadoJogo = ESTADO_JOGO::MENU;
	int escolhaMenu = MENU::INICIAR;
	int escolhaInstrucao = 0;

	controleDeEstado.instrucaoAtual = 1;

	Console::SetWindowSize(100, 30);
	Console::SetBufferSize(100, 50);
	Console::CursorVisible = false;
	
	for (;;){
		ConsoleKeyInfo tecla;
		switch (controleDeEstado.estadoJogo)
		{
		case ESTADO_JOGO::MENU:
			controleDeInstrucoes.quantOpcoes = 4;
			if (controleDeEstado.auxMenu == 0){
				Console::Clear();

				ImprimirMenu();
				CorConsolePadrao();
			
				if (Console::KeyAvailable){
					tecla = Console::ReadKey(true);
				}
			
				MenuOpcoesSelecao(0,controleDeInstrucoes.quantOpcoes, tecla, Opcoes);
				CorConsolePadrao();
			}
			
			if (controleDeEstado.auxMenu == 1){
				switch (controleDeEstado.estadoMenu)
				{
				case MENU::INICIAR:
					controleDeEstado.estadoJogo = ESTADO_JOGO::GAMEPLAY;
					break;

				case MENU::INFO:
					Console::Clear();
					Console::Write("info");
					break;
				case MENU::REGRAS:
					Console::Clear();
					Console::Write("regras");
					break;
				}
			}
			
			break;

		case ESTADO_JOGO::GAMEPLAY:
			Console::Clear();
			
			Instrucoes = imprimirInstrucao(controleDeEstado.instrucaoAtual);

			Console::SetCursorPosition(10,22);
			Console::Write(controleDeInstrucoes.quantOpcoes);

			ConsoleKeyInfo tecla;
			if (Console::KeyAvailable){
			tecla = Console::ReadKey(true);
			}
			MenuOpcoesSelecao(1, controleDeInstrucoes.quantOpcoes, tecla, Instrucoes);
			
		}
		Threading::Thread::Sleep(64);

	}
}
