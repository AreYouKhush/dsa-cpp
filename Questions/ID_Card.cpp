#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class ID_Card
{
    char name[25], branch[10], section[3];
    int rollno;
    public:
    int insert(class ID_Card *ptr, int size, int init)
    {
        int j=init;
        for(;init<size;init++)
        {
            cout<<"\nDetails of Student "<<init+1<<" : "<<endl;
            fflush(stdin);
            cout<<"Name : ";
            gets((ptr+init)->name);
            cout<<"Roll Number : ";
            cin>>(ptr+init)->rollno;
            cout<<"Branch : ";
            cin>>(ptr+init)->branch;
            cout<<"Section : ";
            cin>>(ptr+init)->section;
            j++;
        }       
        return j;
    }

    void details(class ID_Card *ptr, int size)
    {
        int i;
        for(i=0;i<size-1;i++)
        {
            cout<<"\nDetails of Student "<<i+1<<" : "<<endl;
            cout<<"Name : "<<(ptr+i)->name<<endl;
            cout<<"Roll Number : "<<(ptr+i)->rollno<<endl;
            cout<<"Branch : "<<(ptr+i)->branch<<endl;
            cout<<"Section : "<<(ptr+i)->section<<endl;
        }
    }

    void update(class ID_Card *ptr, int rollnum, int size)
    {
        for(int i = 0; i<size;i++)
        {
            if (rollnum == (ptr+i)->rollno)
            {
                fflush(stdin);
                cout<<"Name : ";
                gets((ptr+i)->name);
                cout<<"Roll Number : ";
                cin>>(ptr+i)->rollno;
                cout<<"Branch : ";
                cin>>(ptr+i)->branch;
                cout<<"Section : ";
                cin>>(ptr+i)->section;
            }
        }
    }

    // void deleteStudent(class ID_Card *ptr, int rollnum, int size)
    // {
    //     for(int i = 0; i<size;i++)
    //     {
    //         if (rollnum == (ptr+i)->rollno)
    //         {   
    //             //HELP ME!!!
    //         }
    //     }
    // }
};
int main()
{
    ID_Card *s;
    int size, i, choice, init = 0;
    cout<<"Enter the number of students: ";
    cin>>size;
    s = new ID_Card[size];
    do
    {   
        switch (choice)
        {
            case 1: init = s->insert(s, size, init);
                    size++;
                    break;
            case 2: int rollnum;
                    cout<<"Enter the roll number to be updated: ";
                    cin>>rollnum;
                    s->update(s, rollnum, size);
                    break;
            case 3: delete [] s;
                    break;
            case 4: s->details(s, size);
                    break;
        }
        cout<<"\nChoose an Option:\nPress 1 to insert.\nPress 2 to Update.\nPress 3 to Delete.\nPress 4 to Display."<<endl;
        cin>>choice;
    } while (choice != 5);
    return 0;
}