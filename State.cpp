#include<iostream>
using namespace std;

struct State
{
    char Name[25];
    int Population;
    float lit_rate;
    float per_capita_income;
};

void get_info(struct State *St, int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        cout<<"\nState "<<i+1<<" : \n";
        fflush(stdin);
        cout<<"Enter the name of the state: ";
        gets((St+i)->Name);
        cout<<"Enter the Population of "<<(St+i)->Name<<" : ";
        cin>>(St+i)->Population;
        cout<<"Enter the Literacy rate of "<<(St+i)->Name<<" : ";
        cin>>(St+i)->lit_rate;
        cout<<"Enter the Per Capita Income of "<<(St+i)->Name<<" : ";
        cin>>(St+i)->per_capita_income;
    }
}

void display(struct State *St)
{
    cout<<"State Name: "<<St->Name<<endl;
    cout<<"Population: "<<St->Population<<endl;
    cout<<"Literacy Rate: "<<St->lit_rate<<endl;
    cout<<"Per Capita Income: "<<St->per_capita_income<<endl;
}

void High_lit(struct State *St, int num)
{
    int i = 0, pos;
    float temp_lit = St->lit_rate;
    for(i=1;i<num;i++)
    {
        if((St+i)->lit_rate > temp_lit)
        {
            temp_lit = (St+i)->lit_rate;
            pos = i;
        }
    }
    display(St+pos);
}

void High_percap(struct State *St, int num)
{
    int i = 0, pos;
    float temp_cap = St->per_capita_income;
    for(i=1;i<num;i++)
    {
        if((St+i)->per_capita_income > temp_cap)
        {
            temp_cap = (St+i)->per_capita_income;
            pos = i;
        }
    }
    display(St+pos);   
}

int main()
{
    int i;
    cout<<"How many states Data do you want to submit: ";
    cin>>i;
    struct State s[i];
    get_info(s, i);
    cout<<"\nTHE STATE WITH THE HIGHEST LITERACY RATE IS: "<<endl;
    High_lit(s, i);
    cout<<"\nTHE STATE WITH THE HIGHEST PER CAPITA INCOME IS:"<<endl;
    High_percap(s, i);
    return 0;
}
