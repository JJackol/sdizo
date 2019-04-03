#include "DL_List.h"
#include <iostream>
#include <cassert>
#include <iomanip>

	DL_List::DL_List()
	{
	}
	DL_List::DL_List(DL_List & L)
	{
	}
	DL_List::~DL_List()
	{
	    Node2 * temp;
	    while(head != nullptr)
            {
                temp = head->next;
                delete head;
                head = temp;
            }

	}

	void DL_List::print()
	{

	    Node2* temp = head;
	    while(temp != nullptr)
        {
            //std::cout.width(3);
            std::cout<< std::setw(4)<<std::left <<temp->val << " ";
            temp = temp->next;
	    }
	    std::cout<<std::endl;

//	    for (int i = 0; i<my_size; i++)
//        {
//            std::cout<< temp->val << " ";
//            temp = temp->next;
//        }
//        std::cout<<std::endl;

	}

	bool DL_List::is_Empty()
	{
		return head==nullptr;
	}
	void DL_List::insert_end(int val)
	{
	    if(head==nullptr)
        {
            head = new Node2{val};
            return;
        }
        Node2* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = new Node2{val};

	}
	void DL_List::insert_beg(int val)
	{
	    if(is_Empty())
        {
            head = new Node2{val, nullptr};
            return;
        }
        Node2* temp=head;
        head = new Node2{val, temp};
	}
	void DL_List::insert(int index, int val)
	{
// TODO (jaca#1#): inert item
	    //todo
	}

	int DL_List::at(int index)
	{
        if(is_Empty())
        {
            std::cout<<"lista pusta"<<std::endl;
            return -1;
        }

        Node2* temp=head;
        while(index--)
        {
            if(temp->next == nullptr) // jesli i-ty el nie istnieje wyjdź
            {
                std::cout<<"element o podanym indeksie nie istnieje"<<std::endl;
                return -1;
            }
            temp = temp->next;
	    }
	    return temp->val;


	}
	int DL_List::find(int val)
	{
	    if(is_Empty())
            return -1;
        Node2* temp=head;
        int i=0;
        do
        {
            if(temp->val == val)
                return i;
            temp = temp->next;
            i++;
        }while(temp->next != nullptr);
        return -2;
	}
	void DL_List::remove_at(int index)
	{
	    assert(index>=0);
	    if(is_Empty())
            return;
        Node2* temp = head;
        if(index==0) // jesli usuwany jest 0 el.
        {
            head = head->next;
            delete temp;
            return;
        }

	    while(--index)
        {
            if(temp->next == nullptr) // jesli i-ty el nie istnieje wyjdź
                return;
            temp = temp->next;

	    }
	    Node2* delNode2 = temp->next;//zmienna pomocnicza do usuwania węzła i przerzucenia wskaźnika
	    if(delNode2!= nullptr)
        {
            temp->next = delNode2->next;
            delete delNode2;
        }
        return;
	}

	//usuwa wszystkie wystąpienia val
	void DL_List::remove_val(int val)
	{
	    if(is_Empty()) //jesli lista jest pusta nic nie rob
            return;

        Node2* temp = head;
        while(head->val == val){
            head = head->next;
            delete temp;
            temp = head;
        }
        Node2* delNode2;//zmienna pomocnicza do usuwania węzła i przerzucenia wskaźnika

	    while( temp->next != nullptr){
            if( (temp->next)->val==val )
            {
                delNode2 = temp->next;
                temp->next = delNode2->next; //przestaw wskaźnik
                delete delNode2;

            }
            else    temp = temp->next;//przejdź do kolejnego
        }
	}

	void DL_List::remove_end()
	{
	    if(is_Empty()) //jeśli lista jest pusta nic nie rób
            return;
        if(head->next == nullptr) //jeśli lista ma jeden element usuń go
        {
            delete head;
            head = nullptr;
            return;
        }
	    Node2* temp = head;
	    //dopóki element następny względem następnego(2 do przodu) istnieje
	    while( (temp->next)->next != nullptr)
            //przejdz do kolejnego
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr; //temp jest teraz ogonem
	}
	void DL_List::remove_beg()
	{
	    //Node2* temp=head;
	    if(!is_Empty())
        {
            Node2* temp = head;
            head = head->next;
            delete temp;
        }
	}
