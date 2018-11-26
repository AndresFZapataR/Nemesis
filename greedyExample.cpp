#include<iostream>
#include<vector>

using namespace std;

bool palitos(vector<size_t> pal, size_t size);
size_t select(vector<size_t> pal, size_t size);

int main(){
	vector<size_t> arr = {7,5,3};
	cout<<"Tenemos baras de este tamaño: "<<endl;
	for(size_t i = 0; i < arr.size(); i++){
		cout<<">"<< arr[i]<<endl;
	}
	size_t tam = 15;
	cout<<"Queremos armar una bara de tamaño "<<tam<<" apartir de las anteriores:"<<endl;
	bool res = palitos(arr, tam);
	if(res){
		cout<<"Si se puede armar!"<<endl;
	}else{
		cout<<"No se puede armar"<<endl;
	}
	return 0;
}

bool palitos(vector<size_t> pal,size_t size){
	size_t sel = select(pal,size);
	if(sel == 0){
		cout<<"No tenemos una bara de ese tamaño"<<endl;
		return false;
	}
	if(sel == size){
		return true;
	}else{
		cout<<"Hace falta "<< size - sel<<endl;
		return palitos(pal, size - sel);
	}
}

size_t select(vector<size_t> pal, size_t size){
	for(size_t i = 0; i < pal.size(); i++){
		if(pal[i] <= size){
			cout<<"Usamos una bara de tamaño: "<<pal[i]<<endl;
			return pal[i];
		}
	}
	return 0;
}
