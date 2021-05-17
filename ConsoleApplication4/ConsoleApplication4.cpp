// ConsoleApplication4.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <cassert>
#include "Dijkstra.h"

/*Fonctions test Exercice 1*/

bool inferieur(int debut, int fin, int* t, int pivot) {
    for (int i = debut; i < fin; i++)
        if (t[i] >= t[pivot])
            return false;
    return true;
}

bool supperieur(int debut, int fin, int* t, int pivot) {
    for (int i = debut; i < fin; i++)
        if (t[i] <= t[pivot])
            return false;
    return true;
}

bool infOuEgale(int debut, int fin, int* t, int pivot) {
    for (int i = debut; i < fin; i++)
        if (t[i] > t[pivot])
            return false;
    return true;
}

bool supOuEgale(int debut, int fin, int* t, int pivot) {
    for (int i = debut; i < fin; i++)
        if (t[i] < t[pivot])
            return false;
    return true;
}

bool between(int a, int i, int j) {
    return(a >= i && a <= j);
}

/**/

void permuter(int* a,int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* median(int* debut,int* fin,int* milieu) {
    return milieu;
}

int /*return k*/partition(int* t,int i,int j) {
    int k, l;
    permuter(&t[i],median(&t[i],&t[j],&t[(i+j)/2]));
    l = i + 1; k = j;
    while (l <= k) {
        while (t[k] > t[i] && l <= k) {
            k--;
            assert(supperieur(k+1, j, t, i));
        }
        while (t[l] <= t[i] && l <= k) {
            l++;
            assert(infOuEgale(i + 1, l-1, t, i));
        }
        if (l < k) {
            permuter(&t[l],&t[k]);
            l++; k--;
            assert(between(l,i,j));
            assert(between(k,i,j));
        }
        assert(infOuEgale(i + 1, l-1, t, i) && supperieur(k+1, j, t,i));
    }
    assert(infOuEgale(i + 1, k + 1, t,i) && supperieur(k + 1, j, t,i));
    permuter(&t[i],&t[k]);
    assert(infOuEgale(i, k, t,k) && supOuEgale(k, j, t,k));
    return k;
}
/* fonctions test exercice 1*/
void testRandEx1(int s) {
    int a = (int)time(NULL);
    a += s;
    std::cout << "seed :" << a;
    srand(a);
    int t[25];
    int j = 3 + rand() % 22;
    int i = rand() % (j - 2);
    for (int i = 0; i < 24; i++)
        t[i] = rand() % 255;

    partition(t, i, j);

    std::cout << "\nFIN RAND success\n";
}

void testNRandEx1(int seed) {
    std::cout << "seed :" << seed;
    srand(seed);
    int t[25];
    int j = 3 + rand() % 22;
    int i = rand() % (j - 2);
    for (int i = 0; i < 24; i++)
        t[i] = rand() % 255;

    partition(t, i, j);

    std::cout << "\nFIN NOT RAND\n";
}
/**/

// asserts exercice 2

int tabTrie(int* tab, int deb, int fin) {
    for (int i = deb; i < fin; i++) {
        if (tab[i] > tab[i + 1])
            return 0;
    }
    return 1;
}

int estMaximum(int max,int* tab,int deb,int fin) {
    for (int i = deb; i <= fin; i++) {
        if (max < tab[i]) 
            return 0;
    }
    return 1;
}

int estMinimum(int min, int* tab, int deb, int fin) {
    for (int i = deb; i <= fin; i++) {
        if (min > tab[i])
            return 0;
    }
    return 1;
}
// tests exercice 2

void triBoustroCorrige(int* tab, int taille);

/*fonctions exercice 2*/
void triBoustro(int* t, int deb, int fin) {
    triBoustroCorrige(t,fin);
    return;
    int taille = fin;
    for (int i = 0; i < taille; i++) {
        int posN = taille - i;
        int posP = i;
        for (int j = posP; j < posN; j++) {
            if (t[j] < t[j + 1]) {
                permuter(&t[j], &t[j + 1]);
            }
            if (t[posN - j] > t[posN - j - 1])
            {
                permuter(&t[posN - j], &t[posN - j - 1]);
            }
        }

    }
}

void triBoustroCorrige(int* tab, int taille) {

    int deb = 0;
    int fin = taille-1;

    for (int j = 0; j < (taille / 2); j++) {
        for (int i = 1; i < fin-j; i++)
            if (tab[i] < tab[i - 1]){
                permuter(&tab[i], &tab[i - 1]);
               assert(estMaximum(tab[i], tab, 0, i-1));//(1)
            }
        assert(tabTrie(tab, fin - j, fin));//(2)
        for (int i = fin-j-1; i > j; i--)
            if (tab[i] > tab[i + 1]) {
                permuter(&tab[i], &tab[i + 1]);
                assert(estMinimum(tab[i], tab, i+1, fin));//(3)
            }
        assert(tabTrie(tab, 0, j));//(4)
        assert(tabTrie(tab, fin - j, fin) && tabTrie(tab, 0, j));//(5)
    }
    assert(tabTrie(tab, 0, fin));//(6)
}



void testRandEx2(int s) {
    int a = (int)time(NULL);
    a += s;
    std::cout << "seed :" << a;
    srand(a);
    int t[25];
    for (int i = 0; i < 25; i++)
        t[i] = rand() % 255;

    triBoustro(t, 0, 25);
    assert(tabTrie(t,0,24));
    std::cout << "\nFIN RAND success\n";
}

int main()
{
    // exercice 1
  for (int i = 0; i < 200; i++)
        testRandEx1(i);
   /* testNRandEx1(1617805099);*/
   
   // exercice 2 
   for (int i = 0; i < 200; i++)
	   testRandEx2(i);

   mainDijkstra();

    std::cout << "\nFIN\n";
    return EXIT_SUCCESS;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
