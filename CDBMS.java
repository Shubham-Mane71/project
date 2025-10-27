import java.util.Scanner;

class node
{
    private static int Counter = 1;

    public int Rno;
    public String Name;
    public String City;
    public int Marks;

    public node next;

    public node(String B, String C, int D)
    {
        Rno = Counter;
        Counter++;
        Name = B;
        City = C;
        Marks = D;
        next = null;
    }
}

class DBMS
{
    public node first;

    public DBMS()
    {
        first = null;
        System.out.println("DBMS initailised succesfully.....");
        System.out.println("Student Table gets created successfully....");
    }

    public void help()
    {
        System.out.println();
        System.out.println("SelectStarFrom          : Dispaly complete table..");
        System.out.println("SelectCount             : Count of the records..");
        System.out.println("SumMarks                : sum of marks..");
        System.out.println("AverageMarks            : Average of marks..");
        System.out.println("MinMarks                : Display minimum marks of all..");
        System.out.println("MaxMarks                : Display maximum marks of all..");
        System.out.println("manual                  : Dispaly Description and syntax for command..");
        System.out.println("DeleteFromTableWhere    : Delete record from table with help of Rno..");
        System.out.println("SelectStarFromWhereCity : Dispaly row with help of city name..");
        System.out.println("SelectStarFromWhereName : Display row with help of name..");
        System.out.println("Select                  : display specific column..");
        System.out.println("UpdateCity              : updat record with help of city name..");
        System.out.println("Insert_Into_Table       : insert record into table..");
        System.out.println();
    }

public void manual(String str)
    {
        if(str.equalsIgnoreCase("Insert_Into_Table"))
        {
            System.out.println("Description : insert record into table..");
            System.out.println("Usage       : Insert_Into_Table <Name> <City> <Marks> ");
        }
        else if(str.equalsIgnoreCase("SelectStarFrom"))
        {
            System.out.println("Description : Dispaly complete table..");
            System.out.println("Usage       : SelectStarFrom ");
        }
        else if(str.equalsIgnoreCase("Select"))
        {
            System.out.println("Description : display specific column..");
            System.out.println("Usage       : Select <Column_name> <Rno> ");
        }
        else if(str.equalsIgnoreCase("SelectStarFromWhereCity"))
        {
            System.out.println("Description : Dispaly row with help of city name..");
            System.out.println("Usage       : SelectStarFromWhereCity <city_name> ");
        }
        else if(str.equalsIgnoreCase("SelectStarFromWhereName"))
        {
            System.out.println("Description : Display row with help of name..");
            System.out.println("Usage       : SelectStarFromWhereName <name> ");
        }
        else if(str.equalsIgnoreCase("SelectCount"))
        {
            System.out.println("Description : Count of the records..");
            System.out.println("Usage       : SelectCount ");
        }
        else if(str.equalsIgnoreCase("SumMarks"))
        {
            System.out.println("Description : sum of marks..");
            System.out.println("Usage       : SumMarks ");
        }
        else if(str.equalsIgnoreCase("AverageMarks"))
        {
            System.out.println("Description : Average of marks..");
            System.out.println("Usage       : AverageMarks");
        }
        else if(str.equalsIgnoreCase("MinMarks"))
        {
            System.out.println("Description : Display minimum marks of all..");
            System.out.println("Usage       : MinMarks ");
        }
        else if(str.equalsIgnoreCase("MaxMarks"))
        {
            System.out.println("Description : Display maximum marks of all..");
            System.out.println("Usage       : MaxMarks ");
        }
        else if(str.equalsIgnoreCase("UpdateCity"))
        {
            System.out.println("Description : updat record with help of city name..");
            System.out.println("Usage       : UpdateCity <new_city_name> <Rno>");
        }
        else if(str.equalsIgnoreCase("DeleteFromTableWhere"))
        {
            System.out.println("Description : Delete record from table with help of Rno..");
            System.out.println("Usage       : DeleteFromTableWhere <rno> ");
        }
        else
        {
            System.out.println("ERROR : Command not found!!!");
        }
        System.out.println();
    }

    public void Insert_Into_Table(String Name, String City, int Marks)
    {
        node newn = new node(Name, City, Marks);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            node temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        System.out.println("One record gets inserted succesfully...");
    }

    public void SelectStarFrom()
    {
        System.out.println("Data from the table is : ");
        node temp = first;

        System.out.println("+---------------------------------------------------------------+");
        System.out.println("|"+ "RNo" +"\t|"+ "Name" +"   \t\t|"+ "City" +"   \t\t|"+ "Marks" + "\t|");
        System.out.println("+---------------------------------------------------------------+");
        while(temp != null)
        {
            System.out.println("|"+ temp.Rno +"\t|"+ temp.Name +"   \t\t|"+ temp.City +"   \t\t|"+ temp.Marks + "\t|");
            temp = temp.next;
        }
        System.out.println("+---------------------------------------------------------------+");
    }

