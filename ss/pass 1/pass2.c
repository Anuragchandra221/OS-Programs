#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *finter,*fsym,*fop,*flen,*flisting,*fobj;
char label[10], opcode[10], operand[10], address[10],
     st_addr[10], length[10], size[10], t1[10], t2[10], t3[10], t4[10];
int o=-1, i, s=-1, ad, a, j;
struct optab{
    char opcode[10], hexcode[10];
}OT[30];
struct symtab{
    char label[10];
    char addr[10];
}ST[30];

void read_optab(){
    while(1){
        o++;
        // write opcode to structure opcode along with hex code
        fscanf(fop, "%s%s", OT[o].opcode, OT[o].hexcode);
        if(getc(fop)==EOF) break;
    }
}
void read_symtab(){
    while(1){
        s++;
        // write symbol to structure symbol along with address
        fscanf(fsym, "%s%s", ST[s].label, ST[s].addr);
        if(getc(fsym)==EOF) break;
    }
}
void read_line(){
    strcpy(t1, "");
    strcpy(t2, "");
    strcpy(t3, "");
    strcpy(t4, "");
    fscanf(finter, "%s", t1);
    if(getc(finter)!='\n'){
        fscanf(finter, "%s", t2);
        if(getc(finter)!='\n'){
            fscanf(finter, "%s", t3);
            if(getc(finter)!='\n'){
                fscanf(finter, "%s", t4);
            }
        }
    }
    if(strcmp(t1,"")!=0 && strcmp(t2, "")!=0 && strcmp(t3, "")!=0 && strcmp(t4, "")!=0){
        strcpy(address, t1);
        strcpy(label, t2);
        strcpy(opcode, t3);
        strcpy(operand, t4);
    }else if(strcmp(t1,"")!=0 && strcmp(t2, "")!=0 && strcmp(t3, "")!=0 && strcmp(t4, "")==0){
        strcpy(address, t1);
        strcpy(label, "");
        strcpy(opcode, t2);
        strcpy(operand, t3);
    }else if(strcmp(t1,"")!=0 && strcmp(t2, "")!=0 && strcmp(t3, "")==0 && strcmp(t4, "")==0){
        strcpy(address, t1);
        strcpy(label, "");
        strcpy(opcode, t2);
        strcpy(operand, "");
    }
}
int main(){
    
    finter = fopen("intermediate.txt","r");
    fsym = fopen("symtab.txt","r");
    fop = fopen("opcode.txt","r");
    flen = fopen("length.txt","r");
    flisting = fopen("listing.txt","w");
    fobj = fopen("objcode.txt","w");
    fscanf(flen,"%s%s", length, size);
    read_optab();
    for(i=0; i<=o; i++){
        printf("%s %s \n", OT[i].opcode, OT[i].hexcode);
    }
    read_symtab();
    for(i=0; i<=s; i++){
        printf("%s %s \n", ST[i].label, ST[i].addr);
    }
    fscanf(finter,"%s%s", opcode, operand);
    strcpy(st_addr, operand);

    if(strcmp(opcode, "START")==0){
        fprintf(flisting,"\t\t%s\t%s\n", opcode, operand);
        fprintf(fobj, "H^      ^00%s^0000%s\n", operand, length);
        fprintf(fobj,"T^00%s^%s",operand,size);
        read_line();
    }
    while(strcmp(opcode, "END")!=0){
        if(strcmp(opcode, "BYTE")==0){
            fprintf(flisting, "%s\t%s\t%s\t%s", address, label, opcode, operand);
            sprintf(&ad,"%x",operand[2]);
            fprintf(flisting,"%s\n",ad);
            fprintf(fobj, "^%s",ad);
        }else if(strcmp(opcode, "WORD")==0){
            sprintf(&a,"%x",atoi(operand));
            fprintf(flisting, "%s\t%s\t%s\t%s\t00000%s", address, label, opcode, operand, a);
            fprintf(fobj, "^00000%s",a);
        }else if(strcmp(opcode,"RESB")==0 || strcmp(opcode, "RESW")==0){
            fprintf(flisting, "%s\t%s\t%s\t%s", address, label, opcode, operand);
        }else{
            j = 0;
            while(strcmp(opcode, OT[j].opcode)!=0){
                j++;
            }
            i = 0;
            while(strcmp(operand, ST[i].label)!=0){
                i++;
            }
            fprintf(flisting, "%s\t%s\t%s\t%s\t%s%s\n", address, label, opcode, operand, OT[j].hexcode, ST[i].addr);
            fprintf(fobj, "^%s%s", OT[j].hexcode, ST[i].addr);
        }
        read_line();
    }
    fprintf(flisting, "\t%s\t%s\t%s", label, opcode, operand);
    fprintf(fobj, "\nE^00%s", st_addr);
    fclose(finter);
    fclose(fsym);
    fclose(fop);
    fclose(flen);
    fclose(flisting);
    fclose(fobj);
}