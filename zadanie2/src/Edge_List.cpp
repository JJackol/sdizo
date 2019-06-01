#include "Edge_List.h"
#include <iostream>
#include <iomanip>

	Edge_List::Edge_List(): head{nullptr}
	{

	}

	Edge_List::~Edge_List()
	{
			ENode * temp;
			while(head != nullptr)
				{
					temp = head->next;
					delete head;
					head = temp;
				}
	}

	Edge_List::Edge_List(const Edge_List& other)
	{
		if (other.head!=nullptr)
			head = new ENode(*other.head);
		else
			return;

		ENode * other_temp = other.head;
		ENode * temp = head;
		while(other.head != nullptr)
			{
				temp->next = new ENode{ *(other_temp->next) };
				delete head;
				head = temp;
			}
	}

	Edge_List& Edge_List::operator=(const Edge_List& rhs)
	{
		if (this == &rhs) return *this; // handle self assignment

		return *this;
	}

	void Edge_List::insert_beg(Edge edge)
	{
	    if(head==nullptr)
        {
            head = new ENode{edge, nullptr};
            return;
        }
        ENode* temp=head;
        head = new ENode{edge, temp};
	}

//	void Edge_List::remove_val(int dest)
//	{
//	    if(head==nullptr) //jesli lista jest pusta nic nie rob
//            return;
//
//        Node* temp = head;
//        while(head->dest == dest){
//            head = head->next;
//            delete temp;
//            temp = head;
//        }
//        Node* delNode;//zmienna pomocnicza do usuwania węzła i przerzucenia wskaźnika
//
//	    while( temp->next != nullptr){
//            if( (temp->next)->dest==dest )
//            {
//                delNode = temp->next;
//                temp->next = delNode->next; //przestaw wskaźnik
//                delete delNode;
//            }
//            else    temp = temp->next;//przejdź do kolejnego
//        }
//	}

//	int Edge_List::get_weight(int source, int dest)
//	{
//	    if(head==nullptr)
//            return NOT_AN_EDGE;
//        Node* temp=head;
//        do
//        {
//            if(temp->dest == dest)
//                return temp->weight;
//            temp = temp->next;
//        }while(temp != nullptr);
//        return NOT_AN_EDGE;
//	}

	int Edge_List::get_size()
	{
		int i=0;
		ENode* temp = head;
		while(temp!=nullptr)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}

	int Edge_List::get_weight()
	{
		int sum=0;
		ENode* temp = head;
		while (temp!=nullptr)
		{
			sum += temp->e.weight;
			temp = temp->next;
		}
		_weight = sum;
		return sum;
	}

	void Edge_List::clear()
	{
		ENode* temp;
		while(head!=nullptr)
		{
			temp = head;
			head = head->next;
            delete temp;
		}
	}

	void Edge_List::display()
	{
		ENode* temp = head;

		while(temp != nullptr)
		{
			temp->e.display();
			temp = temp->next;
		}
		std::cout<<"size: "<<get_size()<<std::endl;
		std::cout<<"mst weight: "<<get_weight()<<std::endl;
		std::cout<<std::endl;

	}

