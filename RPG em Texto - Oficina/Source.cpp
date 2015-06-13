#include "ConsoleHelper.h"
#include<stdlib.h>
#include<locale.h>
#include<stdio.h>

//#include "Fases.h"

#define ESTADO_JOGO_MENU 0
#define ESTADO_JOGO_GAMEPLAY 1
#define ESTADO_JOGO_INFO 2
#define ESTADO_JOGO_REGRAS 3
#define ESTADO_JOGO_GAMEOVER 4

#define ESCOLHA_MENU_INICIAR 0
#define ESCOLHA_MENU_INFO 1
#define ESCOLHA_MENU_REGRAS 2
#define ESCOLHA_MENU_SAIR 3

#define SELECTED_FONTE_COLOR ConsoleColor::Green
#define SELECTED_BACKGROUND_COLOR ConsoleColor::Blue

using namespace System;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int estadoJogo = ESTADO_JOGO_MENU;
	int escolhaMenu = ESCOLHA_MENU_INICIAR;
	int escolhaInstrucao = 0;

	int instrucaoAtual = 1;

	char opcoes[5][20];

	Console::SetWindowSize(100, 30);
	Console::SetBufferSize(100, 50);
	Console::CursorVisible = true;


	for (;;){
		switch (estadoJogo)
		{
		case ESTADO_JOGO_MENU:
			Console::Clear();

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

			Console::BackgroundColor = ConsoleColor::Black;
			Console::ForegroundColor = ConsoleColor::White;

			switch (escolhaMenu)
			{
			case ESCOLHA_MENU_INICIAR:
				ConsoleHelper::ImprimirASCIIExtended(43, 15, SELECTED_BACKGROUND_COLOR, SELECTED_FONTE_COLOR, "INICIAR");
				ConsoleHelper::ImprimirASCIIExtended(44, 16, ConsoleColor::Black, ConsoleColor::White, "INFO");
				ConsoleHelper::ImprimirASCIIExtended(43, 17, ConsoleColor::Black, ConsoleColor::White, "REGRAS");
				ConsoleHelper::ImprimirASCIIExtended(44, 18, ConsoleColor::Black, ConsoleColor::White, "SAIR");
				break;

			case ESCOLHA_MENU_INFO:

				ConsoleHelper::ImprimirASCIIExtended(43, 15, ConsoleColor::Black, ConsoleColor::White, "INICIAR");
				ConsoleHelper::ImprimirASCIIExtended(44, 16, SELECTED_BACKGROUND_COLOR, SELECTED_FONTE_COLOR, "INFO");
				ConsoleHelper::ImprimirASCIIExtended(43, 17, ConsoleColor::Black, ConsoleColor::White, "REGRAS");
				ConsoleHelper::ImprimirASCIIExtended(44, 18, ConsoleColor::Black, ConsoleColor::White, "SAIR");

				break;
			case ESCOLHA_MENU_REGRAS:

				ConsoleHelper::ImprimirASCIIExtended(43, 15, ConsoleColor::Black, ConsoleColor::White, "INICIAR");
				ConsoleHelper::ImprimirASCIIExtended(44, 16, ConsoleColor::Black, ConsoleColor::White, "INFO");
				ConsoleHelper::ImprimirASCIIExtended(43, 17, SELECTED_BACKGROUND_COLOR, SELECTED_FONTE_COLOR, "REGRAS");
				ConsoleHelper::ImprimirASCIIExtended(44, 18, ConsoleColor::Black, ConsoleColor::White, "SAIR");

				break;

			case ESCOLHA_MENU_SAIR:
				ConsoleHelper::ImprimirASCIIExtended(43, 15, ConsoleColor::Black, ConsoleColor::White, "INICIAR");
				ConsoleHelper::ImprimirASCIIExtended(44, 16, ConsoleColor::Black, ConsoleColor::White, "INFO");
				ConsoleHelper::ImprimirASCIIExtended(43, 17, ConsoleColor::Black, ConsoleColor::White, "REGRAS");
				ConsoleHelper::ImprimirASCIIExtended(44, 18, SELECTED_BACKGROUND_COLOR, SELECTED_FONTE_COLOR, "SAIR");

				break;
			}
			ConsoleKeyInfo tecla;
			tecla = Console::ReadKey(true);

			if (tecla.Key == ConsoleKey::S || tecla.Key == ConsoleKey::DownArrow)
			{
				escolhaMenu++;
				if (escolhaMenu == 4)
					escolhaMenu = 0;
			}
			if (tecla.Key == ConsoleKey::W || tecla.Key == ConsoleKey::UpArrow)
			{
				if (escolhaMenu == 0)
					escolhaMenu = 3;
				else
					escolhaMenu--;
			}

			Console::ForegroundColor = ConsoleColor::White;
			Console::BackgroundColor = ConsoleColor::Black;


			// MUNDANÇA DE MODO 
			if (escolhaMenu == ESCOLHA_MENU_INICIAR && tecla.Key == ConsoleKey::Enter)
			{
				estadoJogo = ESTADO_JOGO_GAMEPLAY;
			}
			if (escolhaMenu == ESCOLHA_MENU_INFO && tecla.Key == ConsoleKey::Enter)
			{
				estadoJogo = ESTADO_JOGO_INFO;
			}
			if (escolhaMenu == ESCOLHA_MENU_REGRAS && tecla.Key == ConsoleKey::Enter)
			{
				estadoJogo = ESTADO_JOGO_REGRAS;
			}
			if (escolhaMenu == ESCOLHA_MENU_SAIR && tecla.Key == ConsoleKey::Enter)
			{
				exit(0);
			}
			break;

		case ESTADO_JOGO_GAMEPLAY:
			Console::Clear();

			switch (instrucaoAtual){
			case 1:
				Console::BackgroundColor = ConsoleColor::Black;
				Console::ForegroundColor = ConsoleColor::White;

				Console::SetCursorPosition(5, 3);
				Console::WriteLine ("Finalmente a sua caminhada de dois dias chegou ao fim. Você desembainha a sua ");
				Console::SetCursorPosition(5, 4);
				Console::WriteLine( "espada, coloca-a no chão e suspira aliviado, enquanto se abaixa para se sentar ");
				Console::SetCursorPosition(5, 5);
				Console::WriteLine("nas pedras cheias de musgo para um momento de descanso.Você se espreguiça, ");
				Console::SetCursorPosition(5, 6);
				Console::WriteLine("esfrega os olhos e, afinal, olha para a Montanha do Cume de Fogo.");
					
				Console::SetCursorPosition(5, 8);
				Console::WriteLine("A própria montanha em si já tem um ar ameaçador. Algum animal gigantesco parece ");
				Console::SetCursorPosition(5, 9);
				Console::WriteLine("ter deixado as marcas de suas garras na encosta íngreme diante de você.Penhascos");
				Console::SetCursorPosition(5, 10);
				Console::WriteLine("rochosos e pontudos se projetam, formando ângulos estranhos.No cume você já pode");
				Console::SetCursorPosition(5, 11);
				Console::WriteLine("vislumbrar a sinistra coloração vermelha - provavelmente alguma vegetação ");
				Console::SetCursorPosition(5, 12);
				Console::WriteLine("que deu nome à montanha.Talvez ninguém jamais chegue a saber o que cresce lá em ");
				Console::SetCursorPosition(5, 13);
				Console::WriteLine("cima, misteriosa uma vez que escalar o pico deve ser com certeza impossível.");

				Console::SetCursorPosition(5, 15);
				Console::WriteLine("Sua busca está para começar.Do outro lado da clareira há uma escura entrada de ");
				Console::SetCursorPosition(5, 16);
				Console::WriteLine("caverna.Você pega a sua espada, levanta-se e considera que perigos podem estar ");
				Console::SetCursorPosition(5, 17);
				Console::WriteLine("à sua frente.Mas, com determinação, você recoloca a sua espada na bainha e se");
				Console::SetCursorPosition(5, 18);
				Console::WriteLine("aproxima da caverna.");

				Console::SetCursorPosition(5, 20);
				Console::WriteLine("Você dá uma primeira olhada na penumbra e vê - paredes escuras e úmidas com poças ");
				Console::SetCursorPosition(5, 21);
				Console::WriteLine("de água no chão de pedra à sua frente. O ar é frio e úmido.Você acende a sua ");
				Console::SetCursorPosition(5, 22);
				Console::WriteLine("lanterna e avança cautelosamente pela escuridão.Teias de aranha tocam seu rosto e ");
				Console::SetCursorPosition(5, 23);
				Console::WriteLine("você ouve a movimentação de pés minúsculos : muito provavelmente, ratazanas.Você ");
				Console::SetCursorPosition(5, 24);
				Console::WriteLine("adentra a caverna.Depois de uns poucos metros, chega logo a uma encruzilhada. ");
				Console::SetCursorPosition(5, 26);
				Console::WriteLine("Você Deseja:");

				//virar para o oeste(vá para 71) ou para o leste(vá para 278) ?
				do{
					ConsoleHelper::ImprimirASCIIExtended(5, 28, "Virar para Oeste - 71");
					ConsoleHelper::ImprimirASCIIExtended(5, 29, "Virar para Leste - 278");
					Console::SetCursorPosition(17, 26);
					scanf_s("%d", &instrucaoAtual);
				} while (instrucaoAtual != 71 && instrucaoAtual != 278);

				

				break;
			case 71:
				Console::Clear();
				Console::SetCursorPosition(5, 3);
				Console::Write("Há uma curva na passagem para a direita, levando para o norte.Cautelosamente, você se ");
				Console::SetCursorPosition(5, 4);
				Console::WriteLine("aproxima de um posto de sentinela em um canto e, ao olhar para dentro, vê um ser  ");
				Console::SetCursorPosition(5, 5);
				Console::WriteLine("estranho, parecido com um Goblin, vestido de armadura de couro e adormecido em seu");
				Console::SetCursorPosition(5, 6);
				Console::WriteLine("posto.Você tenta passar por ele na ponta dos pés.Teste a sua Sorte.Se você tiver");
				Console::SetCursorPosition(5, 7);
				Console::WriteLine("sorte, ele não acorda e continua a roncar alto. Se você não tiver sorte, você pisa");
				Console::SetCursorPosition(5, 8);
				Console::WriteLine("em terreno mole e faz um barulho, e os olhos do ser se abrem instantaneamente");
				Console::SetCursorPosition(5, 9);
				Console::WriteLine(" – vá para 248.");
				

				break;

			case 278:

				break;

			}


			break;


		}
		Threading::Thread::Sleep(64);

	}
}
