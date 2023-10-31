/* POSTO E PIVOT DE MATRIZ
LUAN F�BIO MARINHO GALINDO
*/

#include <iostream>
#include <...PATH...\EIGEN\Eigen/Dense>
using namespace Eigen;
using namespace std;

int Posto (MatrixXf);

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "PORTUGUESE");
	int p, q, cont;
	MatrixXf Coeficientes(3, 4), Valores(3, 1), Ampliada(3, 5), Aux;
	cont = 0;
	cout << "\n No item (a), temos:";
	for (p = 0; p < 10; p++)
		for (q = 0; q < 10; q++)
		{
			Coeficientes << 1, 0, 1, 2,
						 1, 1, 2, 1,
						 0, 2, 2, p;
			Valores << 1,
					3,
					q;
			Ampliada << Coeficientes, Valores;

			if ((Posto(Ampliada) == Posto(Coeficientes)) && (Posto(Ampliada) == Ampliada.cols()))
			{
				cont++;
				cout << "\n O sistema \n" << Ampliada << "\n Tem solu��o �nica, e p = " << p << " e q = " << q;
			}
		}
	if (cont == 0)
	{
		cout << "\n O sistema n�o possui solu��o �nica."
			 << "\n De fato, note que o posto da matriz ampliada � " << Posto(Ampliada) << " e o grau de liberdade � " << Ampliada.cols() - Posto(Ampliada);
	}
	if (Posto(Ampliada) < Ampliada.cols())
		cout << "\n O sistema possui infinitas solu��es.";

	cout << "\n No item (b), temos:"
	     << "\n Calculando no intervalo de -10 a 9";
	for (p = -10; p < 10; p++)
		for (q = -10; q < 10; q++)
		{
			Coeficientes << 1, 0, 1, 2,
						 0, 1, 1, -1,
						 0, 0, 0, p + 2;
			Valores << 1,
					2,
					q - 4;
			Ampliada << Coeficientes, Valores;
			// N�o consegui escalonar pelo Eigen
			Aux = Coeficientes.fullPivLu().solve(Valores);
			if ((Coeficientes * Aux).isApprox(Valores) == 0)
			{
				cout << "\n\n O sistema n�o possui solu��o para p = " << p << " e q = " << q;
				cout << "\n Veja a matriz ampliada:\n" << Ampliada;
			}
			/*if ((Posto(Ampliada) == Posto(Coeficientes)) && (Posto(Ampliada) == Ampliada.cols()))
			{
				Aux = Coeficientes.fullPivLu().solve(Valores);
				if ((Coeficientes * Aux).isApprox(Valores))
				{
					cout << "\n\n O sistema \n" << Ampliada << "\n\n Tem solu��o, com p = " << p << " e q = " << q;
					cout << "\n De fato, os seguintes valores satisfazem o sistema: " << "\n\n " << Aux;
				}
			}*/

		}
		cout << "\n Para o item (c), temos:"
		     << "\n I. Por (a), o sistema possui infinitas solu��es"
		     << "\n II. Por (b), o sistema n�o possui solu��o quando p = -2 e q != 4";

	return 0;
}

int Posto (MatrixXf M)
{
	FullPivLU <MatrixXf> lu(M);
	return lu.rank();
}
