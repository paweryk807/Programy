#include <iostream>
#include <fstream>
using namespace std;

void planszaDrukuj(int **tab)
{
	for (int i = 0; i <= 5; i++)
	{
		cout << " --------------------------" <<endl;
		for (int k = 0; k <= 5; k++)
			cout << " | " << tab[i][k];
		cout << " | " << endl << " --------------------------" << endl;;
	}
}
void tabAlocate(int **tab)
{
	for (int i = 0; i < 6; i++)
	{	
			tab[i] = new int [6];
	}
}

int main()
{
	int **tab = new int *[6];
	fstream plik("data.txt");

	tabAlocate(*&tab);
	for(int i=0;i<6;i+=5)
	{
		for(int j=0;j<=5;j++)
		{
			tab[i][j] = 0;
			tab[j][i] = 0;
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int k = 1; k <= 4; k++)
		{
			plik >> tab[i][k];
		}
	}
	for(int i=0;i<7;i+=5) //<--------------------------------------
	{
		for (int j = 1; j < 5; j++)
		{
			int maxH = -1;
			int maxV = -1;
			for (int k = 1; k <= 4; k++)
			{
				if(tab[j][k]>maxH)
				{
					maxH = tab[j][k];
					tab[j][0]++;
				}
				if(tab[k][j]<maxV)
				{
					maxV = tab[k][j];
					tab[0][j]++;
				}
			}
		}	
	}
	planszaDrukuj(tab);
	
}
