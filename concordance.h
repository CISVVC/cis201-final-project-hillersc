/*
File: concordance.h
Description: interface for concordance.cpp 
Author: Colby Hillers
Email: hillersc144964@student.vvc.edu
Date: 12/16/18
*/

#ifndef CONCORDANCE_H
#define CONCORDANCE_H
#include "word.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Concordance
{
public:
    Concordance(std::string filename);
    void parse();
    void new_word(std::string word, int line);
    bool is_whitespace(char c);
    bool is_punct(char c);
    void eat_whitespace(std::ifstream &input);
    void eat_punct(std::ifstream &input);
    std::string next_word(std::ifstream &input);
    void print();
private:
    std::vector<Word> m_word_stats;
    std::string m_filename;
    int m_line;
};

#endif
