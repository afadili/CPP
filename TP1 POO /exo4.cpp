#include <iostream>
#include <vector>

using namespace std;


int maxValue(int *tab, int taille);


int main(int argc, char const *argv[])
{
	int n;
	cout << "Entrer la taille du tableau :" << endl;
	cin >> n;	
	int *tab = new int[n];
	cout << "Entrer les valeurs du tableau :" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> tab[i];
	}
	for (int j=0; j<n; j++){ cout << tab[j]; }
	cout << endl;
	cout << "Adresse des 3 premiers elements : " << endl;
	for (int k=0; k<3; k++){ cout << &(tab[k]) << "size :"<< sizeof(tab[k]); cout << endl;}
	cout << "Premier élement : " << *tab << endl;
	cout << "Cinquième élement : " << *(tab+4) << endl;
	cout << "Max du tableau : " << maxValue(tab,n) << endl;
	delete(tab);
	return 0;
}

int maxValue(int *tab, int taille)
{
	int max = 0;
	for (int i=0; i<taille; i++)
	{
		if (tab[i] > max)
		{
			max = tab[i];
		}
	}
	return max;
}