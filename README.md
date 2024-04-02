# Push Swap 

=)

En construction ! Derniere mise a jour mardi 02/04/2024 23h14

🚧🚧🚧

source : 

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a


## **Etape 1** 

- Faire les fonctions pa, pb ,sa ...

## **ETAPE 2**

## **Pour le trie par 3 :** 

![Screenshot from 2024-03-26 10-51-40](https://github.com/Teddyburgonde/push_swap/assets/93845046/569b1298-718a-47f7-8104-d1600d938b30)

## **Pour le trie par 5 :**

![Screenshot from 2024-03-26 11-03-56](https://github.com/Teddyburgonde/push_swap/assets/93845046/0fb0377d-e21d-4b14-9ea2-170641b22ab3)

![Screenshot from 2024-03-26 11-04-28](https://github.com/Teddyburgonde/push_swap/assets/93845046/fca1e597-3397-4757-903e-c780740d550d)

![Screenshot from 2024-03-26 11-04-55](https://github.com/Teddyburgonde/push_swap/assets/93845046/e501f928-36e5-42bf-9f66-8e77bc69dc58)


## **fonction qui permet d'imprimer les valeurs**

Si tu trie et tu vois afficher pa sa sa pb ... ce n'est pas tres visuel ,
on prefere qu'on nous affiche 1 55 77 88 99

##  **Normalisation**

- Imaginer que vous avez 100 chiffres a trier , dans ses chiffres il peut avoir 12000 , 5, 77777 etc...
Si on dit a l'ordinateur de trier en etat cela prendrai beaucoup trop de temps...
C'est pour cela qu'on doit faire une normalisation des valeurs, peut importe le chiffre il deviendra un index (une position dans la pile a trier) et sa sera plus rapide de trier l'index 5 avec index 0.


## **Algorithme papillion** 

En etat c'est algorithme vous permettra de valider votre projet mais pas à 100 %. 
Si vous voulez avoir les 100 % aller demander a Mr Ppuivif.
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

