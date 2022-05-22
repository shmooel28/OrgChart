
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main() {
  OrgChart organization;
  organization.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI").add_root("shmuel");      // Now the VP_BI is subordinate to the COO

  cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
       CEO
       |--------|--------|
       CTO      CFO      COO
       |                 |
       VP_SW             VP_BI
 */

  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI
  cout<<endl;
  for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: VP_SW VP_BI CTO CFO COO CEO
  cout<<endl;
  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: CEO CTO VP_SW CFO COO VP_BI
  cout<<endl;
  for (auto element : organization)
  { // this should work like level order
      cout << element << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI

  // demonstrate the arrow operator:
  cout<<endl;
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << it->size() << " " ;
  } // prints: 3 3 3 3 5 5
  cout<<endl;
  OrgChart organization2;
  organization2.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CTO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CTO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CFO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI");     // Now the VP_BI is subordinate to the COO

  cout << organization2 << endl; /* Prints the org chart in a reasonable format. For example:
       CEO
       |--------|--------|
       CTO      CFO      COO
       |                 |
       VP_SW             VP_BI
 */

  for (auto it = organization2.begin_level_order(); it != organization2.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI
  cout<<endl;
  for (auto it = organization2.begin_reverse_order(); it != organization2.reverse_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: VP_SW VP_BI CTO CFO COO CEO
  cout<<endl;
  for (auto it=organization2.begin_preorder(); it!=organization2.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: CEO CTO VP_SW CFO COO VP_BI
  cout<<endl;
  for (auto element : organization2)
  { // this should work like level order
      cout << element << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI

  // demonstrate the arrow operator:
  cout<<endl;
  for (auto it = organization2.begin_level_order(); it != organization2.end_level_order(); ++it)
  {
    cout << it->size() << " " ;
  } // prints: 3 3 3 3 5 5
  cout<<endl;
  //delete organization;
  OrgChart org;
  //cout<<"enter the big manager"<<endl;
  string parent;
  //cin>>parent;
  //org.add_root(parent);
  string chaild;
  int user_choise = -3;
  while (user_choise >= 0)
  {    
        cout<<"enter parent name"<<endl;
        cin>>parent;
        cout<<"enter employee name"<<endl;
        cin>>chaild;
        org.add_sub(parent,chaild);
        cout<<"for add sub press 0\nto print level order press 1\nto print reverse press 2\nto print preorder press 3\nto print the organization press 4\nto exit press -1";
        cin>>user_choise;
        cout<<endl;
        if (user_choise ==1)
        {
            for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
            {
            cout << (*it) << " " ;
            }
        }
        else if (user_choise ==2)
        {
            for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
            {
                cout << (*it) << " " ;
            }
        }
        else if (user_choise ==3)
        {
            for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
                cout << (*it) << " " ;
            }
        }
        else if (user_choise ==4)
        {
            cout << org << endl;
        }
  }
  
}