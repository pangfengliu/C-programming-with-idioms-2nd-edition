typedef struct employee {
	char first_name[32];
	char last_name[32];
	struct employee *boss;
} Employee;

int relation(Employee *employee1, Employee *employee2)
{
    Employee *A = employee1;
    Employee *B = employee2; 
    while (A->boss!=A) {
          if (A->boss==employee2) return 1;
          else { 
          A = A->boss;
          }
          }
    
             A = employee1;
             B = employee2;
             while (B->boss!=B) {
                  if (B->boss==A) return 2;
                  else { 
                  B = B->boss;
                  }
                  } 
                 A = employee1;
                 B = employee2; 
                 while (A->boss!=A) {
                 if (A->boss==B->boss) return 3;
                 else {
                      if (B->boss==B){A = A->boss; B=employee2;}
                      else
                      B = B->boss;
                      }
                 }

return 4;
}
