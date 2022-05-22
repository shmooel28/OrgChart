#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include<vector>
#include"OrgChart.hpp"
using namespace std;

using namespace ariel;

TEST_CASE("org 1 - check simple case")
{
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO","sdf"));
    CHECK_NOTHROW(organization.add_sub("CEO","sdf"));
    CHECK_NOTHROW(organization.add_sub("CEO","str").add_sub("sdf","tre"));
    CHECK_NOTHROW(organization.add_root("CDE").add_sub("CDE","gfd"));
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        CHECK_EQ(it->size(),3);
    }

}
TEST_CASE("org2 - check valid input")
{
    OrgChart organization2;
    CHECK_THROWS(organization2.add_sub("","CEO"));
    CHECK_THROWS(organization2.add_sub("CEO","CEO"));
    CHECK_THROWS(organization2.add_sub("CEO",""));
    CHECK_THROWS(organization2.add_root(" "));
    CHECK_THROWS(organization2.add_root("\n"));
    CHECK_THROWS(organization2.add_root("\t"));
}
TEST_CASE("org3 - check algorithem")
{
    OrgChart organization3;
    CHECK_NOTHROW(organization3.add_root("CEO")
      .add_sub("CEO", "CTO")    
      .add_sub("CEO", "CFO")         
      .add_sub("CEO", "COO")        
      .add_sub("CTO", "VP_SW") 
      .add_sub("COO", "VP_BI").add_root("shmuel"));
    vector<string> level_order_test = {"shmuel", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
    vector<string> reverse_order_test = {"VP_SW", "VP_BI", "CTO", "CFO", "COO","shmuel"};
    vector<string> pre_order_test = {"shmuel", "CTO",  "VP_SW","CFO", "COO", "VP_BI"};
    int i = 0;
    for (auto it = organization3.begin_reverse_order(); it != organization3.reverse_order(); ++it)
    {
       CHECK_EQ((*it),reverse_order_test.at((unsigned int)i));
       i++;
    }
    i = 0;
    for (auto it = organization3.begin_preorder(); it != organization3.end_preorder(); ++it)
    {
        CHECK_EQ((*it),pre_order_test.at((unsigned int)i));
       i++;
    }
    i = 0;
    for (auto it = organization3.begin_level_order(); it != organization3.end_level_order(); ++it)
    {
        CHECK_EQ((*it),level_order_test.at((unsigned int)i));
        i++;
    }
    i = 0;
    for (auto element : organization3)
    {
        CHECK_EQ(element,level_order_test.at((unsigned int)i));
        i++;
    }

}
TEST_CASE("check print")
{
    OrgChart organization4;
    organization4.add_root("a").add_sub("a","b").add_sub("a","c");
    organization4.add_sub("b","d").add_sub("d","e").add_sub("b","f");
    organization4.add_sub("c","g").add_sub("c","h").add_sub("h","i").add_sub("a","j").add_sub("d","k");
    for (auto it = organization4.begin_level_order(); it != organization4.end_level_order(); ++it)
    {
        cout << (*it) << " " ;
    } 
    cout<<endl;
    Node *temp = organization4.findNode(organization4.get_root(),"b");
    for (size_t i = 0; i < temp->son.size(); i++)
    {
        cout<<temp->son.at(i).value<<"   ";
    }
    cout<<endl;
    Node *temp2 = organization4.findNode(organization4.get_root(),"c");
    for (size_t i = 0; i < temp2->son.size(); i++)
    {
        cout<<temp2->son.at(i).value<<"   ";
    }
    cout<<endl;

    for (auto it = organization4.begin_level_order(); it != organization4.end_level_order(); ++it)
    {
        cout<<(*it)<<" ";
    }

    cout<<organization4;

}