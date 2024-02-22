#include <iostream>
using namespace std;

class node
{
    public:
    int bin;
    node *next, *prev;
};
class list
{
    public:
    node *msb, *lsb, *q, *q1, *temp, *newnode;
    list()
    {
        msb = NULL;
    }
    // ---------------------------------------
    void input(int n)
    {
        int rem;
        while (n != 0)
        {
            rem = n % 2;
            n = n / 2;
            newnode = new(node);
            newnode->bin = rem;
            // newnode->next = NULL;
            // newnode->prev = NULL;
            if (msb == NULL)
            {
                msb = newnode;
                msb->next = NULL;
                msb->prev = NULL;
            }
            else
            {
                newnode->next = msb;
                msb->prev = newnode;
                msb = newnode;
            }
        }
    }
    void inList(int n)
    {
        newnode = new(node);
        newnode->bin = n;
        // newnode->next = NULL;
        // newnode->prev = NULL;
        if (msb == NULL)
        {
            msb = newnode;
            msb->next = NULL;
            msb->prev = NULL;
        }
        else
        {
            newnode->next = msb;
            msb->prev = newnode;
            msb = newnode;
        }
    }
    // ---------------------------------------
    list operator + (list l2)   // binary operator overloading for 3 bit binary addition
    {
        list l3;
        q = msb;
        q1 = l2.msb;
        int carry = 0;
        while (q->next != NULL)
        {
            q = q->next;
        }
        while (q1->next != NULL)
        {
            q1 = q1->next;
        }
        while (q != NULL && q1 != NULL)
        {
            cout << "\nq->bin = " << q->bin << "\nq1->bin = " << q1->bin << "\ncarry = " << carry << "\nXOR = " << (q->bin ^ q1->bin ^ carry) << "\n\n";
            l3.inList(q->bin ^ q1->bin ^ carry); // 3 bit binary adder sum formula => a XOR b XOR c
            carry = ((q->bin & q1->bin) | (q1->bin & carry) | (carry & q->bin));    // 3 bit binary adder carry formula => ab+bc+ca
            q = q->prev;
            q1 = q1->prev;
        }
        while (q != NULL)
        {
            l3.inList(q->bin ^ carry);
            q = q->prev;
        }
        while (q1 != NULL)
        {
            l3.inList(q1->bin ^ carry);
            q1 = q1->prev;
        }
        l3.inList(carry);
        return l3;
    }
    // ---------------------------------------
    void displayBinary()
    {
        for (q = msb; q != NULL; q = q->next)
        {
            cout << q->bin;
        }
    }
    // ---------------------------------------
};
int main(int argc, char const *argv[])
{
    list l1, l2, l3;
    int n, ch;
    long int bin1, bin2;
    char opt;
    do
    {
        repeat:
        cout << "(1) Input Decimal Number\n";
        cout << "(2) Display Binary Number\n";

        cout << "(3) Binary Addition";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                cout << "\nEnter Decimal Number: ";
                cin >> n;
                l1.input(n);
                break;
            
            case 2:
                l1.displayBinary();
                break;
            
            case 3:
                cout << "Enter Number 1: ";
                cin >> bin1;
                l1.input(bin1);
                cout << "Binary Number 1: ";
                l1.displayBinary();

                cout << "\n\nEnter Number 2: ";
                cin >> bin2;
                l2.input(bin2);
                cout << "Binary Number 2: ";
                l2.displayBinary();
                cout << "\n\n";
                l1.displayBinary();
                cout << " + ";
                l2.displayBinary();
                cout << " = ";
                l3 = l1 + l2;
                l3.displayBinary();
                cout << "\n-----------------\n";
                break;
            
            default:
                cout << "\nInvalid Choice!\n";
                goto repeat;
        }
        cout << "\nContinue? (Y/N): ";
        cin >> opt;
    }
    while (opt == 'y' || opt == 'Y');
    return 0;
}
