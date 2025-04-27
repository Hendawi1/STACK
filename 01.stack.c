#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// STACK DOSE NOT EXSIST = -1


// create STACK data type:
struct STACK {
	int top;
	size_t size;
	char *arr;
};



// careate a creation function of STACK:
struct STACK* creat_stack(size_t size){
	struct STACK* stack =  NULL;
	stack = (struct STACK*) malloc(sizeof(struct STACK));
	if (stack){
		stack->top = -1;
		stack->size = size;
		stack->arr = (char *)malloc(stack->size*sizeof(char));
		if(!stack -> arr) stack =  NULL;
	}
	return stack;
}



int is_empty(struct STACK* stack){
	if (stack) return (stack->top == -1);
	return -1;
}



int is_full(struct STACK* stack){
	if (stack) return (stack->top == (stack->size)-1);
	return -1;
}



int push(struct STACK* stack, char x){
	if (stack){
		if(is_full(stack)){
			return 0;
		}
		else if (!is_full(stack)){
			stack->arr[++stack->top]=x;
			return 1;
		}
	}
	return -1;
}


int pop(struct STACK* stack, char *pop_res){
	if (stack){
		if(is_empty(stack)) return 0;
		else{
			*(pop_res) = stack->arr[stack->top];
			stack->top--;
			return 1;
		}
	}
	return -1;
}



int print(struct STACK* stack){
	if (stack){
//		if (!is_empty(stack)){
			printf("stack: ");
			for(int i=0; i<=stack->top; i++){
				printf("%c, ", stack->arr[i]);
			}
			printf("\n");
			return 1;
//		}
//		return 0;
	}
	return -1;
}



int show_top(struct STACK* stack, char *showtop_res){
        if (stack){
                if (!is_empty(stack)){
                        *(showtop_res) = stack->arr[stack->top];
                        return 1;
                }
		return 0;
	}
	return -1;
}



int clear(struct STACK* stack){
        if (stack){
                stack->top = -1;
		return 1;
        }
	return -1;
}



/*struct STACK* delete_stack(struct STACK* stack){
	if (stack){
		stack->top = -1;
		stack->arr = NULL;
		return NULL;
	}
}*/



bool delete_stack(struct STACK* stack){
	if (stack){
		free(stack->arr);
		stack->arr = NULL;

		free(stack);
		stack = NULL;

		if (stack) return 0;
		return 1;
	}
	return -1;
}



void net(){
	printf("\nstacka neto!!\n");
}




/*
int main(){

	int x;
	size_t sz;
	char el, top, pop_res;
	struct STACK * stack = NULL;
	while (true){
		printf("\n1- create\n2- is empty\n3- is full\n4- push\n5- pop\n6- print\n7- show top\n8- clear\n0- exit\n==> ");
		scanf("%d", &x);

		if (x==1)
			{printf("\nsize = ");
			scanf("%d", &sz);
			stack = creat_stack(sz);
			if (stack) printf("\n[+] DONE!!\n");
			else{printf("\n[-] ERROR!!\n"); break;}}

		else if (x==2)
			{if (is_empty(stack) == -1) net();
			else if (is_empty(stack)) printf("\n[+] YES, empty stack!!\n");
			else printf("\nNO\n");}

                else if (x==3)
                        {if (is_full(stack) == -1) net();
			else if (is_full(stack) == 1) printf("\nyes\n");
                        else printf("\nNO\n");}

                else if (x==4)
			{printf("\nelsement = ");
			scanf(" %c", &el);
			int test = push(stack, el);
			if (test == -1) net();
			else if (x == 0) printf("\nstack overflow!!\n");}

                else if (x==5)
                        {int test = pop(stack, &pop_res);
			if (test == -1) net();
			else if (test == 0) printf("\nstack underflow!!\n");
			else printf("\npop result: %c\n", pop_res);}

                else if (x==6)
			{int test = print(stack);
			if (test == -1) net();
			else if (test == 0) printf("\n[-] net elementof to print!!\n");}

                else if (x==7)
                        {int test = show_top(stack, &top);
			if (test == -1) net();
			else if (test == 0) printf("\n[-] empty stack!!\n");
			else printf("\ntop : %c\n", top);}

		else if (x==8)
			{int test = clear(stack);
			if (test == -1) net();
			else printf("\n[+] Cleared!\n");}

		else if (x==0)
			break;

		else printf("\n[-] unknown choice\n");
	}
	return 0;
}


*/
