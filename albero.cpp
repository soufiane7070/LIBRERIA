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
#include "Nodo.h"
using namespace std;


int main(){
  srand(time(NULL));
  nodo radice(5);
  nodo *punt{&radice};
  for(int i=0;i<10;i++){
    int g;
    g=rand()%23+2;
    radice.inser(punt,g);
  }
  radice.print(punt);
}