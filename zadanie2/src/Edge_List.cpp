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
		std::cout<<std::endl;

	}

