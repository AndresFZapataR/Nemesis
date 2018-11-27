#ifdef _HuffmanCode_hpp_

#include<iostream>
#include<vector>
#include <map>

using namespace std;

Tree* huffman(vector<Tree*> & vector){
	if(vector.size() == 1){
		return vector[0];
	}
	else{
		Tree *t1 = new Tree;
		t1->insert(vector[0]);
		vector.erase(vector.begin());
		Tree *t2 = new Tree;
		t2->insert(vector[0]);
		vector.erase(vector.begin());
		Tree *t = new Tree;
		t->insert(t1, t2);
		vector.push_back(t);
		BubbleSort(vector);
		huffman(vector);
		return vector[0];
	}
}

void compress(Tree *t,string  str, map<char, string> & m){
	if(t->c != 00){
		m[t->c] = str;
	}
	else{
		compress(t->left, str + "0", m);
		compress(t->right, str + "1", m);
	}
}

void Tree::display(Tree *t){
	if(t->right == nullptr && t->left == nullptr){
    if(t->c == 00){
      cout<<"Caracter: NULL"<<'\t'<<"Frecuencia: "<<t->frec<<'\n';
    }else if(t->c == '\n'){
      cout<<"Caracter: /n "<<'\t'<<"Frecuencia: "<<t->frec<<'\n';
    }else{
      cout<<"Caracter: "<<t->c<<'\t'<<"Frecuencia: "<<t->frec<<'\n';
    }
	}else{
		display(t->left);
    if(t->c == 00){
      cout<<"Caracter: NULL"<<'\t'<<"Frecuencia: "<<t->frec<<'\n';
    }else if(t->c == '\n'){
      cout<<"Caracter: /n "<<'\t'<<"Frecuencia: "<<t->frec<<'\n';
    }else{
      cout<<"Caracter: "<<t->c<<'\t'<<"Frecuencia: "<<t->frec<<'\n';
    }
		display(t->right);
	}
}

void Tree::insert(Tree *t1){
	c = t1->c;
	frec = t1->frec;
	left = t1->left;
	right = t1->right;
}

void Tree::insert(Tree *t1, Tree *t2){
	c = 00;
	frec = t1->frec + t2->frec;
	left = t1;
	right = t2;
}

void BubbleSort(vector<Tree*> & vec){
	for(size_t i = 0; i<vec.size()-1; i++){
		for(size_t j = 0; j < vec.size()-i-1;j++){
			if(vec[j]->frec > vec[j+1]->frec){
				swap(vec[j], vec[j+1]);
			}
		}
	}
}

#endif /* _HuffmanCode_hpp_ */
