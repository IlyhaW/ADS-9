// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <cctype>
#include <string>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  BST<std::string> str;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error." << std::endl;
    return str;
  }
  std::string word = "";
  while (!file.eof()) {
    int ch = tolower(file.get());
    if ((ch > 96 && ch < 123)) {
      word += ch;
    } else {
      if (word != "")
        str.addPiece(word);
      word = "";
    }
    if (ch == ' ') {
      str.addPiece(word);
      word = "";
    }
  }
  file.close();
  return str;
}
