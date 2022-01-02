#include "hashTable.h"

hashTable::hashTable()
{
    //ctor
}

/**checking whether the hashTable list is empty
    Take each list element(column) and checks whether it is empty...
    if the sum "size" returns zero than truly the list(column ) is empty
        else then the list is not empty...
**/
bool hashTable::isEmpty()const{
    int sum =0;
    for(int i =0; i< hashSize;i++){
        sum += hashMembers[i].size();
    }
    if(!sum){
        std::cout<<"[WARNING] Yes its empty!"<<std::endl;
        return true;

    }else{
        std::cout<<"[INFO] NO its NOT empty!"<<std::endl;
    }
    return false;
}

/** this function return the hash function index of sort.
*   add more when you understand
**/
int hashTable::hashFunction(int key){
    return key % hashSize;
}

/** To insert items into the hashTable
* set the the keyExist as default false, meaning we assume the key does not exist
* insert the pair at a specific position in the cell of the list for this we use the hashFunction WHICH returns an index OF THE position of the a pair in a list
* iterator to emplace_back pair since is it a list
* confirm addition
* check if cell isEmpty , if cell is not empty, maintain the key but change value
* else if it not IsEmpty then add pair.
**/

void hashTable::insertItem(int key, std::string value){
    bool keyexist = false;
    int hashValue = hashFunction(key);
    auto &cell = hashMembers[hashValue];
    auto itr = cell.begin();
    for(; itr!=cell.end();itr++){
        if (itr->first == key){
            keyexist = true;
            itr->second = value;
            break;
                std::cout << "Key exist but value added"<< std::endl;
        }
    }
    if(!keyexist){
        cell.emplace_back(key,value);
    }
}
/** To search a specific cell in a HashTable
* so we check is the key exists , by the the keyExist is set to false
* assign a specific cell in the hashTable a reference to it index.
* iterate true the each cell in the list of the hashTable
* return the value of the of the corresponding key
**/
void hashTable::searchTable(int key){
    bool keyExist = false;
    auto &cell = hashMembers[hashFunction(key)];
    for (auto itr = cell.begin(); itr != cell.end(); itr++){
        if (itr->first == key){
            keyExist = true;
            //return = itr->first;
            std::cout<< "This key " << itr->first << " has value " << itr->second << std::endl;
            break;

            //return itr->second;
        }
    }
    if (!keyExist){
        std::cout << "[INFO]Key not found!"<<std::endl;
    }
}
/** algorithm similar to search table.
*
*
**/

void hashTable::removeItem(int key){
    bool keyExist = false;
    auto &cell = hashMembers[hashFunction(key)];
    for(auto itr = cell.begin(); itr != cell.end(); itr++){
        if (itr->first == key){
            keyExist = true;
            itr = cell.erase(itr);
            std::cout<< "[INFO] Item removed."<<std::endl;
            break;
        }
    }
    if (!keyExist){
        std::cout << " [WARNING!] Key does not Exist found!"<<std::endl;
    }
}

/** algorithm similar to removeItem table.
*
*
**/


void hashTable::removeItembyString(int key ,std::string value){
     bool valueExist = false;
    auto &cell = hashMembers[hashFunction(key)];
    for(auto itr = cell.begin(); itr != cell.end(); itr++){
        if (itr->second == value){
            valueExist = true;
            itr = cell.erase(itr);
            std::cout<< "[INFO] Item removed."<<std::endl;
            break;
        }
    }
    if (!valueExist){
        std::cout << " [WARNING!] Key does not Exist found!"<<std::endl;
    }

}

/** Print the HashTable
* if the list (column) is empty continue
*   for iterator in hashTable, print out in the format....
**/


void hashTable::PrintHashFunction(){
        for(int i =0; i< hashSize; i++){
            if (hashMembers[i].size() == 0) continue;

            for(auto itr : hashMembers[i]){
                std::cout<<"[INFO] Key: "<<itr.first << " Value: " << itr.second << std::endl;
        }
        }
}
