#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coefficient;
    int power;
    struct Node *link;
};

struct Node *createNode(int coefficient, int power)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->power = power;
    newNode->link = NULL;
    return newNode;
}

struct Node *insertInPolynomial(struct Node *head, int coefficient, int power)
{

    struct Node *newNode, *ptr, *temp = head;

    newNode = createNode(coefficient, power);

    if (head == NULL || head->power < power)
    {
        newNode->link = head;
        return newNode;
    }

    while (temp != NULL)
    {

        ptr = temp;
        temp = temp->link;

        if (temp == NULL)
        {
            ptr->link = newNode;
            return head;
        }
        else if ((power < ptr->power) && (power > temp->power))
        {
            newNode->link = temp;
            ptr->link = newNode;
            return head;
        }
    }

    return head;
}

struct Node * addInResultantMultplication(struct Node *headP3, int coefficient, int power){

    struct Node *temp = headP3;
    struct Node *newNode;

    if(temp == NULL || headP3->power < power){
        newNode = createNode(coefficient, power);
        newNode->link = headP3;
        return newNode;
    }else {

        while(temp != NULL) {

            if(temp->power == power){
                temp->coefficient=temp->coefficient+coefficient;
                return headP3;
            }

            if(temp->power > power && (temp->link == NULL || temp->link->power < power)){
                newNode = createNode(coefficient, power);
                newNode->link = temp->link;
                temp->link = newNode;
                return headP3;
            }

            temp = temp->link;

        }

        newNode->link = NULL;
        temp->link = newNode;
        
    }

    return headP3;

}

struct Node* multiplyPolynomials(struct Node *headP3, struct Node *headP1, struct Node *headP2){

    struct Node * temp = headP2;
    int coefficient, power;

    if(headP2 == NULL && headP1 == NULL){
        return NULL;
    }

    if(headP1 == NULL){
        return headP2;
    }else if(headP2 == NULL){
        return headP1;
    }

    while(headP1 != NULL){

        while(headP2 != NULL){

            coefficient = headP1->coefficient * headP2->coefficient;
            power = headP1->power + headP2->power;
            headP2 = headP2->link;
            headP3 = addInResultantMultplication(headP3, coefficient, power);
        }

        headP2 = temp;
        headP1 = headP1->link;

    }

    return headP3;

}

struct Node* addPolynomials(struct Node *headP1, struct Node *headP2){

    int coeffSum;
    struct Node *finalHead = NULL;
    struct Node *finalTail = NULL;

    if(headP1 == NULL && headP2 == NULL){
        return NULL;
    }

    while(headP1 != NULL && headP2 != NULL){

        if(headP1->power > headP2->power){
            if(finalHead == NULL){
                finalHead = createNode(headP1->coefficient, headP1->power);
                finalTail = finalHead;
                headP1 = headP1->link;
            }else{
                struct Node* newNode = createNode(headP1->coefficient, headP1->power);
                finalTail->link = newNode;
                finalTail =  newNode;
                headP1 = headP1->link;
            }
        }else if(headP2->power > headP1->power){
            if(finalHead == NULL){
                finalHead = createNode(headP2->coefficient, headP2->power);
                finalTail = finalHead;
                headP2 = headP2->link;
            }else{
                struct Node* newNode = createNode(headP2->coefficient, headP2->power);
                finalTail->link = newNode;
                finalTail =  newNode;
                headP2 = headP2->link;
            }
        }else {
            coeffSum = headP1->coefficient + headP2->coefficient;
            struct Node* newNode = createNode(coeffSum, headP1->power);

            if(finalHead == NULL){
                finalHead = newNode;
                finalTail = finalHead;
            }else{
                finalTail->link = newNode;
                finalTail =  newNode;

            }
            headP1 = headP1->link;
            headP2 = headP2->link;
        }

    }

    while(headP1 != NULL){
        struct Node* newNode = createNode(headP1->coefficient, headP1->power);
        if(finalHead == NULL){
            finalHead = newNode;
            finalTail = finalHead;
        }else{
            finalTail->link = newNode;
            finalTail =  newNode;
        }
        headP1 = headP1->link;
    }

    while(headP2 != NULL){
        struct Node* newNode = createNode(headP2->coefficient, headP2->power);
        if(finalHead == NULL){
            finalHead = newNode;
            finalTail = finalHead;
        }else{
            finalTail->link = newNode;
            finalTail =  newNode;
        }
        headP2 = headP2->link;
    }

    return finalHead;

}

struct Node* subtractPolynomials(struct Node *headP1, struct Node *headP2){

    int coeffSum;
    struct Node *finalHead = NULL;
    struct Node *finalTail = NULL;

    if(headP1 == NULL && headP2 == NULL){
        return NULL;
    }

