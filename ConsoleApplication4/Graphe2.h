#pragma once
#include "Graphe.h"
class Graphe2
{
	public :
	std::vector<Noeud> a;

	void CreerGraphe() {


		int Array[9][9] = { { 0, 14, 0, 0, 0, 0, 0, 18, 0 },
				{ 14, 0, 18, 0, 0, 0, 0, 21, 0 },
				{ 0, 18, 0, 17, 0, 14, 0, 0, 12 },
				{ 0, 0, 17, 0, 19, 24, 0, 0, 0 },
				{ 0, 0, 0, 19, 0, 20, 0, 0, 0 }, /////////////////////////////////////
				{ 0, 0, 14, 24, 20, 0, 12, 0, 0 },
				{ 0, 0, 0, 0, 0, 12, 0, 11, 16 },
				{ 18, 21, 0, 0, 0, 0, 11, 0, 17 },
				{ 0, 0, 12, 0, 0, 0, 16, 17, 0 } };

		for (int i = 0; i < 9; i++) {
			this->AjouterNoeud();
		}
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
					if(i > j)
						this->LierNoeuds(i, j, Array[i][j] );
		//SupprimmerNoeud(8);
	}

	void AjouterNoeud() {
		Noeud z = Noeud();
		a.push_back(z);


	}

	void LierNoeuds(int A, int B, int dist) {
		a[A].LierNoeud(&a[B],dist);
	}

	void ModifDistance(int A, int B, int dist) {
		LierNoeuds(A, B, dist);
	}

	void SupprimerRelation(int A, int B) {
		LierNoeuds(A, B, 0);
	}

	void SupprimmerNoeud(int A) {
		for (int i = 0; i < a.size(); i++)
		{
			SupprimerRelation(i, A);
			a.at(i).updateVoisin(A);
		}
		a.erase(a.begin()+A);
	}

	void AfficherGraph() {
		for (int i = 0; i < a.size(); i++)
		{
			AfficherNoeud(i);
		}
	}

	void AfficherNoeud(int A) {
		for (int i = 0; i < a.size(); i++)
		{
			std::cout << distance(A, i);
				if (distance(A, i) < 10)
					std::cout << " ";
			std::cout  <<",";
		}
		std::cout << "\n";
	};

	int taille() {
		return a.size();
	};

	int distance(int A, int B) {
		return a[A].Distance(a[B]);
	}

	bool estVide() {
		return a.size() == 0;
	}

	/*std::vector<int> Voisin(int A) {
		return a[A];
	}*/

};

