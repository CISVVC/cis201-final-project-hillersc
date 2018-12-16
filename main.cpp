/*
File: main.cpp
Description: main file that runs concordance.cpp
Author: Colby Hillers
Email: hillersc144964@student.vvc.edu
Date: 12/16/18
*/

#include "concordance.h"

int main()
{
   Concordance con("alice.txt");
   con.parse();   
   con.print();

   return 0;
}
