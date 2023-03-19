#include <iostream>
//#include <fstream>

//std::ifstream fin("text.in");


int main()
{
	int drumuri, noduri, i, j, nodfin;
	std::string cuv, lit, matrice[20][20];
	std::string var;
	char c;
	bool ok;
	std::cout << "cuvantul pe care vrem sa il verificam: ";
	std::cin >> cuv;
	std::cout << "nr de drumuri: ";
	std::cin >> drumuri;
	std::cout << "nr de noduri: ";
	std::cin >> noduri;
	std::cout << "nodul final: ";
	std::cin >> nodfin;

	
	for (i = 0;i < noduri;i++)
		for (j = 0;j < noduri;j++)
			matrice[i][j] = '0';
	

	std::cout << "nod initial, nod final, litera:"<<std::endl;
	for (int k = 0;k < drumuri;k++)
	{
		std::cin >> i >> j >> lit;
		matrice[i][j] = lit;
	}

	for (i = 0;i < noduri;i++)
	{
		for (j = 0;j < noduri;j++)
			std::cout << matrice[i][j] << " ";
		std::cout << std::endl;
	}
	
	ok = false;
	
	for (int k = 0;k < noduri;k++)
	{
		//var.assign(1, cuv[0]);
		c = cuv[0];
		std::string var = std::string(1, cuv[0]);
		
		if (var.compare(matrice[0][k][0]) != 0)
		{
			cuv == matrice[0][j];
			ok = true;
			i = 0;
			j = k;
			break;
		}
	}

	if (!ok)
		std::cout << "cuvantul nu e acceptat :(( ";
	else
	{
		ok = false;
		for (int k = 1;k < cuv.length();k++)
		{
			if (k == cuv.length()-1 && j == nodfin)
				ok = true;

			for (int n = 0;n < noduri;n++)
			{
				if(matrice[j][n].compare(cuv[i])  
			}


		}
	}

	return 0;
}