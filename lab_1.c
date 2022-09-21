#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

 struct node
{
        int info;
        struct node *next;
};

struct node *start=NULL;
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void readFromFile();
void deserialize(struct node** root);
void insert_end1(struct node** root, int value);
void serialize(struct node** root);
void reverse(struct node** head_ref);
void swap(struct node *a, struct node *b);
void Sort(struct node **start);
void search();
void joinTwoLists();

int main()     
{
        int choice;
        while(1){
               
                printf("\n Task Bar \n");
                printf(" 1.Create the linkedList \n");
                printf(" 2.Display \n");
                printf(" 3.Insert at the beginning \n");
                printf(" 4.Insert at the end  \n");
                printf(" 5.Insert at specified position \n");
                printf(" 6.Delete from beginning \n");
                printf(" 7.Delete from the end \n");
                printf(" 8.Delete from specified position \n");
                printf(" 9.Add saved numbers \n");
                printf(" 10.Save to file \n");
                printf(" 11.Reverse List \n");
                printf(" 12.Sort List \n");
                printf(" 13.Search for a value \n");
                printf(" 14.Join 2 LinkedLists \n");
                printf(" 15.Exit the program \n");
                printf("--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;
                        case 9:
                                        deserialize(&start);
                                        break;
                        case 10:
                                        serialize(&start);
                                        break;
                        case 11:
                                        reverse(&start);
                                        break;
			case 12:
                                        Sort(&start);
                                        break;
                        case 13:
                                        search();
                                        break;
                        case 14:
                                        joinTwoLists();
                                        break;
                        case 15:
                                        return 0;
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}

void create(){
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        int a;
        printf("\nEnter the initial number of emenets in the linkedList: ");
        scanf("%d", &a);
        for(int i = 1; i <= a; i++){
            insert_end();
        }
}

void display(){
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\t");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are: ");
                while(ptr!=NULL)
                {
                        printf("%d  ",ptr->info );
                        ptr=ptr->next;
                }
        }
}

void insert_begin(){
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL){
                start=temp;
        }
        else{
                temp->next=start;
                start=temp;
        }
}

void insert_end(){
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data value for the node:\t" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL){
                start=temp;
        }
        else{
                ptr=start;
                while(ptr->next !=NULL){
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos(){
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf("Enter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("Enter the data value of the node:\t");
        scanf("%d",&temp->info) ;
        temp->next=NULL;
        if(pos==0){
                temp->next=start;
                start=temp;
        }
        else{
                for(i=0,ptr=start;i<pos-1;i++) {
                    ptr=ptr->next;
                        if(ptr==NULL){
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void delete_begin(){
        struct node *ptr;
        if(ptr==NULL){
                printf("List is Empty:\n");
                return;
        }
        else{
                ptr=start;
                start=start->next ;
                printf("The deleted element is :%d\t",ptr->info);
                free(ptr);
        }
}
void delete_end(){
        struct node *temp,*ptr;
        if(start==NULL){
                printf("List is Empty:");
                exit(0);
        }
        else if(start->next ==NULL){
                ptr=start;
                start=NULL;
                printf("The deleted element is: %d\t",ptr->info);
                free(ptr);
        }
        else{
                ptr=start;
                while(ptr->next!=NULL){
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("The deleted element is: %d\t",ptr->info);
                free(ptr);
        }
}
void delete_pos(){
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL){
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else{
                printf("Enter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0){
                        ptr=start;
                        start=start->next ;
                        printf("The deleted element is:%d\t",ptr->info  );
                        free(ptr);
                }
                else{
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL){
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info );
                        free(ptr);
                }
        }
}

void insert_end1(struct node** root, int value) {
    struct node* new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node -> info = value;
    
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    
    struct node* curr = *root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

	void deserialize(struct node** root) {
    FILE* file = fopen("./saves.txt", "r");
    if (file == NULL) {
        exit(0);
    }

    int val;
    while(fscanf(file, "%d\n", &val) > 0) {
        insert_end1(root, val);
    }
    fclose(file);
    file = fopen("./saves.txt", "w");
    fclose(file);
}

void serialize(struct node** root) {
    FILE* file = fopen("./saves.txt", "w");
    if (file == NULL) {
        exit(1);
    }

    for (struct node* curr = *root; curr != NULL; curr = curr->next) {
        fprintf(file, "%d\n", curr->info);
    }
    fclose(file);
}

void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void Sort(struct node **start){ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = *start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->info > ptr1->next->info) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
void swap(struct node *a, struct node *b){ 
    int temp = a->info; 
    a->info = b->info; 
    b->info = temp; 
}

void search(){
	int a;
	bool b = false;
	printf("\nIntroduce the searced number: ");
	scanf("%d", &a);
    struct node *current = start;
    while (current != NULL) {
        if (current->info == a){
        	b = true;
        }
        current = current->next;
    }

    if(b){
		printf("\nThis number is present\n");
	}
	else{
		printf("\nThis number is not present\n");
	}
}

void joinTwoLists(){
	struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    int a;
    printf("\nEnter the initial number of numbers in the second linkedList: ");
    scanf("%d", &a);
    for(int i = 1; i <= a; i++){
   	printf("\nEnter the %d data value for the node:\t", i);
    scanf("%d",&temp->info);
    temp->next = NULL;
    insert_end1(&start, temp->info);
    }
}