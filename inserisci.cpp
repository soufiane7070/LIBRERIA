#include "Nodo.h"
using namespace std;


void  nodo:: inser(nodo*& radice, int valu) {
	if (radice == nullptr) {
        radice = new nodo(valu); 
     //   cout << "si1" << endl;
        return;
    }
               // cout<<"si2"<<endl;

	nodo* genit;
	nodo* corr;
	genit = nullptr;
	corr = radice;
               // cout<<"si3"<<endl;

	while (true) {
		genit = corr;
		if (valu < corr->val) {
			corr = corr->fs;
			if (corr == nullptr) {
				genit->fs = new nodo(valu);
                    //        cout<<"si4"<<endl;

				return;
			}
		}
		else corr = corr->fd;
		if (corr == nullptr) {
			genit->fd = new nodo(valu);
           // cout<<"si5"<<endl;
            return;

		}
	}
}
