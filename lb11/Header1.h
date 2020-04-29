#pragma once
#include "Header.h"

template<typename Data> struct Node
{
	Data data;
	weak_ptr<Node> prev;
	shared_ptr<Node> next;

	Node(Data);
	~Node();
};

template<typename Data> Node<Data>::Node(Data data)
{
	this->data = data;
}

template<typename Data> Node<Data>::~Node()
{
	if (next != nullptr)
	{
		cout << "Узел со значением: " << this->data << " был удален. Следующий имеет " << next.use_count() << " указателей"<<endl;
		next.reset();
	}
	else {
		cout << "Узел со значением: " << this->data << " был удален."<<endl;
	}
}



template<typename Data> class RingList
{
public:
	void insert(Data);
	void remove(Data);
	shared_ptr<Node<Data>> search(Data);


	RingList() { };
	~RingList();

private:
	weak_ptr<Node<Data>> m_last;
};

template<typename Data> void RingList<Data>::insert(Data data)
{
	shared_ptr<Node<Data>> newOne(new Node<Data>(data));

	if (m_last.lock() != nullptr) {
		newOne->prev = m_last;
		newOne->next = m_last.lock()->next;
		m_last.lock()->next->prev = newOne;
		m_last.lock()->next = newOne;
	}
	else
	{
		newOne->prev = newOne;
		newOne->next = newOne;
	}

	m_last = newOne;
}

template<typename Data> shared_ptr<Node<Data>> RingList<Data>::search(Data data)
{
	if (m_last.lock() != nullptr)
	{
		auto node = m_last.lock();

		do
		{
			if (node->data == data) return node;

			node = node->next;
		} while (node != m_last.lock());
	}

	return nullptr;
}

template<typename Data> void RingList<Data>::remove(Data data)
{
	auto node = search(data);

	if (node)
	{
		node->next->prev = node->prev;
		node->prev.lock()->next = node->next;

		if (node == m_last.lock())
		{
			m_last = node->prev;
		}

		node.reset();
	}
}

template<typename Data> RingList<Data>::~RingList()
{
	if (!m_last.expired())
	{
		m_last.lock()->next.reset();
		m_last.reset();
	}
}
