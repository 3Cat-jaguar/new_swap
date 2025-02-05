/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:25:59 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/22 14:02:47 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prgm_init(t_program *prgm)
{
	prgm->error = 0;
	prgm->letter = 0;
	prgm->nbrneg = 0;
	prgm->range = 0;
}

void	check_stack(t_element *a, t_element *b)
{
	t_element	*temp;

	temp = 0;
	printf("A : ");
	temp = a;
	while (1 && temp)
	{
		printf("%d ", temp->val);
		temp = temp->next;
		if ((a)->val == temp->val)
			break ;
	}
	printf("\nB : ");
	temp = b;
	while (1 && temp)
	{
		printf("%d ", temp->val);
		temp = temp->next;
		if ((b)->val == temp->val)
			break ;
	}
	printf("\n");
}

void	stack_free(int r, t_element **ab)
{
	t_element *next;

	while (r > 0)
	{
		if (r != 1)
			next = (*ab)->next;
		free(*ab);
		*ab = next;
		r--;
	}
}

int	main(int nb, char **arg)
{
	t_element	*a;
	t_element	*b;
	t_program	prgm;

	a = NULL;
	b = NULL;
	prgm_init(&prgm);
	a = stack_init(nb, arg, &prgm);
	if (error_check(&prgm, nb, a) == 1)
		return (0);
	atob(nb - 1, 0, &a, &b); //atob 5 -> atob 2 -> btoa6 -> atob3-> btoa3 ->
//	check_stack(a, b);
/* pivot sort에서 문제가 생김!
	atob(5, 0, &a, &b);
	atob(2, 0, &a, &b);
	printf("a->prev %d\n",(a)->prev->val);
	printf("b start\n");
	btoa(6, 0, &a, &b);
//	printf("%p %p\n",a,b);
//	printf("%p %p\n",a->next, b->next);
	atob(3, 0, &a, &b);
//	btoi(3, 0, &a, &b);
	check_stack(a, b);
//	stack_free(nb - 1, &a);
*/
//	system("leaks push_swap | grep \"total leaked\"");
	return (0);
}