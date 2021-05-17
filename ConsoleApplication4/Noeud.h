#pragma once
#include "Arc.h"
#include <vector>

class Noeud
{



public:
	int id;
	std::vector<Arc> voisin;
	static int count;

	Noeud();

	int Distance(Noeud* N,bool test = false);
		
	void updateVoisin(int start);

	int LierNoeud(Noeud* N, int dist,bool pass = 0);

	int RemoveNoeud(Noeud* N, int dist, bool pass);
};