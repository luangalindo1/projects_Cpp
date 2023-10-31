/* INVERTENDO UMA MATRIZ
LUAN F�BIO MARINHO GALINDO
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
	cout << "\n Insira o n�mero da sua matr�cula: ";
	cin >> a;
	cout << "\n Para a inversa de uma matriz existir, seu determinante deve ser diferente de zero.";
	// Vamos testar todos os valores poss�veis de x
	for (i = 0; i < 10; i++)
	{
		x = i;
		M <<  1, 1, 1, 1,
		  0, 1, 1, 1,
		  0, 0, (x - a), 1,
		  0, 0, 0, x;
		if (M.determinant() == 0)
		{
			cout << "\n\n Essa matriz  N�O � invers�vel: \n" << M
				 << "\n\n Note que x = " << x
				 << "\n\n--------------------------------------";

		}
	}
	cout << "\n\n Para todos os outros valores de x, tais que x seja um n�mero real, a matriz � invers�vel."
	     << "\n\n--------------------------------------";	
	return 0;
}
