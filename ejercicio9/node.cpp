#include "node.h"

PNode &push(PNode &head, Student const &st)
{
	if (!head)
	{
		head = make_shared<Node>(Node{st, nullptr});
		return head;
	}

	auto it = head;
	while (it->next)
	{
		it = it->next;
	}

	PNode node = make_shared<Node>(Node{st, nullptr});
	it->next = node;

	return head;
}

void forEach(PNode const &head, LambdaForEach const &f)
{
	auto it = head;
	while (it)
	{
		f(it->data);
		it = it->next;
	}
}

vector<PNode> filter(PNode const &head, function<bool(Student const &)> const &f)
{
	vector<PNode> result;
	auto it = head;
	while (it)
	{
		if (f(it->data))
		{
			result.push_back(it);
		}
		it = it->next;
	}
	return result;
}

PNode find(PNode const &head, function<bool(Student const &)> const &f)
{
	auto it = head;
	while (it)
	{
		if (f(it->data))
		{
			return it;
		}
		it = it->next;
	}
	return nullptr;
}

PNode findLast(PNode const &head, function<bool(Student const &)> const &f)
{
	PNode last = nullptr;
	auto it = head;
	while (it)
	{
		if (f(it->data))
		{
			last = it;
		}
		it = it->next;
	}
	return last;
}

PNode delete_node(PNode &head, function<bool(Student const &)> const &f)
{
    PNode current = head;
    PNode previous = nullptr;

    while (current != nullptr) {
        if (f(current->data)) {
            if (previous == nullptr) {
                // El nodo a eliminar es la cabeza
                head = current->next;
            } else {
                // El nodo a eliminar está en medio o al final
                previous->next = current->next;
            }
            PNode temp = current;
            current = current->next;
        } else {
            previous = current;
            current = current->next;
        }
    }
    return head;
}