#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
/*The linked list to store the words and initiate count while adding nodes to the link list*/
typedef struct WNODE{
char word[70]; 
int count;
float freq;
int order;
int length;
struct WNODE *next;
}wordlist;


/*The linked list to store the charachters and initiate count while adding nodes to the link list*/
typedef struct CNODE{
char c;
    int count;
    float freq;
    int order;
    struct CNODE *next;
}charlist;

wordlist*headW=NULL; //wordlist type pointer variable to store the adress of the head adress of the words list created by the add node function
charlist*headC=NULL; //charlist type pointer variable to store the adress of the head adress of the charachter list created by the add node function
char buf[70]; //buffer char type variable to store a temperary word while reading from the given file
char *buf3; // buffer char pointer type variable to store the adress of a temporary word while processing


char *preprocess(char buf[]); //prototype of the function to preprocess while reading from file
int Wlen(char buf[]); //prototype of a function to caclulate the length of the words

void add_Wnodes( char *buf3,int len1); //prototype of the function to add words to to the linked list
void add_Cnodes( char ch); //prototype of the function to add charachters to to the linked list


wordlist *cal_Wfreq(wordlist * head); //prototype of a function to calculate the frequency of a particular word
charlist *cal_Cfreq(charlist * head); //prototype of the function to calculate the frequency of the charachters

wordlist *sort_Wlist(wordlist *head); //prototype of the function to sort the wordlist
charlist *sort_Clist(charlist *head); //prototype of the function to sort the charachter list

void printChart_Wnonscaled(wordlist *head); //prototype of the function to print the non scaled word chart
void printChartnonscaled(charlist *head); //prototype of the function to print the non scaled charachter chart
void printChart(charlist *head);   //prototype of the function to print the scaled word chart
void printChart_W(wordlist *head); //prototype of the function to print the scaled chart

int var=10; //initially the number of rows is set to 10 so if -l option is not given or in the default state chart of 10 rows are printed
int noNodes=0; //global variable of number of nodes set to zero
int max=0; //global variable of maximum length of the node set to zero

