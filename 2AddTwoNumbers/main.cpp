#include<iostream>
#include<cstdlib>
#include <string>
#include <vector>

using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution
 {
   public:
     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
     {
         vector<ListNode *> listNodes;
         listNodes.push_back(l1);
         listNodes.push_back(l2);
         vector<long long> nums;
         nums.push_back(0);
         nums.push_back(0);

         ListNode *p = NULL;

         for (int i = 0; i < 2; i++)
         {
             p = listNodes[i];
             long long par = 1;
             while (p != NULL)
             {
                 nums[i] += par * p->val;
                 par *= 10;
                 p = p->next;
             }
         }

         nums[0] += nums[1];

         string sum_str = std::to_string(nums[0]);
         ListNode *sum_list = NULL;

         delete p;
         p=NULL;
         for (int i=sum_str.size()-1;i>=0;i--)
         {
            ListNode *node = new ListNode(sum_str.at(i)-'0');
            if (sum_list == NULL)
             {
                sum_list = node;
                p = node;
             }
             else
             {
                p->next = node;
                p = p->next;
             }
         }

         return sum_list;
     }
 };

 int main(int argc, char const *argv[])
 {
     string temp;
     vector<char> stack;
     //vector<vector<int>> nums;
     vector<ListNode *> listNodes;
     int num_index=0;

     /*ListNode *tempNode=NULL;
     listNodes.push_back(tempNode);
     listNodes.push_back(tempNode);*/
     listNodes.resize(2);

     cin>>temp;

     ListNode *p=NULL;
     for(int i=0;i<temp.size();i++)
     {
         if(temp.at(i)>='0'&&temp.at(i)<='9')
         {
            ListNode *node=new ListNode(temp.at(i)-'0');
            if(listNodes[num_index]==NULL)
            {
                listNodes[num_index]=node;
                p=listNodes[num_index];
            }
            else
            {
                p->next=node;
                p=p->next;
            }

         }else if(temp.at(i)==']')
         {
             num_index++;
             p=NULL;
         }
     }

     //输出数据
     for(int i=0;i<2;i++)
     {
         p=listNodes[i];
         long long par=1;
         long long num=0;
         while(p!=NULL)
         {
             num+=par*p->val;
             par*=10;
             p=p->next;
         }
         cout<<"num: "<<num<<std::endl;
     }
     
     ListNode *sum;
     Solution sol;
     sum=sol.addTwoNumbers(listNodes[0],listNodes[1]);

     p = sum;
     long long par = 1;
     long long num = 0;
     while (p != NULL)
     {
         num += par * p->val;
         par *= 10;
         p = p->next;
     }
     cout <<"sum: "<< num << std::endl;

     return 1;
 }
