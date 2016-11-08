//Ssc.cpp

#include "Ssc.h"

Ssc::Ssc():Ssc("",0,""){} //constructor 

Ssc::Ssc(string str, int i, string c): 
    line(str), index(i), character(c), Instruction(){}
    
void Ssc::initialize(stringstream& ss)
{
    string s= "";
    getline(ss,s,',');
    line.assign(s);
    //cout<<line<<endl;
    getline(ss,s, ',');
    index = strtof(s.c_str(),NULL);
    //cout<<index<<endl;
    getline(ss,s, ',');
    character.assign(s);
    //cout<<character<<endl;
}

void Ssc::process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec)
{
    ofstream err;
    err.open("MIS.err", std::ios_base::app);
    if(varMap.count(line)==1)
    {
        //grab the first character and set it to the corresponding index
        string temp=""; //create temp string to assign
        temp.assign(varMap[line].first); //assigns string variable to temp
        temp[index] = character[0];//changes the character at the index of the string variable.
        varMap[line].first = temp;
    } else {err<<"Key doesn't exist"<<endl;}
}

Instruction * Ssc::clone(stringstream & ss) //clones the ssc object
{
    Ssc* ssc= new Ssc();
    ssc->initialize(ss);
    return ssc;
}

string Ssc::getName()
{
    return "";
}

Ssc::~Ssc(){}
