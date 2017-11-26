struct Node
{
  int data;
  struct Node *next;
}


Node* MergeLists(Node *startA, Node* startB)
{
	if (startA == nullptr)
	{
	    return startB;
	}
	else if (startB == nullptr)
	{
	    return startA;
	}
    
	Node *start;
    
	if (startA->data < startB->data)
	{
		start = startA;
		startA = startA->next;
	}
	else
	{
		start = startB;
		startB = startB->next;
	}
    
	Node *current = start;
    
	while (startA != nullptr && startB != nullptr)
	{
		if (startA->data < startB->data)
		{
			current->next = startA;
			startA = startA->next;
		}
		else
		{
			current->next = startB;
			startB = startB->next;
		}
        
		current = current->next;
	}
	
	if (startA == nullptr)
	{
		current->next = startB;
	}
	else
	{
		current->next = startA;
	}

	return start;
}
