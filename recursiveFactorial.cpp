#include<iostream>
#include<map>
#include<ctime>
#include<vector>
#include<fstream>
using namespace std;

int recursive (int n){
	if (n==1 or n==2){
		return 1;
	}
	else{
		return recursive(n-1)+recursive(n-2);
	}

}

int memoize(int n, std::map<int, int> & myMap){
	std::map<int, int>::iterator it = myMap.find(n);
	if(it!=myMap.end()){
		return myMap[n]; 	
	}
	if (n==1 or n==2){
		return 1;
	}
	else{
		int result =  memoize(n-1, myMap)+memoize(n-2, myMap);
		myMap[n] = result;
	}

}
int main(){
	unsigned t0, t1;
	map<int, double> rcs;
	map<int, double> mmo;
	std::map<int,int>memo;
	for (int i = 1; i<=50;i++){
		t0 = clock();
		cout<<recursive(i)<<endl;
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<"Execution Time of Recursive Fibonacci with"<<i<<" is: "<<time<<endl;
		rcs[i]=time;
		t0 = clock();
		cout<<memoize(i, memo)<<endl;
		t1 = clock();
		double timeMemo = (double(t1-t0)/CLOCKS_PER_SEC);
		cout<<"Execution Time of Memoize solution: "<<i<<" is: "<<timeMemo<<endl;
		mmo[i]=timeMemo;
	}
	ofstream result;
	result.open("resultados.txt");
	result<<"Recursiva			Memoize\n";
	std::map<int, double>::iterator it1 = mmo.begin();
	for(std::map<int, double>::iterator it =rcs.begin(); it!=rcs.end(); it++){
		result<<it->first<<"	"<<it->second<<"		"<<"	"<<it1->second<<endl;
		it1++;
	} 
	
	result.close();
	return 0;
}
