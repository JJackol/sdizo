#include "Adjacency_List.h"
#include <iostream>
#include <iomanip>

	Adjacency_List::Adjacency_List(): head{nullptr}
	{
	}

	Adjacency_List::~Adjacency_List()
	{
		 Node * temp;
			while(head != nullptr)
				{
					temp = head->next;
					delete head;
					head = temp;
				}
	}

	void Adjacency_List::insert_beg(int _dest, int _weight)
	{
	    if(head==nullptr)
        {
            head = new Node{_dest, _weight, nullptr};
            return;
        }
        Node* temp=head;
        head = new Node{_dest, _weight, temp};
	}

	void Adjacency_List::remove_val(int dest)
	{
	    if(head==nullptr) //jesli lista jest pusta nic nie rob
            return;

        Node* temp = head;
        while(head->dest == dest){
            head = head->next;
            delete temp;
            temp = head;
        }
        Node* delNode;//zmienna pomocnicza do usuwania węzła i przerzucenia wskaźnika

	    while( temp->next != nullptr){
            if( (temp->next)->dest==dest )
            {
                delNode = temp->next;
                temp->next = delNode->next; //przestaw wskaźnik
                delete delNode;
            }
            else    temp = temp->next;//przejdź do kolejnego
        }
	}

	int Adjacency_List::get_weight(int dest)
	{
	    if(head==nullptr)
            return NOT_AN_EDGE;
        Node* temp=head;
        do
        {
            if(temp->dest == dest)
                return temp->weight;
            temp = temp->next;
        }while(temp != nullptr);
        return NOT_AN_EDGE;
	}

	void Adjacency_List::clear()
	{
		Node* temp;
		while(head!=nullptr)
		{
			temp = head;
			head = head->next;
            delete temp;
		}
	}

	void Adjacency_List::print()
	{
		Node* temp = head;

		while(temp != nullptr)
		{
			std::cout<< '(' << temp->dest <<", w:" << temp->weight << ") ";
			temp = temp->next;
		}
		std::cout<<std::endl;

	}
