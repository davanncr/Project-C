#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i;

struct Data{
    int id;
    int age;
    char name[20];
    char gender[10];
    char phone[20];
    char gmail[25];
    char position[20];
    float salary;
};
typedef struct Data DATA;
struct Node{
    DATA data;
    struct Node *next;
};
typedef struct Node NODE;
struct list{
    NODE *head;
    int n; // size of the list
};
typedef struct list LIST;
LIST* create_list(){
    LIST *list;
    list = (LIST*)malloc(sizeof(LIST));
    list->n = 0;
    list->head = NULL;
    return list;
} 
DATA create_data(int id,int age,char name[20],char gender[10],char phone[20],char gmail[25],char position[20],float salary){
       // DATA data={id,age,name,gender,phone,gmail,position,salary};
       DATA data;
       data.id=id;
       data.age=age;
       strcpy(data.name,name);
       strcpy(data.gender,gender);
       strcpy(data.phone,phone);
       strcpy(data.gmail,gmail);
       strcpy(data.position,position);
       strcpy(data.position,position);
       data.salary=salary;
    return data;
}
void menu(LIST *list);
// insert_front
void insert_front(LIST *list, DATA data){
    NODE *tmp;
    tmp = (NODE*)malloc(sizeof(NODE));
    tmp->data=data;
    tmp->next = list->head;
    list->head = tmp;
    list->n +=1;
}

// insert_end
void insert_end(LIST *list,DATA data){
    if (list->n==0) insert_front(list,data);
    else{
        NODE *tmp, *tail;
        tmp = (NODE*) malloc(sizeof(NODE));
        tmp->next = NULL;
        // Find the tail
        tmp->data=data;
        tail = list->head;
    while (tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = tmp;
    list->n += 1;
    }
}
LIST* maxID(LIST *list){
    
    int n=list->n;
    int arr[n];

}
void add(LIST *list);
void upload_to_file(LIST *list);
void print_list(){
    FILE* file=fopen("List.csv","r");
    DATA tmp;

    // if(file==NULL){
    // printf("Empty list\n");
    // }
    
    while(fread(&tmp,sizeof(DATA),1,file)!=NULL){
        printf("%d %d %s %s %s %s %s %.3f\n",tmp.id,tmp.age,tmp.name,tmp.gender,tmp.phone,tmp.gmail,tmp.position,tmp.salary);
    }
}
int main(){
    LIST * list;
    menu(list);
    return 0;
}  

/** 
 * ?menu function 
 */
void menu(LIST *list){
    int op;
    do{
        system("cls");
        printf("[1]. Add Employee\n");
        printf("[2]. List of All Employees\n");
        printf("[3]. Delete Employee\n");
        printf("Choose one option : ");scanf("%d",&op);
        switch(op){
            case 1:{
                add(list);
                break;
            }
            case 2:{
                print_list(list);
                break;
            }
            case 3:{
                delete_employee();
                break;
            }
            case 5:{
                exit(0);
            }
        }
        printf("Press Enter to Continue...\n");
    }while(getch() == 13);
}

/**
*   ? Add Employees
*/
void add(LIST *list){
    list=create_list();
    int id,age,n;
    char name[20],gender[10],phone[20],gmail[25],position[20];
    float salary;
    printf("Enter the numbers of Employees to add: ");scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter ID : ");scanf("%d",&id);
        printf("Enter AGE : ");scanf("%d",&age);
        fflush(stdin);
        printf("Enter NAME : ");gets(name);
        printf("Enter GENDER : ");gets(gender);
        printf("Enter PHONE : ");gets(phone);
        printf("Enter GMAIL : ");gets(gmail);
        printf("Enter POSITION : ");gets(position);
        printf("Enter SALARY : ");scanf("%f",&salary);
        insert_end(list,create_data(id,age,name,gender,phone,gmail,position,salary));
        //printf("%d - %d - %s - %s - %s - %s - %s -%0.2f",id,age,name,gender,phone,gmail,position,salary);
    }
    upload_to_file(list);

}

/**
* ? upload linked list to file
 */
void upload_to_file(LIST *list){

    FILE *f;
    f = fopen("List.csv", "a");
    for(i=0;i<list->n;i++){
        fwrite(&list->head->data,sizeof(DATA),1,f);
        list->head = list->head->next;
    }
    fclose(f);

}

void delete_employee(){
    LIST *list =create_list();
    int id;
    printf("Enter(ID):");
    scanf("%d",&id);
    FILE *f=fopen("List.csv","r");
    DATA data;
    while (fread(&data,sizeof(DATA),1,f))
    {
        insert_end(list,data);
    }
    fclose(f);
    FILE *fileW=fopen("List.csv","w");
    FILE *fileA=fopen("List.csv","a");
    FILE *fdl=fopen("ListDeleted.csv","a");
    while (list->head != NULL)
    {
        if(list->head->data.id == id){
           fwrite(&list->head->data,sizeof(DATA),1,fdl);
        }else{
            fwrite(&list->head->data,sizeof(DATA),1,fileA);
        }
        list->head=list->head->next;  
    }
    fclose(fileW);
    fclose(fileA);
    fclose(fdl);
}