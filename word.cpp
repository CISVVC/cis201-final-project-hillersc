/*
File: word.cpp
Description: implementation file for word.h
Author: Colby Hillers
Email: hillersc144964@student.vvc.edu
Date: 12/16/18
*/

#include "word.h"

Word::Word(std::string  word)
{
   m_word = word;
   m_count = 1;
}

void Word::add_count(int count)
{
   m_count++;
}

void Word::add_line(int line)
{
    m_line.push_back(line);
}

std::string Word::get_word() const
{
    return m_word;
}

void Word::print() const 
{
    std::cout << m_word << ": " << m_count << ": ";
    for (int i = 0; i < m_line.size(); ++i) 
    {
        std::cout << m_line[i] << ",";
    }
}
