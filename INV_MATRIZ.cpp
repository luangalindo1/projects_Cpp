/* INVERTENDO UMA MATRIZ
LUAN FÁBIO MARINHO GALINDO
*/

#include <iostream>
#include <...PATH...\EIGEN\Eigen/Dense>
using namespace Eigen;
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "PORTUGUESE");
	int x, a, i;
	Matrix4f M;
	cout << "\n Insira o número da sua matrícula: ";
	cin >> a;
	cout << "\n Para a inversa de uma matriz existir, seu determinante deve ser diferente de zero.";
	// Vamos testar todos os valores possíveis de x
	for (i = 0; i < 10; i++)
	{
		x = i;
		M <<  1, 1, 1, 1,
		  0, 1, 1, 1,
		  0, 0, (x - a), 1,
		  0, 0, 0, x;
		if (M.determinant() == 0)
		{
			cout << "\n\n Essa matriz  NÃO é inversível: \n" << M
				 << "\n\n Note que x = " << x
				 << "\n\n--------------------------------------";

		}
	}
	cout << "\n\n Para todos os outros valores de x, tais que x seja um número real, a matriz é inversível."
	     << "\n\n--------------------------------------";	
	return 0;
}
