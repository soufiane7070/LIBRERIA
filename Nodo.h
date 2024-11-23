#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;
/// modifiche in corso della classe: funzioni gia modificate: inserisci;
class nodo{
    int val;
	nodo* fd;
	nodo* fs;
    int weight;
    public:

    nodo(int val1);
  nodo(int val1,int val2);

void inser(nodo*& radice, int valu);

void print(nodo* radice) {
    if (radice == nullptr) {
        return; 
    }
    
    print(radice->fs);
    
    cout << radice->val << " ";
    
    print(radice->fd);
}
nodo* trova(nodo* radice, int valu) {
    if (radice == nullptr) {
        return nullptr; 
    }
    if (radice->val == valu) {
		cout<<"trovato"<<endl;
        return radice;
    }

    nodo* risultato = trova(radice->fs, valu);
    if (risultato != nullptr) {
		
        return risultato;
    }
    
    return trova(radice->fd, valu);
}


void del(nodo*& radice, int valu) {
    nodo* genit;
    nodo* corr;
    genit = nullptr;
    corr = trova(radice, valu);

    while (true) {
        if (corr == nullptr) {
            return;
        }
        
        genit = corr;
        if (corr->val == valu) {
            if (corr->fd == nullptr && corr->fs == nullptr) {
                delete corr;
                corr = nullptr;
                return;
            } else if (corr->fs != nullptr && corr->fd == nullptr) {
                nodo* temp = corr->fs;
                delete corr;
                corr = temp;
                return;
            } else if (corr->fd != nullptr && corr->fs == nullptr) {
                nodo* temp = corr->fd;
                delete corr;
                corr = temp;
                return;
            } else {
                nodo* successore = corr->fd;
                while (successore->fs != nullptr) {
                    successore = successore->fs;
                }
                corr->val = successore->val;
                del(corr->fd, successore->val);
                return;
            }
        }
        break;
    }
}




int alt(nodo* radice,int &cont) {
    if (!radice) {
        return -1; 
    }

    int alts = alt(radice->fs,cont);
    int altd = alt(radice->fd,cont);

    if (alts > altd) {
		cont++;
        return alts + 1; 
    } else {
		cont++;
        return altd + 1; 
    }
}

bool ver(nodo* root, int min, int max) {
    if (!root) {
        return true; 
    }

    if (root->val <= min) {
        return false; 
    }

    if (root->val >= max) {
        return false; 
    }

    return ver(root->fs, min, root->val) && ver(root->fd, root->val, max);
}


};