#include "OrgChart.hpp"
#include<algorithm>

using namespace std;

namespace ariel
{
    Node *OrgChart::findNode(Node *root, string val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->value == val)
        {
            return root;
        }
        for (size_t i = 0; i < root->son.size(); i++)
        {
            Node *temp = findNode(&(root->son.at(i)),val);
            if (temp != nullptr)
            {
                return temp;
            }
        }
        return nullptr;
    }

    OrgChart::OrgChart(){};

    OrgChart &OrgChart::add_root(string parent)
    {
        this->root.value = parent;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string parent, string chaild)
    {
        if(root.value.compare(parent) == 0)
        {
            Node temp_son;
            temp_son.value = chaild;
            root.son.push_back(temp_son);
            
            return *this;
        }
        bool flag = false;
        Node *temp = findNode(&root,parent);
        if(temp == nullptr)
        {
            throw runtime_error("not such parent");
        }
        Node temp_son;
        temp_son.value = chaild;
        temp->son.push_back(temp_son);
        return *this;
    }

    string *OrgChart::begin_level_order()
    {
        iter_level_order.clear();
        iter_level_order.push_back(root.value);
        start_level_order(root);
        return &iter_level_order[0];
    }
    string *OrgChart::end_level_order()
    {
        return &iter_level_order[iter_level_order.size()];
    }
    string *OrgChart::begin_reverse_order()
    {
        iter_reverse_order.clear();
        begin_level_order();
        iter_reverse_order = iter_level_order;
        reverse(iter_reverse_order.begin(),iter_reverse_order.end());
        return &iter_reverse_order[0];
    }
    string *OrgChart::end_reverse_order()
    {
        return &iter_reverse_order[iter_reverse_order.size()];
    }
    string *OrgChart::begin_preorder()
    {
        iter_preorder.clear();
        start_pre_order(root);
        return &iter_preorder[0];
    }
    string *OrgChart::end_preorder()
    {
        return &iter_preorder[iter_preorder.size()];
    }
    void OrgChart::start_level_order(Node &root)
    {
        for (size_t i = 0; i <root.son.size(); i++)
        {
            iter_level_order.push_back(root.son.at(i).value);
        }
        for (size_t i = 0; i < root.son.size(); i++)
        {
            start_level_order(root.son.at(i));
        }
    }
    void OrgChart::start_pre_order(Node &root)
    {
        iter_preorder.push_back(root.value);
        for (size_t i = 0; i < root.son.size(); i++)
        {
            start_pre_order(root.son[i]);
        }
    }
    ostream &operator<<(ostream &out, OrgChart &root)
    {
        out<<root.root.value;
        out<<endl<<"|"<<endl;
        /*for (size_t i = 0; i < root.root.son.size(); i++)
        {
            out<<root.root.son.at(i).value;
            out<<" ";
            for (size_t j = 0; j < root.root.son.at(i).son.size(); j++)
            {
                out<<endl<<"|"<<endl;
                out<<root.root.son.at(i).son.at(j).value;
                out<<" ";
            }
            
            
        }*/
        out<<root.print_level(root.root);
        return out;
    }
    string OrgChart::print_level(Node root)
    {
        string ans;
        for (size_t i = 0; i < root.son.size(); i++)
        {
            if (i == root.son.size()-1)
            {
                ans += root.son.at(i).value;
            }
            else
            {
                ans += root.son.at(i).value;
                ans += "-----------";
            }  
        }
        for (size_t i = 0; i < root.son.size(); i++)
        {
            ans += "\n|";
            ans += print_level(root.son.at(i));
        }
        
        return ans;
        
    }
}


