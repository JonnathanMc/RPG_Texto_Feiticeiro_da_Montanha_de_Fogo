#include "Tela.h"
#include "ConsoleHelper.h"
#include "MenuNavegavel.h"
#include "GerenciadorVariaveis.h"

using namespace System;
extern Instrucoes controleDeInstrucoes;

void ImprimirTexto(){
	Console::Write("Imprimir texto");
}
void ImprimirMenu(){
	ConsoleHelper::ImprimirASCIIExtended(10, 1, "            ___    __      _ _   _          _                 _                        ");
	ConsoleHelper::ImprimirASCIIExtended(10, 2, "           /___\\  / _| ___(_) |_(_) ___ ___(_)_ __ ___     __| | __ _                  ");
	ConsoleHelper::ImprimirASCIIExtended(10, 3, "          //  // | |_ / _ \\ | __| |/ __/ _ \\ | '__/ _ \\   / _` |/ _` |                 ");
	ConsoleHelper::ImprimirASCIIExtended(10, 4, "         / \\_//  |  _|  __/ | |_| | (_|  __/ | | | (_) | | (_| | (_| |                 ");
	ConsoleHelper::ImprimirASCIIExtended(10, 5, "         \\___/   |_|  \\___|_|\\__|_|\\___\\___|_|_|  \\___/   \\__,_|\\__,_|                 ");
	ConsoleHelper::ImprimirASCIIExtended(10, 6, "                                                                                       ");
	ConsoleHelper::ImprimirASCIIExtended(10, 7, "                       _              _                 _         __                   ");
	ConsoleHelper::ImprimirASCIIExtended(9, 8, "  _ __ ___   ___  _ __ | |_ __ _ _ __ | |__   __ _    __| | ___   / _| ___   __ _  ___  ");
	ConsoleHelper::ImprimirASCIIExtended(9, 9, " | '_ ` _ \\ / _ \\| '_ \\| __/ _` | '_ \\| '_ \\ / _` |  / _` |/ _ \\ | |_ / _ \\ / _` |/ _ \\ ");
	ConsoleHelper::ImprimirASCIIExtended(10, 10, "| | | | | | (_) | | | | || (_| | | | | | | | (_| | | (_| |  __/ |  _| (_) | (_| | (_) | ");
	ConsoleHelper::ImprimirASCIIExtended(10, 11, "|_| |_| |_|\\___/|_| |_|\\__\\__,_|_| |_|_| |_|\\__,_|  \\__,_|\\___| |_|  \\___/ \\__, |\\___/  ");
	ConsoleHelper::ImprimirASCIIExtended(10, 12, "                                                                           |___/        ");
}
void CorConsolePadrao()
{
	Console::BackgroundColor = ConsoleColor::Black;
	Console::ForegroundColor = ConsoleColor::White;
}

void ImprimirGerenciadorOpcoes(int quantOpcoes, int escolhaMenu, array<System::String^>^ Instrucoes, int posicaoY)
{
	for (int a = 0; a < quantOpcoes; a++){
		if (a == escolhaMenu){
			Console::BackgroundColor = ConsoleColor::White;
			Console::ForegroundColor = ConsoleColor::Black;
		}
		else{
			Console::BackgroundColor = ConsoleColor::Black;
			Console::ForegroundColor = ConsoleColor::White;
		}
		Console::SetCursorPosition(Console::WindowWidth*0.5f, (controleDeInstrucoes.linhaApos + 2) + a);
		Console::WriteLine(Instrucoes[a]);
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor::White;
	}
}