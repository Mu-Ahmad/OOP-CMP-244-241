#include<iostream>

using namespace std;

class PersonData
{
    protected:
        string first_name, last_name, email, city /*No space..*/;
        unsigned int house_number;
        char block_name; // should be capital..
    public:
        PersonData(const string first_name = "", const string last_name = "", const string email = "", const string city ="", const unsigned int house_number = 0, const char block_name = 'A')
        {
            set_person(first_name, last_name, email, city, house_number, block_name);
        }

       void set_person(string first_name = "", string last_name = "", string email = "", string city ="", unsigned int house_number = 0, char block_name = 'A')
        {
            this->first_name = first_name;
            this->last_name = last_name;
            this->email = email;
            this->city = city;
            this->house_number = house_number;
            start:
            if(block_name >= 'A' && block_name <= 'Z')
                this->block_name = block_name;
            else
            {
                this->block_name = 'A';
            }
            
        }

        string get_first_name(void) const
        {
            return first_name;
        }

        string get_last_name(void) const
        {
            return last_name;
        }

        string get_email(void) const
        {
            return email;
        }
        
        string get_city(void) const
        {
            return city;
        }
        
        int get_house_number(void) const
        {
            return house_number;
        }
        
        char get_block_name(void) const
        {
            return block_name;
        }
        ~PersonData()
        {

        }
        friend ostream& operator << (ostream& out, const PersonData& p);
};

//Ostream Operators..
ostream& operator << (ostream& out, const PersonData& p)
{
    out<<"Name: "<<p.first_name<<" "<<p.last_name<<'\n';
    out<<"Email: "<<p.email<<'\n';
    out<<"City: "<<p.city<<"\n";
    out<<"House Number: "<<p.house_number<<"\n";
    out<<"Block Name: "<<p.block_name<<"\n";

    return out;
}

class CustomerData :public PersonData
{
    protected:
        static unsigned int customer_number;
        bool email_allowed;
    public:
        CustomerData(const string first_name = "", const string last_name = "", const string email = "", const string city ="", const unsigned int house_number = 0, const char block_name = 'A' , const bool email_allowed = false):PersonData(first_name, last_name, email, city, house_number, block_name)
        {
            set_customer_email(email_allowed);
            customer_number++;
        }
       void  set_customer_email(const bool email_allowed = false)
        {
            this->email_allowed = email_allowed;
        }

        bool get_email_allowed(void) const
        {
            return this->email_allowed;
        }

        static unsigned int get_customer_number(void) 
        {
            return customer_number;
        }

        ~CustomerData()
        {
            customer_number--;
        }

        friend ostream& operator<<(ostream& os, const CustomerData& data);

};

ostream& operator<<(ostream& os, const CustomerData& data)
{
    os<<"Customer Number:"<<data.customer_number<<'\n';
    if(data.email_allowed == true)
        os <<"Email:"<<"Subscribed to the Mailing List"<<'\n';
    else
         os <<"Email:"<<"Not Subscribed to the Mailing List"<<'\n';
    os<< (PersonData)data << '\n';
    return os;
}
int unsigned CustomerData::customer_number = 0; //static variable of the class CustomerData
int main(void)
{
   /* PersonData P("Arslan", "Ahmed", "emai", "Lahore", 128, 'A');
    cout << P;*/
    CustomerData C("Arslan", "Ahmed", "emai", "Lahore", 128, 'A', false);
    cout << C;
    return 0;
}