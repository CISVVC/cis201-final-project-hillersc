/*
File: word.h
Description: interface file for word.cpp
Author: Colby Hillers
Email: hillersc144964@student.vvc.edu
Date: 12/16/18
*/

#ifndef WORD_H
#define WORD_H
#include <iostream>
#include<vector>
#include<string>

class Word
{
public:
   Word(std::string  word);
   void add_line(int line);
   void add_count(int count);
   void print() const;
   std::string get_word() const;
private:
   int m_count;
   std::string m_word;
   std::vector<int> m_line;
};

#endif

