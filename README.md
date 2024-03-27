# Push Swap 

Je vous prepare un readme de fou =)

En construction ! Derniere mise a jour mardi 27/03/2024 9h56 

🚧🚧🚧

source : 

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

## **Pour le trie par 3 :** 

![Screenshot from 2024-03-26 10-51-40](https://github.com/Teddyburgonde/push_swap/assets/93845046/569b1298-718a-47f7-8104-d1600d938b30)


## **Pour le trie par 5 :**

![Screenshot from 2024-03-26 11-03-56](https://github.com/Teddyburgonde/push_swap/assets/93845046/0fb0377d-e21d-4b14-9ea2-170641b22ab3)

![Screenshot from 2024-03-26 11-04-28](https://github.com/Teddyburgonde/push_swap/assets/93845046/fca1e597-3397-4757-903e-c780740d550d)

![Screenshot from 2024-03-26 11-04-55](https://github.com/Teddyburgonde/push_swap/assets/93845046/e501f928-36e5-42bf-9f66-8e77bc69dc58)

## Algorithme papillion 

En etat c'est algorithme vous permettra de valider votre projet mais pas à 100 %. 
```c
void	ft_butterfly(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	i;
	int	tracker;
	int	number_elements_in_chunk;
	int	len;

	len = ft_lstsize(*stack_a);
	number_elements_in_chunk = ft_lstsize(*stack_a) / chunk;
	tracker = number_elements_in_chunk;
	while (*stack_a != NULL)
	{
		i = 0;
		while (i < number_elements_in_chunk && *stack_a != NULL)
		{
			if ((*stack_a)->rank < tracker)
			{
				ft_push(stack_b, stack_a, 'b');
				if ((*stack_b)->rank > (tracker - len / (chunk * 2)))
					ft_rotate(stack_b, 'b');
				i++;
			}
			else
				ft_rotate(stack_a, 'a');
		}
		tracker += number_elements_in_chunk;
	}
}
```
🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧
