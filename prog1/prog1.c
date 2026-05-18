#include<stdio.h>
#include<stdlib.h>
struct records{
    int id;
    char name[20];
    float salary;
};
readrecords(struct records *r){
    printf("Enter the id:");
    scanf("%d",&r->id);
    printf("Enter the name:");
    scanf("%s",r->name);
    printf("Enter the salary:");
    scanf("%f",&r->salary);
}
display(struct records r){
    printf("Id:%d\n",r.id);
    printf("Name:%s\n",r.name);
    printf("Salary:%.2f\n",r.salary);
}
delete(struct records *r){
    r->id=0;
    r->name[0]='\0';
    r->salary=0.0;
}
countrecords(struct records *r,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(r[i].id!=0){
            count++;
        }
    }
    return count;
}
storerecords(struct records *r,int n){
    FILE *fp;
    fp=fopen("records.bin","wb");
    for(int i=0;i<n;i++){
        if(r[i].id!=0){
            fprintf(fp,"%d %s %.2f\n",r[i].id,r[i].name,r[i].salary);
        }
    }
    fclose(fp);
}
int main(){
    int n;
    printf("Enter the number of records:");
    scanf("%d",&n);
    struct records *r=(struct records*)malloc(n*sizeof(struct records));
    for(int i=0;i<n;i++){
        readrecords(&r[i]);
    }
    printf("Records:\n");
    for(int i=0;i<n;i++){
        display(r[i]);
    }
    printf("Number of records:%d\n",countrecords(r,n));
    storerecords(r,n);
    delete(r);
    free(r);
    return 0;
}