#include <iostream>
#include <fstream>

std::ifstream fin("text.in");

class drum
{
	int nodin;
	int nodout;
	char litera;

public:
	friend std::istream& operator>>(std::istream&, drum&);

	int getnodin() const
	{
		return nodin;
	}
	int getnodout() const
	{
		return nodout;
	}
	char getlit() const
	{
		return litera;
	}

};

std::istream& operator>>(std::istream& in, drum& d)
{
	in >> d.nodin >> d.nodout >> d.litera;
	return in;
}


int main()
{
	int drumuri, nin, nout, nodfin[10], nodinit, nr;
	std::string cuv;
	drum lista[20];
	bool ok;
	//std::cout << "nr de drumuri: ";
	fin >> drumuri;
	//std::cout << "nodul initial: ";
	fin >> nodinit;
	//std::cout << "nr de noduri finale: ";
	fin >> nr;
	//std::cout << "nodirile: ";
	for (int i = 0;i < nr;i++)
	{
		fin >> nodfin[i];
	}

	//std::cout << "nod initial, nod final, litera:"<<std::endl;
	for (int k = 0;k < drumuri;k++)
	{
		fin >> lista[k];
	}

	//std::cout << "cuvantul pe care vrem sa il verificam: ";
	fin >> cuv;

	if (cuv.length() == 0)
	{
		for (int i = 0;i < nr;i++)
		{
			if (nodinit == nodfin[i])
				std::cout << "cuvantul vid e acceptat :) ";
		}
	}
	else
	{
		ok = false;

		for (int k = 0;k < drumuri;k++)
		{
			if (lista[k].getnodin() == nodinit && cuv[0] == lista[k].getlit())
			{
				ok = true;
				nout = lista[k].getnodout();
				break;
			}
		}

		if (!ok)
			std::cout << "cuvantul nu e acceptat (din prima) :( ";
		else
		{
			for (int k = 1;k < cuv.length();k++)
			{
				ok = false;
				for (int n = 0;n < drumuri;n++)
				{
					if (nout == lista[n].getnodin() && cuv[k] == lista[n].getlit())
					{
						nout = lista[n].getnodout();
						break;
					}
				}
				for (int i = 0;i < nr;i++)
				{
					if (k == cuv.length() - 1 && nout == nodfin[i])
					{
						ok = true;
						break;
					}
				}
			}

			if (ok)
				std::cout << "cuvantul e acceptat :) ";
			else
				std::cout << "cuvantul nu e acceptat :( ";
		}
	}
	
	return 0;
}