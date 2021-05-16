#include "Noeud.h"
#include "Arc.h"

    int Noeud::count = 0;
	
	Noeud::Noeud() {
		voisin = std::vector<Arc>();
		id = count;
		count++;
	}

	void Noeud::updateVoisin(int start) {
		for (int i = 0; i < this->voisin.size(); i++) {
			if (i > start) // si voisin est au dessus du depart on le decremente
				//this->voisin[i].idNoeud--;
			if (i == start) {
				this->voisin.erase(voisin.begin() + i);
				i--;
			}
		}
	}

	int Noeud::Distance(Noeud N) {
		for (int i = 0; i < voisin.size(); i++)
			if (voisin[i].idNoeud == N.id)
				return voisin[i].distance;
		return 0;
	}

	int Noeud::LierNoeud(Noeud* N, int dist,bool pass) {
		if (dist == -1)
			for (int i = 0; i < voisin.size(); i++) {
				if (voisin[i].idNoeud == N->id) {
					voisin.erase(voisin.begin() + i);//.distance = dist;
					pass = true;
					//voisin.clear();
				}
			}
		if(pass) return 0;
		this->voisin.push_back(Arc(N->id, dist));
		N->voisin.push_back(Arc(this->id, dist));
		return 1;
	}
	/*
	int Noeud::RemoveNoeud(Noeud* N, int dist, bool pass) {
		if (dist == 0)return 0;

		this->voisin.(Arc(N, dist));
		N->voisin.push_back(Arc(this, dist));
		return 1;
	}*/
