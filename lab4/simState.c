#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
/*
------------------
STARTING NODE IS C
------------------
    A F E
    B C D
    C C H
    D A G
    E G C 
    F B D
    G E B
    H F A
*/
struct State {
    struct State *last;
    struct State *next;
    char stateID;
    int nodeCount;
};

void print(struct State *states[]);

void switchStates(struct State *states[], char userInput, struct State *currentState, int whichState);

void garbage(struct State *current, struct State *last, struct State *next, struct State *rootNode);

void removeStates(struct State *states[], struct State *currentState, char userInput);

void reset(struct State * states[]);

static int AMTofStates = 8; //!!! MUST CHANGE DURING TESTING !!!

int main(int argc, char * argv[])
{
    //My FSM
    static struct State A,B,C,D,E,F,G,H;

    //setValue of FSM
    A.last = &F; A.next = &E; A.stateID = 'A'; A.nodeCount = 0; 
    B.last = &C; B.next = &D; B.stateID = 'B'; B.nodeCount = 0; 
    C.last = &C; C.next = &H; C.stateID = 'C'; C.nodeCount = 0; 
    D.last = &A; D.next = &G; D.stateID = 'D'; D.nodeCount = 0; 
    E.last = &G; E.next = &C; E.stateID = 'E'; E.nodeCount = 0; 
    F.last = &B; F.next = &D; F.stateID = 'F'; F.nodeCount = 0; 
    G.last = &E; G.next = &B; G.stateID = 'G'; G.nodeCount = 0; 
    H.last = &F; H.next = &A; H.stateID = 'H'; H.nodeCount = 0; 

    struct State *states[] = {&A, &B, &C, &D, &E, &F, &G, &H};    

/*
    //Test FSM (Example)
    static struct State A,B,C,D;

    A.last = &B; A.next = &C; A.stateID = 'A'; A.nodeCount = 0; 
    B.last = &A; B.next = &A; B.stateID = 'B'; B.nodeCount = 0; 
    C.last = &A; C.next = &D; C.stateID = 'C'; C.nodeCount = 0; 
    D.last = &D; D.next = &C; D.stateID = 'D'; D.nodeCount = 0; 
    
    struct State *states[] = { &A, &B, &C, &D }; 
*/

    struct State *currentState = &C; //set Current State

    printf("Current State: %c\n", currentState->stateID);

    char userInput[100];

    while (strncmp(userInput, "q", 1) != 0) { //quit

        fgets(userInput, sizeof(userInput) + 1, stdin);

        switch(userInput[0]) {
            case '0':
                if((currentState -> last)!= NULL) {
                    currentState = currentState -> last;
                    printf("%c\n", currentState -> stateID);
                } else {
                    printf("No such state. \n");
                }
                break;
            case '1':
                if((currentState -> next)!= NULL) {
                    currentState = currentState -> next;
                    printf("%c\n", currentState -> stateID);
                } else {
                    printf("No such state. \n");
                }
                break;
            case 'c':
                if(userInput[2] == '0') {
                    switchStates(states, userInput[4], currentState, 0);                    
                }  
                if (userInput[2] == '1') {
                    switchStates(states, userInput[4], currentState, 1);
                } 
                break;
            case 'p':
                print(states);
                break;
            case 'g':
                reset(states);
                garbage(currentState, currentState -> last, currentState -> next, currentState);

                int garbStatus = 0;

                for (int i = 0; i < AMTofStates; i++) {
                    if(states[i] != NULL) {
                        if(states[i] -> nodeCount == 0) {
                            printf("Garbage %c\n", states[i] -> stateID);
                            garbStatus = 1;
                        }
                    }
                }

                if(garbStatus == 0) {
                    printf("No garbage.\n");
                }
                break;
            case 'd':
                reset(states);
                garbage(currentState, currentState -> last, currentState -> next, currentState);
                removeStates(states, currentState, userInput[2]);
        }
    }
    return 0;
}

void switchStates(struct State *states[], char userInput, struct State *currentState, int selection) {
    for (int i = 0; i < AMTofStates; i++) {
        if (states[i]->stateID == userInput && selection == 0) {
            currentState->last = states[i];
        } 
        if (states[i]->stateID == userInput && selection == 1) {
            currentState->next = states[i];
        }
    }
}

void print(struct State *states[]) {
    for (int i = 0; i < AMTofStates; i++) {
        if (states[i] != NULL) {
            printf("The States are:\n %c %c %c\n", states[i] -> stateID, states[i] -> last -> stateID, states[i] -> next -> stateID);
        } 
    }
}

void garbage(struct State *current, struct State *last, struct State *next, struct State *rootNode) {
    current-> nodeCount++;
    if (current != last && last != rootNode && last->nodeCount == 0) {
        garbage(last, last->last, last->next, rootNode);
    }
    if (current != next && next != rootNode && next->nodeCount == 0) {
        garbage(next, current, next->next, rootNode);
    }
}

void reset(struct State * states[]) {
    for (int i = 0; i < AMTofStates; i++) {
        if (states[i] != NULL) {
            states[i] -> nodeCount = 0;
        }
    }
}

void removeStates(struct State *states[], struct State *currentState, char userInput) {
    int garbState = 0;
    
    for (int i = 0; i < AMTofStates; i++) {
        if (states[i] != NULL && states[i]->nodeCount == 0) {
            garbState = 1;
            break;
        }
    }

    if (userInput == '\0' ) {
        if (garbState == 0) {
            printf("No states deleted.\n");
        } else {
            for (int i = 0; i < AMTofStates; i++) {
                if (states[i] != NULL && states[i]-> nodeCount == 0) {
                    printf("Deleted: %c\n", states[i]-> stateID); //set node to null
                    states[i]-> next = NULL;
                    states[i]-> last = NULL;
                    states[i] = NULL;
                }
            }
        }
    } else { 
        int found = 0;
        for (int i = 0; i < AMTofStates; i++) {
            if (states[i] != NULL && states[i]->stateID == userInput) {
                if (states[i]-> nodeCount == 0) {
                    printf("Deleted.\n");
                    states[i]-> next = NULL;
                    states[i]-> last = NULL;
                    states[i] = NULL;
                } else {
                    printf("Delete Error.\n");
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("State not located.\n");
        }
    }
}