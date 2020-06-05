#include <iostream>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

/*
 * 首先排除掉空链表的情况
 * 然后使用STL的map 逐个扫描链表，
 * 记录下每个节点出现的次数，一旦某个节点出现两次，
 * 即可认为出现环
 * （吐槽一下这个题，题目描述都快看不懂了，pos明明不是参数
 * 所以，自己写测试的时候就按照无头节点链表来写，
 * 有没有出现环自己定）
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        map<ListNode*, int> mp;
        ListNode *p = head;
        while (p != NULL)
        {
            mp[p]++;
            if (mp[p] > 1)
                return true;

            p = p->next;
        }
        return false;
    }
};

int main()
{
    ListNode *head = NULL;
    ListNode *p = NULL;
    int num;

    for (int i = 0; i < 5; ++i)
    {
        cin >> num;
        if (head == NULL)
        {
            head = (ListNode*)malloc(sizeof(ListNode));
            head->val = num;
            head->next = NULL;
            p =  head;
        }
        else
        {
            ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
            temp->val = num;
            temp->next = NULL;
            p->next = temp;
            p = temp;
        }
    }
    //无头节点链表，head指针始终指向头部
    p = head;
    for (int i = 0; i < 5; ++i)
    {
        if (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
    cout << endl << endl;

    Solution s;
    bool flag = s.hasCycle(head);
    
    cout << flag << endl;

    //让p指针指向head的下一个节点，然后让p的next指针指向head
    //就构成一个环
    p = head->next;
    p->next = head;
    flag = s.hasCycle(head);

    cout << flag << endl;
    
    return 0;

}
