#include<iostream>

#include<vector>


using namespace std;



bool palitos(vector<size_t> pal, size_t size);

size_t select(vector<size_t> pal, size_t size);



int main(){

	vector<size_t> arr = {7,5,3,2,1};

	cout<<palitos(arr,16)<<endl;

	return 0;

}



bool palitos(vector<size_t> pal,size_t size){

	if(select(pal,size) == 0){

		return false;

	}

	if(select(pal,size) == size){

		return true;

	}else{

		return palitos(pal, size - select(pal,size));

	}



size_t select(vector<size_t> pal, size_t size){

	for(size_t i = 0; i < pal.size(); i++){

		if(pal[i] <= size){

			return pal[i];

		}

	}

	return 0;
}
