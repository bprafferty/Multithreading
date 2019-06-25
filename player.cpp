/************************************************************
 Name: Brian Rafferty -- cssc0852 -- redID: 816988452
 Class: CS 570, Summer 2019
 Project: Program Assignment #1 -- Multithreading
 File: player.cpp
 Notes: This is the source code for a program that creates 4
        threads that run concurrently. Each thread is scheduled
        to run at a different speed, and they are managed through 
        the use of semaphores. Each thread acts as a mini process
        that prints the current card in the hand of the player
        until all 4 threads have exhausted their portion of the
        deck. Once the cards have all been printed to the output
        file, a message is printed to the console.
*************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

#define THREAD_COUNT 4

sem_t FLAG;
int errorNo;

string fileName = "STACK.txt";
ofstream outputFile;
string cards[14] = {"A", "2", "3", "4", "5", "6", "7",
                        "8", "9", "10", "J", "Q", "K"};

/************************************************************
 FUNCTION: checkErr
 DESCRIPTION: Receives the error number from sections of code
                that need to make sure that all system calls
                were successful. 
 I/O:   Input: int
        Output: void
*************************************************************/
void checkErr(int errorNo) {
    if (errorNo != 0) {
        cout << "ErrorNo other than zero: " << errorNo << endl;
        exit(0);
    }
}

/************************************************************
 FUNCTION: printDiamond
 DESCRIPTION: If the thread id is 0, then it waits 125 msec
                and places the semaphore in the critical
                section. If no errors occurred with the
                system call, then the thread will execute
                by printing to the console indicating success
                and printing to the file STACK.txt with the
                next Diamond card. Once completed, execution
                is stopped by raising the semaphore back out
                of the critical section before closing the file.
 I/O:   Input: int
        Output: void
*************************************************************/
void printDiamond(int id) {
    
    for (int i = 0; i < 13; i++){
        usleep(125000);
        errorNo = sem_wait(&FLAG);
        checkErr(errorNo);
        cout << "Thread " << id << " is running"<< endl;
        outputFile.open(fileName.c_str(), fstream::in | fstream::app);
        outputFile << "Diamond " << cards[i] << endl;
        errorNo = sem_post(&FLAG);
        checkErr(errorNo);
        outputFile.close();
        
    }
    
}

/************************************************************
 FUNCTION: printClub
 DESCRIPTION: If the thread id is 1, then it waits 250 msec
                and places the semaphore in the critical
                section. If no errors occurred with the
                system call, then the thread will execute
                by printing to the console indicating success
                and printing to the file STACK.txt with the
                next Diamond card. Once completed, execution
                is stopped by raising the semaphore back out
                of the critical section before closing the file.
 I/O:   Input: int
        Output: void
*************************************************************/
void printClub(int id) {
 
    for (int i = 0; i < 13; i++){
        usleep(250000);
        errorNo = sem_wait(&FLAG);
        checkErr(errorNo);
        cout << "Thread " << id << " is running"<< endl;
        outputFile.open(fileName.c_str(), fstream::in | fstream::app);
        outputFile << "Club " << cards[i] << endl;
        errorNo = sem_post(&FLAG);
        checkErr(errorNo);
        outputFile.close();
        
    }
    
}

/************************************************************
 FUNCTION: printHeart
 DESCRIPTION: If the thread id is 2, then it waits 500 msec
                and places the semaphore in the critical
                section. If no errors occurred with the
                system call, then the thread will execute
                by printing to the console indicating success
                and printing to the file STACK.txt with the
                next Diamond card. Once completed, execution
                is stopped by raising the semaphore back out
                of the critical section before closing the file.
 I/O:   Input: int
        Output: void
*************************************************************/
void printHeart(int id) {
   
    for (int i = 0; i < 13; i++){
        usleep(500000);
        errorNo = sem_wait(&FLAG);
        checkErr(errorNo);
        cout << "Thread " << id << " is running"<< endl;
        outputFile.open(fileName.c_str(), fstream::in | fstream::app);
        outputFile << "Heart " << cards[i] << endl;
        errorNo = sem_post(&FLAG);
        checkErr(errorNo);
        outputFile.close();
        
    }
    
}

/************************************************************
 FUNCTION: printSpade
 DESCRIPTION: If the thread id is 3, then it waits 750 msec
                and places the semaphore in the critical
                section. If no errors occurred with the
                system call, then the thread will execute
                by printing to the console indicating success
                and printing to the file STACK.txt with the
                next Diamond card. Once completed, execution
                is stopped by raising the semaphore back out
                of the critical section before closing the file.
 I/O:   Input: int
        Output: void
*************************************************************/
void printSpade(int id) {
    
    for (int i = 0; i < 13; i++){
        usleep(750000);
        errorNo = sem_wait(&FLAG);
        checkErr(errorNo);
        cout << "Thread " << id << " is running"<< endl;
        outputFile.open(fileName.c_str(), fstream::in | fstream::app);
        outputFile << "Spade " << cards[i] << endl;
        errorNo = sem_post(&FLAG);
        checkErr(errorNo);
        outputFile.close();
        
    }
    
}

/************************************************************
 FUNCTION: getCard
 DESCRIPTION: Converts the thread's address into its id by
                casting it as a long. The id is then passed
                to its corresponding print method.
 I/O:   Input: void*
        Output: void
*************************************************************/
void *getCard(void *threadPointer) {
    long id;
    id = (long)threadPointer;

    if (id == 0) {
        printDiamond(id);
    }
    else if (id == 1) {
        printClub(id);
    }
    else if (id == 2) {
        printHeart(id);
    }
    else {
        printSpade(id);
    }
    
    return NULL;
}

/************************************************************
 FUNCTION: createFile
 DESCRIPTION: Creates the file STACK.txt and checks to see
                if it opened correctly. If the file is set up
                properly, then it prints the Process ID to
                the first line of the file and then closes it.
 I/O:   Input: string
        Output: void
*************************************************************/
void createFile(string file){
    outputFile.open(file.c_str());
    if (outputFile.good()){
        outputFile << getpid() << endl;
    }
    else {
        cout << "Error creating file." << endl;
        exit(0);
    }
    outputFile.close();
}

/************************************************************
 FUNCTION: main
 DESCRIPTION: Calls method to create file STACK.txt before
                initializing the semaphore to 1. The error
                number on the system call is checked before
                continuing by instantiating an array of four
                threads. Each thread is then created using
                a loop, and again each error number is checked
                to insure valid system calls. Each thread is
                ran concurrently, but in a fashion that does
                not allow for corruption of their data using
                join calls on each thread. Once all threads
                have terminated, the semaphore will be destroyed
                and a message indicating success will print to 
                the console.
 I/O:   Input: int, char*
        Output: int
*************************************************************/
int main(int argc,char *argv[]){
    createFile(fileName);

    errorNo = sem_init(&FLAG, 0, 1);
    checkErr(errorNo);

    pthread_t threadArray[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; i++) {
        errorNo = pthread_create(&threadArray[i], NULL, getCard,(void *)i);
        checkErr(errorNo); 
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        errorNo = pthread_join(threadArray[i], NULL);
        checkErr(errorNo); 
    }

    errorNo = sem_destroy(&FLAG);
    checkErr(errorNo);

    cout << "Threads finished." << endl;
    pthread_exit(NULL);
 
}

/***********************[ EOF: player.cpp ]*********************/