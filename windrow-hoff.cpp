#include <iostream>
#include <math.h>
using namespace std;

int main()
{

	// ENTRADAS
	float ent[4][3];

	// PESOS
	float W[4][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, W1[3];

	// SAIDAS INTERMEDIARIAS
	float S[4] = {0}, E[] = {0, 0, 0, 0};

	// SAIDA FINAL
	float Y[4];

	// SAIDAS DESEJADA
	float d[] = {0.5, -0.5, -0.5, -0.5};

	// PARAMETROS
	float alfa = 1.5, tol = 0.9;

	// INDICES
	int x, y, ite, ite_count = 0, err = 0;

	// AUXILIARES
	float div;

	cout << "Informe a quantidade de iterações: ";
	cin >> ite;
	cout << "Informe o valor de erro: ";
	cin >> tol;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Informe a saida[" << i << "]"
				 << "[" << j << "]: ";
			cin >> ent[i][j];
		}
	}

	while (ite_count != ite)
	{
		for (x = 0; x < 4; x++)
		{

			// CALCULANDO SAIDA INTERMIDIARIA
			for (y = 0; y < 3; y++)
			{
				S[x] += W[x][y] * ent[x][y];
			}

			// CACULANDO O ERRO
			E[x] = d[x] - S[x];

			// VERICAÇÃO DE TOLERANCIA1
			if (tol > abs(E[x]))
			{
				// CRIANDO VALORES PARA DIVISÃO COM AS ENTRADAS
				div = 0;
				for (y = 0; y < 3; y++)
				{
					div += pow(ent[x][y], 2);
				}

				// ATUALIZANDO OS PESOS
				for (y = 0; y < 3; y++)
				{
					W[x][y] += ((alfa * E[x]) / div) * ent[x][y];
				}
			}

			cout << "Erro Calculado: " << E[x] << endl;
			cout << "Saida intermediaria: " << S[x] << endl;
			cout << "Pesos: ";
			for (y = 0; y < 3; y++)
			{
				cout << W[x][y] << "\t";
			}
			cout << endl;
		}

		// PASSANDO NO RELÉ
		for (x = 0; x < 4; x++)
		{
			Y[x] = S[x] >= 0 ? 1 : -1;
			if (E[x] < tol)
			{
				ite_count = ite;
			}
			else
			{
				ite_count++;
			}

			cout << endl
				 << ite_count << endl;
		}
	}

	setlocale(LC_ALL, "Portugues");
	return 0;
}