int main(int argc,char *argv[]){
  
char *files[100]; //local variable to store the file name
int count=0; //local variable to store the number of files set to zero
int size; //local variable to store the size of the file



for (int j=1;j<=argc-1;j++){ //a loop to iterate for number of arguments entered minus one

for(int i=1;i<=argc-1;i++){ //if both -c and -w are given as arguments then the following code block is executed
if((strcmp(argv[j],"-c"))==0 && (strcmp(argv[i],"-w"))==0){
    printf("[-c] and [-w] cannot use together\nusage: %s [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n",argv[0]);
    return 0;
}
}


   
if((strcmp(argv[j],"-l"))==0){ //if an argument of -l is entered the folllowing block is executed


    if(argc<=j+1){ //if -l is entered at the end of an argument then print the following error message
    printf("Not enough options for [-l]\nusage: %s [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n",argv[0]);
    return 0;
}
for(int i=0 ; i<strlen(argv[j+1]);i++){ //to check wether the argument entered after -l is a numeric
    if((argv[j+1][0]=='-')&& i==0){ //if the  argument after -l contains a - as the first element then the next iteration is called
        continue;
    }
    if(!isdigit(argv[j+1][i])){ //if the rest does not contain a digit then the following error message is printed
        printf("Invalid options for [-l]\nusage: %s [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n",argv[0]);
        return 0;
    }

}

if(argv[j+1][0]=='-'){ //if the condition after -l is - then it is displayed as a negative number 
    printf("Invalid option(negative) for [-l]\nusage: %s [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n",argv[0]);
    return 0;
}


var=atoi(argv[j+1]); //else var variable is assigned with the value after -l by converting it to an integer

continue;


}


else if((strcmp(argv[j],"-w"))==0){ 
    
 continue;

}else if((strcmp(argv[j],"-c"))==0){

continue;

}else if(strcmp(argv[j],"--scaled")==0){
    continue;

}



else if(argv[j][0]=='-'){ //if an invalid argument or flag is give then the following error message is printed
    printf("Invalid option %s\nusage: %s [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n",argv[j],argv[0]);
    return 0;
}else{ //all other arguments are considered as files
    if(strcmp(argv[j-1],"-l")==0){ //this is given inorder to avoid considering the number entered after -l to be considered as a file 
        continue;
    }
    files[count]=(char*)malloc(sizeof(strlen(argv[j]))); //memory is allocated to store the file names
    strcpy(files[count],argv[j]); //names of the files are copied
    count++; //number of files variable is incremented
}


if(var==0){ //if the condition or argument entered after -l is given as zero then the program is terminated
   return 0;
}





}if (count==0){ //if no files are given following code block is executed
    printf("No input files were given\nusage: %s [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n",argv[0]);
    return 0;
}

//for words

for(int i=1;i<=argc-1;i++){ //a loop to iterate for number of arguments entered minus one
if(strcmp(argv[i],"-w")==0){ //if the argument given contains a -w then the following code block is executed
FILE *filePointer; //FILE type pointer variables to store adresses of the files
FILE *fptr;
FILE *fileptr=NULL;
for(int j=0;j<count;j++) //loop to iterate for number of files times
{

    fptr = fopen(files[j], "r+"); //file is opened in read and modify mode
    if(fptr==NULL){ //if cannot open the files following error message is printed

    printf("Cannot open one or more given files\n");
    return 0;
    }
}
if(count==1){ //if an empty file is created and only this file is given as an argument following error message is printed
    
    fileptr=fopen(files[0],"r+"); 
    if(fileptr!=NULL){ 
        fseek (fileptr, 0, SEEK_END);
            size = ftell(fileptr);

    if (0 == size) {
        printf("No data to process\n");
        return 0;
}
    }

}

for(int i=0;i<count;i++){ //loop to iterate for number of files times
 
    
    

        filePointer = fopen(files[i], "r+"); //file is opened in read and modify mode

        if(filePointer!=NULL){
            
    
           while(1){ //while true (infinty loop)
fscanf(filePointer,"%s",buf); //scan word by word and assign inside buffer variable
if(feof(filePointer)){ //if the end of the file is reached terminate the process
    break;
}
int len1=Wlen(buf); //integer variable is assigned with the length of the buffer variable by a function to calculate the length of a word
buf3=preprocess(buf); //the word is preprocessed and the address is assigned to buf3 pointer variable
add_Wnodes(buf3,len1); //this word is added to a node in the link list created to store words

}

fclose(filePointer); //close file

}


}

cal_Wfreq(headW); //frequency is claculated of a word
sort_Wlist(headW); //word list is sorted

 for (int j=1;j<=argc-1;j++){ //if scaled option is given in any of the arguments the scaled version of the chart is printed
if((strcmp(argv[j],"--scaled"))==0)
{

     printChart_W(headW);
     return 0;

 }
 
}
printChart_Wnonscaled(headW); //else the non scaled version is printed

 return 0;

}
}

//for chars

for(int j=1;j<=argc-1;j++){
if(strcmp(argv[j],"-c")==0){ //if the argument given contains a -c then the following code block is executed
    FILE *filePointer; /* FILE type pointers define to store adresses of the file*/
    FILE *fptr=NULL; 
    FILE *fileptr=NULL;
for(int i=0;i<count;i++){ //loop for count number of times

    fptr = fopen(files[i], "r+"); //file is opened in read and modify mode
    if(fptr==NULL){ //if the file cannot be opened then the following erro message is printed

    printf("Cannot open one or more given files\n");
    return 0;

    }
}
if(count==1){ // if only one file is given and that file is empty then the following code block is executed
    
    fileptr=fopen(files[0],"r+");
    if(fileptr!=NULL){ //if the file can be opened and the size of the file is zero then the following message is printed
        fseek (fileptr, 0, SEEK_END);
            size = ftell(fileptr);

    if (0 == size) {
        printf("No data to process\n");
        return 0;
}
    }

}

for(int i=0;i<count;i++){ //loop for count number of times


filePointer = fopen(files[i], "r+");//read and modify
if(filePointer!=NULL){ //if the file can be opened then the followig code block is executed




char ch; //a char variable is declared to store each charachter one it is read from the file
ch = fgetc(filePointer); //each and every charachter read from the getc function is stored in ch variable
while (ch != EOF){ //until the file pointer reaches the end of the file the following instructions are executed
    if (isalnum(ch)){ //if the charachter is either a alphanumeric
       
       ch=tolower(ch); //charachter is converted to its lower case
    
    if(ch!=' '){ //if ch is not a space then it is added to a node in te charachter list
    add_Cnodes( ch);
}
}
ch = fgetc(filePointer); //the file pointer is shifted to the next charachter in the file

    }
     fclose(filePointer); //file is closed
 }
  

}

    cal_Cfreq( headC); //frequency of a charachter is calculated
    sort_Clist(headC); //charachter list is sorted
    for (int j=1;j<=argc-1;j++){ //loop until number of argument times minues one
if((strcmp(argv[j],"--scaled"))==0) //checked wether any of the argument given is equal to scaled
{

     printChart(headC); //if so the scaled version is printed
     return 0;
 }

 }
  printChartnonscaled(headC); //else the non scaled version is printed
 return 0;
}
        
}



//DEFAULT OPTION

FILE *filePointer;  /* FILE type pointers are declared to store adresses of the files */
FILE *fptr;
FILE *fileptr=NULL;
for(int j=0;j<count;j++){ //checked whether any given file can be opened or not 

    fptr = fopen(files[j], "r+");
    if(fptr==NULL){ //if the file cannot be opened then the following error message is printed

    printf("Cannot open one or more given files\n");
    return 0;
    }
    
}
if(count==1){ //if only one file is given and the file is empty the following message is displayed
   
    fileptr=fopen(files[0],"r+");
    if(fileptr!=NULL){
        fseek (fileptr, 0, SEEK_END);
            size = ftell(fileptr);

    if (0 == size) {
        printf("No data to process\n");
        return 0;
}
    }

}
for(int i=0;i<count;i++){ //loop untill count times




        filePointer = fopen(files[i], "r+"); //file is opened is read and modify mode

        if(filePointer!=NULL){ //if the file can be opened
            


           while(1){ //untill true (infinite loop)

fscanf(filePointer,"%s",buf);  //word by word is scanned and stored in the buffer variable
if(feof(filePointer)){ //if the end of the file is reached then the process is terminated
    break;
}
int len1=Wlen(buf); //length of the word is calculated
buf3=preprocess(buf); //word is undergone the process of preprocessing
add_Wnodes(buf3,len1); //then the word is added to the node in the word link list


}
fclose(filePointer); //close file
}


}
cal_Wfreq(headW); //calculate the frequency of the word
sort_Wlist(headW); //word list is sorted

 for (int j=1;j<=argc-1;j++){
if((strcmp(argv[j],"--scaled"))==0) //if the scaled option is given
{

     printChart_W(headW); //print the scaled version
     return 0;
 }
}

        printChart_Wnonscaled(headW); //else print the non scaled version
        return 0;



}

char *preprocess(char buf[]){ //function to preprocess the word stored in buffer
static char buf2[70]; //a static variable to return the preprocessed word
int i=0;
for(int j=0;buf[j]!='\0';j++){ //loop until end of word is done
if(isalnum(buf[j])){ //if it is an alphanumeric

buf2[i]=tolower(buf[j]);//then assign it to static variable by converting it to lower case
i++;
}
}
buf2[i]='\0';//assign the end of word symbol to every word stored in the static variable
return buf2 ;
}




int Wlen(char buf[]){  //function to find the length of the word
int len=0;
for(int j=0;buf[j]!='\0';j++){
if(isalnum(buf[j])){ //if the word is an alpha numeric then the len variable is incremented until end of word symbol is met
len++;
}

}
return len; // return the length of the word
}

void add_Wnodes( char *buf3,int len1){ //function to add nodes to the word list
  static int x=0; //initially a static variable x is declared

wordlist*p=NULL;// struct type pointer assigned to null initially
    wordlist *q=NULL;//assign a pointer to null
    if(headW==NULL){//if the list is empty then add the first node
    wordlist *temp=NULL;//a temporary pointer variable declared and assigned to null
temp=(wordlist*)malloc(sizeof(wordlist)); //memory is allocated to the temporary pointer of size struct wordlist
    if((strcmp(buf3,""))!=0){ //if the word in bufs is not empty then the following code block is executed
    strcpy(temp->word,buf3); //the word in the buf3 is copied to the word variable in temp node
    temp->length=len1; //length of the word is assigned to length variable in temp node
temp->count=1; //count is set to 1 in temp node
    x=1; //x is set to 1
    temp->order=x; //order in temp node is set to x
temp->next=NULL; //next variable in the temp node is set to null
headW=temp; //headw global variable is assigned the address of temp
}
   return ;
} // If the char is in the list, increment its count
p=headW; //p variable is assigned withe address of headw
while(p!=NULL){ //until the list reaches null the following code block is executed
            if((strcmp(p->word,buf3))==0){ //buf3 word is compared with the word variable in the list
                p->count++; //if the word is present alraedy in the list then the count of the corresponding node is incremented
                return;
           
            }
q=p; //q is assigned with address of p
p=p->next;// p is shifted to the next node
}//if word is not in the list then it is added to list
    wordlist *temp=NULL; //another temporary variable is declared
    temp=(wordlist*)malloc(sizeof(wordlist)); //memory is set
    if((strcmp(buf3,""))!=0){ /* the similar procedure done above to add a node is done below once again each time when a new word is added to the list*/
    strcpy(temp->word,buf3);
    temp->length=len1;
    temp->count=1;
    x++;
    temp->order=x;
    temp->next=NULL;
    q->next=temp;
   
}

}
void add_Cnodes( char ch){ /* function to add nodes to the charachter list */



//instructions are similar to that of add node function implemented to add words to the list


static int n=0;
charlist*p=NULL;
    charlist *q=NULL;
    if(headC==NULL){//if list is empty then create the first node
    charlist *temp=NULL;
temp=(charlist*)malloc(sizeof(charlist));
temp->c=ch;
temp->count=1;
    n=1;
    temp->order=n;
temp->next=NULL;
headC=temp;
   
    return ;
} //if char is already present increase the count
p=headC;
while(p!=NULL){
            if(p->c==ch){
                p->count++;
              return ;
           
            }
q=p;
p=p->next;
}//if char is not added earlier the create a new node and link the node to the list
    charlist *temp=NULL;
    temp=(charlist*)malloc(sizeof(charlist));
    temp->c=ch;
    temp->count=1;
    n=n+1;
    temp->order=n;
    temp->next=NULL;
    q->next=temp;  

}


