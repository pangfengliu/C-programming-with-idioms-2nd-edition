typedef struct employee {
	char first_name[32];
	char last_name[32];
	struct employee *boss;
} Employee;

int relation(Employee *employee1, Employee *employee2)
{
    Employee *emp1 = employee1;
    Employee *emp2 = employee2;
    
    
    while (emp1 -> boss != emp1){
        if (emp1 -> boss == employee2)
            return 1;
        else {
            emp1 = emp1-> boss;
        }
    }
    
    emp1 = employee1;
    emp2 = employee2;
   
    
    while (emp2 -> boss != emp2){
        if (emp2 -> boss == emp1)
            return 2;
        else {
            emp2 = emp2-> boss;
        }
    }
    
    emp1 = employee1;
    emp2 = employee2;
    
    while (emp1 -> boss != emp1){
        if (emp1-> boss == emp2-> boss)
            return 3;
        else {
            if(emp2-> boss == emp2){
                emp1 = emp1-> boss;
                emp2 = employee2;}
            else
                emp2 = emp2-> boss;
        }
    }
    return 4;

}
