#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <iostream>
#include <cstring>
#include <string>


class hashTable
{
public:
   hashTable();
   ~hashTable();
   bool isEmpty ()const;
   int hashFunction(int key);
   void insertItem(int key, std::string);
   void searchTable(int key);
   void removeItem(int key);
   void removeItembyString (int,std::string);
   void PrintHashFunction();


private:
    static const int hashSize = 10;
    std::list<std::pair<int,std::string>> hashMembers[hashSize];
};

#endif // HASHTABLE_H