    public void Select(String str,int rno)
    {
        node temp = first;

        while(temp.Rno != rno)
        {
            temp = temp.next;
        }

        if(str.equalsIgnoreCase("Name"))
        {
            System.out.println("+-------+");
            System.out.println("|"+temp.Name +"\t|");
            System.out.println("+-------+");
        }
        else if(str.equalsIgnoreCase("City"))
        {
            System.out.println("+-------+");
            System.out.println("|"+temp.City +"\t|");
            System.out.println("+-------+");
        }
        else if(str.equalsIgnoreCase("Marks"))
        {
            System.out.println("+-------+");
            System.out.println("|"+temp.Marks +"\t|");
            System.out.println("+-------+");
        }
    }

    public void SelectStarFromWhereCity(String str)
    {
            node temp = first;
            boolean record = false;

            System.out.println("+-------------------------------------------------------+");
            System.out.println("|"+ "Rno" +"\t|"+ "Name" +"   \t\t|"+ "City" +"\t|\t"+ "Marks" + "\t|");
            System.out.println("+-------------------------------------------------------+");
            while(temp != null)
            {
                if(temp.City.equalsIgnoreCase(str))
                {
                    System.out.println("|"+ temp.Rno +"\t|"+ temp.Name +"    \t\t|"+ temp.City +"\t|\t"+ temp.Marks + "\t|");
                    System.out.println("+-------------------------------------------------------+");
                    record = true;
                }
                temp = temp.next;
            }
    }

    public void SelectStarFromWhereName(String str)
    {
        node temp = first;
        boolean record = false;

        System.out.println("+-------------------------------------------------------+");
        System.out.println("|"+ "Rno" +"\t|"+ "Name" +"   \t\t|"+ "City" +"\t|\t"+ "Marks" + "\t|");
         System.out.println("+-------------------------------------------------------+");
        while(temp != null)
        {
            if(temp.Name.equalsIgnoreCase(str))
            {
                System.out.println("|"+ temp.Rno +"\t|"+ temp.Name +"    \t\t|"+ temp.City +"\t|\t"+ temp.Marks + "\t|");
                System.out.println("+-------------------------------------------------------+");
                record = true;
            }
            temp = temp.next;
        }
    }

    public int SelectCount()
    {
        int iCount = 0;
        node temp = first;

        while(temp != null)
        {
            iCount++;
            temp = temp.next;
        }
        return iCount;
    }

    public int SumMarks()
    {
        node temp = first;
        int iSum = 0;

        while(temp != null)
        {
            iSum += temp.Marks;
            temp = temp.next;
        }

        return iSum;
    }

    public float AverageMarks()
    {
        float Avg = 0;
        int iSum = SumMarks();
        int iCnt = SelectCount();

        Avg = (float)iSum / (float)iCnt;

        return Avg;
    }   

    public int MinMarks()
    {
        node temp = first;
        int Min = first.Marks;

        while(temp != null)
        {
            if(temp.Marks < Min)
            {
                Min = temp.Marks;
            }
            temp = temp.next;
        }
        return Min;
    }

    public int MaxMarks()
    {
        node temp = first;
        int Max = first.Marks;

        while(temp != null)
        {
            if(temp.Marks > Max)
            {
                Max = temp.Marks;
            }
            temp = temp.next;
        }
        return Max;
    }

    public void UpdateCity(String str, int rno)
    {
        node temp = first;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            if(temp.Rno == rno)
            {
                temp.City = str;
            }
            temp = temp.next;
        }
        System.out.println("Record updated successfully!");
        System.out.println("--------------------------------------------------------------");
    }

    public void DeleteFromTableWhere(int rno)
    {
        if (first == null)
        {
            System.out.println("ERROR: No records to delete!");
            return;
        }

        if (first.Rno == rno)
        {
            first = first.next;
            System.out.println("Record with Rno " + rno + " deleted successfully!");
            return;
        }

        node temp = first;
        while (temp.next != null)
        {
            if (temp.next.Rno == rno) 
            {
                temp.next = temp.next.next;
                System.out.println("Record with Rno " + rno + " deleted successfully!");
                return;
            }
            temp = temp.next;
        }

        System.out.println("ERROR: Record with Rno " + rno + " not found!");
    }
    
}