wordlist *cal_Wfreq(wordlist * head){ //function to calculate the frequency 
  
     wordlist *p=headW;
     wordlist *q=head;

    float freq;

    float sum=0; //sum is set to zero intially
    while(q!=NULL){ //execute the following while q is not equal to NULL

      noNodes++; //no of nodes global variable is incremented in each iteration
sum=sum+q->count; //sum is equal to sum plus count variable in in q node
q=q->next; //q node is iterated
}

    while(p!=NULL){ 
freq=((p->count)*100)/sum; //algorithm to find the frequency of a word
p->freq=freq;  //freq variable in the p node is set with the calculated frequency above
p=p->next;//next frequency in the list is traveresed
}
return head; //head list containing the frequency variable in each node is returned
}


charlist *cal_Cfreq(charlist * head){ //function to calculate the frequency of each charachter

   //instrcutions are smilar to that of calculating frquency of a word function

     charlist *p=head;
     charlist *q=head;
    float freq;
    float sum=0;
     while(q!=NULL){
        sum=sum+q->count;
        q=q->next;
}
    while(p!=NULL){
freq=((p->count)*100)/sum;
p->freq=freq;
p=p->next;
}
return head;
}

wordlist *sort_Wlist(wordlist *head){//function to sort word list
    float t;//t variable to store the frequency of nodes
    int cnt; //int variable to store the count when swapping
    char cha[70]; //char array to copy the word in nodes when swapping
    int order1; //int variable store the order variable when swapping
    int len; //int variable to store when swapping
    wordlist *p=head;
    wordlist *current=NULL;
    while(p!=NULL){
      /* the algorithm corresponding in to sort a list is implemented below*/
        for(current=p->next;current!=NULL;current=current->next){
            if(current->freq>p->freq){//if the frequency of the current node is greater than the p node then the elements in those nodes are swapped
                t=p->freq;
                strcpy(cha,p->word);
                cnt=p->count;
                order1=p->order;
                len=p->length;

                p->freq=current->freq;
               strcpy(p->word,current->word);
                p->count=current->count;
                p->order=current->order;
                p->length=current->length;

                current->freq=t;
                strcpy(current->word,cha);  
                current->count=cnt;
                current->order=order1;
                current->length=len;
            } if(current->freq==p->freq){ //if the frequency of the current node is equal to that of the p node then the elements in those nodes are swapped
                if(current->order<p->order){
                t=p->freq;
                strcpy(cha,p->word);
                cnt=p->count;
                order1=p->order;
                len=p->length;

                p->freq=current->freq;
               strcpy(p->word,current->word);
                p->count=current->count;
                p->order=current->order;
                p->length=current->length;

                current->freq=t;
                strcpy(current->word,cha);  
                current->count=cnt;
                current->order=order1;
                current->length=len;;

                }
            }

        }
      p=p->next;  //next node is traveresed
    }

wordlist *r=head; //now the list is sorted therefore instructions to find the maximum length node is given below
int l;
int x=noNodes;
if(x>=var){
        l=var;

    }
    else{
        l=x;
    }

while(l>0){
   //algorithm to find the greatest element of element with the greatest length is implemented below
if(r->length>max){
max=r->length;
}
    l--;
r=r->next;
}

return head; //sorted list is returned


}


