#include<iostream>

#include<utility>

#include<fstream>

#include<vector>


using namespace std;


struct Tree{

	pair<char, size_t> par;

	Tree *parent,  *left, *right;

};


vector<Tree> order(vector<Tree> & vec){

	for(size_t i = 1; i < vec.size(); i++){

    		Tree num = vec[i];

    		size_t j = i-1;

    	while (num.par.second < vec[j].par.second && j >= 0) {

      		vec[j+1] = vec[j];

      		j--;
 
   	}

    	swap(num, vec[j+1]);

  	}

	return vec;

}


Tree hulffman(vector<Tree> & myV){

	if(myV.size() ==1){

		return myV[0];

	}else{

		Tree *n = new Tree;

		n->parent = nullptr;

		Tree t1 = myV[0];

		Tree t2 = myV[1];

		n->left = &t1;

		n->right = &t2;

		n->right->parent = n->left->parent = n;

		n->par.second = n->right->par.second + n->left->par.second;

		n->par.first =00;

		myV.erase(myV.begin(),myV.begin()+1);

		auto it = myV.begin();

		while(n->par.second > it->par.second){

			it++;

		}

		myV.insert(it, *n);

		return hulffman(myV);
	}


}

int main(){

	vector<Tree> vector;

	char c;

	bool in = false;

	ifstream file;

	file.open("txt.txt");

	while (file.get(c)){

		for(size_t i = 0; i<vector.size();i++){

			if(c==(vector[i].par).first){

				vector[i].par.second++;

				in = true;

			}

		}

		if(!in){

			pair<char, int> p;

			p.first = c;

			p.second = 1;

			Tree *t = new Tree;

			t->par = p;
	
		t->left = t->right = t->parent = nullptr;

			vector.push_back(*t);

		}

		in = false;

	}


	vector = order(vector);
	for(size_t i =0;i<vector.size();i++){

		cout<<vector[i].par.first<<"		"<<vector[i].par.second<<endl;

	}


	hulffman(vector);

	file.close();

	return 0;

}
