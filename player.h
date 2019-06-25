/************************************************************
 Name: Brian Rafferty -- cssc0852 -- redID: 816988452
 Class: CS 570, Summer 2019
 Project: Program Assignment #1 -- Multithreading
 File: player.h
 Notes: Header file for player.cpp, and functions by instantiating
        all methods that are used within the source code.
*************************************************************/
#ifndef PLAYER_H
#define PLAYER_H


using namespace std;

void checkErr(int errorNo);
void printDiamond(int id);
void printClub(int id);
void printHeart(int id);
void printSpade(int id);
void *getCard(void *threadPointer);
void createFile();


#endif

/***********************[ EOF: player.h ]*********************/