    while(headP1 != NULL && headP2 != NULL){

        if(headP1->power > headP2->power){
            if(finalHead == NULL){
                finalHead = createNode(headP1->coefficient, headP1->power);
                finalTail = finalHead;
                headP1 = headP1->link;
            }else{
                struct Node* newNode = createNode(headP1->coefficient, headP1->power);
                finalTail->link = newNode;
                finalTail =  newNode;
                headP1 = headP1->link;
            }
        }else if(headP2->power > headP1->power){
            if(finalHead == NULL){
                finalHead = createNode(headP2->coefficient, headP2->power);
                finalTail = finalHead;
                headP2 = headP2->link;
            }else{
                struct Node* newNode = createNode(headP2->coefficient, headP2->power);
                finalTail->link = newNode;
                finalTail =  newNode;
                headP2 = headP2->link;
            }
        }else {
            coeffSum = headP1->coefficient - headP2->coefficient;
            struct Node* newNode = createNode(coeffSum, headP1->power);

            if(finalHead == NULL){
                finalHead = newNode;
                finalTail = finalHead;
            }else{
                finalTail->link = newNode;
                finalTail =  newNode;

            }
            headP1 = headP1->link;
            headP2 = headP2->link;
        }

    }

    while(headP1 != NULL){
        struct Node* newNode = createNode(headP1->coefficient, headP1->power);
        if(finalHead == NULL){
            finalHead = newNode;
            finalTail = finalHead;
        }else{
            finalTail->link = newNode;
            finalTail =  newNode;
        }
        headP1 = headP1->link;
    }

    while(headP2 != NULL){
        struct Node* newNode = createNode(headP2->coefficient, headP2->power);
        if(finalHead == NULL){
            finalHead = newNode;
            finalTail = finalHead;
        }else{
            finalTail->link = newNode;
            finalTail =  newNode;
        }
        headP2 = headP2->link;
    }

    return finalHead;

}

void printPolynomial(struct Node *ptr)
{
    int i = 0;
    int flag = 0;
    while (ptr)
    {
        if (ptr->power != 0 && ptr->power != 1)
        {
            if (ptr->coefficient > 0 && flag == 0)
            {
                printf("%dx^%d", ptr->coefficient, ptr->power);
                flag++;
            }
            else if (ptr->coefficient > 0 && flag == 1)
            {
                printf("+%dx^%d", ptr->coefficient, ptr->power);
            }
            else if (ptr->coefficient < 0)
            {
                printf("%dx^%d", ptr->coefficient, ptr->power);
            }
        }
        else if (ptr->power == 0)
        {
            if (ptr->coefficient > 0 && flag == 0)
            {
                printf("%d", ptr->coefficient);
                flag++;
            }
            else if (ptr->coefficient > 0 && flag == 1)
            {
                printf("+%d", ptr->coefficient);
            }
            else if (ptr->coefficient < 0)
            {
                printf("%d", ptr->coefficient);
            }
        }
        else if (ptr->power == 1)
        {
            if (ptr->coefficient > 0 && flag == 0)
            {
                printf("%dx", ptr->coefficient);
                flag++;
            }
            else if (ptr->coefficient > 0 && flag == 1)
            {
                printf("+%dx", ptr->coefficient);
            }
            else if (ptr->coefficient < 0)
            {
                printf("%dx", ptr->coefficient);
            }
        }
        ptr = ptr->link;
        i++;
    }
    printf("\n");
    return;
}

struct Node * getPolynomialFromUser(){

    struct Node *head = NULL;

    int coefficient, power, i, n;
    int count;
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        printf("Enter the coefficient part:");
        scanf("%d", &coefficient);
        printf("Enter the power part:");
        scanf("%d", &power);
        head = insertInPolynomial(head, coefficient, power);
    }

    return head;
}

int main()
{

    struct Node *headP1 = NULL, *headP2 = NULL, *headP3 = NULL, *headP4 = NULL, *headP5 = NULL;

    
    printf("Enter the number of coefficients in the first polynomial:");
    headP1 = getPolynomialFromUser();
    
    printf("Enter the number of coefficients in the second polynomial:");
    headP2 = getPolynomialFromUser();

    printf("Polynomial Expression 1: ");
    printPolynomial(headP1);
    
    printf("Polynomial Expression 2: ");
    printPolynomial(headP2);

    headP3 = multiplyPolynomials(headP3, headP1, headP2);
    printf("Output of multiplication:\n");
    printPolynomial(headP3);
    headP4 = addPolynomials(headP1, headP2);
    printf("Output of addition:\n");
    printPolynomial(headP4);
    headP5 = subtractPolynomials(headP1, headP2);
    printf("Output of subtraction:\n");
    printPolynomial(headP5);


    return 0;
}