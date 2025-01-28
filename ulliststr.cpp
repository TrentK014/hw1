#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_front(const std::string& val)
{
  if (head_ == nullptr)
  {
    Item* temp = new Item();
    temp->next = nullptr;
    temp->prev = nullptr;
    temp->last = 10;
    temp->first = 9;
    temp->val[9] = val;
    head_ = temp;
    tail_ = temp;
    size_++;
  }
  else if (head_->first > 0)
  {
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
  }
  else
  { //adds new item
    Item* temp = new Item();
    temp->last = ARRSIZE;
    temp->first = ARRSIZE - 1;
    temp->next = head_;
    temp->prev = nullptr;
    head_->prev = temp;
    head_ = temp;
    head_->val[ARRSIZE - 1] = val;
    size_ += 1;
  }
}

void ULListStr::push_back(const std::string& val)
{
  if (head_ == nullptr)
  {
    Item* temp = new Item();
    temp->next = nullptr;
    temp->prev = nullptr;
    temp->last = 1;
    temp->first = 0;
    temp->val[0] = val;
    head_ = temp;
    tail_ = temp;
    size_ += 1;
  }
  else if (tail_->last == ARRSIZE)
  { //adds new item
    Item* temp = new Item();
    temp->last = 1;
    temp->first = 0;
    temp->val[0] = val;
    temp->prev = tail_; 
    temp->next = nullptr;
    tail_->next = temp;
    tail_ = temp;
    size_ += 1;
  }
  else
  {
    tail_->val[tail_->last] = val;
    tail_->last += 1;
    size_++;
  }
}

void ULListStr::pop_front()
{
  if (head_ == nullptr)
  {
    return;
  }
  if (head_->first == ARRSIZE - 1)
  {
    if (head_->next == nullptr)
    {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
      size_ = 0;
    }
    else
    {
      Item* temp = head_;
      head_ = head_->next; 
      delete temp;
      head_->prev = nullptr;
      size_ -= 1;
    }
  }
  else
  {
    head_->val[head_->first] = "";
    head_->first += 1;
    size_--;
  }
}

void ULListStr::pop_back()
{
  if (tail_ == nullptr)
  {
    return;
  }
  if (tail_->last == 1)
  {
    if (tail_->prev == nullptr)
    {
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
      size_ = 0;
    }
    else
    {
      Item* temp = tail_;
      tail_ = tail_->prev;
      delete temp;
      tail_->next = nullptr;
      size_--;
    }
  }
  else
  {
    tail_->last -= 1;
    tail_->val[tail_->last] = "";
    size_--;
  }
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  Item* curr = head_;
  size_t sum = 0;
  if (loc < 0 || loc >= size_)
  {
    return nullptr;
  }

  while (curr != nullptr)
  {
    if (sum + (curr->last - curr->first - 1) < loc)
    {
      sum += (curr->last - curr->first);
      curr = curr->next;
    }
    else
    {
      return &curr->val[curr->first + loc - sum];
    }
  }

  return nullptr;
}

void ULListStr::print()
{
  Item* Curritem = head_;
  while (Curritem != NULL)
  {
      for (unsigned int j = Curritem->first; j < Curritem->last; j++)
      {
        std::cout << Curritem->val[j] << " "; 
      }
      Curritem = Curritem->next;
  }
  std::cout << std::endl;
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
