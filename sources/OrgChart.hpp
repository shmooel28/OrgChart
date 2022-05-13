#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

namespace ariel
{
    class Iterator;
    struct Node
    {
        string value;
        vector<Node> son;
    };
    class OrgChart
    {
        private:
            Node root;
            vector<string> iter_level_order;
            vector<string> iter_reverse_order;
            vector<string> iter_preorder;
            void start_level_order(Node &root);
            void start_pre_order(Node &root);

        public:
            Node *findNode(Node *root,string val);
            OrgChart();
            OrgChart &add_root(string parent);
            OrgChart &add_sub(string parent,string child);

            friend ostream &operator<<(ostream &os, OrgChart &root);
            string print_level(Node root);
            
            string *begin_level_order();
            string *end_level_order();

            string *begin_reverse_order();
            string *end_reverse_order();

            string *begin_preorder();
            string *end_preorder();

            string *begin(){return begin_level_order();}
            string *end(){return end_level_order();}
            
    };
}