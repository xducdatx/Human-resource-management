/* CT TINH TIEN LUONG CHO NHAN VIEN */

#include<iostream>
#include<math.h>

using namespace std;

class NV
{
    private:
    int mnv;
    string name;
    string dob;
    public:
    NV(int mnv, string name, string dob)
    {
        this -> mnv = mnv;
        this -> name = name;
        this -> dob = dob;
    }
    virtual int sumSalary() = 0;
    virtual void display() = 0;
    void setMnv(int mnv)
    {
        this -> mnv = mnv;
    }
    int getMnv()
    {
        return mnv;
    }
    void setName(string name)
    {
        this -> name = name;
    }
    string getName()
    {
        return name;
    }
    void setDob(string dob)
    {
        this -> dob = dob;
    }
    string getDob()
    {
        return dob;
    }
};

class NVVP : public NV
{
    private:
    int numberOfWorkingDays;
    int basicSalaryNVVP;
    int subsidize;
    public:
    NVVP(int mnv, string name, string dob, int numberOfWorkingDays, int basicSalaryNVVP, int subsidize) : NV(mnv, name, dob)
    {
        this -> numberOfWorkingDays = numberOfWorkingDays;
        this -> basicSalaryNVVP = basicSalaryNVVP;
        this -> subsidize = subsidize;
    }
    int sumSalary()
    {
        return basicSalaryNVVP + numberOfWorkingDays * 220000 + subsidize;
    }
    void display()
    {
        cout << "mnv: " << getMnv() << endl;
        cout << "name: " << getName() << endl;
        cout << "dob: " << getDob() << endl;
        cout << "sumSalary: " << sumSalary() << endl;
    }
};

class NVSX : public NV
{
    private:
    int numberOfProduct;
    int basicSalaryNVSX;
    public:
    NVSX(int mnv, string name, string dob, int numberOfProduct, int basicSalaryNVSX) : NV(mnv, name, dob)
    {
        this -> numberOfProduct = numberOfProduct;
        this -> basicSalaryNVSX = basicSalaryNVSX;
    }
    int sumSalary()
    {
        return basicSalaryNVSX + numberOfProduct * 175000;
    }
    void display()
    {
        cout << "mnv: " << getMnv() << endl;
        cout << "name: " << getName() << endl;
        cout << "dob: " << getDob() << endl;
        cout << "sumSalary: " << sumSalary() << endl;
    }
};

class NVQL : public NV
{
    private:
    int coefficient;
    int basicSalaryNVQL;
    int bonus;
    public:
    NVQL(int mnv, string name, string dob, int coefficient, int basicSalaryNVQL, int bonus) : NV(mnv, name ,dob)
    {
        this -> coefficient = coefficient;
        this -> basicSalaryNVQL = basicSalaryNVQL;
        this -> bonus = bonus;
    }
    int sumSalary()
    {
        return basicSalaryNVQL * coefficient + bonus;
    }
    void display()
    {
        cout << "mnv: " << getMnv() << endl;
        cout << "name: " << getName() << endl;
        cout << "dob: " << getDob() << endl;
        cout << "sumSalary: " << sumSalary() << endl;
    }
};

void Swap(NV *nv1, NV *nv2)
{
    NV* temp = nv1;
    nv1 = nv2;
    nv2 = temp;
}
int main()
{
NV** nv = new NV* [6];
nv[0] = new NVVP(2114633, "SANG", "01/01/2003", 3, 3000000, 500000);
nv[1] = new NVVP(2114592, "QUY", "02/02/2003", 4, 3000000, 400000);
nv[2] = new NVSX(2114644, "SACH", "03/03/2003", 3, 4000000);
nv[3] = new NVSX(2115047, "TRANG", "04/04/2003", 7, 4000000);
nv[4] = new NVQL(2115103, "TRONG", "05/05/2003", 2, 5000000, 700000);
nv[5] = new NVQL(2115164, "TUAN", "06/06/2003", 3, 5000000, 800000);

for (int i = 0 ; i < 2; i ++)
{
    cout << i+1 << ": " << endl;
    nv[i] -> display();
}
for (int i = 2; i < 4; i++)
{
    cout << i+1 << ": " << endl;
    nv[i] -> display();
}
for (int i = 4; i < 6; i++)
{
    cout << i+1 << ": " << endl;
    nv[i] -> display();
}

cout << "Trung Binh Tien Luong Nhan Vien Van Phong: " << (nv[0] -> sumSalary() + nv[1] -> sumSalary()) / 2 << endl;
cout << "Trung Binh Tien Luong Nhan Vien San Xuat: " << (nv[2] -> sumSalary() + nv[3] -> sumSalary()) / 2 << endl;
cout << "Trung Binh Tien Luong Nhan Vien Quan Ly: " << (nv[4] -> sumSalary() + nv[5] -> sumSalary()) / 2 << endl;

/* Find mnv*/
int mnvFind = 2115164; // THANG TUAN;
for(int i = 0 ; i < 6; i++)
{
    if (nv[i] -> getMnv() == mnvFind)
    {
        nv[i] -> display();
    }
}

/* Find Max Salary*/

int position = 0;
int max = nv[0] -> sumSalary();
for (int i = 1; i < 6; i++)
{
    if (nv[i] -> sumSalary() > max)
    {
        max = nv[i] -> sumSalary();
        position = i;
    }
}
nv[position] -> display();

/*Delete nv theo mnv*/

// int mnvDelete = 2115047; // TRANG NV[3]
// for (int i = 0; i < 6; i ++)
// {
//     if (nv[i] -> getMnv() == mnvDelete)
//     {
//         delete []nv[i];
//     }
// }
// nv[3] -> display(); // LUC NAY KHONG CON THONG TIN NUA

for (int i = 0 ; i < 5; i++)
{
    for (int j = i + 1; j < 6 ; j++)
    {
        if(nv[i] -> sumSalary() > nv[j] -> sumSalary()) swap(nv[i], nv[j]);
    }
}

for (int i = 0 ; i < 2; i ++)
{
    cout << i+1 << ": " << endl;
    nv[i] -> display();
}
for (int i = 2; i < 4; i++)
{
    cout << i+1 << ": " << endl;
    nv[i] -> display();
}
for (int i = 4; i < 6; i++)
{
    cout << i+1 << ": " << endl;
    nv[i] -> display();
}
}