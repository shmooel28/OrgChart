#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<iterator>
using namespace std;

namespace ariel
{
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
            void start_level_order(Node &node,queue<Node *> q);
            void start_pre_order(Node &root);
            void start_reverse_order(Node &node);

        public:
            OrgChart();
            Node *findNode(Node *root,string const &val);
            Node *get_root(){return &root;};
            OrgChart &add_root(string parent);
            OrgChart &add_sub(string const &parent,string chaild);

            vector<string>::iterator begin_level_order();
            vector<string>::iterator end_level_order();

            vector<string>::iterator begin_reverse_order();
            vector<string>::iterator reverse_order();

            vector<string>::iterator begin_preorder();
            vector<string>::iterator end_preorder();

            vector<string>::iterator begin(){return begin_level_order();}
            vector<string>::iterator end(){return end_level_order();}

            friend ostream &operator<<(ostream &out, OrgChart &root);            

            
    };
}