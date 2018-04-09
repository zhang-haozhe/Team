//
//  main.cpp
//  pa2.cpp
//
//  Created by James Boultinghouse on 3/1/18.
//  Copyright © 2018 James Boultinghouse. All rights reserved.
//

#include <iostream>
#include "pa2.h"
using namespace std;
int algorithmUsed;

///*********PAGES********///
//Used as a boolean check for adding/removing programs before
//manipulating the linked list:
//Constructor:
Pages::Pages(): maxMemory(128) {memUsed = 0;}
//Adds the name, memory size, and number of pages used by a program once checking to
//see if there is enough pages/memory/the program has not been already added:
bool Pages::addPrgmMem(int programSize, string programName, int numPages){
    
    for(int i = 0; i < 32;i++) {
        if(programName == this->programName[i]){
            cout<<endl;
            cout<<"Error, Program "<<programName<<" already running."<<endl;
            return false;
        }
    }
    if(memUsed + programSize > maxMemory) {
        cout<<endl;
        cout<<"Error, Not enough memory for Program "<<programName<<endl;
        return false;
    }
    else if(pagesUsed + numPages > maxPages) {
        cout<<endl;
        cout<<"Error, Not enough pages for Program "<<programName<<endl;
        return false;
    }
    else {
        memUsed += programSize;
        pagesUsed += numPages;
        this->programMem[index] = programSize;
        this->programName[index] = programName;
        this->programPages[index] = numPages;
        index++;
        return true;
    }
}
//Deletes the name, memory size, and number of pages used by a program once
//checking to see if the program does exist:
bool Pages::deletePrgmMem(string programName) {
    for(int i = 0; i < 32; i++){
        if(this->programName[i] == programName) {
            
            this->programName[i] = "";
            memUsed = memUsed - programMem[i];
            pagesUsed = pagesUsed - programPages[i];
            
            cout<<endl;
            cout<<"Program "<<programName<<" succesfully killed, "<<programPages[i]<<" page(s) reclaimed."<<endl;
            
            programMem[i] = 0;
            programPages[i] = 0;
            return true;
        }
    }
    return false;
}
///*********LIST********///
//Constructor:
List::List(){ this->head = NULL; }
//Sets the default value of the 32 node linked list to "Free":
void List::addFreePages(string programName) {
    if(head==NULL){
        head = new Node();
        head->value = programName;
        size++;
        return;
    }
    
    Node * temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
        
    }
    temp->next=new Node();
    temp->next->value=programName;
    size++;
}
//Chooses between the worst and best algorithm for adding programs:
void List::addProgram(string programName, int numPages){
    if(algorithmUsed==1){bestAddProgram(programName, numPages);}
    else if(algorithmUsed==2){worstAddProgram(programName, numPages);}
}
//Adds program to the smallest segment of free memory possible:
void List::bestAddProgram(string programName, int numPages){
    Node * temp = head;
    Node * addProgram = head;
    int freeFrags = amountOfFreeFrags();
    
    int StartIndexFreeFrags[freeFrags];
    int EndIndexFreeFrags[freeFrags];
    
    int lengthFreeFrags[freeFrags];
    int minLength = 32;
    int indexOfMin = 0;
    
    //If there is only one free fragment, then add
    //program to the set of already added programs:
    if(freeFrags==1) {
        for(int i = 0; i < numPages; i++) {
            while(temp->value != "Free") {
                temp = temp->next;
            }
            temp->value = programName;
            temp = temp->next;
        }
    }
    //For more than one free fragment, use the algorithm:
    else if(freeFrags > 1) {
        //Finds the starting and ending index of every free fragment:
        for(int i = 0; i <freeFrags; i++ ) {
            if(i == 0) {
                StartIndexFreeFrags[0] = startIndOfFF(0);
                EndIndexFreeFrags[0] = endIndOfFF(0);
            }
            else {
                StartIndexFreeFrags[i] = startIndOfFF(StartIndexFreeFrags[i-1]);
                EndIndexFreeFrags[i] = endIndOfFF(EndIndexFreeFrags[i-1]);
            }
        }
        //Finds the length of each fragment:
        for(int i = 0; i <freeFrags; i++) {
            lengthFreeFrags[i] = EndIndexFreeFrags[i] - StartIndexFreeFrags[i];
        }
        //Compares the length of each free fragment until the smallest one to
        //fit the program is obtained:
        for(int i = 0; i <freeFrags; i++) {
            if((lengthFreeFrags[i] < minLength) && (lengthFreeFrags[i] >= numPages)) {
                minLength = lengthFreeFrags[i];
                indexOfMin = StartIndexFreeFrags[i];
            }
        }
        //Takes the linked list to the index of the best free fragment:
        for(int i = 0; i < indexOfMin; i++) {
            addProgram = addProgram->next;
        }
        //Adds the program based on its number of pages:
        for(int i = 0; i < numPages; i++) {
            addProgram->value = programName;
            addProgram = addProgram->next;
        }
    }
}
//Adds program to the largest segment of free memory possible:
//(Comments are the same as the Best Algorithm except for comparing
//the lengths of the free fragments)
void List::worstAddProgram(string programName, int numPages){
    Node * temp = head;
    Node * addProgram = head;
    int freeFrags = amountOfFreeFrags();
    
    int StartIndexFreeFrags[freeFrags];
    int EndIndexFreeFrags[freeFrags];
    
    int lengthFreeFrags[freeFrags];
    int maxLength = 0;
    int indexOfMax = 0;
    
    if(freeFrags==1) {
        for(int i = 0; i < numPages; i++) {
            while(temp->value != "Free") {
                temp = temp->next;
            }
            temp->value = programName;
            temp = temp->next;
        }
    }
    else if(freeFrags > 1) {
        
        for(int i = 0; i <freeFrags; i++ ) {
            if(i == 0) {
                StartIndexFreeFrags[0] = startIndOfFF(0);
                EndIndexFreeFrags[0] = endIndOfFF(0);
            }
            else {
                StartIndexFreeFrags[i] = startIndOfFF(StartIndexFreeFrags[i-1]);
                EndIndexFreeFrags[i] = endIndOfFF(EndIndexFreeFrags[i-1]);
            }
        }
        
        for(int i = 0; i <freeFrags; i++) {
            lengthFreeFrags[i] = EndIndexFreeFrags[i] - StartIndexFreeFrags[i];
        }
        //Compares the length of each free fragment until the largestt one to
        //fit the program is obtained:
        for(int i = 0; i <freeFrags; i++) {
            if((lengthFreeFrags[i] > maxLength) && (lengthFreeFrags[i] >= numPages)) {
                maxLength = lengthFreeFrags[i];
                indexOfMax = StartIndexFreeFrags[i];
            }
        }
        for(int i = 0; i < indexOfMax; i++) {
            addProgram = addProgram->next;
        }
        for(int i = 0; i < numPages; i++) {
            addProgram->value = programName;
            addProgram = addProgram->next;
        }
    }
}
//Deletes a specified program:
void List::deleteProgram(string programName) {
    Node * temp = head;
    while(temp!=NULL) {
        if(temp->value == programName) {
            temp->value = "Free";
        }
        temp = temp->next;
    }
}
//Finds the number of continguous segments of used memory:
int List::amountOfFrags(){
    int frags = 0;
    Node * temp1 = head;
    Node * temp2 = head->next;
    while(temp2!=NULL){
        if((temp1->value != "Free") && (temp2->value == "Free" || temp2==NULL)){
            frags++;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return frags;
}
//Finds the number of continguous segments of free memory:
int List::amountOfFreeFrags(){
    int freeFrags = 1;
    Node * temp1 = head;
    Node * temp2 = head->next;
    while(temp2!=NULL){
        if((temp1->value == "Free") && (temp2->value != "Free")){
            freeFrags++;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(freeFrags==0) { freeFrags = 1; }
    
    return freeFrags;
}
//Finds the starting index of a contiguous segment of free memory:
int List::startIndOfFF(int lastStartIndex) {
    Node * temp = head;
    int startIndex = 1;
    for(int i = 0; i < lastStartIndex; i++) {
        temp = temp->next;
    }
    
    while(temp!=NULL) {
        if(temp->value != "Free" && temp->next->value == "Free" ) {
            break;
        }
        else if(lastStartIndex == 0 && temp->value == "Free") {
            break;
        }
        temp= temp->next;
        startIndex++;
    }
    return lastStartIndex + startIndex;
}
//Finds the ending index of a contiguous segment of free memory:
int List::endIndOfFF(int lastEndIndex) {
    Node * temp = head;
    int endIndex = 1;
    
   // if(lastEndIndex != 0 ) {
        for(int i = 0; i < lastEndIndex; i++) {
            temp = temp->next;
        }
    //}
    while(temp->next!=NULL) {
        if(temp->value == "Free" && (temp->next->value != "Free" || temp->next == NULL)) {
            break;
        }
        temp=temp->next;
        endIndex++;
    }
    return lastEndIndex + endIndex;
}
//Prints the values within the linked list:
void List::print(){
    
    Node* temp = head;
    int newLine = 1;
    
    while(temp!=NULL){
        cout<<temp->value;
        int numSpaces = 8 - (int)temp->value.length();

        for (int i = 0; i <numSpaces; i++) {
            cout<<" ";
        }
        temp=temp->next;
        if(newLine == 8){
            cout<<endl;
            newLine = 0;
        }
        newLine++;
    }
}
///*******MAIN******///
//Includes the menu and ability to add, delete, and check programs:
int main(int argc, const char * argv[]) {
    
    
    //MUST take in command line argument to work:
    if(argc == 1) {
        cout<<"?????"<<endl;
        algorithmUsed = 1;
    } else if(strcmp(argv[1], "worst") == 0) {
        algorithmUsed = 2;
    } else if(strcmp(argv[1], "best") == 0){
        algorithmUsed = 1;
    }
    
    List * linkedList = new List();
    Pages * programs = new Pages();
    int const listSize = 32;
    int programSize, frags, numPages;
    int menOption = 0;
    string programName;
    bool exitProgram = false;
    
    for(int i = 0; i < listSize;i++){
        linkedList->addFreePages("Free");
    }
    
    //Menu
    
    cout<<"    1. Add program"<<endl;
    cout<<"    2. Kill program"<<endl;
    cout<<"    3. Fragmentation"<<endl;
    cout<<"    4. Print Memory"<<endl;
    cout<<"    5. Exit"<<endl;

    while(!exitProgram) {
        
        cout<<endl;
        
        cout<<"choice - ";
        cin>>menOption;
        cout<<endl;
        while(cin.fail()) {
            cin.clear();
            cin.ignore(100000, '\n');
            cout<<"Invalid input. Please try again."<<endl<<endl;
            cout<<"choice - ";
            cin>>menOption;
            cout<<endl;
        }
        
        switch(menOption) {
            case 1:
                //No spaces when inputting program name here:
                cout<<"Program name - ";
                cin>>programName;
                cout<<"Program size (KB) - ";
                cin>>programSize;
                
                while(cin.fail()) {
                    cin.clear();
                    cin.ignore(100000, '\n');
                    cout<<endl;
                    cout<<"Invalid input. Please try again."<<endl<<endl;
                    cout<<"Program size (KB) - ";
                    cin>>programSize;
                }
                
                if(programSize % 4 == 0) {numPages = programSize / 4;}
                else{numPages = (programSize / 4) + 1;}
                
                if(programs->addPrgmMem(programSize, programName, numPages)) {
                    linkedList->addProgram(programName, numPages);
                    cout<<endl;

                    cout<<"Program "<<programName<<" added successfully: "<<numPages<<" page(s) used."<<endl;
                }
                break;
            case 2:
                //No spaces when inputting program name here:
                cout<<"Program name - ";
                cin>>programName;
                
                if(programs->deletePrgmMem(programName)) {
                    linkedList->deleteProgram(programName);
                } else {
                    cout<<endl;
                    cout<<"Error, Program "<<programName<<" not found."<<endl;
                }
                
                break;
            case 3:
                frags = linkedList->amountOfFrags();
                cout<<"There are " <<frags<<" fragment(s)."<<endl;
                break;
            case 4:
                linkedList->print();
                break;
            case 5:
                exitProgram = true;
                break;
            default:
                cout<<"Invalid input. Please try again."<<endl;
                break;
        }
    }
    return 0;
}
