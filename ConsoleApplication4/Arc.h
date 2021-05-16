#pragma once

class Noeud;

class Arc
{
	public :
		//Noeud* noeud;
		int idNoeud;
		int distance;

		Arc() {
		
		}

		Arc(int ID,int dist) {
			//noeud = N;
			idNoeud = ID;
			distance = dist;
		}

};

