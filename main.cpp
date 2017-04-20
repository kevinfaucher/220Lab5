/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin Faucher, Alexia Nebrao
 *
 * Created on April 12, 2017, 8:34 PM
 */
#include <stdlib.h>
#include <string>
#include "ZDatabase.hpp";
using namespace std;

int main() {
    string g = "zipcodefile.txt"; //The full file – after you have everything
    // working
    string h = "ziptestfile.txt"; // for testing purposes

    ZDatabase *zdb = new ZDatabase(g, false);
    ZDatabase *zdb2 = new ZDatabase(g,true);

    return 0;
}