#include "concordance.h"
#include <iostream>

Concordance::Concordance(std::string filename)
{
    m_filename = filename;
    m_line = 1;
}

void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());
    while(!file.eof())
    {
        std::string word = next_word(file);
        new_word(word, m_line);
    }
}

void Concordance::new_word(std::string word, int line)
{
    int index = -1;
    for(int i = 0; i < m_word_stats.size(); ++i)
    {
        if(m_word_stats[i].get_word() == word)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        Word ward(word);
        ward.add_line(line);
        m_word_stats.push_back(ward);
    } else {
        m_word_stats[index].add_count(1);
        m_word_stats[index].add_line(line);
    }
}

bool Concordance::is_whitespace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

bool Concordance::is_punct(char c)
{
    return (c == '.' || c == ',' || c == '?' || c == '!' || c == '\'' || c== '\"' || c == ';' || c == ':' || c == ')' || c == '(');
}

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

void Concordance::print()
{
    for (int i = 0; i < m_word_stats.size(); ++i) 
    {
        m_word_stats[i].print();
        std::cout << std::endl;
    }
}
