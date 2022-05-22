#include "OrgChart.hpp"
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

namespace ariel
{
    Node *OrgChart::findNode(Node *root, string const &val)
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
        if (parent == " " || parent.empty())
        {
            throw runtime_error("valid input");
        }
        
        
        this->root.value = parent;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string const &parent, string chaild)
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
        if (parent.empty())
        {
            throw runtime_error("valid input");
        }
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

    vector<string>::iterator OrgChart:: begin_level_order()
    {
        if(root.value.empty())
        {
            throw runtime_error("empty tree");
        }
        iter_level_order.clear();
        queue<Node *> q;
        q.push(&root);
        start_level_order(root,q);
        return iter_level_order.begin();
    }
    vector<string>::iterator OrgChart:: end_level_order()
    {
        if(root.value.empty())
        {
            throw runtime_error("empty tree");
        }
        return iter_level_order.end();
    }
    vector<string>::iterator OrgChart::begin_reverse_order()
    {
        iter_reverse_order.clear();
        //iter_reverse_order.insert(iter_reverse_order.begin(), root.value);
        start_reverse_order(root);
        if(root.value.empty())
        {
            throw runtime_error("empty tree");
        }
        return iter_reverse_order.begin();
    }
    vector<string>::iterator OrgChart::reverse_order()
    {
        if(root.value.empty())
        {
            throw runtime_error("empty tree");
        }
        return iter_reverse_order.end();
    }
    vector<string>::iterator OrgChart::begin_preorder()
    {
        iter_preorder.clear();
        start_pre_order(root);
        if(root.value.empty())
        {
            throw runtime_error("empty tree");
        }
        return iter_preorder.begin();
    }
    vector<string>::iterator OrgChart::end_preorder()
    {
        if(root.value.empty())
        {
            throw runtime_error("empty tree");
        }
        return iter_preorder.end();
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
    void OrgChart::start_reverse_order(Node &node)
    {
        vector<Node*> temp;
        temp.push_back(&root);
        for (size_t i = 0; i < temp.size(); i++)
        {
            Node* tempNode = temp[i];
            for (int j = (int)(tempNode->son.size())-1; j >= 0; j--)
            {
                temp.push_back(&(tempNode->son[(size_t)j]));
            }
        }
        for (int i = (int)temp.size()-1; i >= 0; i--)
        {
            string newName = temp[(size_t)i]->value;
            iter_reverse_order.push_back(newName);
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
                if (!temp_node2->son.empty())
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
        vector<int> te;
        te.begin();
        te.end();
        return out;
    }
    
}


