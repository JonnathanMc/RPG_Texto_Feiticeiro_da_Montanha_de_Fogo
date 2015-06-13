#include<stdlib.h>

#using<system.dll>
#include<stdio.h>
#include "LeitorDeArquivos.h"
#include "GerenciadorVariaveis.h"

using namespace System;
using namespace System::IO;
using namespace std;


extern Instrucoes controleDeInstrucoes;

array<System::String^>^ imprimirInstrucao(int paragrafo){
	
	int contador = 0, count = 0;
	int countOpcoes = 0;
	int countLinhas = 0;
	//int opcoesNumericas[12];
	
	array<String^>^ managedArray = gcnew array<String^>(1000);  //Array de Strings com 100 linhas, cada linha da String armazena uma linha do arquivo de texto
	array<String^>^ opcoes = gcnew array<String^>(100);
	//int escolhaMenu;

	String^ fileName;

	int a, assist = 0, finalInstrucao = 0;
	if (paragrafo <= 36)
		fileName = "instrucoes.txt"; // nome do arquivo txt, deve ter o mesmo nome do .txt localizado na pasta do projeto
	if (paragrafo > 36)
		fileName = "instrucoes2.txt";
	if (paragrafo > 81)
		fileName = "instrucoes3.txt";

	try
	{
		//Console::WriteLine("trying to open file {0}...", fileName);
		StreamReader^ din = File::OpenText(fileName);

		String^ str;
		String^ pars;

		Console::WriteLine("{0}", managedArray[0]);

		pars = "#" + paragrafo + "#";  // uma string (pars) que recebe o numero do paragrafo e concatena com "#" para corresponder à tag do arquivo de texto 

		while ((str = din->ReadLine()) != pars)  // str = din->ReadLine() || faz a string receber a linha do arquivo de texto e percorre o arquivo ate encontrar o padrado "#paragrafo#" ex: #12#
		{
			count++;

		}
		while ((str = din->ReadLine()) != "!!!"){

			if (str == "@" && finalInstrucao == 0){
				finalInstrucao = 1;
			}

			if (assist == 2){

				controleDeInstrucoes.opcoesNumericas[countOpcoes] = Convert::ToInt32(str);
				assist = 0;
				countOpcoes++;
			}
			if (assist == 1) //  se assist for igual a 1(encontrar '@') ele vai pegar a proxima linha depois do '@'
			{
				opcoes[countOpcoes] = str;

				assist = 2;
			}

			if (str == "@"){
				assist = 1;
			}

			if (finalInstrucao != 1){
				managedArray[contador] = str; // array de string recebe a string que recebeu a linha do arquivo txt
				contador++;
				countLinhas++;
				controleDeInstrucoes.linhaApos++;

			}

			Console::SetCursorPosition(3, count);
			count++;

		}
	}
	catch (Exception^ e)
	{
		if (dynamic_cast<FileNotFoundException^>(e))
			Console::WriteLine("file '{0}' not found", fileName);
		else
			Console::WriteLine("problem reading file '{0}'", fileName);
	}
	Console::Clear();
	// Imprime todas as linhas da instrução atual
	for (a = 0; a < contador; a++){
		Console::SetCursorPosition(3, a);
		Console::WriteLine("{0}", managedArray[a]);		
	}
	Console::Write("pica");


	return opcoes;
}