charlist *sort_Clist(charlist *head){//function to sort the char list

   //instructions to sort the char list is also similar to that of sorting the word list as above
    float t;
    int cnt;
    char cha;
    int order1;
    charlist *p=head;
    charlist *current=NULL;
    while(p!=NULL){
        for(current=p->next;current!=NULL;current=current->next){
            if(current->freq>p->freq){
                t=p->freq;
                cha=p->c;
                cnt=p->count;
                order1=p->order;

                p->freq=current->freq;
                p->c=current->c;
                p->count=current->count;
                p->order=current->order;

                current->freq=t;
                current->c=cha;
                current->count=cnt;
                current->order=order1;
            } if(current->freq==p->freq){
                if(current->order<p->order){
                t=p->freq;
                cha=p->c;
                cnt=p->count;
                order1=p->order;

                p->freq=current->freq;
                p->c=current->c;
                p->count=current->count;
                p->order=current->order;

                current->freq=t;
                current->c=cha;
                current->count=cnt;
                current->order=order1;


                }
            }

        }
      p=p->next;  
    }
return head;

}



void printChart(charlist *head){//function to print chart
charlist *p=head; //p pointer is assigned with chart head address
float m=p->freq; //m is assigned with the frequency of the p list
float n; //n variable declared to store frequencies of each charachters
while(var>0){

    if(p==NULL) break;
float t;
    
n=p->freq;
if((int)n==100){ //if only one word is present in the file then the following code block iis executed
   t=69;
}else if ((int)n>=10){ //if frequencies are greater than or equal to 10 then the following code block is executed
 t=70;
}else{// else the following is executed
    t=71;
}
for(int j=0;j<3;j++){ //loop to repeat thrice
if(j==1){ // when the second iteration process is happening(second sub row)
printf(" %c \u2502",p->c); //first the charachter is printed
for(int i=0;i<(int)((t/m)*n);i++){ //then according to the scaling algorithm number of boxes are printed

printf("\u2591");
}
printf("%.2f%%\n",p->freq); //then the frequency is printed
}else{ //the reamianing two iterations the following instrcution is given

printf("   \u2502"); //first a space is printed
for(int i=0;i<(int)((t/m)*n);i++){  //then according to the scaling algorithm first a line and boxes are printed
printf("\u2591");
}
printf("\n"); //after a new line
}}
printf("   \u2502");//a line is printed
printf("\n"); // new line
p=p->next; //travesed the list
var--; //var variable is decremented
}
printf("   \u2514"); //a L is printed finally
for(int i=0;i<76;i++){ //then 76 horizontal lines are printed
printf("\u2500");
}
printf("\n"); // new line
}
void printChart_W(wordlist *head){ //function to print word chart
 
//instructions are as above, the only change is the area to print the boxes are calculated after deducting the length of the maximum word in the list from the algorithm
wordlist *p=head;

float m=p->freq;
float n;
    
    
  
   
while(var>0){
    float t;
    if (p==NULL) break;
n=p->freq;
if((int)n==100){
   t=70;
}else if((int)n>=10){
    t=71;
}else if((int)n<10){
    t=72;
}

       for(int j=0;j<3;j++){
if(j==1){
printf(" %s",p->word);
for(int i=0;i<(max+1)-p->length;i++){
printf(" ");
}
printf("\u2502");


for(int i=1;i<=(int)(((t-max)/m)*n);i++){

printf("\u2591");
}
printf("%.2f%%\n",p->freq);
}else{
for(int i=0;i<max+2;i++){
printf(" ");
}

printf("\u2502");
for(int i=0;i<(int)(((t-max)/m)*n);i++){
printf("\u2591");
}
printf("\n");
}}
for(int i=0;i<max+2;i++){
printf(" ");
}

printf("\u2502");
printf("\n");
p=p->next;
var--;
}
for(int i=0;i<max+2;i++){
printf(" ");
}

printf("\u2514");
for(int i=0;i<80-(max+3);i++){
printf("\u2500");
}
printf("\n");
}



