#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;//stack boyut
    int top;//en tepesindeki elemanýn index
    char *arr;//karacter dizisi
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;

    }
}

int parenthesisMatch(char * exp){//bir karactere dizisi parametr olarak
    // Create and initialize the stack
    struct stack* sp=malloc(sizeof(*sp));//memory allocation
    sp->size = 100;//stack boyutu 100 diyelim
    sp->top = -1;//baþlangiçta stack boþ diyelim
    sp->arr = (char *)malloc(sp->size * sizeof(char));//memory allocation

    for (int i = 0; exp[i]!='\0'; i++)//karacter dizisi gezdirecegýz baþlangiçtan sonuna kadar
    {
        if(exp[i]=='('){//açık parantezi karşılaştıgı zaman
            push(sp, '(');//Yığıtın üstüne bir açılış parantezi itin
        }
        else if(exp[i]==')'){
        //Kapanış parantez olması durumunda, yığının boş olup olmadığını kontrol edelim
            if(isEmpty(sp)){
                return 0;//demek ki parantez yanlış yazıldı
            }
        //boş eğilse, yığının üstekı açılış parantezini çıkartalım
            pop(sp);
        }
    }
    //karacter dizisi gezdiktan sonra bir bir daha kontrol edecegız

    if(isEmpty(sp)){
            //eğer stack boşsa demek ki parantezler iyi bir şekilde kullanildı
        return 1;
    }
    else{
        //eğer stack boş değilse demek ki parantezler iyi kullanilmadı
        return 0;
    }

}
int main()
{
    char* c=(char*)malloc(100*sizeof(char));
    printf("entrer a expression: ");//kullanıcıdan bir ifade istenmek
    scanf("%s",c);
    if(parenthesisMatch(c)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    free(c);
    return 0;
}

