#pragma once
#include <vector>
#include <iostream>
#include "Noeud.h"

class Graphe {
	std::vector<std::vector<int>> a;
	
	std::vector<Noeud> Noeuds;

public : 

		void CreerGraphe() {
			int Array[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
					{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
					{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
					{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
					{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
					{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
					{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
					{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
					{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

			for (int i = 0; i < 9; i++) {
				this->AjouterNoeud();
			}
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					this->LierNoeuds(i, j, Array[i][j]);
			SupprimmerNoeud(0);
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
	}

	void AfficherNoeud(int A) {
		for (int i = 0; i < a[A].size(); i++)
		{
			std::cout << a[A][i]<<",";
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