void printChartnonscaled(charlist *head){ //function to print a nonscaled charachter chart
   //instructions are similar to that of printing a scaled charachter chart , only difference is  the algorithm for non scaled is given here
charlist *p=head;
float m=p->freq;
float n;
while(var>0){

    if(p==NULL) break;
float t;
    
n=p->freq;
if (n>10){
 t=70;
}else{
    t=71;
}
for(int j=0;j<3;j++){
if(j==1){
printf(" %c \u2502",p->c);
for(int i=0;i<(int)((t*n)/100);i++){

printf("\u2591");
}
printf("%.2f%%\n",p->freq);
}else{

printf("   \u2502");
for(int i=0;i<(int)((t*n)/100);i++){
printf("\u2591");
}
printf("\n");
}}
printf("   \u2502");
printf("\n");
p=p->next;
var--;
}
printf("   \u2514");
for(int i=0;i<76;i++){
printf("\u2500");
}
printf("\n");
}

void printChart_Wnonscaled(wordlist *head){ //fucntion to print the non scaled word chart


   //instructions are similar to that of printing a scaled word chart , only difference is  the algorithm for non scaled is given here

wordlist *p=head;
     
float m=p->freq;
float n;
    
    
  
   
while(var>0){
    float t;
    if (p==NULL) break;
n=p->freq;
if(n>10){
    t=71;
}else{
    t=72;
}
       for(int j=0;j<3;j++){
if(j==1){
printf(" %s",p->word);
for(int i=0;i<(max+1)-p->length;i++){
printf(" ");
}
printf("\u2502");


for(int i=0;i<(int)(((t-max)*n)/100);i++){

printf("\u2591");
}
printf("%.2f%%\n",p->freq);
}else{
for(int i=0;i<max+2;i++){
printf(" ");
}

printf("\u2502");
for(int i=0;i<(int)(((t-max)*n)/100);i++){
printf("\u2591");
}
printf("\n");
}}
for(int i=0;i<max+2;i++){
printf(" ");
}

printf("\u2502");
printf("\n");
p=p->next;
var--;
}
for(int i=0;i<max+2;i++){
printf(" ");
}

printf("\u2514");
for(int i=0;i<80-(max+3);i++){
printf("\u2500");
}
printf("\n");
}