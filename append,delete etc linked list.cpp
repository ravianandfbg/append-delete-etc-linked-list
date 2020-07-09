#include<iostream>
using namespace std;
class linklist
{
private:
    struct node
    {
        int data;
        node *link;
    }*p;
public:
    linklist()
    void append(int num);
    void addafter(int c,int num);
    void del(int num);
    void display();
int count();
~linklist();
};
linklist::linklist()
{
    p=NULL;
}
void linklist::append(int num)
{
    node *q,*t;
    if(p==NULL)
    {
        p=new node;
        p->data=num;
        p->link=NULL;
    }
    else
    {
        q=p;
        while(q->link!=NULL)
            q=q->link;
        t=new node;
        t->data=num;
        t->link=NULL;
        q->link=t;
    }

    }
    void linklist::add_as_first(int num)
    {
        node *q;
        q=new node;
        q->data=num;
        q->link=p;
        p=q;
    }
    void linklist::addafter(int c,int num)
    {
        node *q,*t;
        int i;
        for(i=0,q=p;i<c;i++)
        {
            q=q->link;
            if(q==NULL)
            {
                cout<<"\nThere are less than"<<c<<"elements.";
                return;
            }
        }
        t=new node;
        t->data=num;
        t->link=q->link;
        q->link=t;
    }
    void linklist::del(int num)
    {
        node *q,*r;
        q=p;
        if(q->data==num)
        {
            p=q->link;
            delete q;
            return;
        }
        r=q;
        while(q!=NULL)
        {
            if(q->data==num)
            {
                r->link=q->link;
                delete q;
                return;
                }
                r=q;
                q=q->link;
        }
        cout<<"\nElement"<<num<<"not found";
    }
    void linklist::display()
    {
        node*q;
        cout<<endl;
        for(q=p;q!=NULL;q=q->link)
            cout<<endl<<q->data;
    }
    int linklist::count()
    {
        node *q;
        int c=0;
        for(q=p;q!=NULL;q=q->link)
            c++;
        return c;
    }
    linklist::~linklist()
    {
        node *q;
        if(p==NULL)
            return;
        while(p!=NULL)
        {
            q=p->link;
            delete p;
            p=q;
        }
    }
    int main()
    {
        linklist l;
        l.append(1);
        l.append(2);
        l.append(3);
        l.add_as_first(10);
        l.add_as_first(20);
        l.addafter(3,333);
        l.addafter(6,666);
        l.display();
        cout<<"\nNo. of elements: "<<l.count();
        l.del(333);
        l.del(12);
        l.del(98);
        cout<<"\nNo.of elements: "<<l.count();

    }


