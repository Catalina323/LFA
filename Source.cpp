#include <iostream>
#include <cstring>
//#include <fstream>

//std::ifstream fin("text.in");

class drum
{
	int nodin;
	int nodout;
	char litera;

public:
	friend std::istream& operator>>(std::istream&, drum&);

	int getnodin()
	{
		return nodin;
	}
	int getnodout()
	{
		return nodout;
	}
	char getlit()
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
	int drumuri, nin, nout, nodfin;
	std::string cuv;
	drum lista[20];
	bool ok;
	std::cout << "cuvantul pe care vrem sa il verificam: ";
	std::cin >> cuv;
	std::cout << "nr de drumuri: ";
	std::cin >> drumuri;
	std::cout << "nodul final: ";
	std::cin >> nodfin;

	std::cout << "nod initial, nod final, litera:"<<std::endl;
	for (int k = 0;k < drumuri;k++)
	{
		std::cin >> lista[k];
	}
	//std::cout << cuv.length() << std::endl;

	ok = false;
	
	for (int k = 0;k < drumuri;k++)
	{
		if (lista[k].getnodin()==0 && cuv[0] == lista[k].getlit())
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
					//std::cout << "am parcurs litera: " << lista[n].getlit()<<std::endl;
					//std::cout << "nod final curent: " << lista[n].getnodout() << std::endl;
					//std::cout << "k=" << k << std::endl;
					nout = lista[n].getnodout();
					break;
				}
			}

			if (k == cuv.length() - 1 && nout == nodfin)
			{
				ok = true;
				break;
			}

		}


		if (ok)
			std::cout << "cuvantul e acceptat :) ";
		else
			std::cout << "cuvantul nu e acceptat :( ";
	}
	


	return 0;
}