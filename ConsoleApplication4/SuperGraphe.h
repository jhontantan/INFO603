#pragma once

#include <vector>

class SuperGraphe
{
	public:
		virtual void CreerGraphe() = 0;

		virtual void AjouterNoeud() = 0;

		virtual void LierNoeuds(int A, int B, int dist) = 0;

		virtual void ModifDistance(int A, int B, int dist) = 0;

		virtual void SupprimerRelation(int A, int B) = 0;

		virtual void SupprimmerNoeud(int A) = 0;

		virtual void AfficherGraph() = 0;

		virtual void AfficherNoeud(int A) = 0;
	
		virtual int taille() = 0;

		virtual int distance(int A, int B) = 0;

		virtual bool estVide() = 0;

		virtual std::vector<int> Voisin(int A) = 0;
};

