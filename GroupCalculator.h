#ifndef GOUPCALCULATOR_H_
#define GOUPCALCULATOR_H_

#include <iostream>
#include <string>
using namespace std;
#define MAX_GROUP_SIZE 10
#define MAX_CALCULATOR_SIZE 10

class Group {
public:
    Group() : name(""), size(0), items(new int[MAX_GROUP_SIZE]), psize(0),
              gItems(new Group*) {}
    Group(string name, int size, int* items);
    Group(Group** groups){ gItems = groups; }
    void AddItem(int i);
    string GetName() const { return name; }
    int GetSize() const { return size; }
    int GetpSize() const { return psize; }
    int GetItem(int i) const { return items[i]; }
    int* GetItems() const { return items; }
    Group** GetGroupItems() const { return gItems; }
    Group* removeIntItem(int item);
    void SetName(string n) { name = n; }
    void SetSize(int s) { size = s; }
    void SetItems(int* newItems);
    void Print() const;
private:
    string name;
    int size;
    int* items;
    int psize;
    Group** gItems;
};
class Calculator {
public:
    Calculator() { size = 0; groups = new Group * [MAX_CALCULATOR_SIZE]; }
    void AddGroup();
    void AddGroup(Group* g);
    Group* GetGroup(string name) const;
    int GetSize() const{ return size; }
    void DeleteGroup();
    void DeleteGroup(string g);
    void UnionGroups(Group* a, Group* b, string union_group_name);
    void UnionGroups();
    int SimilarItems(Group* a, Group* b);
    void InterGroups(Group* a, Group* b, string inter_group_name);
    void InterGroups();
    Group** PowerGroup(Group* g, Group** Pg, int size, int* index, int* powersetsize);
    void PowerGroup();
    void Print();
    void Exit();
private:
    Group** groups;
    int size;
};


#endif // !GOUPCALCULATOR_H_

