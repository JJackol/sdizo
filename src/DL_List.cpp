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


	}

	void DL_List::print_rev()
	{

	    Node2* temp = tail;
	    while(temp != nullptr)
        {
            //std::cout.width(3);
            std::cout<< std::setw(4)<<std::left <<temp->val << " ";
            temp = temp->prev;
	    }
	    std::cout<<std::endl;

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
            tail = head;
            return;
        }
        else
		{
			tail->next = new Node2{val, nullptr, tail};
			tail = tail->next;
        }


	}
	void DL_List::insert_beg(int val)
	{
	    if(is_Empty())
        {
            tail = head = new Node2{val, nullptr};
            return;
        }
        else
		{
			head->prev = new Node2{val, head};
			head = head->prev;
		}
	}
	void DL_List::insert(int index, int val)
	{
		if(is_Empty())
		{
			if(index==0)
				tail = head = new Node2{val};
			return;
		}
		if(index == 0)
		{
			insert_beg(val);
			return;
		}

		Node2* temp = head;
		while(temp->next != nullptr && --index)
		{
			temp = temp->next;
		}
		temp->next = new Node2{val, temp->next, temp};
		if(temp == tail) tail = temp->next; //jesli dodano na koncu zaktualizuj tail.
	}

	int DL_List::at(int index)
	{
        if(is_Empty())
        {
            std::cout<<"lista pusta"<<std::endl;
            return -1;
        }
        if(index<0)
        {
        	std::cout<<"element o ujemnym indeksie nie istnieje"<<std::endl;
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
	int DL_List::find(int val)//done
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
        }while(temp != nullptr);
        return -2;
	}

	void DL_List::remove_at(int index)//done
	{
	    assert(index>=0);
	    if(is_Empty())
            return;
        Node2* temp = head;
        if(index==0) // jesli usuwany jest 0 el.
        {
            remove_beg();
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
            if(temp->next != nullptr)
			{
				temp->next->prev = temp;
			}
			else	tail = temp;

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
            remove_beg();
            temp = head;
        }
        Node2* pre_del;//zmienna pomocnicza do usuwania węzła i przerzucenia wskaźnika, poprzednik usuwanego

        while(temp != nullptr)
		{
			if(temp->val == val)
			{
				pre_del = temp->prev;
				pre_del->next = temp->next;
				delete temp;
				if(pre_del->next != nullptr)
				{
					temp = pre_del->next;
					temp->prev = pre_del;
				}
				else
				{
					tail = pre_del;
				}
			}
			else
			{
				temp = temp->next;
			}
		}//koniec while'a
	}

	void DL_List::remove_end()
	{
		if(!is_Empty())
        {
        	if( head == tail )
			{
				delete head;
				head = tail = nullptr;
				return;
			}
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
	}
	void DL_List::remove_beg()
	{
	    if(!is_Empty())
        {
        	if( head == tail)
			{
				delete head;
				head = tail = nullptr;
				return;
			}
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
	}

	void DL_List::clear()
	{
		while(!is_Empty())
			remove_beg();
	}
