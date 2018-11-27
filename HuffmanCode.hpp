#ifndef _HuffmanCode_hpp_
#define  _HuffmanCode_hpp_

#include<iostream>
#include<vector>
#include <map>

using namespace std;

struct Tree{
	char c;
	size_t frec;
	Tree *right, *left;

  /*
  * FUNTION insert:
  * INPUT: Tree*
  * OUTPUT: None
  * USAGE: insert(tree);
  */
	void insert(Tree *t);
  /*
  * FUNTION insert:
  * INPUT: Tree*
  * OUTPUT: None
  * USAGE: insert(tree, tree);
  */
	void insert(Tree *t1, Tree *t2);
  /*
  * FUNTION display:
  * INPUT: Tree*
  * OUTPUT: None
  * USAGE: display(tree);
  */
	void display(Tree *t);
};

/*
* FUNTION huffman:
* INPUT: std::vector<Tree*> v
* OUTPUT: Tree*
* USAGE: huffman(vector);
*/
Tree* huffman(vector<Tree*> & vector);

/*
* FUNTION BubbleSort:
* INPUT: std::vector<Tree*> v
* OUTPUT: None
* USAGE: BubbleSort(vector);
*/
void BubbleSort(vector<Tree*> & vec);

/*
* FUNTION huffman:
* INPUT: std::vector<Tree*> v
* OUTPUT: Tree*
* USAGE: huffman(vector);
*/
Tree* huffman(vector<Tree*> & vector);

/*
* FUNTION compress:
* INPUT: std::vector<Tree*> v , std::map<char,string> m
* OUTPUT: None
* USAGE: huffman(vector,"",map);
*/
void compress(Tree *t,string  str, map<char, string> & m);

#include "HuffmanTree.cpp"

#endif /* _HuffmanCode_hpp_ */
