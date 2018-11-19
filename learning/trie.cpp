#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
//Aprendiendo tries :)
//Basado en http://www.geeksforgeeks.org/trie-insert-and-search/
using namespace std;

const int ALPH_SIZE = 26;

struct node {
  node* children[ALPH_SIZE];
  bool isEnd;
  
  node() : isEnd(false) {
    for(int i=0; i < ALPH_SIZE; ++i)
      children[i] = NULL;
  }

  void insert(const string& word){
    node* traveler = this;

    for(int i = 0; i < word.length(); ++i){
      int index =  word[i] - 'a';
      
      if(!traveler->children[index])
	traveler->children[index] = new node();
      
      traveler = traveler->children[index];      
    }

    traveler->isEnd = true;  
  }

  bool contains(const string& word){
    node* traveler = this;

    for(int i = 0; i < word.length(); ++i){
      int index = word[i] - 'a';

      traveler = traveler->children[index];
    }

    return traveler != NULL && traveler->isEnd;
  }

  void autocomplete(const string& word){
    node* last = this;

    for(int i=0; i<word.length() && last != NULL; ++i){
      int idx = word[i] - 'a';
      last = last->children[idx];
    }
    
    if(last != NULL)
      autocomplete(word, last);
  }
  
  void autocomplete(const string& word, const node* curr){
    if(curr->isEnd){
      cout << word << endl;
    }

    for(int i=0; i<ALPH_SIZE; ++i){
      if(curr->children[i] != NULL)
	autocomplete(word + static_cast<char>(i + 'a'), curr->children[i]);
    }    
  }
};

int main(int argc, char** argv){
  string word;
  node root;
  
  if(argc > 1){
    ifstream file(argv[1]);
    
    while(file >> word){
      root.insert(word);
    }
  }
  
  while(cin >> word){
    root.autocomplete(word);
  }
  
  return EXIT_SUCCESS;
}
