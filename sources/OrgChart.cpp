#include "OrgChart.hpp"
#include<algorithm>
#include<queue>

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
        const int max = 125;
        const int minim = 32;
        for (size_t i = 0; i < parent.length(); i++)
        {
            if (parent[i] > max || parent[i]<minim)
            {
                throw runtime_error("valid input");
            }
        }
        if (parent == " " || parent =="")
        {
            throw runtime_error("valid input");
        }
        
        
        this->root.value = parent;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string parent, string chaild)
    {
        const int max = 125;
        const int minim = 32;
        for (size_t i = 0; i < chaild.length(); i++)
        {
            if (chaild[i] > max || chaild[i]<minim)
            {
                throw runtime_error("valid input");
            }
        }
        if (parent == "")
        {
            throw runtime_error("valid input");
        }
        
        /*if(root.value.compare(parent) == 0)
        {
            Node temp_son;
            temp_son.value = chaild;
            root.son.push_back(temp_son);
            
            return *this;
        }*/
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
        queue<Node *> q;
        q.push(&root);
        start_level_order(root,q);
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
    string *OrgChart::reverse_order()
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
    void OrgChart::start_level_order(Node &node,queue<Node *> q)
    {
        while (!q.empty())
        {
            Node *node = q.front();
            iter_level_order.push_back(node->value);
            q.pop();
            for (size_t i = 0; i <node->son.size(); i++)
            {
                q.push(&(node->son.at(i)));
            }
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
        int next_level = 0;
        int first_level = root.root.son.size();
        out<<root.root.value<<endl;
        for (auto it = root.begin_level_order(); it != root.end_level_order();)
        {
            if (first_level == 0)
            {
                ++it;
            }
            
            for (size_t i = 0; i < first_level; i++)
            {
                it++;
                if (it == root.end_level_order())
                {
                    break;
                }
                
                Node *temp_node2 = root.findNode(&root.root,(*it));
                if (temp_node2->son.size() > 0)
                {
                    next_level += temp_node2->son.size();
                }
                out<<(*it) <<"    ";
            }
            first_level = next_level;
            if (it == root.end_level_order())
            {
                break;
            }
            out<<endl;
        }
        
        return out;
    }
    /*void OrgChart::delete_Node(Node *node)
    {
        for (size_t i = 0; i < node->son.size(); i++)
        {
            delete_Node(&(node->son.at(i)));
        }    
        delete node;
    }
    OrgChart::~OrgChart()
    {
        delete_Node(&root);
    }*/
}


