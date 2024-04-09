#include <string>
#include<iostream>
#include<sstream>
#include<istream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include "GroupCalculator.h"
using namespace std;

void PowerGroupPrint(Group** Pg, int* size) //prints the set of sets
{
    int j;
    for (int i = 0; i < *size; i++)//goes through all the groups
    {
        int itemsgroupsize = Pg[i]->GetSize();
        cout << "{";
        for (j = 0; j < itemsgroupsize; j++)//goes through all the elements
        {
            cout << Pg[i]->GetItems()[j];
            if(j < itemsgroupsize - 1)
                cout << ",";
        }
        cout << "}";
        if(i < *size -1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;
}
void GroupGroupSort(Group** Pg, int* size)
{
    Group* temp;
    if (*size < 2)
        return;
    for (int i = 1; i < *size; i++) //sorts the groups by their sizes
    {
        int j = i;
        while (Pg[j]->GetSize() < Pg[j - 1]->GetSize()) {
            temp = Pg[j - 1];
            Pg[j - 1] = Pg[j];
            Pg[j] = temp;
            if (j < 2)
                continue;
            else
                j--;
        }
    }
    for (int i = 1; i < *size; i++)//sorts the groups with the same size by their elements value
    {
        int j = i, k = 0;
        while (Pg[j]->GetSize() == Pg[j - 1]->GetSize())
        {
            if(Pg[j]->GetItems()[k] < Pg[j - 1]->GetItems()[k])
            {
                temp = Pg[j - 1];
                Pg[j - 1] = Pg[j];
                Pg[j] = temp;
                if (j < 2)
                    continue;
                else
                    j--;
            }
            else if(Pg[j]->GetItems()[k] == Pg[j - 1]->GetItems()[k])
                k++;

        }
    }
}
void IntGroupSort(Group* g) //sorts the elements in a group
{
    int temp;
    if (g->GetSize() < 2)
        return;
    for (int i = 1; i < g->GetSize(); i++)
    {
        int j = i;
        while (g->GetItems()[j] < g->GetItems()[j - 1])
        {
            temp = g->GetItem(j - 1);
            g->GetItems()[j - 1] = g->GetItem(j);
            g->GetItems()[j] = temp;
            if (j < 2)
                continue;
            else
                j--;
        }
    }
}
bool isValidItems(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (!(isdigit(input[i])) && input[i] != ' ' && input[i] != '-')
            return false;
    }
    return true;
}
bool isValidTitle(string title) //checks if a title is valid
{
    if(title.length() == 0 || title.length() > 8) {
        cerr << "ERROR: invalid input" << endl;
        return false;
    }
    for (int i = 0; i < title.length(); i++) //checks if all the letters of the title are capital
    {
        if (!(isupper(title[i])))
        {
            cerr << "ERROR: invalid input" << endl;
            return false;
        }
    }
    return true;
}
int itemExists(int num, int* items, int size)// checks if an element exists in a set
{
    for (int i = 0; i < size; i++)
    {
        if (items[i] == num)
            return i;
    }
    return -1;
}
int GroupExists(Group* g, Group** groups, int size)//checks if a set exists in a set
{
    bool found;
    int i = 0;
    if (size == 0)
        return -1;
    while (i < size)
    {
        found = true;
        if(g->GetSize() != groups[i]->GetSize()) {
            i++;
            continue;
        }
        for (int j = 0; j < g->GetSize(); j++)
        {
            if (g->GetItem(j) != groups[i]->GetItem(j)) {
                found = false;
                break;
            }
        }
        if(found == true)
            return i;
        i++;
    }
    return -1;
}
int groupTitleExists( string group_name, Group** groups, int size )//checks if a groups with the same title exists in the calculator
{
    for (int i = 0; i < size; i++)
    {
        if (group_name.compare(groups[i]->GetName()) == 0)
            return i;
    }
    return -1;
}
void cpy_Group_array(Group** source, Group** dest, int size)//deep copies a set of sets
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = new Group(source[i]->GetName(), source[i]->GetSize(), source[i]->GetItems());
    }
}
void cpy_int_array(int* source, int* dest, int size)//copies a set of elements
{
    for (int i = 0; i < size; i++)
    {
        if (itemExists(source[i], dest, size) == -1)
        {
            dest[i] = source[i];
        }
    }
}
Group::Group(string n, int s, int* i)
{
    name = n;
    size = s;
    items = i;
}
void Group::AddItem(int num) //adds an element to the set
{
    if (size > MAX_GROUP_SIZE)  //checks if more space is needed to allocate
    {
        int* temp = new int[MAX_GROUP_SIZE * 2];
        cpy_int_array(items, temp, size - 1);
        delete[] items;
        items = new int[size];
        cpy_int_array(temp, items, size - 1);
    }
    this->items[size - 1] = num;
}
void AddGroupItem(Group* g, Group** groups, int* index, int* powerSetSize) //adds a set to a set
{
    groups[*index] = new Group("", g->GetSize(), g->GetItems());
}
void Group::SetItems(int* newItems) // changes the elements in a set
{
    delete[] items;
    items = new int[size];
    cpy_int_array(newItems, items, size);
}
Group* Group::removeIntItem(int item) //removes an element from a set
{
    Group* newGroup = new Group;
    int* newItems = new int[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (items[i] != item)
        {
            newItems[j] = items[i];
            j++;
        }
    }
    newGroup->SetSize(size - 1);
    newGroup->SetItems(newItems);
    newGroup->SetName(name);
    return newGroup;
}
void Group::Print() const //prints a set
{
    cout << name << "={";
    if (size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            cout << items[i] << ",";
        }
        cout << items[size - 1];
    }
    cout << "}" << endl;
}
void Calculator::AddGroup(Group* g) //adds a set to the calculator
{
    int i = groupTitleExists(g->GetName(), groups, size);
    if (i != -1) //checks if group already exists in the calculator
    {
        groups[i] = g;
    }
    size++;
    if (size > MAX_CALCULATOR_SIZE) //checks if more space is needed to allocate
    {
        Group** temp = new Group * [MAX_CALCULATOR_SIZE * 2];
        cpy_Group_array(groups, temp, size - 1);
        delete[] groups;
        cpy_Group_array(temp, groups, size);
        delete[] temp;
    }
    IntGroupSort(g);
    this->groups[size - 1] = g;
    return;
}
void Calculator::AddGroup() //function that scans the input
{
    Group* g = new Group;
    string input;
    int num, gsize = 0, i = 0;
    getline(cin, input);
    if (!(isValidTitle(input))) //check if the title is valid
        return;
    g->SetName(input);
//    cin.ignore(); //ignores the '\0' so that getline can scan proprely
    getline(cin, input);
    if (input[0] != '{') //checks that the set starts with {
    {
        cerr << "ERROR: invalid input" << endl;
        return;
    }
    if (input[input.length() - 1] != '}') //checks that the set ends with }
    {
        cerr << "ERROR: invalid input" << endl;
        return;
    }
    if (input.length() == 2) { //adds an empty group
        g->AddItem(-1);
        AddGroup(g);
        return;
    }
    input.erase(0, 1); //removes {
    input.erase(input.length() -1, 1); //removes }
    stringstream st(input);
    if(!(isValidItems(input)))
    {
        cerr << "ERROR: invalid input" << endl;
        return;
    }
    while (st >> num) //puts all the numbers in the set
    {
        if (gsize && itemExists(num, g->GetItems(), gsize) != -1) //checks if the set is not empty then checks if the number already exists
            continue;
        gsize++;
        if (gsize > MAX_GROUP_SIZE) {
            int* temp = new int[gsize];
            cpy_int_array(g->GetItems(), temp, g->GetSize());
            g->SetItems(temp);
            delete[] temp;
        }
        g->SetSize(gsize);
        g->AddItem(num);
    }
    AddGroup(g);
}
void Calculator::DeleteGroup(string name) // deletes a set from the calculator
{
    int i = groupTitleExists(name, groups, size);
    if ( i != -1) //checks if group already exists in calculator
    {
        groups[i]->SetName("");
        groups[i]->SetItems(new int[0]);
        groups[i]->SetSize(0);
    }
    else
    {
        cerr << "ERROR: " << name << " does not exist" << endl;
        return;
    }
    return;
}
void Calculator::DeleteGroup() //deals with the input
{
    string input;
    getline(cin, input);
    if (!(isValidTitle(input))) //check if the title is valid
        return;
    DeleteGroup(input);
}
void Calculator::UnionGroups(Group* a, Group* b, string union_group_name) //unions two sets into a new set
{
    int* unionItems = new int[MAX_GROUP_SIZE];
    int unionSize = 0;
    int k = 0;
    Group* c = new Group;
    int i = groupTitleExists(union_group_name, groups, size);
    if (i != -1) //checks if group exists in the calculator
    {
        c = groups[i];
    }
    else {
        c->SetName(union_group_name);
    }
    for (int i = 0; i < a->GetSize(); i++) //copies all the items from group a
    {
        if (itemExists(a->GetItem(i), unionItems,unionSize) != -1)
            continue;
        else
        {
            unionSize++;
            unionItems[k] = a->GetItem(i);
            k++;
        }
    }
    for (int i = 0; i < b->GetSize(); i++) //copies all the items from group b
    {
        if (itemExists(b->GetItem(i), unionItems, unionSize) != -1)
            continue;
        else
        {
            unionSize++;
            unionItems[k] = b->GetItem(i);
            k++;
        }
    }
    c->SetSize(unionSize);
    c->SetItems(unionItems);
    AddGroup(c);
}
void Calculator::UnionGroups() //deals with the input
{
    string name1, name2, name3, test, input;
    Group *g1, *g2;
//    cin.ignore(); //ignores the '\0' so that getline can scan proprely
    getline(cin, input);
    stringstream st(input);
    st >> name1;
    st >> name2;
    st >> test;
    if(test != "\0" || name2 == "\0")
    {
        cerr << "ERROR: invalid input" << endl;
        return;
    }
    if (!(isValidTitle(name1)) || !(isValidTitle(name2))) //check if the title is valid
        return;
    int i = groupTitleExists(name1, groups, size);
    if (i != -1) //checks if group already exists in calculator
    {
        g1 = groups[i];
    }
    else
    {
        cerr << "ERROR: " << name1 << " does not exist" << endl;
        return;
    }
    i = groupTitleExists(name2, groups, size);
    if (i != -1) //checks if group already exists in calculator
    {
        g2 = groups[i];
    }
    else
    {
        cerr << "ERROR: " << name2 << " does not exist" << endl;
        return;
    }
    getline(cin, name3);
    if(!(isValidTitle(name3)));
    UnionGroups(g1, g2, name3);
}
int Calculator::SimilarItems(Group* a, Group* b) //returns the amount of similar elements in two sets
{
    int count = 0;
    for (int i = 0; i < a->GetSize(); i++)
    {
        for (int j = 0; j < b->GetSize(); j++)
        {
            if (a->GetItems()[i] == b->GetItems()[j])
            {
                count++;
            }
        }
    }
    return count;
}
void Calculator::InterGroups(Group* a, Group* b, string inter_group_name) //saves the intersection set of two sets in the calculator
{
    Group* c = new Group;
    int interSize = 0 , k = 0;
    int *interItems = new int[MAX_GROUP_SIZE];
    int i = groupTitleExists(inter_group_name, groups, size);
    if (i != -1) //checks if group exists in the calculator
    {
        c = groups[i];
    }
    else {
        c->SetName(inter_group_name);
    }
    for (int i = 0, j = 0; i < a->GetSize() || j < b->GetSize(); i++, j++)
    {
        if (itemExists(a->GetItem(i), b->GetItems(), b->GetSize()) != -1)
        {
            if (itemExists(a->GetItem(j), interItems, interSize) != -1)
                continue;
            interSize++;
            interItems[k] = a->GetItem(i);
            k++;
        }
        if (itemExists(b->GetItem(j), a->GetItems(), a->GetSize()) != -1)
        {
            if (itemExists(b->GetItem(j), interItems, interSize) != -1)
                continue;
            interSize++;
            interItems[k] = b->GetItem(j);
            k++;
        }
    }
    c->SetSize(interSize);
    c->SetItems(interItems);
    AddGroup(c);
}
void Calculator::InterGroups()//deals with the input
{
    string name1, name2, name3, test, input;
    Group *g1, *g2;
//    cin.ignore(); //ignores the '\0' so that getline can scan proprely
    getline(cin, input);
    stringstream st(input);
    st >> name1;
    st >> name2;
    st >> test;
    if(test != "\0" || name2 == "\0")
    {
        cerr << "ERROR: invalid input" << endl;
        return;
    }
    if (!(isValidTitle(name1))) //check if the title is valid
        return;
    if (!(isValidTitle(name2))) //check if the title is valid
        return;
    int i = groupTitleExists(name1, groups, size);
    if (i == -1) //checks if group exists in the calculator
    {
        cerr << "ERROR: " << name1 << " does not exist" << endl;
        return;
    }
    else
        g1 = groups[i];
    i = groupTitleExists(name2, groups, size);
    if (i == -1) //checks if group exists in the calculator
    {
        cerr << "ERROR: " << name2 << " does not exist" << endl;
        return;
    }
    else
        g2 = groups[i];
    getline(cin, name3);
    isValidTitle(name3);
    InterGroups(g1, g2, name3);
}
void Calculator::Print() // deals with the input
{
    string input;
    getline(cin, input);
    if (!(isValidTitle(input))) //check if the title is valid
        return;
    int i = groupTitleExists(input, groups, size);
    if (i != -1) //checks if group already exists in the calculator
    {
        this->groups[i]->Print();
        return;
    }
    cerr << "ERROR: " << input << " does not exist" << endl;
}
void Calculator::Exit()
{
    exit(1);
}
Group** Calculator::PowerGroup(Group* g, Group** Pg, int size, int* index, int* powerSetSize) { //returns the powerset of a set
    if (GroupExists(g, Pg, *powerSetSize) == -1) {
        AddGroupItem(g, Pg, index, powerSetSize);
        (*powerSetSize)++;
        (*index)++;
    }
    if (g->GetSize() != 0)
    {
        for (int i = 0; i < g->GetSize(); i++)
        {
            Pg = PowerGroup(g->removeIntItem(g->GetItem(i)), Pg, size - 1, index, powerSetSize);
        }
    }
    return Pg;
}
void Calculator::PowerGroup() //deals with the input
{
    Group* g = new Group;
    string input;
    getline(cin, input);
    if (!(isValidTitle(input))) //check if the title is valid
        return;
    int i = groupTitleExists(input, groups, size);
    if (i == -1) //checks if group exists in the calculator
    {
        cerr << "ERROR: " << input << " does not exist" << endl;
        return;
    }
    else
        g = groups[i];
    if (g->GetSize() > 10)
    {
        cerr << "group has more than 10 elements" << endl;
        return;
    }
    Group* Pg;
    int tempSize = pow(2, g->GetSize());
    int powerSetSize = 0, index = 0;
    Group** temp = new Group*[tempSize];
    temp = PowerGroup(g, temp, g->GetSize(), &index, &powerSetSize);
    Pg = new Group(temp);
    GroupGroupSort(Pg->GetGroupItems(), &powerSetSize);
    cout << "P(" << g->GetName() << ")={";
    PowerGroupPrint(Pg->GetGroupItems(), &powerSetSize);
}