/*
NAME			: B.DIVYA
DATE			: 09-02-2026
DESCRIPTION		: Arbitrary precision Calculator [APC] The calculator supports addition, subtraction, multiplication, and division
				  using doubly linked lists, where each node stores a single digit of the number.*/
#include "apc.h"

#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define RESET "\033[0m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	int p_flag1=0,p_flag2=0,n_flag1=0,n_flag2=0,result_sign=0;
    // Validation
	if(!cla_validation(argc,argv))
	{
		printf("Error : Invalid arguments\n");
		return FAILURE;
	}
	printf(BLUE "============================================================================\n" RESET);
	printf(MAGENTA "                ~~~~~~~~~~~~~APC CALCULATOR~~~~~~~~~~~~~~~~               \n"RESET);
	printf(BLUE "============================================================================\n" RESET);

	printf(CYAN "Operand 1 : "WHITE "%s\n" RESET, argv[1]);
	printf(CYAN "Operand 2 : "WHITE "%s\n" RESET, argv[3]);
	printf(CYAN "Operator  : "WHITE "%c\n" RESET, argv[2][0]);


    // Create 2 lists of operands
	create_list(argv[1],&head1,&tail1);
	create_list(argv[3],&head2,&tail2);

    //Remove pre zeros
	remove_pre_zeros(&head1);
	remove_pre_zeros(&head2);

	if(argv[1][0]=='+')
		p_flag1=1;
	else if(argv[1][0]=='-')
		n_flag1=1;
	if(argv[3][0]=='+')
		p_flag2=1;
	else if(argv[3][0]=='-')
		n_flag2=1;
    char oper = argv[2][0];
	//fetch operator
	if(oper == '+')
	{
		// -a + -b
		if(n_flag1 == 1 && n_flag2==1)
		{
			oper='+';
		}
		// +a + -b
		else if(n_flag1==0 && n_flag2 == 1)
		{
			oper='-';
		}
		// -a + +b
		else if(n_flag1 == 1 && n_flag2==0)
		{
			oper='-';
		}
	}
	else if(oper == '-')
	{
		// -a - -b
		if(n_flag1 == 1 && n_flag2==1)
		{
			oper='-';
		}
		// +a - -b
		else if(n_flag1==0 && n_flag2 == 1)
		{
			oper='+';
		}
		// -a - +b
		else if(n_flag1 == 1 && n_flag2==0)
		{
			oper='+';
		}
	}
	if(oper == '+')
		printf(MAGENTA"Operation : ADDITION(+)\n"RESET);
	else if(oper == '-')
	{
		printf(MAGENTA"Operation : SUBTRACTION(-)\n"RESET);
	}
	else if(oper == 'x' || oper == 'X')
	{
		printf(MAGENTA"Operation : MULTIPLICATION(X)\n"RESET);
	}
	else if(oper == '/')
	{
		printf(MAGENTA"Operation : DIVISION(/)\n"RESET);
	}
	
	printf(BLUE "============================================================================\n" RESET);
	switch(oper)
	{
		case '+':
			addition(tail1, tail2, &headR, &tailR);
			if(n_flag1 == 1 && n_flag2==0)
				result_sign =1;
			else
				result_sign = (n_flag1 && n_flag2);
			break;

		case '-':
		{
			int ret = compare_list(head1, head2);

			if (ret == OPERAND1)
			{
				subtraction(tail1, tail2, &headR, &tailR);
				result_sign = n_flag1;
			}
			else if (ret == OPERAND2)
			{
				subtraction(tail2, tail1, &headR, &tailR);
				result_sign = !n_flag1;
			}
			else
			{
				insert_first(&headR, &tailR, 0);
				result_sign = 0;
			}
			break;
		}

		case 'x':
		case 'X':
			multiplication(tail1, tail2, &headR, &tailR);
			result_sign = (n_flag1 != n_flag2);
			break;

		case '/':
			if (head2->data == 0)
			{
				printf("Runtime Error : Divisible by Zero\n"); 
				return FAILURE;
			}
			division(head1, head2, tail2, &headR, &tailR);
			result_sign = (n_flag1 != n_flag2);
			break;

		default:
			printf("Invalid operator\n");
			return FAILURE;
	}
	remove_pre_zeros(&headR); // it removes pre zeors
	printf(MAGENTA"Result : " RESET);

	/* avoid printing -0 */
	if (result_sign && !(headR->data == 0))
    	printf("-");

	print_list(headR);
	printf("\n");
	return SUCCESS;
}