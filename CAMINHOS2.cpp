/* RELAÇÃO CAMINHOS CIDADES 2 - ORIGEM LIVRO BOLDRINI - ÁLGEBRA LINEAR
LUAN FÁBIO MARINHO GALINDO
*/

#include <iostream>
#include <locale.h>
#include <E:\DOCUMENTOS\GÁS INFINITO\INFORMÁTICA\TRABALHOS\ÁLGEBRA LINEAR\EIGEN\Eigen/Dense>
using namespace Eigen;
using namespace std;
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "PORTUGUESE");
	int op, cont;
	MatrixXf linhas(5, 5), passos (5, 5);
	//Relação caminho/cidade
	linhas << 0, 1, 1, 1, 1,
			 1, 0, 1, 1, 0,
			 0, 1, 0, 1, 0,
			 0, 0, 1, 0, 1,
			 0, 0, 0, 1, 0;
			 
	passos = linhas;
	cont = 0;
	do
	{
		cont++;
		cout << "\n Para " << cont << " passo(s), a quantidade de caminhos possíveis partindo de cada cidade são:\n"
			 << "\nA B C D E"
			 << "\n"
			 << passos
			 << "\n Deseja continuar? Se sim, digite 1. ";
		cin >> op;
		if (op == 1)
			passos *= linhas;
	}
	while(op == 1);
	return 0;
}
