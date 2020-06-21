#include <iostream>

using namespace std;
class subject
{
public:
    class Node
    {
    public:
        string sn;
        double total,point;
        char grade;
        Node*next;
    };
private:
    Node*head;
    Node*tail;
    int length;
public:
    subject()
    {
        head=NULL;
        tail=NULL;
        length=0;
    }
protected:
    void Sinsert(string name,double t,double p,char g,int index)
    {
        Node*newnode=new Node();
        newnode->grade=g;
        newnode->point=p;
        newnode->sn=name;
        newnode->total=t;
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            if(index==0)
            {
                newnode->next=head;
                head=newnode;
            }
            else
            {
                Node*prev=NULL;
                Node*curr=head;
                int counter=index;
                while(counter>0)
                {
                    prev=curr;
                    curr=curr->next;
                    counter--;
                }
                prev->next= newnode;
                newnode->next=curr;
            }

        }
    }
public:
    void cinsert(int NRC)
    {
        for(int i=0; i<NRC; i++)
        {
            string s;
            double a,c;
            char d;
            cout<<"enter the "<<i+1<<" subject name,grade,point and total"<<endl;
            cin>>s>>d>>a>>c;
            Sinsert(s,c,a,d,i);
        }

    }
    void sremove(string name)
    {
        string removed=name;
        Node*curr;
        Node*prev;
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;

        }
        else
        {
            if(head->sn==removed)
            {
                curr=head;
                head=head->next;
                delete curr;
            }
            else
            {
                curr=head->next;
                prev=head;
                while(curr!=NULL)
                {
                    if(curr->sn==removed)
                    {
                        break;
                    }
                    prev=curr;
                    curr=curr->next;
                }
                if(curr==NULL)
                {
                    cout<<"Not Found";

                }
                prev->next=curr->next;
                delete curr;
            }
        }
    }

    void display()
    {
        Node*curr = this->head;
        while(curr!=NULL)
        {
            cout<<curr->sn<<" "<<curr->grade<<" "<<endl;
            curr=curr->next;
        }

        cout<<endl;

    }
};
class student
{
    class Node
    {
    public:
        string name;
        string Department;
        int NRC;
        Node*next;
        subject A;
    };
private:
    Node*head,*tail;
    int length;
public:
    student()
    {
        head=NULL;
        tail=NULL;

    }
    void insertion(string N,string D,int num)
    {
        Node* node=new Node();
        node->name=N;
        node->Department=D;
        node->NRC=num;
        cout<<N << " , Please Enter your courses "<<endl;
        node->A.cinsert(num);
        node->next=NULL;
        if(head==NULL)
        {
            head=tail=node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }

    }

   void removing(string name)
    {
        string removed=name;
        Node*curr;
        Node*prev;
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        else
        {
            if(head->name==removed)
            {
                curr=head;
                head=head->next;
                delete curr;
                return;
            }
            else
            {
                curr=head->next;
                prev=head;
                while(curr!=NULL )
                {
                    if(curr->name==removed)
                    {
                        break;
                    }
                    prev=curr;
                    curr=curr->next;
                }
                if(curr==NULL)
                {
                    cout<<"Not Found";
                    return;
                }
                else{
                cout<<"Deleting : " <<curr->name <<endl;
                prev->next = curr->next;
                delete curr;
                }

            }
        }
    }

    void print()
    {
        Node*curr=head;
        if(curr == NULL)
            cout<<"Empty List"<<endl;
        while(curr!=NULL)
        {
            cout<<curr->name<<" "<<curr->Department<<" "<<curr->NRC<<" "<<endl;
            curr->A.display();
            curr=curr->next;

        }

        cout<<endl;

    }
};

int main()
{
    student s;

    s.insertion("Lina","IS",1);
    s.insertion("Rania","DS",1);
    s.insertion("Fatma","IT",1);
    s.insertion("Radwa","CS",1);
    s.print();
    cout<<endl;
    s.removing("Radwa");
     cout<<endl;
     s.removing("Ahmed");
     cout<<endl;
    s.print();
    return 0;
}
