/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useit015 <useit015@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:28:04 by useit015          #+#    #+#             */
/*   Updated: 2019/07/18 19:47:24 by useit015         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

int		cycle_detector(const t_list *lst)
{
	t_list *slow = (t_list *)lst;
	t_list *fast = (t_list *)lst;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return 1;
	}
	return 0;
}

void	push(t_list** head, int data)
{
	t_list* newNode = (t_list *)malloc(sizeof(t_list));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

int		main(void)
{
	int keys[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(keys) / sizeof(keys[0]);
	t_list* head = NULL;
	for (int i = size - 1; i >= 0; i--)
		push(&head, keys[i]);
	// t_list* tmp = head;
	// while (tmp->next)
	// 	tmp = tmp->next;
	// tmp->next = head->next;
	printf(cycle_detector(head) ? "Cycle Found\n" : "No Cycle Found\n");
	return 0;
}