class CDBMS
{
    public static void main(String Arg[])
    {
        DBMS obj = new DBMS();
        String str = new String();
        Scanner sobj = new Scanner(System.in);
        int Count = 0, iRet = 0;
        float fRet = 0.0f;

        while(1 == 1)
        {
            System.out.print("Shubham sql > ");
            Count = 0;
            str = null;
            str = sobj.nextLine();

            String[] command = str.trim().split("\\s+");
            Count = command.length;

            if(Count == 1)
            {
                if(command[0].equalsIgnoreCase("SelectStarFrom"))
                {
                    obj.SelectStarFrom();
                    continue;
                }
                else if(command[0].equalsIgnoreCase("SelectCount"))
                {
                    iRet = obj.SelectCount();
                    System.out.println("+-------+");
                    System.out.println("|"+ "Count" +"\t|");
                    System.out.println("+-------+");
                    System.out.println("|"+ iRet +"\t|");
                    System.out.println("+-------+");
                    continue;
                }
                else if(command[0].equalsIgnoreCase("SumMarks"))
                {
                    iRet = obj.SumMarks();
                    System.out.println("+-------+");
                    System.out.println("|"+ "Sum" +"\t|");
                    System.out.println("+-------+");
                    System.out.println("|"+ iRet +"\t|");
                    System.out.println("+-------+");
                    continue;
                }
                else if(command[0].equalsIgnoreCase("AverageMarks"))
                {
                    fRet = obj.AverageMarks();
                    System.out.println("+-------+");
                    System.out.println("|"+ "Avg" +"\t|");
                    System.out.println("+-------+");
                    System.out.println("|"+ fRet +"\t|");
                    System.out.println("+-------+");
                    continue;
                }
                else if(command[0].equalsIgnoreCase("MinMarks"))
                {
                    iRet = obj.MinMarks();
                    System.out.println("+-------+");
                    System.out.println("|"+ "Min" +"\t|");
                    System.out.println("+-------+");
                    System.out.println("|"+ iRet +"\t|");
                    System.out.println("+-------+");
                    continue;
                }
                else if(command[0].equalsIgnoreCase("MaxMarks"))
                {
                    iRet = obj.MaxMarks();
                    System.out.println("+-------+");
                    System.out.println("|"+ "Max" +"\t|");
                    System.out.println("+-------+");
                    System.out.println("|"+ iRet +"\t|");
                    System.out.println("+-------+");
                    continue;
                }
                else if(command[0].equalsIgnoreCase("exit"))
                {
                    System.out.println("Exited from Database!!!");
                    System.out.println("Thank you for using shubham's student DB");
                    break;
                }
                else if(command[0].equalsIgnoreCase("cls"))
                {
                    System.out.println("Exited from Database!!!");
                    System.out.println("Thank you for using shubham's student DB");
                    break;
                }
                else if(command[0].equalsIgnoreCase("help"))
                {
                    obj.help();
                    continue;   
                }
                else 
                {
                    System.out.println("ERROR : Command does not found!!");
                    continue;
                }
            }
            else if(Count == 2)
            {
                if(command[0].equalsIgnoreCase("SelectStarFromWhereCity"))
                {
                    obj.SelectStarFromWhereCity(command[1]);
                    continue;
                }
                else if(command[0].equalsIgnoreCase("manual"))
                {
                    obj.manual(command[1]);
                    continue;
                }
                else if(command[0].equalsIgnoreCase("SelectStarFromWhereName"))
                {
                    obj.SelectStarFromWhereName(command[1]);
                    continue;
                }
                else if(command[0].equalsIgnoreCase("DeleteFromTableWhere"))
                {
                    obj.DeleteFromTableWhere(Integer.parseInt(command[1]));
                    continue;
                }
                else
                {
                    System.out.println("ERROR : Command does not found!!");
                    continue;
                }
            }
            else if(Count == 3)
            {
                if(command[0].equalsIgnoreCase("Select"))
                {
                    obj.Select(command[1],Integer.parseInt(command[2]));
                    continue;
                }
                else if(command[0].equalsIgnoreCase("UpdateCity"))
                {
                    obj.UpdateCity(command[1],Integer.parseInt(command[2]));
                    continue;
                }
            }
            else if(Count == 4)
            {
                if(command[0].equalsIgnoreCase("Insert_Into_Table"))
                {
                    obj.Insert_Into_Table(command[1],command[2],Integer.parseInt(command[3]));
                    continue;
                }
            }
        }
        
    }
}


/*
Supported Queries

1 : insert into student values('Amit','Pune',78);
2 : select * from student;
3 : slect *  from student where City = '_____';
4 : select Count(Marks) from student;
5 : select Sum(Marks) from student;
6 : select Avg(Marks) from student;
7 : select Max(Marks) from student;
8 : select Min(Marks) from student;
9 : select * from student where name = "_____";
10 : update student set City = "____" where Rno = ____;
11 : delete from student where Rno = ___;
12 : select ___ where Rno = __; 

*/