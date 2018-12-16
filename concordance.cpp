/*
File: concordance.cpp
Description: implementation file for concordance.h, pasres through text file utilizing word objects
Author: Colby Hillers
Email: hillersc144964@student.vvc.edu
Date: 12/16/18
*/

#include "concordance.h"
#include <iostream>

// Constructor for concordance object
Concordance::Concordance(std::string filename)
{
    m_filename = filename;
    m_line = 1;
}

// function to parse for Alice.txt file
void Concordance::parse()
{
    // Open file stream
    std::ifstream file(m_filename.c_str());
    // Parse through file and take in data
    while(!file.eof())
    {
        std::string word = next_word(file);
        new_word(word, m_line);
    }
}

// Add word to m_word_stats vector
void Concordance::new_word(std::string word, int line)
{
    int index = -1;
    // Loop through vector containing words
    for(int i = 0; i < m_word_stats.size(); ++i)
    {
        // if the indexed word matches word, set equal to index
        if(m_word_stats[i].get_word() == word)
        {
            index = i;
            break;
        }
    }
    // if word not found
    if(index == -1)
    {
        Word ward(word);
        ward.add_line(line);
        m_word_stats.push_back(ward);
    } else { // if word is found
        m_word_stats[index].add_count(1);
        m_word_stats[index].add_line(line);
    }
}

// Test for whitespace
bool Concordance::is_whitespace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

// Test for punctuation
bool Concordance::is_punct(char c)
{
    return (c == '.' || c == ',' || c == '?' || c == '!' || c == '\'' || c== '\"' || c == ';' || c == ':' || c == ')' || c == '(');
}

// Remove whitespace
void Concordance::eat_whitespace(std::ifstream& input)
{
     for(;;)
    {
        char c;
        input.get(c);
        if(input.eof()) {
            break;
        }

        if(!is_whitespace(c))
        {
            input.putback(c); // this will put the character back on the input stream
            break;
        }
        if(c == '\n')
            m_line++;
    }
}

// Remove punctuation
void Concordance::eat_punct(std::ifstream &input)
{
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_punct(c))
        {
            input.putback(c);
            break;
        }
    }
}

// Check for next word
std::string Concordance::next_word(std::ifstream &input)
{
    std::string word;
    for(;;)
    {
        char c;
        input.get(c);
        if (input.eof()) 
        {
            break;
        }
        if(!is_whitespace(c) && !is_punct(c))
        {
            word += tolower(c);
        }
        else
        {
            eat_whitespace(input);
            break;
        }
    }
    return word;
}

// Print out words from m_word_stats vector
void Concordance::print()
{
    for (int i = 0; i < m_word_stats.size(); ++i) 
    {
        m_word_stats[i].print();
        std::cout << std::endl;
    }
}
