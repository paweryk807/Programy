#include <iostream>
#include <fstream>
using namespace std;

void planszaDrukuj(int** tab)
{
	
	for (int i = 0; i <= 5; i++)
	{
		if(i == 1)	cout << " -------------------------------" << endl;
		
		for (int k = 0; k <= 5; k++)
		{
			if (k == 1) cout << " | ";
			cout << " | " << tab[i][k];
			if (k == 4) cout << " | ";
			
		}
		cout << " | " << endl;
		
		if(i == 4) cout << " -------------------------------" << endl;
	}
	
}

int main()
{
	int **tab = new int *[6];
	fstream plik("data.txt");
	
	for (int i = 0; i < 6; i++)
	{
		tab[i] = new int[6];
	}

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
			if(tab[k][j]>maxV)
			{
				maxV = tab[k][j];
				tab[0][j]++;
			}
		}
	}	
	for (int j = 1; j < 5; j++)
	{
		int maxH = -1;
		int maxV = -1;
		for (int k = 4; k >= 1; k--)
		{
			if(tab[j][k]>maxH)
			{
				maxH = tab[j][k];
				tab[j][5]++;
			}
			if(tab[k][j]>maxV)
			{
				maxV = tab[k][j];
				tab[5][j]++;
			}
		}
	}	
	planszaDrukuj(tab);
	return 0;
}