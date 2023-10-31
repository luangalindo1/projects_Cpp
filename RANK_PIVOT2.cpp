/* ANALISANDO AS SOLUÇÕES DE UMA MATRIZ
LUAN FÁBIO MARINHO GALINDO
*/

#include <iostream>
#include <...PATH...\EIGEN\Eigen/Dense>
using namespace Eigen;
using namespace std;

void EstudaSistema (MatrixXf, MatrixXf);

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "PORTUGUESE");
	// Coef = Matriz dos coeficientes; Var: vetor dos termos independentes; Amp: Matriz ampliada;
	MatrixXf CoefA(4, 3), VarA(4, 1), AmpA(4,4), VarB(4, 1), AmpB(4,4), CoefC(2, 3), VarC(2, 1), AmpC(2,4);
	CoefA << 1, 4, 6,
		  0, 2, 5,
		  0, 0, 3,
		  0, 0, 0;

	VarA << 2,
		 2,
		 1,
		 0;
	AmpA << CoefA, VarA;

	VarB << 2,
		 2,
		 1,
		 1;
	AmpB << CoefA, VarB;

	CoefC << 0, 1, 0,
		  0, 0, 1;
	VarC << 2,
		 2;
	AmpC << CoefC, VarC;

	cout << "\n As temos as matrizes:\n A:\n" << AmpA << "\n\n B:\n" << AmpB << "\n\n C:\n" << AmpC << "\n\n";
	
	EstudaSistema(CoefA, VarA);
	EstudaSistema(CoefA, VarB);
	EstudaSistema(CoefC, VarC);

	return 0;
}

int Posto (MatrixXf M)
{
	FullPivLU <MatrixXf> lu(M);
	return lu.rank();
}
void EstudaSistema (MatrixXf Coef, MatrixXf Var)
{
	int lin, col;
	
	lin = Coef.rows();
	col = Coef.cols() + Var.cols();
	
	MatrixXf Aux(lin,col);
	Aux << Coef, Var;
	if((Posto(Aux) == Posto(Coef)) && (Posto(Aux) == Aux.cols()))
		cout << "\n\n O sistema\n" << Aux << "\n\n Tem solução única";
	else if(Posto(Aux) == Posto(Coef))
		cout << "\n\n O sistema\n\n" << Aux << "\n\n Possui infinitas soluções."
	         << "\n Note que ele possui " << Aux.cols() - Posto(Aux) << " grau(s) de liberdade."
	         << "\n Além disso, veja que Pc = " << Posto(Coef) << " e Pa = " << Posto(Aux);
	 else
	 	cout << "\n\n O sistema \n" << Aux << "\n\n NÃO possui solução.";		
	
}
