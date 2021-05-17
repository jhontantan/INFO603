#pragma once
#include <vector>
#include <iostream>
#include "Noeud.h"
#include "SuperGraphe.h"

class Graphe : public SuperGraphe{
	std::vector<std::vector<int>> a;

public : 


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
				if (i > j)
					this->LierNoeuds(i, j, Array[i][j]);
	}

	void AjouterNoeud() {
		a.push_back(std::vector<int>(a.size()));
		for (int i = 0; i < a.size(); i++)
			a[i].push_back(0);
		
	}

	void LierNoeuds(int A, int B,int dist) {
		a[A][B] = dist;
		a[B][A] = dist;
	}

	void ModifDistance(int A, int B, int dist) {
		LierNoeuds(A, B, dist);
	}

	void SupprimerRelation(int A, int B) {
		LierNoeuds(A,B,0);
	}

	void SupprimmerNoeud(int A) {
		a.erase(a.begin()+A);
		for (int i = 0; i < a.size(); i++)
			a[i].erase(a[i].begin()+A);
	}

	void AfficherGraph() {
		for (int i = 0; i < a.size(); i++)
		{
			AfficherNoeud(i);
		}
		std::cout << "\n";
	}


	void AfficherNoeud(int A) {
		for (int i = 0; i < a.size(); i++)
		{
			std::cout << distance(A, i);
			if (distance(A, i) < 10)
				std::cout << " ";
			std::cout << ",";
		}
		std::cout << "\n";
	};

	int taille() {
		return a.size();
	};

	int distance(int A,int B) {
		return a[A][B];
	}

	bool estVide() {
		return a.size() == 0;
	}

	std::vector<int> Voisin(int A) {
		return a[A];
	}
};