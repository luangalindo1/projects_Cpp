/* ANÁLISE DE MATRIZ
LUAN FÁBIO MARINHO GALINDO
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "PORTUGUESE");
	int M, N, P, Q, R, S, cont;

	cont = 0;
	cout << "\n\n No item (a), considerando que os valores variam de um a nove, temos:";
	for (M = 1; M < 10; M++)
		for (N = 1; N < 10; N++)
			for (P = 1; P < 10; P++)
				for (Q = 1; Q < 10; Q++)
					for (R = 1; R < 10; R++)
						for (S = 1; S < 10; S++)
							if (N == P && M == R && S == Q)
							{
								cout << "\n\n Para o produto existir, deve ocorrer:"
									 << "\n N = P = " << N
									 << "\n M = R = " << M
									 << "\n S = Q = " << Q
									 << "\n A matriz seria, então: C(" << R << "x" << S << ")";
								cont++;
							}
	cout << "\n\n São " << cont << " possibilidades em (a)" << endl << endl;
	system("pause");

	cont = 0;
	cout << "\n\n No item (b), considerando que os valores variam de um a nove, temos:";
	for (M = 1; M < 10; M++)
		for (N = 1; N < 10; N++)
			for (P = 1; P < 10; P++)
				for (Q = 1; Q < 10; Q++)
					for (R = 1; R < 10; R++)
						for (S = 1; S < 10; S++)
							if (((R == M) == P) && ((S == N) == Q))
							{
								cout << "\n\n Para a soma existir, deve ocorrer:"
									 << "\n R = M = P = " << R
									 << "\n S = N = Q = " << S
									 << "\n A matriz seria, então: C(" << R << "x" << S << ")";
								cont++;
							}
	cout << "\n\n São " << cont << " possibilidades em (b)" << endl << endl;
	system("pause");

	cout << "\n\n No item (c), a igualdade é falsa, pois há um escalar envolvido.";

	cont = 0;
	cout << "\n\n No item (d), considerando que os valores variam de um a nove, temos:"
		 << "\n Condições de existência da inversa:"
		 << "\n I. As matrizes devem ser quadradas;"
		 << "\n II. det(M) != 0;"
		 << "\n Então, os valores possíveis são:\n";
	for (R = 1; R < 10; R++)
	{
		cout << "\n R = S = M = N = " << R
			 << "\n A matriz seria, então: C(" << R << "x" << R << ")";
		cont++;
	}
	cout << "\n\n São " << cont << " possibilidades em (d)" << endl << endl;
	system("pause");

	cont = 0;
	cout << "\n\n No item (e), considerando que os valores variam de um a nove, temos:";
	for (P = 1; P < 10; P++)
		for (Q = 1; Q < 10; Q++)
		{
			cout << "\n R = N = " << P
				 << "\n Q = M = " << Q
				 << "\n A matriz seria, então: B(" << P << "x" << Q << ")" << endl << endl;
			cont++;
		}
	cout << "\n\n São " << cont << " possibilidades em (e)" << endl << endl;
	system("pause");

	cont = 0;
	cout << "\n\n No item (f), considerando que os valores variam de um a nove, temos:";
	for (M = 1; M < 10; M++)
	{
		cout << "\n M = N = " << M
			 << "\n A matriz seria, então: A(" << M << "x" << M << ")";
		cont++;
	}
	cout << "\n\n Sï¿½o " << cont << " possibilidades em (f)" << endl << endl;
	system("pause");

	cont = 0;
	cout << "\n\n No item (g), considerando que os valores variam de um a nove, temos:";

	for (R = 1; R < 10; R++)
	{
		cout << "\n R = S = " << R
			 << "\n A matriz seria, então: C(" << R << "x" << R << ")";
		cont++;
	}
	cout << "\n\n São " << cont << " possibilidades em (g)" << endl << endl;
	system("pause");

	return 0;
}