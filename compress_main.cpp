#include<iostream>
#include<vector>
#include <map>
#include<fstream>
#include "HuffmanCode.hpp"

using namespace std;

int main(){
	vector<Tree*> vector;
	char c;
	bool in = false;
	ifstream file;
	file.open("txt.txt");
  cout<<"Generando histograma... "<<endl;
  std::vector<char> keys;
	while (file.get(c)){
		for(size_t i = 0; i<vector.size();i++){
			if(c == vector[i]->c){
				vector[i]->frec++;
				in = true;
			}
		}
		if(!in){
			Tree *t = new Tree;
      cout<<"Agregamos el caracter: "<<c<<'\n';
      keys.push_back(c);
			t->c = c;
			t->frec = 1;
			t->left = t->right = nullptr;
			vector.push_back(t);
		}
		in = false;
	}
  cout<< '\n';
	BubbleSort(vector);
  cout<<"Histograma ordenado: "<<'\n';
	for(size_t i = 0; i < vector.size(); i++){
    if(keys[i] == '\n'){
		    cout<<"Caracter: /n"<<'\t'<<"Frecuencia: "<<vector[i]->frec<<'\n';
    }else{
      cout<<"Caracter: "<<vector[i]->c<<'\t'<<"Frecuencia: "<<vector[i]->frec<<'\n';
    }
	}
  cout<<'\n';
	Tree *h = new Tree;
	h = huffman(vector);
  cout << "Huffman Tree: " << '\n';
	h->display(h);
  map<char, string> m;
	compress(h, "",m);
  cout<<'\n';
  cout << "Resultado: " << '\n';
	for (size_t i = 0; i < keys.size(); i++) {
    if(keys[i] == '\n'){
      cout <<"/n"<< " ---> " <<m[keys[i]]<< '\n';
    }else{
      cout <<keys[i]<< " ---> " <<m[keys[i]]<< '\n';
    }
  }
 return 0;
}
