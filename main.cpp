#include <iostream>
#include "hashTable.h"


void function (){

    static int i = 0;
    i++;
    std::cout<<"number: "<<i<<std::endl;
    }


class Singleton
{
public:

    static Singleton &Get(){
        static Singleton instance;
        return instance;
    }
    void hello (){

        std::cout << " i am here"<<std::endl;
    }


};

class Entity {
private:
    int m_x, m_y;
public:
    int getInt () const{
        return m_x;
    }
    int getInt(){
        return m_x;
    }

    void setX(int x){
        m_x = x;
    }
};

void PrintFunc (const Entity& e){
    std::cout<< e.getInt()<< std::endl;
};


class Log {
public:
    enum Level {
        levelError, levelWarning, levelInfo
    };
private:
    int m_level = levelInfo;
public:
    void setLevel (int level){
        m_level = level;
    }

    void Error (const char* message ){
        if(levelInfo == levelError){
            std::cout << "[ERROR]" << message <<  std::endl;
        }
    }
    void Warning (const char* message ){
        if(levelInfo == levelWarning){
            std::cout << "[WARNING]" << message <<  std::endl;
        }
    }
    void Info (const char* message ){
        if(levelInfo == levelInfo){
            std::cout << "[WARNING]" << message <<  std::endl;
        }
    }


};

class Reporter {
private:
    int status;
public:
    enum Status {
        PassStatus, failedStatus, state
    };
    void setStatus (int test){
        status = test;
    }

    void  Pass (const char* message ){
        if(state == PassStatus){
            std::cout << "[PASS]" << message <<  std::endl;
        }
    }
    void Failed (const char* message ){
        if(state == failedStatus){
            std::cout << "[Failed]" << message <<  std::endl;
        }
    }
    void STATE (const char* message ){
        if(state == state){
            std::cout << "[STATE]" << message <<  std::endl;
        }
    }


};


int main()
{
    Singleton::Get().hello();
    Singleton::Get().hello();
    function();
    function();
    function();

    Entity e1;
    e1.setX(23);
    PrintFunc(e1);

    const int MAX_AGE = 90;

    int *a  = new int;

    *a = 2;

    a = (int*)&MAX_AGE;

    std::cout << *a << std::endl;

    Log log;
    log.setLevel(Log::levelWarning);
    log.Error("hello");
    log.Warning("hello");
    log.Info("hello");

    Reporter rep;
    rep.setStatus(Reporter::PassStatus);
    rep.Pass("hello pass");
    rep.Pass("hello");
    rep.Failed("hello");
    rep.STATE("hello");

    hashTable *table = new hashTable;
    table->isEmpty();
    table->insertItem(100,"prince");
    (*table).insertItem(101, "Krista");
    table->insertItem(102,"Farid");
    (*table).insertItem(103,"Navida");
    table->searchTable(101);
    table->removeItem(103);
    table->removeItembyString(101,"Krista");
    table->PrintHashFunction();

    return 0;
}
